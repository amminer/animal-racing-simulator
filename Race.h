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

/* class Race
 * See header comment
 * Only to be instantiated in main driver code
 * 	when user chooses to set up a race
 */
class Race{
    public:
		Race(void);
		~Race(void);
		Race(vector<Animal>);
		Race(const Race& other) = delete;
		Race& operator=(const Race& rhs) = delete;

		void start(void);				//calculates the performance of animals in roster.
		void stop(void);				//reports the results of start().
		void separate_lanes(void);		//sets lane_separators_raised to true.
		void unseparate_lanes(void);	//sets lane_separators to true.
		void remove_prey(void);

        /* foos::bar(args)
         * PURPOSE: x (what it does - how goes in .cpp)
         * ARGS:    y
         * RETURN:  z
         */
        void bar();

    private:
		Animal* winners[2]; //contains ptrs to the first and second place animals
		void display(display); //called from start to display contestants
};
