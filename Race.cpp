#include "Race.h"
#include "Animal.h"
#include <algorithm>
#include <typeinfo>

/* Amelia Miner
 * 04/11/22
 * CS 202 section 003
 * PROGRAM #: 1
 * FILE: Race.cpp
 * PURPOSE: Represents a competition between an arbitrary set of animals;
 * 	minimum of 2 animals checked by start function.
 * 		Animals are raced by calculating their performance and removing prey animals.
 *	Predatory animals larger than any prey animals will remove those prey animals
 *	from the race if separators are not set to raised.
 * 		May allow option to base race length on a time instead of distance - base race
 *	with derived time_race and dist_race?
 * 		May also add functionality between Race and Animal to give Animals an age
 *	based on the number of races they have run with increasing chance to have
 *	to retire with each additional race.
 */

/*				CONSTRUCTORS, DESTRUCTORS, OPERATORS, AND HELPERS				*/
//Race::Race(void) //race should only be instantiated with parameters
//	: distance(0.0), winners({nullptr, nullptr}), separators_raised(false) {}

Race::Race(float new_distance, vector<Animal*>& competitors, bool separators)
	: distance(new_distance), winners({nullptr, nullptr}), separators_raised(separators)
{
	for (Animal* elmt: competitors){
		auto new_entry = pair<Animal*, float>(elmt, -1.0);
		scoreboard.push_back(new_entry);
	}
}

/*						PUBLIC FUNCTIONS					*/
/* If any predators are adjacent to smaller prey, removes prey from race;
see class Animal for details of predation mechanic.
Predator-pray relation is antisymmetric, so no need to worry about mutual
predation, we can just check each pair and filter for unique return values.
Returns animals eaten.
May mutate state of scoreboard (predators incur penalty for eating).*/
vector<Animal*> Race::remove_prey(void)
{
	vector<Animal*> ret;
	int num_competitors = scoreboard.length();
	float penalty_for_eating = 60.0;
	for (int i=0; i < num_competitors; i++){
		Animal* this_animal = scoreboard.at(i).first;
		if (i!=0){							//check prev animal unless on head
			Animal* prev_animal = scoreboard.at(i-1).first;
			if (this_animal->predates(*prev_animal)
				and std::find(ret.begin(), ret.end(), prev_animal) == ret.end()){ //i eats i-1
				ret.push_back(scoreboard.at(i-1).first);
				scoreboard.at(i).second += penalty_for_eating;
				continue; //one meal per predator
			}
		}
		else if (i != num_competitors-1){	//check next animal unless on tail
			Animal* next_animal = scoreboard.at(i+1).first;
			if (this_animal->predates(*next_animal)
				and std::find(ret.begin(), ret.end(), next_animal) == ret.end()){ //i eats i+1
				ret.push_back(scoreboard.at(i+1).first);
				scoreboard.at(i).second += penalty_for_eating;
				continue; //one meal per predator
			}
		}
	}
	return ret;
}

bool Race::start(void)
{
	int num_competitors = scoreboard.length();
	if (num_competitors > 1){
		//remove prey
		if (!separators_raised)
			losers = remove_prey();
		//calculate scores
		vector<float> scores;
		for (int i=0; i < num_competitors; i++){
			Animal* this_animal = scoreboard.at(i).first;
			/*
			if (Cat* specific_animal = dynamic_cast<Cat*>(this_animal)){
				std::cout << "Cat detected\n";
				scoreboard.at(i).second = specific_animal->calculate_time(distance);
			}
			else
			*/
				scoreboard.at(i).second = this_animal->calculate_time(distance);
			scores.push_back(scoreboard.at(i).second);
		}
		//determine winners
		pair<Animal*, float> gold=pair(nullptr, -1.0), silver=pair(nullptr, -1.0);
		for (int i=0; i < num_competitors; i++){
			if (std::find(losers.begin(), losers.end(), scoreboard.at(i).first) == losers.end()){
				if (scores.at(i) < gold.second or gold.second < 0){
					if (gold.first)
						silver = gold;
					gold = scoreboard.at(i);
				}
				else if (scores.at(i) < silver.second or silver.second < 0)
					silver = scoreboard.at(i);
			}
		}
		winners.at(0) = gold.first;
		winners.at(1) = silver.first;
		return true;
	}
	else
		return false;
}

vector<Animal*> Race::stop(void)
{
	std::cout << "First place: " << *winners.at(0)
		      << "Second place: " << *winners.at(1) << '\n';
	return losers;
}
