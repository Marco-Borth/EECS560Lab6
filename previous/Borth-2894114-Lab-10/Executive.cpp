/* -----------------------------------------------------------------------------
*
* File Name:  Executive.cpp
* Author: Marco Borth
* Assignment:   EECS-268 Lab 10 Program
* Description:  Executive Class creates and runs driver class: Hospital.
* Date: 5/9/19
*
---------------------------------------------------------------------------- */

#include "Executive.h"
#include "Hospital.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Executive::Executive(string input)
{
	userInput = input;
}

void Executive::run()
{
	Hospital KUWatkins(userInput);
	KUWatkins.run();
}
