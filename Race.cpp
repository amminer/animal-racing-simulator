#include "Race.h"
#include "Animal.h"

/* Amelia Miner
 * 04/11/22
 * CS 202 section 003
 * PROGRAM #: 1
 * FILE: Race.cpp
 * PURPOSE: Represents a competition between an arbitrary set of animals;
 * 	minimum of 2 animals checked by start function.
 *  Animals stored in a dynamically allocated array of linkedlists, where
 * 	each breed has a row in the array and each animal of that breed is stored
 * 	in a node of that array row/linkedlist.
 * 		Animals are raced by calculating their performance and removing prey animals.
 *	Predatory animals larger than any prey animals will remove those prey animals
 *	from the race if separators are not set to raised.
 * 		May allow option to base race length on a time instead of distance - base race
 *	with derived time_race and dist_race?
 * 		May also add functionality between Race and Animal to give Animals an age
 *	based on the number of races they have run with increasing chance to have
 *	to retire with each additional race.
 */

Race::Race(void)
	: distance(0.0), winners({nullptr, nullptr}), separators_raised(false) {}

Race::Race(float new_distance, vector<Animal*> competitors, bool separators)
	: distance(new_distance), winners({nullptr, nullptr}), separators_raised(separators)
{
	for (Animal* elmt: competitors){
		auto new_entry = pair<Animal*, double>(elmt, -1.0);
		scoreboard.push_back(new_entry);
	}
}
