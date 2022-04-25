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

int main(void)
{
	Stable myStable = Stable();

	Cat* newCat = new Cat("Majora");
	myStable.add_animal(*newCat);
	how_many_animals(myStable);

	Cat* anotherCat = new Cat("Jean");
	myStable.add_animal(*anotherCat);
	how_many_animals(myStable);
}
