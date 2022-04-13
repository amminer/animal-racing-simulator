/* Amelia Miner
 * 04/10/22
 * cs 202 section 003
 * program #: 1
 */
#include "Race.h"
#include "Animal.h"
#include "CLL.h"
#include "LLL.h"
#include <iostream>
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
}

int main(void)
{
	test_CLL();
	test_LLL();
}
