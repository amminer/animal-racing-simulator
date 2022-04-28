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
	list.push_back(1);
	list.push_back(3);
	list.push_back(5);
	list.push_back(7);
	list.display();
}
