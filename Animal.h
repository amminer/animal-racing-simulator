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
#include<cstring>
#include<iostream>	//display
#include<stdexcept> //bounds check on size_bracket
using namespace std;

/*		used to constrain size property of base Animal class		*/
class size_brackets
{
	private:
		int size_int;
	public:
		size_brackets(void);
		size_brackets(int new_size);
		bool operator<(const size_brackets& rhs) const;
		bool operator>(const size_brackets& rhs) const;
		int restrict_size(int new_size);
};

/* base class for derived animals, should not be instantiated except as a search key*/
class Animal
{
	private:
		char* name;						//set PER-INSTANCE of subclasses by user.
		const string breed;				//set by derived classes.
		const bool predator;			//set by derived classes.
		const bool prey;				//set by derived classes.
		//set by derived classes; int with min 0, max 9, needed for predation
		const size_brackets size_bracket;

	protected:
		const float min_speed;			//set by derived classes.
		const float max_speed;			//set by derived classes.
		//set PER-INSTANCE of subclasses based on min, max.
		float speed;				    //units are seconds per meter

	public:
		Animal(void);
		Animal(string name);
		Animal(string name, string breed);
		Animal(string name, string breed, bool predator, bool prey, size_brackets size, float min_speed, float max_speed);
		virtual ~Animal(void); //virtual to suppress compiler warning
		Animal(const Animal& src);
		const Animal& operator=(const Animal& rhs);
		friend ostream& operator<<(ostream& os, const Animal& oa);
		bool operator==(const Animal& other) const;

		string get_name(void) const;
		string get_breed(void) const; 
		void set_name(string new_name);
		void display(void);
		bool is(Animal& other);

		/*Animal::calculate_time(float dist)
		 * 		Calculates how long it would take for an Animal object to
		 * 	run a race of distance dist; behavior unimplemented in Animal superclass
		 *	and derived differently for each subclass.
		 */
		float calculate_time(int dist);
		//virtual float calculate_dist(float time); //May want to allow for time-based races

		/*Animal::predates(Animal& other)
		 * Returns whether this animal can predate upon other;
		 * Makes use of animal::size_bracket::size_int, predator, and prey members
		 */
		bool predates(Animal& other);
};


/* derived Animals */
class Cat: public Animal
{
	public:
		Cat(string new_name);
};
		
class Tortoise: public Animal
{
	public:
		Tortoise(string new_name);
};
		
class Hare: public Animal
{
	public:
		Hare(string new_name);
};
