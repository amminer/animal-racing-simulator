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

	add_an_animal(myStable, newCat);	 //successfully added a new breed when the array is empty
	add_an_animal(myStable, anotherCat); //successfully added more of existing breed
	add_an_animal(myStable, anotherCat); //successfully rejected duplicate name!
	//TODO test multiple rows :S add another breed...
	how_many_animals(myStable);			 //yep that works too (pending more testing)
}
