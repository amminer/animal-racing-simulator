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

Stadium::Stadium(bool clear_screen)
	: stable(Stable()), roster({}), CLEAR_SCREEN(clear_screen)
{
	startup();
}

void Stadium::clear_screen(void)
{
	#ifdef WINDOWS
		system("cls");
	#else
		//assume posix compliant
		system("clear");
	#endif
}

void Stadium::pause(void)
{
	cout << "Press enter to continue...\n";
	cin.ignore(100, '\n');
}

void Stadium::startup(void)
{
cout << "Welcome to Animal Racing Simulator Extreme!\n";
if (CLEAR_SCREEN)
	pause();
bool cont {true};
int choice {0};
while (cont)
{
	choice = 0;
	if (CLEAR_SCREEN)
		clear_screen();
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
			display_stable(); //ignoring returned bool
			break;
		case 2:
			display_roster(); //ignoring returned bool
			break;
		case 3:
			add_to_stable();
			break;
		case 4:
			remove_from_stable();
			break;
		case 5:
			add_to_roster();
			break;
		case 6:
			remove_from_roster();
			break;
		case 7:
			setup_race();
			break;
		case 8:
			cont = false;
			break;
		default:
			cout << "Invalid selection - try again\n";
			break;
	}
}
cout << "Thanks for playing!\n";
return;
}

void Stadium::setup_race(int distance)
{
	if (roster.size() < 2 or roster.size() > 8){
		cout << "Roster must have 2 to 8 animals!\n";
		return;
	}
	int choice {-1};
	bool separators;
	if (distance == -1){
		cout << "How many meters long should the race be? {-1 to cancel; minimum 100}\n";
		display_cursor();
		distance = get_int();
		if (distance == -1)
			return;
		else if (distance < 100){ //should be const private member var MIN_DIST TODO
			cout << distance << " meters is not a valid choice!\n";
			setup_race();
			return;
		}
	}
	cout << "Should the animals' lanes be separated from one another?\n"
		 << " 1 - yes\n"
		 << " 2 - no\n"
		 << " 3 - cancel\n";
	display_cursor();
	choice = get_int();
	switch (choice){
		case 1:
			separators = true;
			break;
		case 2:
			separators = false;
			break;
		case 3:
			return;
		default:
			cout << "Invalid selection - try again\n";
			setup_race(distance);
			return;
	}
	Race race {Race(distance, roster, separators)};
	if (race.start()){
		clear_roster();
		for (Animal* rip: race.stop()){
			stable.remove_animal(rip->get_name());
		}
		if (CLEAR_SCREEN)
			pause();
	}
	else{
		cout << "Error running race... try again\n";
	}
	return;
}
void Stadium::clear_roster(void)
{
	while(!roster.empty())
		roster.pop_back();
	return;
}

void Stadium::remove_from_roster(void)
{
	if (!display_roster(true))
		return; //no roster to remove from!
	int choice {0};
	cout << "Would you like to choose by number or by name?\n"
		 << " 1 - number in roster\n"
		 << " 2 - name\n"
		 << " 3 - clear roster\n"
		 << " 4 - cancel\n";
	display_cursor();
	choice = get_int();
	switch (choice){
		case 1:
			remove_from_roster_by_index();
			break;
		case 2:
			remove_from_roster_by_name();
			break;
		case 3:
			clear_roster();
			break;
		case 4:
			return;
		default:
			cout << "Invalid selection - try again\n";
			remove_from_roster();
			return;
	}
}
void Stadium::remove_from_roster_by_index(void)
{
	int choice {0};
	cout << "Enter the animal number: {-1 to cancel}\n";
	display_cursor();
	choice = get_int();
	if (choice != -1){
		if (choice > 0 and (size_t)choice < roster.size()){
			string name = roster.at(choice-1)->get_name();
			roster.erase(roster.begin() + choice - 1);
			cout << "Removed " << name << " from the roster.\n";
			if (CLEAR_SCREEN)
				pause();
		}
		else{
			cout << "Error while finding the animal... try again\n";
			remove_from_roster_by_index();
		}
	}
	return;
}
void Stadium::remove_from_roster_by_name(string name)
{
	if (name == "_"){
		cout << "Enter the name of the animal {!q to quit}: ";
		getline(cin, name);
		if (name == "!q")
			return;
	}
	if (auto found_animal = stable.find_animal(name); found_animal){
		if (auto to_del = find(roster.begin(), roster.end(), found_animal); to_del != roster.end()){
			roster.erase(to_del);
			cout << "Removed " << name << " from the roster.\n";
		}
		if (CLEAR_SCREEN)
			pause();
	}
	else{
		cout << "Error removing " << name << " from the roster... try again\n";
		remove_from_roster_by_name();
	}
	return;
}

