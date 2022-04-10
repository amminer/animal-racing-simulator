/* Amelia Miner
 * 04/09/22
 * cs 202 section 003
 * program #: 1
 * file: LL.h
 * PURPOSE: linear doubly linked list class template
 * and node class template. Used as parent of CLL,
 * used as elements of stable array in main function.
 */

#pragma once

#include<string>	//name 
#include<cstdlib>	//randomized stats
using namespace std;

/* base class for derived animals, should not be instantiated */
class Animal
{
	public:
		Animal();
		Animal(string name);
		~Animal();
		string get_name();
		string get_breed(); 
		void set_name(string new_name);
		void set_breed(string new_breed);
		void display();
		bool is_faster_than(Animal& competitor, float dist);
	private:
		//TODO convert to char* name, priv funcs to convert from/to interface
		string name;
		string breed; //set by derived classes
		float calculate_time(float dist); //placeholder for use in is_faster_than
};

/* derived Animals */
class Cat: public Animal
{
	public:
		Cat();
		Cat(string new_name);
		~Cat();
	private:
		float calculate_time(float dist);
};
		
class Tortoise: public Animal
{
	public:
		Tortoise();
		Tortoise(string new_name);
		~Tortoise();
	private:
		float calculate_time(float dist);
};
		
class Hare: public Animal
{
	public:
		Hare();
		Hare(string new_name);
		~Hare();
	private:
		float calculate_time(float dist);
};
