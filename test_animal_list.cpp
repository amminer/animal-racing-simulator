/* Amelia Miner
 * 04/10/22
 * cs 202 section 003
 * program #: 1
 */
#include "Animal.h"
#include "LinkedList.h"
#include <iostream>
#include <unistd.h>
using namespace std;

void test_CLL(void)
{
	cout << "\ntesting CLL:\n";
	Tortoise x = Tortoise("billy");
	Cat y("bob");
	Hare z("jim");

	CLL<Animal> l;
	l.push_back(x);
	l.push_back(y);
	l.push_back(z);
	l.display();

	cout << "\ntesting lookup...\n";
	Animal* found_animal = l.lookup(Animal("bob"));
	if (found_animal)
		cout << "Found " << *found_animal;
	else
		cout << "Not found! (ERROR)\n";

	cout << "\ntesting remove...\n";
	l.remove(Animal("bob"));
	l.display();
}

void test_LLL(void)
{
	cout << "\ntesting LLL:\n";
	Tortoise x = Tortoise("billy");
	Cat y("bob");
	Hare z("jim");

	LLL<Animal> l;
	l.push_back(x);
	l.push_back(y);
	l.push_back(z);
	l.display();

	cout << "\ntesting lookup...\n";
	Animal* found_animal = l.lookup(Animal("billy"));
	if (found_animal)
		cout << "Found " << *found_animal;
	else
		cout << "Not found! (ERROR)\n";

	cout << "\ntesting remove...\n";
	l.remove(Animal("billy"));
	l.display();
}

	
int main(void)
{
	test_LLL();
	test_CLL();
}
