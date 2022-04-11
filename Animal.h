/* Amelia Miner
 * 04/09/22
 * cs 202 section 003
 * program #: 1
 * file: Animal.h
 * PURPOSE: Represent an Animal to be raced. Contains a base class Animal
 *  which is not meant to be instantiated, and several derived classes
 *  which are. Animals are mainly passed the parameters of the race to which
 *  they belong as well as another animal against which they are competing
 * 	in order to compute their performance against one another.
 *  The containing Race object tracks the result of each comparison
 * 	amongst its competitors and determines the winner and runner up.
 * 						!!ATTENTION!!
 *	overloads Animal == Animal operator to compare names instead of literal
 *	object identity - to compare identity, use Animal::is(Animal&).
 */

#pragma once

#include<string>	//name 
#include<cstdlib>	//randomized stats
#include<iostream>	//display
using namespace std;

/* base class for derived animals, should not be instantiated */
class Animal
{
	public:
		Animal(void);
		Animal(string name);
		Animal(string name, string breed);
		~Animal(void);
		//TODO copy constructor, operator= when name is char*
		//Animal(const Animal& src) = delete;
		//const Animal& operator=(const Animal& rhs) = delete;
		friend ostream& operator<<(ostream& os, const Animal& oa);
		bool operator==(const Animal& other);

		string get_name(void) const;
		string get_breed(void) const; 
		void set_name(string new_name);
		void set_breed(string new_breed);
		int get_size_bracket(void);
		void display(void);
		bool is(Animal& other);

		/*Animal::calculate_time(float dist)
		 * PURPOSE: Calculates how long it would take for an Animal object to
		 * 	run a race of distance dist; behavior unimplemented in Animal superclass
		 *	and derived differently for each subclass.
		 */
		float calculate_time(float dist);

	private:
		//TODO convert to char* name, priv funcs to convert from/to interface
		string name;					//set PER-INSTANCE of subclasses by user.
		const string breed;				//set by derived classes.
		const float min_speed;			//set by derived classes.
		const float max_speed;			//set by derived classes.
		const float speed;				//set PER-INSTANCE of subclasses based on min, max.
		const bool predator;			//set by derived classes.
		const bool prey;				//set by derived classes.
		struct size_brackets
		{
			int size_int;
			size_brackets()
			{
				size_int = -1; //debug, should never be used with this value
			}

			size_brackets(int new_size)
			{
				if (new_size <= 0)
					size_int = 0;
				else if (new_size >= 9)
					size_int = 9;
				else
					size_int = new_size;
			}
		};
		const size_brackets size_bracket; //set by derived classes; int with min 0, max 9.
};


/* derived Animals */
class Cat: public Animal
{
	public:
		Cat(string new_name);
		~Cat(void);
		float calculate_time(float dist);
};
		
class Tortoise: public Animal
{
	public:
		Tortoise(string new_name);
		~Tortoise(void);
		float calculate_time(float dist);
};
		
class Hare: public Animal
{
	public:
		Hare(string new_name);
		~Hare(void);
		float calculate_time(float dist);
};
