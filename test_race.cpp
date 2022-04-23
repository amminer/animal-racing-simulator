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
	for (int i=0; i < animals.length(); i++){
		animalPtrs.push_back(&animals.at(i));
	}

	auto myRace = Race(2000, animalPtrs, false);

	vector<Animal*> eaten;
	if (myRace.start()){
		cout << "And they're off!\n";
		 eaten = myRace.stop();
	}
	else{
		cout << myRace.scoreboard.length() << " competitor(s) is not enough or too many!\n";
	}

	for (int i=0; i < myRace.scoreboard.length(); i++){
		cout << "Race has a competitor: " << *myRace.scoreboard.at(i).first
			 << " with a score of " << myRace.scoreboard.at(i).second << '\n';
	}

	cout << "\neaten critters:\n";
	for (Animal* a: eaten){
		cout << *a << '\n';
	}
}
