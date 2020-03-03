/* -----------------------------------------------------------------------------
 *
 * File Name:  TestPokedex.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  TestPokedex Class is defined.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

#ifndef TEST_POKEDEX_H
#define TEST_POKEDEX_H

#include "BinarySearchTree.h"
#include "Pokemon.h"
#include <string>
#include <stdexcept>
using namespace std;

class TestPokedex
{
public:
/*
* @pre Pokedex.cpp must construct TestPokedex object.
* @post TestPokedex object is constructed.
*/
  TestPokedex();

/*
* @post TestPokedex object is Deconstructed.
*/
  ~TestPokedex();

/*
* @param bst is a valid BinarySearchTree.
* @post tests the add method of BinarySearchTree.
*/
  void testAdds(BinarySearchTree<Pokemon, std::string>& bst);

/*
* @param bst is a valid BinarySearchTree.
* @post tests the remove method of BinarySearchTree.
*/
  void testRemoves(BinarySearchTree<Pokemon, std::string>& bst);

/*
* @param bst is a valid BinarySearchTree.
* @post tests the saveToFile method of BinarySearchTree, writes inOrder.
*/
  void testWriteToFile(BinarySearchTree<Pokemon, std::string>& bst);
};

#endif
