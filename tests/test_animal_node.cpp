/* Amelia Miner
 * 04/10/22
 * cs 202 section 003
 * program #: 1
 */
#include "Race.h"
#include "Animal.h"
#include "CLL.h"
#include <iostream>

int main(void)
{
	Node<Animal> x;
	x.set_data(Animal("billy"));
	Node<Animal> y = Animal("bob");
	Node<Animal> z = Animal("jim");
	Node<Animal> a = Animal();

	x.set_next(&y);
	y.set_prev(&x);
	y.set_next(&z);
	z.set_prev(&y);
	z.set_next(&a);
	z.set_prev(&z);

	Node<Animal>* temp = &x;
	while (temp){
		cout << temp->get_data().get_name() << " : " << temp->get_data().get_breed() << '\n';
		temp = temp->get_next();
	}
}
