/* -----------------------------------------------------------------------------
 *
 * File Name:  Pokedex.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  Pokedex Class is defined.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

#ifndef POKEDEX_H
#define POKEDEX_H

#include "BinarySearchTree.h"
#include "Pokemon.h"
#include "TestPokedex.h"
#include <string>
#include <stdexcept>
using namespace std;

class Pokedex
{
private:
  string file;
  string command;
  BinarySearchTree<Pokemon, string> originalPlayerDex;
  BinarySearchTree<Pokemon, string> PlayerDexCopy;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/*
* @pre Executive.cpp must construct Pokedex object.
* @post Pokedex object is constructed.
*/
  Pokedex(string filename);

/*
* @post Pokedex object is Deconstructed.
*/
  ~Pokedex();
};

#endif
