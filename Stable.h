/* Amelia Miner
 * 04/11/22
 * CS 202 section 003
 * PROGRAM #: 1
 * FILE: Stable.h
 * PURPOSE: Main purpose is to contain an array of linkedlists, which will
 *	store animals whose object lifetimes will be from when they are created
 *	until they are manually deleted by the user, removed during a race, or
 *	until the program quits and the Stable object is destroyed.
 *		Stable should check for name uniqueness to prevent user from adding
 *	duplicate names, which could cause obvious problems when the user looks
 *	up some animal by name later on.
 *		May also implement functionality between this class and Animal to breed new animals with
 *	stats based on their parents.
 */

#pragma once

#include "LLL.h"

/* class Stable
 * See header comment.
 * Only to be used in main driver code, instantiated once at startup
 *	and used for the lifetime of the program.
 */

class Stable{
	//TODO
    public:
        int foo_data; //stores data

        /* foos::bar(args)
         * PURPOSE: x (what it does - how goes in .cpp)
         * ARGS:    y
         * RETURN:  z
         */
        void bar();

    private:
        //stuff
};
