/* -----------------------------------------------------------------------------
*
* File Name:  main.cpp
* Author: Marco Borth
* Assignment:   EECS-268 Lab 10 Program
* Description:  In this lab you will make a Hospital simulator.
* Patients are arriving at the Hospital with varying degrees of illness.
* You need to make sure the sickest patients are seen first.
* Date: 5/9/19
*
---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
#include"Executive.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Incorrect number of parameters!\n";
	}
	else
	{
		Executive exec(argv[1]); //sample creation of executive object
		exec.run(); //presumably handles the calling of all other member methods
	}

	return(0);
}
