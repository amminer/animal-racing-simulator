/* Amelia Miner
 * 04/09/22
 * cs 202 section 003
 * program #: 1
 * file: Animal.cpp
 * PURPOSE: Represent an Animal to be raced. Contains a base class Animal
 *  which is not meant to be instantiated, and several derived classes
 *  which are. Animals are mainly passed the parameters of the race to which
 *  they belong as well as another animal against which they are competing
 * 	in order to compute their performance against one another.
 *  The containing Race object tracks the result of each comparison
 * 	amongst its competitors and determines the winner and runner up.
 */

#include"Animal.h"

/*					BASE CLASS - DO NOT INSTANTIATE					*/
Animal::Animal(void)
	: name("UNKNOWN"), breed("UNKNOWN"), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(false), prey(false), size_bracket(0)
{}

Animal::Animal(string new_name) //temp? for testing TODO
	: name(new_name), breed("UNKNOWN"), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(false), prey(false), size_bracket(0) {}

Animal::Animal(string new_name, string new_breed) //temp? for testing TODO
	: name(new_name), breed(new_breed), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(false), prey(false), size_bracket(0) {}

Animal::~Animal(void)
{
	//TODO when name is char*
}

bool Animal::operator==(const Animal& other)
{
	if (other.name == name)
		return true;
	else
		return false;
}

string Animal::get_name(void) const
{
	return name;
}

void Animal::set_name(string new_name)
{
	name = new_name;
}

string Animal::get_breed(void) const
{
	return breed;
}

int Animal::get_size_bracket(void)
{
	return size_bracket.size_int;
}

void Animal::display(void) //TODO
{
}

bool Animal::is(Animal& other)
{
	return this == &other;
}

float Animal::calculate_time(float dist) //Placeholder; to be derived by subclasses
{
	return 0.0;
}

ostream& operator<<(ostream& os, const Animal& oa)
{
	os << "Name: " << oa.get_name() << ", breed: " << oa.get_breed() << '\n';
	return os;
}

/*			DERIVED CLASSES - FOR USE IN STABLES, RACES				*/

//TODO
