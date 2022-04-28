#pragma once

#include <vector>		//storing and passing winners and losers (predated)
#include <algorithm>	//std::find, check for presence of animals in win/lose
#include <iostream>		//display race information in stop()
#include "LinkedList.h" //store competitors
#include "Animal.h"		//races use animals

using namespace std;

/* Amelia Miner
 * 04/11/22
 * CS 202 section 003
 * PROGRAM #: 1
 * FILE: Race.h
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

/* class Race
 * See header comment;
 * Only to be instantiated inside class Stadium.
 */
class Race{
    public:
		//Race(void); //race should only be instantiated with parameters.
		Race(float new_distance, vector<Animal*>& competitors, bool separators);

		//returns whether race can run, calls Animal::calculate_time and Race::remove_prey.
		bool start(void);
		vector<Animal*>& stop(void);	//returns removed animals; cannot be const, returns ref

    private:
		//helper functions
		vector<Animal*> remove_prey(void); //enforces predation mechanic (called by start())

		//data
		const float distance;
		vector<Animal*> winners; //contains ptrs to the first and second place animals.
		vector<Animal*> losers;  //containst ptrs to animals that were removed by predation.
		CLL< pair<Animal*, float> > scoreboard; //Holds ptr to each animal and its time.
		const bool separators_raised; //used to determine whether predators can hunt.
};

