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
	: name((char*)"UNKNOWN"), breed("UNKNOWN"), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(false), prey(false), size_bracket(0)
{}

Animal::Animal(string new_name) //temp? for testing TODO
	: breed("UNKNOWN"), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(false), prey(false), size_bracket(0)
{
	set_name(new_name);
}

Animal::Animal(string new_name, string new_breed) //temp? for testing TODO
	: breed(new_breed), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(false), prey(false), size_bracket(0)
{
	set_name(new_name);
}

Animal::~Animal(void)
{
	if (name)
		delete name;
}

bool Animal::operator==(const Animal& other)
{
	if (other.name == name)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const Animal& oa)
{
	os << "Name: " << oa.get_name() << ", breed: " << oa.get_breed() << '\n';
	return os;
}

string Animal::get_name(void) const
{
	
	return string(name);
}

void Animal::set_name(string new_name)
{
	if (name){
		delete name;
		name = new char[new_name.length() + 1];
	}
	strcpy(name, new_name.c_str());
}

string Animal::get_breed(void) const
{
	return breed;
}

void Animal::display(void) //necessary/useful?
{
	cout << *this;
}

bool Animal::is(Animal& other)
{
	return this == &other; //compares pointers
}

/*Animal::predates(Animal& other)
 * Makes use of animal::size_bracket::size_int, predator, and prey members
 */
bool Animal::predates(Animal& other)
{
	bool ret {false};
	//take into account size, prey, and predator status //TODO
	return ret;
}

/*			DERIVED CLASSES - FOR USE IN STABLES, RACES				*/
//TODO

float Cat::calculate_time(int dist) //TODO
{
	return 0.0;
}

float Tortoise::calculate_time(int dist) //TODO
{
	return 0.0;
}

float Hare::calculate_time(int dist) //TODO
{
	return 0.0;
}
