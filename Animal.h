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
		~Animal(void);
		//TODO copy constructor, operator= when name is char*
		//Animal(const Animal& src) = delete;
		//const Animal& operator=(const Animal& rhs) = delete;
		//TODO operator<<
		friend ostream& operator<<(ostream& os, const Animal& oa);
		string get_name(void) const;
		string get_breed(void) const; 
		void set_name(string new_name);
		void set_breed(string new_breed);
		void display(void);
        /* Animal::is_faster_than(Animal& competitor, float dist)
         * PURPOSE:	returns whether this animal is faster than competitor
		 * 	based on how their is_faster_than functions compute their
		 * 	over distance dist; calculate_time derives behavior in subclasses.
         * ARGS:    competitor, the animal to check performance against.
         * RETURN:  bool whether this animal performed better than competitor
		 * 	over distance dist.
         */
		bool is_faster_than(Animal& competitor, float dist);

	private:
		//TODO convert to char* name, priv funcs to convert from/to interface
		string name;
		const string breed;				//set by derived classes
		float min_speed;				//set by derived classes
		float max_speed;				//set by derived classes
		//TODO unsure of whether agility worth including
		float min_agility;				//set by derived classes
		float max_agility;				//set by derived classes

		float calculate_time(float dist); //placeholder for use in is_faster_than
};

/* derived Animals */
class Cat: public Animal
{
	public:
		Cat(void);
		Cat(string new_name);
		~Cat(void);
	private:
		float calculate_time(float dist);
};
		
class Tortoise: public Animal
{
	public:
		Tortoise(void);
		Tortoise(string new_name);
		~Tortoise(void);
	private:
		float calculate_time(float dist);
};
		
class Hare: public Animal
{
	public:
		Hare(void);
		Hare(string new_name);
		~Hare(void);
	private:
		float calculate_time(float dist);
};
