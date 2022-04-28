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

/*				CONSTRUCTORS, DESTRUCTORS, OPERATORS + helpers				*/
Stable::Stable(void)
	: num_breeds(0) {}

Stable::~Stable(void)
{
	if (num_breeds != 0)
		delete [] animals;
}

Stable::Stable(const Stable& other)
	: num_breeds(other.num_breeds)
{
	animals = new LLL<Animal>[num_breeds];
	copy_all_breeds(other.animals, num_breeds);
}
//!ASSUMES dest has at least as many elements as src!
void Stable::copy_all_breeds(LLL<Animal>* dest, size_t arr_len)
{
	if (!(arr_len <= 0)){
		auto target = (dest + arr_len-1);
		*target = *(animals + arr_len-1);
		copy_all_breeds(dest, arr_len - 1);
	}
	return;
}

/*					PUBLIC MEMBER FUNCTIONS + helpers						*/
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
		animals[0].push_back(new_animal);
		done = true;
	}
	else{
		if (check_for_dup_names(new_animal)){
			return false;
		}
		else{
			done = insert_to_existing_breed(new_animal, num_breeds);
		}
		if (!done){
			num_breeds++;
			LLL<Animal>* new_animals = new LLL<Animal>[num_breeds];
			copy_all_breeds(new_animals, num_breeds-1);
			delete [] animals;
			animals = new_animals;
			animals[num_breeds-1].push_back(new_animal);
			done = true;
		}
	}
	return done;
}
//returns whether insertion successful (whether matching breed found)
bool Stable::insert_to_existing_breed(Animal& new_animal, size_t arr_len)
{
	if (arr_len == 0)
		return false;
	else{
		if ((animals + arr_len - 1)->at(0).get_breed() == new_animal.get_breed()){
			(animals + arr_len - 1)->push_back(new_animal);
			return true;
		}
		else
			return insert_to_existing_breed(new_animal, arr_len - 1);
	}
}
//returns whether duplicate name detected
bool Stable::check_for_dup_names(Animal& new_animal, size_t index)
{
	if (index == num_breeds)
		return false;
	else{
		if ((animals + index)->lookup(new_animal))
			return true;
		else
			return check_for_dup_names(new_animal, index + 1);
	}
} 

int Stable::get_num_breeds(void)
{
	return num_breeds;
}

//Returns nullptr if either index is out of bounds
Animal* Stable::find_animal(int breed, int individual)
{
	if ((size_t)breed <= num_breeds and breed >0)
		return &(animals + breed - 1)->at(individual - 1);
	else
		return nullptr;
}

//Return nullptr if not found
Animal* Stable::find_animal(string find_name)
{
	return find_animal(find_name, animals, num_breeds);
}
Animal* Stable::find_animal(string find_name, LLL<Animal>* list, size_t arr_len)
{
	if (arr_len == 0)
		return nullptr;
	else if (Animal* found_animal =
		(list + arr_len - 1)->lookup(Animal(find_name)); found_animal){
		return found_animal;
	}
	else{
		return find_animal(find_name, list, arr_len - 1);
	}
}

bool Stable::remove_animal(string remove_name)
{
	bool done = false;
	if (num_breeds == 0){
	} // we will return false
	else{
		Animal* found_animal = find_animal(remove_name);
		if (found_animal){
			remove_animal(num_breeds, found_animal);
			done = true;
		}
	}
	return done;
}
//removes some animal; if result is empty LLL, removes that too
void Stable::remove_animal(size_t arr_len, Animal* to_rem)
{
	LLL<Animal>* this_ll = (animals + arr_len - 1);
	if (Animal* found_animal = this_ll->lookup(*to_rem); found_animal){
		this_ll->remove(*found_animal);
		if (this_ll->is_empty())
			remove_empty_elmt(arr_len);
	}
	else{
		remove_animal(arr_len - 1, to_rem);
	}
	return;
}
//removes the (empty) LLL at index_to_rem
void Stable::remove_empty_elmt(size_t index_to_rem)
{
	if (index_to_rem == num_breeds){
		num_breeds--;
	}
	else{
		auto target = (animals + index_to_rem - 1);
		*target = *(animals + index_to_rem);
		remove_empty_elmt(index_to_rem+1);
	}
	return;
}

bool Stable::remove_animal(int row, int col)
{
	bool done = false;
	if (num_breeds == 0){
	} // we will return false
	else{
		Animal* found_animal = find_animal(row, col);
		if (found_animal){
			remove_animal(num_breeds, found_animal);
			done = true;
		}
	}
	return done;
}

//allows user to select a breed by index
void Stable::display_breeds(bool indices)
{
	display_breeds(num_breeds, indices);
	return;
}
void Stable::display_breeds(size_t arr_len, bool indices)
{
	if (arr_len > 0){
		if (indices)
			cout << "Breed " << arr_len << ":\n";
		(*(animals + arr_len - 1)).display(indices);
		display_breeds(arr_len - 1, indices); //next breed
	}
	return;
}
