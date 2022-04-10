#include"Animal.h"

Animal::Animal()
	: name("UNKNOWN"), breed("UNKNOWN") 
{}

Animal::~Animal()
{
	//TODO when name is char*
}


Animal::Animal(string newName)
	: name(newName), breed("UNKNOWN") {}

string Animal::get_name()
{
	return name;
}

void Animal::set_name(string new_name)
{
	name = new_name;
}

string Animal::get_breed()
{
	return breed;
}

void Animal::set_breed(string new_breed)
{
	breed = new_breed;
}

//bool Animal::is_faster_than(Animal& competitor, float dist)
//defined in derived classes

//float Animal::calculate_time(float dist)
//defined in derived classes
