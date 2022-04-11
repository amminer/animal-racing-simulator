/* Amelia Miner
 * 04/10/22
 * cs 202 section 003
 * program #: 1
 */
#include <iostream>
#include "CLL.h"
#include "Animal.h"
using namespace std;

int main(void)
{
	CLL<int> list;
	list.insert(1);
	list.insert(3);
	list.insert(5);
	list.insert(7);
	list.display();
}
