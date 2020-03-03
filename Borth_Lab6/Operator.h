/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.h
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 4 – Implementation of Binary Tree
 * Description:  Operator Class is defined.
 * Date: 2/22/20
 *
 ---------------------------------------------------------------------------- */

#ifndef OPERATOR_H
#define OPERATOR_H

#include "BinaryTree.h"
#include "LinkedList.h"
#include "Movie.h"
#include <string>
#include <stdexcept>
using namespace std;

class Operator
{
private:
  int option;

  string file;
  string stars;

  string tagline;
  float review;

  BinaryTree<Movie*> IMDB;

  Movie* newMovie;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/**
* @pre none.
* @post prints list of commands to display for the user.
*/
  void printCommands();

  void parseTitle(string parse);

/*
* @pre filename is a string.
* @post Operator object is constructed, file == filename.
*/
  Operator(string filename);
};
#endif
