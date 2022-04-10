/* Amelia Miner
 * 04/10/22
 * cs 202 section 003
 * program #: 1
 * file: asgmt1.cpp
 * PURPOSE: Main function, display state to/take input from user
 */
#include <iostream>
#include "LL.h"
using namespace std;

int main(void)
{
	//testing int
	Node<int> x;
	x.set_data(2);
	Node<int> y(12);
	Node<int> z(49);
	Node<int> a = 1;

	x.set_next(&y);
	y.set_prev(&x);
	y.set_next(&z);
	z.set_prev(&y);
	z.set_next(&a);
	z.set_prev(&z);

	Node<int>* temp = &x;
	while (temp){
		cout << temp->get_data() << '\n';
		temp = temp->get_next();
	}
}
