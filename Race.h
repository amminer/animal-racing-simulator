/* Amelia Miner
 * 04/11/22
 * cs 202 section 003
 * program #: 1
 * file: Race.h
 * PURPOSE: Represents a competition between an arbitrary set of animals;
 * 	minimum of 2 animals checked by start function;
 *  animals stored in a dynamically allocated array of linkedlists, where
 * 	each breed has a row in the array and each animal of that breed is stored
 * 	in a node of that array row/linkedlist.
 * 	Animals are raced against each other one at a time
 * 	May also add functionality between Race and Animal to give Animals an age
 *	based on the number of races they have run with increasing chance to have
 *	to retire with each additional race.
 */

#pragma once

#include<utility>
#include<vector>
#include "CLL.h"
#include "Animal.h"

/* class Race
 * See header comment
 * Only to be instantiated in main driver code
 * 	when user chooses to set up a race
 */
class Race{
    public:
		Race(void);
		~Race(void);
		Race(vector<Animal> new_roster, int new_dist);
		Race(const Race& other) = delete;
		Race& operator=(const Race& rhs) = delete;

		void start(void);				//calculates the performance of animals in roster.
		vector<Animal*> stop(void);		//prints results, returns dead animals for Stable.
		void separate_lanes(void);		//sets lane_separators_raised to true.
		void unseparate_lanes(void);	//sets lane_separators to true.
		void remove_prey(void);			//if there is a predator, removes all smaller prey

        /* foos::bar(args) TODO document race funcs
         * PURPOSE: x (what it does - how goes in .cpp)
         * ARGS:    y
         * RETURN:  z
         */
        //void bar();

    private:
		Animal* winners[2]; //contains ptrs to the first and second place animals.
		vector<pair<Animal*, double>> roster; //Holds ptr to each animal and its time.
		void display(void); //called from start to display contestants.
		bool separators_raised; //used to determine whether predators can hunt.
		const float distance; //unsure if should be const?
};
