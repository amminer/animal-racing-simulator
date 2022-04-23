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

/*		used to constrain size property of base Animal class		*/
size_brackets::size_brackets(void)
	: size_int(-1) {}

size_brackets::size_brackets(int new_size)
	: size_int(restrict_size(new_size)) {}

bool size_brackets::operator<(const size_brackets& rhs) const
{
	if (this->size_int < rhs.size_int)
		return true;
	else
		return false;
}

bool size_brackets::operator>(const size_brackets& rhs) const
{
	if (this->size_int > rhs.size_int)
		return true;
	else
		return false;
}

int size_brackets::restrict_size(int new_size)
{
	if (new_size < 0)
		return 0;
	else if (new_size > 9)
		return 9;
	else
		return new_size;
}

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

bool Animal::operator==(const Animal& other) const
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
	if (predator and other.prey and size_bracket > other.size_bracket)
		ret = true;
	return ret;
}

float Animal::calculate_time(int dist)
{
	float time_elapsed = (float) dist * (float) speed;
	if (breed == "cat"){
		//cats must rest every so often, randomly
		float seconds_per_rest = 80.0;
		int num_possible_rests = dist / 35;
		for (int i=num_possible_rests; i > 0; i--){
			if (rand() % 2) time_elapsed += seconds_per_rest; //50% chance of nap
		}
	}
	else if (breed == "hare"){
		//hares must rest every so often, regularly
		float seconds_per_rest = 25.0;
		int num_rests = dist / 20;
		time_elapsed += (float)(seconds_per_rest * (float) num_rests);
	}
	else if (breed == "tortoise"){
		//turtles do not rest
	}
	//cout << "time: " << time_elapsed << '\n';
	return time_elapsed;
}

/*			DERIVED CLASSES - FOR USE IN STABLES, RACES				*/
//Cat
Cat::Cat(string new_name) :
	Animal(new_name, (string)"cat", true, true, 4, 0.069f, 0.081f)
{
	//randomized speed
	speed = (float)((rand() % ((int)(100.0f*max_speed) + 1
		    - (int)(100.0f*min_speed)) + (int)(100.0f*min_speed))/100.0f);
}

//Tortoise
Tortoise::Tortoise(string new_name) :
	Animal(new_name, (string)"tortoise", false, false, 4, 1.5f, 2.0f)
{
	//randomized speed
	speed = (float)((rand() % ((int)(100.0f*max_speed) + 1
		    - (int)(100.0f*min_speed)) + (int)(100.0f*min_speed))/100.0f);
}

//Hare
Hare::Hare(string new_name) :
	Animal(new_name, (string)"hare", false, true, 2, 0.063f, 0.075f)
{
	//randomized speed
	speed = (float)((rand() % ((int)(100.0f*max_speed) + 1
		    - (int)(100.0f*min_speed)) + (int)(100.0f*min_speed))/100.0f);
}
