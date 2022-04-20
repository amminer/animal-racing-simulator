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

#pragma once

#include<utility>
#include<vector>
#include "LinkedList.h"
#include "Animal.h"

/* class Race
 * See header comment;
 * Only to be instantiated inside class Stadium.
 */
class Race{
    public:
		Race(void);
		~Race(void);
		Race(vector<Animal> new_roster, int new_dist);
		Race(const Race& other) = delete;
		Race& operator=(const Race& rhs) = delete;

		//returns whether race can run, calls Animal::calculate_time and Race::remove_prey
		bool start(void);
		vector<Animal*> stop(void);	//prints results, returns removed animals.
		Animal* get_results(void);	//returns winners array - should just have stop display winners?
		//if there is a predator, removes at most one smaller prey, closest first.

    private:
		Animal** winners[2]; //contains ptrs to the first and second place animals.
		vector<pair<Animal*, double>> roster; //Holds ptr to each animal and its time.
		const void display(void); //called from start to display contestants.
		const bool separators_raised; //used to determine whether predators can hunt.
		void remove_prey(void);
		const float distance;
};
