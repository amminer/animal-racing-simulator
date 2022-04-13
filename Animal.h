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

/* base class for derived animals, should not be instantiated */
class Animal
{
	private:
		struct size_brackets //put this in its own .h or .h/.cpp?
		{
			int size_int;
			size_brackets(void) : size_int(-1) {}

			size_brackets(int new_size)
			{
				set_size(new_size);
			}
			private:
			void set_size(int new_size)
			{
				/* don't want to do it this way unless I can report the
					traceback which I don't know how to do. TODO
				if (new_size < 0 or new_size > 9)
					throw overflow_error("Animal initialized with bad size value!\n");
				else
					size_int = new_size;
				*/
				if (new_size <= 0)
					size_int = 0;
				else if (new_size >= 9)
					size_int = 9;
				else
					size_int = new_size;
			}
		};
		char* name;						//set PER-INSTANCE of subclasses by user.
		const string breed;				//set by derived classes.
		const float min_speed;			//set by derived classes.
		const float max_speed;			//set by derived classes.
		const float speed;				//set PER-INSTANCE of subclasses based on min, max.
		const bool predator;			//set by derived classes.
		const bool prey;				//set by derived classes.
		//set by derived classes; int with min 0, max 9.
		const size_brackets size_bracket;

	public:
		Animal(void);
		Animal(string name);
		Animal(string name, string breed);
		Animal(string name, string breed, bool predator, bool prey, size_brackets size);
		virtual ~Animal(void);
		Animal(const Animal& src);
		const Animal& operator=(const Animal& rhs);
		friend ostream& operator<<(ostream& os, const Animal& oa);
		bool operator==(const Animal& other);

		string get_name(void) const;
		string get_breed(void) const; 
		void set_name(string new_name);
		void set_breed(string new_breed);
		void display(void);
		bool is(Animal& other);

		/*Animal::calculate_time(float dist)
		 * 		Calculates how long it would take for an Animal object to
		 * 	run a race of distance dist; behavior unimplemented in Animal superclass
		 *	and derived differently for each subclass.
		 *		Cannot make pure virtual - prevents use in linkedlist lookup
		 *	(have to search by instance) - seriously bothered by this. TODO
		 */
		virtual float calculate_time(int dist) {return 0.0;}
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
		//~Cat(void);
		float calculate_time(int dist); //TODO
	private:
		const float min_speed = 0.6;
		const float max_speed = 0.85;
		const float speed;
};
		
class Tortoise: public Animal
{
	public:
		Tortoise(string new_name);
		//~Tortoise(void);
		float calculate_time(int dist); //TODO
	private:
		const float min_speed = 0.1;
		const float max_speed = 0.5;
		const float speed;
};
		
class Hare: public Animal
{
	public:
		Hare(string new_name);
		//~Hare(void);
		float calculate_time(int dist); //TODO
	private:
		const float min_speed = 0.7;
		const float max_speed = 0.95;
		const float speed;
};
