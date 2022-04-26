#include "Stadium.h"

/* Amelia Miner
 * 04/11/22
 * cs 202 section 003
 * program #: 1
 * file: Stadium.cpp
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
 *	predator can remove at most one prey animal, only from an adjacent lane.
 */

Stadium::Stadium(void)
	: stable(Stable()), roster({})
{
	startup();
}

void Stadium::startup(void)
{
cout << "Welcome to Animal Racing Simulator Extreme!\n";
bool cont = true;
while (cont)
{
	//do menu things, call helpers, the usual... TODO
	int choice = 0;
	cout << "/~ Main Menu ~/\n"
		 << " 1 - Inspect the stables\n"
		 << " 2 - Inspect the current roster for the next race\n"
		 << " 3 - Add a new animal to stables\n"
		 << " 4 - Remove an animal from stables\n"
		 << " 5 - Choose an animal from the stables for the next race\n"
		 << " 6 - Remove an animal from the roster for the next race\n"
		 << " 7 - Set up a race with the current roster\n"
		 << " 8 - Exit Animal Racing Simulator Extreme\n\n";
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	if (choice < 1 or choice > 8)
		cout << "Invalid selection - try again\n";
	else{
		switch (choice){
			case 1: //TODO
				break;
			case 2: //TODO
				break;
			case 3: //TODO
				break;
			case 4: //TODO
				break;
			case 5: //TODO
				break;
			case 6: //TODO
				break;
			case 7: //TODO
				break;
			case 8: //TODO
				cont = false;
				break;
		}
	}
}
cout << "Thanks for playing!\n";
}

int main(void)
{
	Stadium();
}
