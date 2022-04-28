#pragma once

#include "LinkedList.h" //stores animals in memory for stadium to refer or point to 
#include "Animal.h"		//stables hold animals
#include <iostream>		//display contents of stable

using namespace std;

/* Amelia Miner
 * 04/11/22
 * CS 202 section 003
 * PROGRAM #: 1
 * FILE: Stable.h
 * PURPOSE: Main purpose is to contain an array of linkedlists, which will
 *	store animals whose object lifetimes will be from when they are created
 *	until they are manually deleted by the user, removed during a race, or
 *	duplicate names, which could cause obvious problems when the user looks
 *	up some animal by name later on.
 *		May also implement functionality between this class and Animal to breed new animals with
 *	stats based on their parents.
 */

/* class Stable
 * See header comment.
 * Only to be used in main driver code, instantiated once at startup
 *	and used for the lifetime of the program.
 */

class Stable{
    public:
		Stable(void);
		~Stable(void);
		Stable(const Stable& other);
		const Stable& operator=(const Stable& rhs);
		//Stable(vector<Animal> new_animals); //so that program can init w/ file input

		bool is_empty(void) const; //returns whether stable has animals
		bool add_animal(const Animal& new_animal); //returns whether success (no dup names)
		Animal* find_animal(string find_name) const; //returns nullptr if not found
		Animal* find_animal(int breed, int individual) const; //returns nullptr if not found
		bool remove_animal(string remove_name); //returns whether success
		bool remove_animal(int row, int col); //returns whether success
		int get_num_breeds(void) const; //returns number of breeds for display, future condition checks
		void display_breeds(bool indices=false) const;	//allows user to select animals by index

    private:
		//recursive helper functions
		bool insert_to_existing_breed(const Animal& new_animal, size_t arr_len); //from add_animal()
		//returns whether duplicate name detected
		bool check_for_dup_names(const Animal& new_animal, size_t index=0) const; //from add_animal()
		void copy_all_breeds(LLL<Animal>* dest, size_t arr_len); //from copy constructor, dynamic array redim
		void remove_animal(size_t arr_len, Animal* to_rem); //recursive helper from remove_animal()
		void remove_empty_elmt(size_t index_to_rem); //recursive helper from remove_animal()
		//returns nullptr if not found
		Animal* find_animal(Animal& to_find, LLL<Animal>* list, size_t arr_len) const;
		void display_breeds(size_t arr_len, bool indices=false) const; //allows selection by index

		//data
		size_t num_breeds;
		LLL<Animal>* animals; //dynamic array of LLLs of Animals
};
