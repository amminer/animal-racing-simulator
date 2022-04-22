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
	: 
