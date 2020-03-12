/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 6 – Implementation of Binary Search Trees
 * Description:  This lab will contain an implementation of an Binary Search Tree.
 * Date: 3/12/20
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
		Executive exec(argv[1]);
		exec.run();
	}

	return(0);
}
