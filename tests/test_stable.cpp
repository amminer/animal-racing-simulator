#include <iostream>
#include <vector>
#include "Stable.h"
#include "Race.h"

using std::cout;
using std::vector;

void how_many_animals(Stable& myStable)
{
	if (myStable.is_empty())
		cout << "Empty stable\n";
	else
		cout << "Stable has " << myStable.get_num_breeds() << " breeds of animal.\n";
}

void add_an_animal(Stable& myStable, Animal& newCat)
{
	if (myStable.add_animal(newCat))
		cout << "Added " << newCat;
	else
		cout << "Adding " << newCat << "\b failed!\n";
}

int main(void)
{
	Stable myStable = Stable();
	Cat newCat = Cat("Majora");
	Cat anotherCat = Cat("Jean");
	Tortoise newTort = Tortoise("Ankeny");
	Hare newHare = Hare("Anthony");

	add_an_animal(myStable, newCat);	 //successfully added a new breed when the array is empty
	add_an_animal(myStable, anotherCat); //successfully added more of existing breed
	add_an_animal(myStable, anotherCat); //successfully rejected duplicate name!
	add_an_animal(myStable, newTort);	 //working!
	add_an_animal(myStable, newCat);	 //working!
	add_an_animal(myStable, newHare);	 //working!
	how_many_animals(myStable);			 //yep that works too (pending more testing)

	int bn=-1, ai=-1;
	myStable.display_breeds();
	cout << "Enter a breed number: ";
	cin >> bn;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Enter an animal index: ";
	cin >> ai;
	cin.clear();
	cin.ignore(100, '\n');
	Animal* thatOne = myStable.get_animal_at_indices(bn, ai);
	thatOne->display(); //works!

	string thisName;
	cout << "Enter an animal's name: ";
	cin >> thisName;
	Animal* thisOne = myStable.find_animal(thisName); //works!
	if (thisOne){
		int torem;
		cout << "Found " << *thisOne;
		cout << "Remove it? Enter 1 or 0: ";
		cin >> torem;
		if (torem){
			myStable.remove_animal(thisOne->get_name());
			cout << "Removed; check state:\n";
			myStable.display_breeds();
		}
		else
			cout << "How saintly of you. Destroying everything...\n";
	}
	else
		cout << "Could not find an animal named " << thisName << "...\n";

}
