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
	: name(nullptr), breed("UNKNOWN"), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(false), prey(false), size_bracket(0)
{}

Animal::Animal(string name)
	: name(nullptr), breed("UNKNOWN"), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(false), prey(false), size_bracket(0)
{
	set_name(name);
}

Animal::Animal(string name, string breed, bool predator, bool prey, size_brackets size)
	: name(nullptr), breed(breed), min_speed(0.0), max_speed(0.0), speed(0.0),
	  predator(predator), prey(prey), size_bracket(size)
{
	set_name(name);
}

Animal::~Animal(void)
{
	if (name)
		delete [] name;
}

Animal::Animal(const Animal& src)
	: name(nullptr), breed(src.breed), min_speed(src.min_speed), max_speed(src.max_speed), speed(src.speed),
	  predator(src.predator), prey(src.prey), size_bracket(src.size_bracket)
{
	if (this != &src) //self assignment check
		*this = src;
}

const Animal& Animal::operator=(const Animal& rhs)
{
	set_name(rhs.get_name());
	return *this;
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
		delete [] name;
	}
	name = new char[new_name.length() + 1];
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
//Cat
Cat::Cat(string new_name) :
	Animal(new_name, "cat", true, true, 4), 
	speed((float)(rand() % ((int)(100*max_speed) + 1 - (int)(100*min_speed))
	  + (int)(100*min_speed))/100) {}

float Cat::calculate_time(int dist)
{
	return speed; //TODO
}

//Tortoise
Tortoise::Tortoise(string new_name) :
	Animal(new_name, "tortoise", true, true, 4),
	speed((float)(rand() % ((int)(100*max_speed) + 1 - (int)(100*min_speed))
	  + (int)(100*min_speed))/100) {}

float Tortoise::calculate_time(int dist)
{
	return speed; //TODO
}

//Hare
Hare::Hare(string new_name) :
	Animal(new_name, "hare", true, true, 2),
	speed((float)(rand() % ((int)(100*max_speed) + 1 - (int)(100*min_speed))
	  + (int)(100*min_speed))/100) {}

float Hare::calculate_time(int dist)
{
	return speed; //TODO
}
