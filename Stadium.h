/* Amelia Miner
 * 04/11/22
 * cs 202 section 003
 * program #: 1
 * file: Stadium.h
 * PURPOSE: Main class instantiated to run program, Maintains a Stable instance
 *	and allows the user to arbitrarily add or remove animals from the stable and
 *	run races with animals (chosen by looking up by name or by displaying the
 *	entire stable or one breed from the stable and choosing an index).
 *		Animals can be of 3 breeds and have an arbitrary name. The range of possible
 *	speed and endurance values for any given animal are predetermined by breed,
 *	but the actual speed and endurance of any animal instance is generated
 *	pseudorandomly.
 *		Races can be of arbitrary length. Races can have each animal run in a
 *	separated lane, or races can have animals run on an un-separated track. If
 *	the lanes are not separated, predatory animals will be free to predate upon
 *	prey animals that they are large enough to individually overwhelm. Prey who
 *	meet these criteria will be removed from the race and will not return to the
 *	stable belonging to the Stadium instance that initiated the race.
 */

#pragma once

#include<utility>
#include<vector>
#include "CLL.h"
#include "Animal.h"

/* class Stadium
 * See header comment
 * Only to be instantiated in main driver code
 */
class Stadium{
    public:
		Stadium(void);
		~Stadium(void);
		Stadium(vector<Animal> new_roster, int new_dist);
		Stadium(const Stadium& other) = delete;
		Stadium& operator=(const Stadium& rhs) = delete;

        /* foos::bar(args) TODO
         * PURPOSE: x (what it does - how goes in .cpp)
         * ARGS:    y
         * RETURN:  z
         */
        //void bar();

    private:
		vector<Animal*> temp_roster; //Holds ptr to animals chosen by user prior to race. TODO empty per race?
		void display(void); //called from start to display contestants.
		bool separators_raised; //used to determine whether predators can hunt.
		const float distance; //unsure if should be const?
};
