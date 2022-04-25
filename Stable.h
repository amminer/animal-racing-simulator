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

#pragma once

#include "LinkedList.h"
#include "Animal.h"

/* class Stable
 * See header comment.
 * Only to be used in main driver code, instantiated once at startup
 *	and used for the lifetime of the program.
 */

class Stable{
    public:
		Stable(void);
		~Stable(void);
		//Stable(vector<Animal> new_animals); //so that program can init w/ file input

		bool is_empty(void);
		bool add_animal(Animal& new_animal); //returns whether success (no dup names)
		Animal* find_animal(string find_name);
		Animal* get_animal_at(int row, int col);
		bool remove_animal(string to_remove); //returns whether success
		int size(void);
		void display_breeds(void);	//allows user to select a breed by index
		void display_breed(void);	//allows user to select an animal by index
		int get_num_breeds(void);

    private:
		void copy_all_breeds(LLL<Animal>** src, LLL<Animal>** dest);
		int count_num_breeds(const LLL<Animal>* list) const;

		size_t num_breeds;
		LLL<Animal>* animals[]; //dynamic array of LLLs of Animals
};
