#include "Stable.h"

/* Amelia Miner
 * 04/11/22
 * CS 202 section 003
 * PROGRAM #: 1
 * FILE: Stable.cpp
 * PURPOSE: Main purpose is to contain an array of linkedlists, which will
 *	store animals whose object lifetimes will be from when they are created
 *	until they are manually deleted by the user, removed during a race, or
 *	duplicate names, which could cause obvious problems when the user looks
 *	up some animal by name later on.
 *		the array is nullptr-terminated.
 *		May also implement functionality between this class and Animal to breed new animals with
 *	stats based on their parents.
 */

Stable::Stable(void)
	: num_breeds(0) {}

Stable::~Stable(void)
{
	if (num_breeds != 0)
		delete [] animals;
}

bool Stable::is_empty(void)
{
	return (bool) (num_breeds == 0);
}

bool Stable::add_animal(Animal& new_animal) //returns whether success (no dup names)
{
	bool done = false;
	if (num_breeds == 0){
		num_breeds++;
		animals = new LLL<Animal>[num_breeds];
		//animals[0] = new LLL<Animal>;
		animals[0].push_back(new_animal);
		done = true;
	}
	else{ //TODO make recursive
		//done = insert_to_existing_breed(new_animal);
		for (size_t i=0; i<num_breeds; i++){
			for (size_t j=0; j<animals[i].length(); j++){
				if (animals[i].at(j).get_name() == new_animal.get_name())
					return false; //NO DUPS
			}
			//no empty LLLs allowed! TODO On delete_animal
			if (animals[i].at(0).get_breed() == new_animal.get_breed()){
				animals[i].push_back(new_animal);
				done = true;
			}
		}
		if (!done){
			num_breeds++;
			LLL<Animal> new_animals[num_breeds];
			copy_all_breeds(animals, new_animals); //TODO copy_all_breeds(src, dest)
			delete [] animals;
			animals = new_animals;
			animals[num_breeds-1].push_back(new_animal);
			done = true;
		}
	}
	return done;
}

int Stable::get_num_breeds(void)
{
	return num_breeds;
}
int Stable::count_num_breeds(const LLL<Animal>* list) const
{
	if (!list)
		return 0;
	else
		return 1 + count_num_breeds(&list[1]);
}

void Stable::copy_all_breeds(LLL<Animal>* src, LLL<Animal>* dest)
{
	if (! src){
		return;
	}
	else{
		dest = new LLL<Animal>(*src);
		copy_all_breeds(src+1, dest+1);
	}
}

Animal* Stable::find_animal(string find_name)
{
	
}


Animal* Stable::get_animal_at(int row, int col)
{
	
}


bool Stable::remove_animal(string to_remove) //returns whether success
{
	
}

void Stable::display_breeds(void) //allows user to select a breed by index
{
	
}


void display_breed(void) //allows user to select an animal by index
{
	
}