void Stadium::add_to_roster()
{
	int choice {0};
	if (!display_stable(true))
		return; //no roster to choose from!
	cout << "Would you like to choose by number or by name?\n"
		 << " 1 - number in stable\n"
		 << " 2 - name\n"
		 << " 3 - cancel\n";
	display_cursor();
	choice = get_int();
	switch (choice){
		case 1:
			add_to_roster_by_index();
			break;
		case 2:
			add_to_roster_by_name();
			break;
		case 3:
			return;
		default:
			cout << "Invalid selection - try again\n";
			break;
	}
}
void Stadium::add_to_roster_by_index(void)
{
	int choice1 {0}, choice2 {0};
	cout << "Enter the breed number: {-1 to cancel}\n";
	display_cursor();
	choice1 = get_int();
	if (choice1 == -1)
		return;
	cout << "Enter the animal number: {-1 to cancel}\n";
	display_cursor();
	choice2 = get_int();
	if (choice2 == -1)
		return;
	if (Animal* found_animal = stable.find_animal(choice1, choice2); found_animal){
		if (find(roster.begin(), roster.end(), found_animal) == roster.end()){
			roster.push_back(found_animal);
			cout << "Added " << found_animal->get_name() << " the "
				 << found_animal->get_breed() << " to the roster.\n";
		}
		else{
			cout << found_animal->get_name() << " the "
				 << found_animal->get_breed() << " is already in the roster!\n"; //TODO Animal::display_flat(bool flat)
		}
		if (CLEAR_SCREEN)
			pause();
	}
	else{
		cout << "Error finding the animal... try again\n";
		add_to_roster_by_index();
	}
	return;
}
void Stadium::add_to_roster_by_name(void)
{
	string name;
	cout << "Enter the name of the animal {!q to quit}: ";
	getline(cin, name);
	if (name == "!q")
		return;
	if (auto found_animal = stable.find_animal(name); found_animal){
		if (find(roster.begin(), roster.end(), found_animal) == roster.end()){
			roster.push_back(found_animal);
			cout << "Added " << name << " to the roster.\n";
		}
		else{
			cout << found_animal->get_name() << " the "
				 << found_animal->get_breed() << " is already in the roster!\n"; //TODO Animal::display_flat(bool flat)
		}
		if (CLEAR_SCREEN)
			pause();
	}
	else{
		cout << "Error adding " << name << " to the roster... try again\n";
		add_to_roster_by_name();
	}
	return;
}

void Stadium::remove_from_stable(void)
{
	if (!display_stable(true))
		return; //no stable to remove from!
	int choice {0};
	cout << "Would you like to remove by number or by name?\n"
		 << " 1 - number in stable\n"
		 << " 2 - name\n"
		 << " 3 - cancel\n";
	display_cursor();
	choice = get_int();
	switch (choice){
		case 1:
			remove_from_stable_by_index();
			break;
		case 2:
			remove_from_stable_by_name();
			break;
		case 3:
			return;
		default:
			cout << "Invalid selection - try again\n";
			break;
	}
}
void Stadium::remove_from_stable_by_index(void)
{
	int choice1 {0}, choice2 {0};
	cout << "Enter the breed number: {-1 to cancel}\n";
	display_cursor();
	choice1 = get_int();
	if (choice1 == -1)
		return;
	cout << "Enter the animal number: {-1 to cancel}\n";
	display_cursor();
	choice2 = get_int();
	if (choice2 == -1)
		return;
	if (Animal* found_animal = stable.find_animal(choice1, choice2)){
		remove_from_roster_by_name(found_animal->get_name());
	}
	if (stable.remove_animal(choice1, choice2)){
		cout << "Removed the animal.\n";
		if (CLEAR_SCREEN)
			pause();
	}
	else{
		cout << "Error while removing the animal... try again\n";
		remove_from_stable_by_index();
	}
}
void Stadium::remove_from_stable_by_name(void)
{
	string name;
	cout << "Enter the name of the animal to remove {!q to quit}: ";
	getline(cin, name);
	if (name == "!q")
		return;
	else{
		if (stable.remove_animal(name)){
			cout << "Removed " << name << " from the stable.\n";
			if (CLEAR_SCREEN)
				pause();
		}
		else{
			cout << "Error removing " << name << " from the stable... try again\n"
				 << "(Names are case-sensitive!)\n";
			remove_from_stable_by_name();
		}
	}
	return;
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
	cout << "What is the new animal's name? {!q to quit} ";
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
	if (stable.add_animal(*animal_ptr)){
		cout << "Successfully added " << name << " the " << animal_ptr->get_breed()
			 << " to the stable!\n";
		if (CLEAR_SCREEN)
			pause();
	}
	else{
		cout << "Error while adding " << name << " the " << breed
			 << " to the stable... try again\n";
	}
	delete animal_ptr;
	return;
}

bool Stadium::display_roster(bool indices)
{
	if (roster.empty()){
		cout << "Roster is empty - choose animals from the stable!\n";
		if (CLEAR_SCREEN)
			pause();
		return false;
	}
	else{
		cout << "Current roster:\n";
		for (size_t i=0; i < roster.size(); i++){
			if (indices)
				cout << "Animal " << i << ":\n";
			cout << *roster.at(i);
		}
		cout << '\n';
		if (!indices and CLEAR_SCREEN)
			pause();
		return true;
	}
}

bool Stadium::display_stable(bool indices)
{
	if (stable.is_empty()){
		cout << "The stable is empty - add new animals!\n";
		if (CLEAR_SCREEN)
			pause();
		return false;
	}
	else{
		cout << "Current stable:\n";
		stable.display_breeds(indices);
		if (!indices and CLEAR_SCREEN)
			pause();
		return true;
	}
}

void Stadium::display_cursor(void)
{
	cout << "~>";
}

int main(int argc, char** argv)
{
	if (argc > 1){ //cmd args
		char clear_flag[2] {'-', 'c'};		   // -c : clear screen
		if (strcmp(argv[1], clear_flag) == 0){ // refreshes screen at main menu, enables pauses
			Stadium(true);
			return 0;
		}
	}
	Stadium();
	return 0;
}
