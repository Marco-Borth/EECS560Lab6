/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  In this lab you will make a Pokemon translator that will
 allow users to look up a Pokemon by it's american name and retrieve its
 Japanese equivalent name. You read in the Pokemon's name and their corresponding
 Japanese translation from a file. Then, you will allow the user to query your
 Pokemon index or "Pokedex" in various ways.
 * Date: 5/3/19
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
