/* Amelia Miner
 * 04/10/22
 * cs 202 section 003
 * program #: 1
 */

#include "Race.h"

int main(void)
{
	srand(time(0));
	vector<Animal> animalsV = {Cat("fredward"), Hare("billiam"),
						   Tortoise("bartholomew"), Hare("James"),
						   Tortoise("bartholomew the second"), Cat("Dahlia")};
	LLL<Animal> animals;
	for (Animal elmt: animalsV)
		animals.push_back(elmt);

	vector<Animal*> animalPtrs;
	for (size_t i=0; i < animals.length(); i++){
		animalPtrs.push_back(&animals.at(i));
	}

	auto myRace = Race(2000, animalPtrs, true);

	vector<Animal*> eaten;
	if (myRace.start()){
		cout << "\nAnd they're off!\n";
		 eaten = myRace.stop();
	}
	else{
		cout << animalsV.size() << " competitor(s) is not enough or too many!\n";
	}
}
