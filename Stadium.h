#pragma once

#include <vector>	//store and pass collections of animals/roster
#include <iostream> //display to/take input from user
#include "Stable.h" //keep a stable of animals; handles memory
#include "Race.h"	//race animals (the whole point!)
#include "Animal.h" //see above

using namespace std;

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

/* class Stadium
 * See header comment
 * Only to be instantiated in main driver code
 */
class Stadium{
    public:
		Stadium(bool clear_screen=false);

		//main loop functions
		void startup(void);				//main loop
		bool display_stable(bool indices=false) const;
		bool display_roster(bool indices=false) const;
		void add_to_stable(void);
		void remove_from_stable(void);
		void add_to_roster(void);		//temporary list of animals to race
		void remove_from_roster(void);	//temporary list of animals to race
		void setup_race(int distance=-1);

		//import_animals(string filename); //intended but not implemented
		//export_animals(string filename); //intended but not implemented

    private:	//private indicates nesting behind main menu
		void ask_clear_roster(void); //called only after race is run
		void clear_roster(void); //called from ask_clear_roster()
		void remove_from_roster_by_name(string name="_"); //default name allows for non-UI reuse
		void remove_from_roster_by_index();
		void add_to_roster_by_name();
		void add_to_roster_by_index();
		void remove_from_stable_by_name(string name="_"); //default name allows for non-UI reuse
		void remove_from_stable_by_index();

		//pure utility//display functions
		int get_int(void); //handles bad cin input, but not bounds checking on menus
		void display_cursor(void) const; //called when collecting anything but a string
		void clear_screen(void) const; //used if user runs program with -c switch
		void pause(void) const;		   //used if user runs program with -c switch

		//data
		Stable stable; //see Stable.h
		vector<Animal*> roster; //Holds ptr to animals chosen by user prior to race.
		Animal* find_animal_by_name(string find_name);
		
		//flags (must be set by constructor)
		bool CLEAR_SCREEN; // set to true in constructor by passing -c switch/cmd line arg
};

