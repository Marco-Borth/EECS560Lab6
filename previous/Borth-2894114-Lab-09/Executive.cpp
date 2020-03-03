/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  Executive Class creates and runs driver class: Pokedex.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

#include "Executive.h"
#include "Pokedex.h"
#include <string>
using namespace std;

Executive::Executive(string filename)
{
	file = filename;
}

void Executive::run()
{
	Pokedex pokedex(file);
	pokedex.run();
}
