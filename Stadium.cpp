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
		I want to use system("clear"), but I fear graders are running Windows
	and I don't feel like checking for OS at runtime.
 */

Stadium::Stadium(void)
	: stable(Stable()), roster({})
{
	startup();
}

void Stadium::startup(void)
{
cout << "Welcome to Animal Racing Simulator Extreme!\n";
bool cont {true};
while (cont)
{
	//do menu things, call helpers, the usual... TODO
	int choice {0};
	cout << "/~ Main Menu ~/\n"
		 << " 1 - Inspect the stables\n"
		 << " 2 - Inspect the current roster for the next race\n"
		 << " 3 - Add a new animal to stables\n"
		 << " 4 - Remove an animal from stables\n"
		 << " 5 - Choose an animal from the stables for the next race\n"
		 << " 6 - Remove an animal from the roster for the next race\n"
		 << " 7 - Set up a race with the current roster\n"
		 << " 8 - Exit Animal Racing Simulator Extreme\n\n";
	display_cursor();
	choice = get_int();
	switch (choice){
		case 1:
			display_stable();
			break;
		case 2:
			display_roster();
			break;
		case 3:
			add_to_stable();
			break;
		case 4: //TODO in prog
			remove_from_stable();
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
		default:
			cout << "Invalid selection - try again\n";
			break;
	}
}
cout << "Thanks for playing!\n";
}

void Stadium::remove_from_stable(void)
{
	int choice {0};
	cout << "Would you like to remove by number or by name?\n"
		 << " 1 - number in stable\n"
		 << " 2 - name\n"
		 << " 3 - cancel\n";
	display_cursor();
	choice = get_int();
	switch (choice){
		case 1:
			remove_by_index();
			break;
		case 2:
			remove_by_name();
			break;
		case 3:
			return;
		default:
			cout << "Invalid selection - try again\n";
			break;
	}
}
void Stadium::remove_by_index(void)
{
	int choice1 {0}, choice2 {0};
	stable.display_breeds(true);
	cout << "Enter the breed number:\n";
	display_cursor();
	choice1 = get_int();
	cout << "Enter the animal number:\n";
	choice2 = get_int();
	if (stable.remove_animal(choice1, choice2)){
		cout << "Removed the animal.\n";
	}
	else{
		cout << "Error while removing the animal... try again\n";
	}

}
void Stadium::remove_by_name(void)
{
	//TODO in prog
}

int Stadium::get_int(void)
{
	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	return choice;
}

void Stadium::add_to_stable(void)
{
	int choice {0};
	string name, breed;
	/* Animal will be passed by ref & copied inside data structures
	 * because I used a class tempalte for my linkedlists
	 * but did not derive lists with animal-specific behaviors...
	 regrettable. */
	Animal* animal_ptr {nullptr}; 
	cout << "What is the new animal's name? {!q to quit}\n";
	display_cursor();
	getline(cin, name);
	if (name == "!q")
		return;
	cout << "What is the new animal's breed?\n"
		 << " 1 - tortoise\n"
		 << " 2 - hare\n"
		 << " 3 - cat\n"
		 << " 4 - cancel new animal\n";
	display_cursor();
	choice = get_int();
	switch (choice){
		case 1:
			animal_ptr = new Tortoise(name);
			break;
		case 2:
			animal_ptr = new Hare(name);
			break;
		case 3:
			animal_ptr = new Cat(name);
			break;
		case 4:
			return;
		default:
			cout << "invalid selection, try again:\n";
			add_to_stable();
			return;
	}
	if (animal_ptr and stable.add_animal(*animal_ptr)){
		cout << "Successfully added " << name << " the " << animal_ptr->get_breed()
			 << " to the stable!\n";
	}
	else{
		cout << "Error while adding " << name << " the " << breed
			 << " to the stable... try again\n";
	}
	delete animal_ptr;
}

void Stadium::display_roster(void)
{
	if (roster.empty())
		cout << "Roster is empty - choose animals from the stable!\n";
	else{
		cout << "Current roster:\n";
		for (auto aptr: roster)
			cout << *aptr;
	}
}

void Stadium::display_stable(void)
{
	if (stable.is_empty())
		cout << "The stable is empty - add new animals!\n";
	else
		stable.display_breeds();
}

void Stadium::display_cursor(void)
{
	cout << "~>";
}

int main(void)
{
	Stadium();
}
