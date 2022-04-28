#pragma once

#include<string>	//name interface, breed
#include<cstdlib>	//randomized stats
#include<cstring>	//name
#include<iostream>	//display

using namespace std;

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
 *		To implement a new animal breed, add a declaration including a
 *	constructor that takes a string name. In Animal::calculate_time,
 *	define a new branch in the control flow to determine how the new
 *	breed behaves based on the breed string assigned in the constructor.
 * 						!!ATTENTION!!
 *	overloads Animal == Animal operator to compare names instead of literal
 *	object identity - to compare identity, use Animal::is(Animal&).
 *	Consumer code will likely have to enforce unique names among collections.
 */

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
	private:						//ordered priv/prot/pub to avoid compiler complaint
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
		//main constructor, called by derived class constructors
		Animal(string name, string breed, bool predator, bool prey, size_brackets size, float min_speed, float max_speed);
		virtual ~Animal(void); //virtual to suppress compiler warning
		Animal(const Animal& src);
		const Animal& operator=(const Animal& rhs);
		friend ostream& operator<<(ostream& os, const Animal& oa);
		bool operator==(const Animal& other) const; //compares names, NOT breed or identity

		//returns name for flexible display
		string get_name(void) const;
		//returns breed for flexible display
		string get_breed(void) const; 
		//possible to rename animals, but keep in mind that code
		//which keeps collections of animals may have to enforce unique names.
		void set_name(string new_name);
		bool is(const Animal& other) const; //compares pointers/identity

		/*Animal::calculate_time(float dist)
		 * 		Calculates how long it would take for an Animal object to
		 * 	run a race of distance dist; behavior unimplemented for Animal superclass
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
