/* Amelia Miner
 * 04/11/22
 * cs 202 section 003
 * program #: 1
 * file: Stadium.h
 * PURPOSE: Main class instantiated to run program, Maintains a Stable instance
 *	and allows the user to arbitrarily add or remove animals from the stable and
 *	run races with animals (chosen by looking up by name or by displaying the
 *	entire stable or one breed from the stable and choosing an index).
 *		Handles all user input and most output to cout; races also have some
 *	output.
 *		Animals can be of at least 3 breeds and have an arbitrary name. The range
 *	of possible speed and endurance values for any given animal are predetermined
 *	by breed, but the actual speed and endurance of any animal instance is
 *	generated pseudorandomly.
 *		Races can be of arbitrary length. Races can have each animal run in a
 *	separated lane, or races can have animals run on an un-separated track. If
 *	the lanes are not separated, predatory animals will be free to predate upon
 *	prey animals that they are large enough to individually overwhelm. Prey who
 *	meet these criteria will be removed from the race and will not return to the
 *	stable belonging to the Stadium instance that initiated the race. Each
 *	predator can remove at most one prey animal, and it will remove the one
 *	which is in the closest lane to itself.
 */

#pragma once

#include <utility>
#include <vector>
#include <iostream>
#include "Stable.h"
#include "Race.h"
#include "Animal.h"

using namespace std;

/* class Stadium
 * See header comment
 * Only to be instantiated in main driver code
 */
class Stadium{
    public:
		Stadium(void); //main loop goes here - write menu functions?

		void startup(void);				//main loop
		void add_to_stable(void);
		void remove_from_stable(void);
		void add_to_roster(void);		//temporary list of animals to race
		void remove_from_roster(void);	//temporary list of animals to race
		void setup_race(void);

        /* foos::bar(args) TODO
         * PURPOSE: x (what it does - how goes in .cpp)
         * ARGS:    y
         * RETURN:  z
         */
		//import_animals(string filename); //eventually?
		//export_animals(string filename); //eventually?

    private:
		void remove_by_name(void);
		void remove_by_index(void);
		void display_roster(void);
		void display_stable(void);
		int get_int(void);
		void display_cursor(void);

		Stable stable; //see Stable.h
		vector<Animal*> roster; //Holds ptr to animals chosen by user prior to race. TODO empty per race
		Animal* find_animal_by_name(string find_name);
};

