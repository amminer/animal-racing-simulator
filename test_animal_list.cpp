/* Amelia Miner
 * 04/10/22
 * cs 202 section 003
 * program #: 1
 */
#include "Race.h"
#include "Animal.h"
#include "CLL.h"
#include <iostream>
using namespace std;

int main(void)
{
	Animal x = Animal("billy");
	Animal y("bob");
	Animal z("jim");
	Animal a = Animal();

	CLL<Animal> l;
	l.push_back(x);
	l.push_back(y);
	l.push_back(z);
	l.push_back(a);
	l.display();

	cout << "Looking up bob...\n";
	if (Animal* bob_found = l.lookup(Animal("bob")); bob_found)
		 cout << "Found:\n" << *bob_found << "At: " << bob_found << '\n';
	else
		cout << "Notfound!\n";

	cout << "Looking up jamie...\n";
	if (Animal* jamie_found = l.lookup(Animal("jamie")); jamie_found)
		 cout << "Found: " << *jamie_found << "At: " << jamie_found << '\n';
	else
		cout << "Notfound!\n";
}
