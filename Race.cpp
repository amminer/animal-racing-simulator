#include "Race.h"
#include "Animal.h"
#include <algorithm>

/* Amelia Miner
 * 04/11/22
 * CS 202 section 003
 * PROGRAM #: 1
 * FILE: Race.cpp
 * PURPOSE: Represents a competition between an arbitrary set of animals;
 * 	minimum of 2 animals checked by start function.
 *  Animals stored in a dynamically allocated array of linkedlists, where
 * 	each breed has a row in the array and each animal of that breed is stored
 * 	in a node of that array row/linkedlist.
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

/* If any predators are adjacent to smaller prey, removes prey from race;
see class Animal for details of predation mechanic.
Predator-pray relation is antisymmetric, so no need to worry about mutual
predation, we can just check each pair and filter for unique return values.
Returns animals eaten. */
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
