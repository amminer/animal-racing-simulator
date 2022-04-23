/* Amelia Miner
 * 04/10/22
 * cs 202 section 003
 * program #: 1
 */

#include "Race.h"

int main(void)
{
	vector<Animal> animalsV = {Cat("fredward"), Hare("billiam"),
						   Tortoise("bartholomew"), Hare("James"),
						   Tortoise("bartholomew the second"), Cat("Dahlia")};
	LLL<Animal> animals;
	for (Animal elmt: animalsV)
		animals.push_back(elmt);

	vector<Animal*> animalPtrs;
	for (int i=0; i < animals.length(); i++){
		animalPtrs.push_back(&animals.at(i));
	}

	auto myRace = Race(1000, animalPtrs, true);

	for (int i=0; i < myRace.scoreboard.length(); i++){
		cout << "Race has a competitor: " << *myRace.scoreboard.at(i).first
			 << " with a score of " << myRace.scoreboard.at(i).second << '\n';
	}

	auto deadCritters = myRace.remove_prey();
	for (auto elmt: deadCritters)
		cout << "One dead: " << *elmt << '\n';
}
