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

/*		BASE CLASS - ONLY INSTANTIATE AS RVALUE FOR LOOKUP		*/
Animal::Animal(void)
	: name(nullptr), breed("UNKNOWN"), predator(false), prey(false),
	  size_bracket(0), min_speed(0.0), max_speed(0.0), speed(0.0)
{}

Animal::Animal(string name)
	: name(nullptr), breed("UNKNOWN"), predator(false), prey(false),
	  size_bracket(0), min_speed(0.0), max_speed(0.0), speed(0.0)
{
	set_name(name);
}

Animal::Animal(string name, string breed, bool predator, bool prey, size_brackets size, float min_speed, float max_speed)
	: name(nullptr), breed(breed), predator(predator), prey(prey),
	  size_bracket(size), min_speed(min_speed), max_speed(max_speed)
{
	set_name(name);
}

Animal::~Animal(void)
{
	if (name)
		delete [] name;
}

Animal::Animal(const Animal& src)
	: name(nullptr), breed(src.breed), predator(src.predator), prey(src.prey),
	  size_bracket(src.size_bracket), min_speed(src.min_speed),
	  max_speed(src.max_speed), speed(src.speed)
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
	if (strcmp(other.name, name) == 0)
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
	Animal(new_name, (string)"cat", true, true, 4, 0.6f, 0.85f)
{
	//randomized speed
	srand(time(0));
	speed = (float)((rand() % ((int)(100.0f*max_speed) + 1
		    - (int)(100.0f*min_speed)) + (int)(100.0f*min_speed))/100.0f);
}

float Cat::calculate_time(int dist)
{
	return speed; //TODO
}

//Tortoise
Tortoise::Tortoise(string new_name) :
	Animal(new_name, (string)"tortoise", false, false, 4, 0.2f, 0.35f)
{
	//randomized speed
	srand(time(0));
	speed = (float)((rand() % ((int)(100.0f*max_speed) + 1
		    - (int)(100.0f*min_speed)) + (int)(100.0f*min_speed))/100.0f);
}

float Tortoise::calculate_time(int dist)
{
	return speed; //TODO
}

//Hare
Hare::Hare(string new_name) :
	Animal(new_name, (string)"hare", false, true, 2, 0.65f, 0.9f)
{
	//randomized speed
	srand(time(0));
	speed = (float)((rand() % ((int)(100.0f*max_speed) + 1
		    - (int)(100.0f*min_speed)) + (int)(100.0f*min_speed))/100.0f);
}

float Hare::calculate_time(int dist)
{
	return speed; //TODO
}
