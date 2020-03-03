/* -----------------------------------------------------------------------------
 *
 * File Name:  TestPokedex.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  TestPokedex Class will test Add, Remove, and Save methods.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

#include "Pokedex.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

TestPokedex::TestPokedex()
{

}

TestPokedex::~TestPokedex()
{

}

void TestPokedex::testAdds(BinarySearchTree<Pokemon, std::string>& bst)
{
  try
  {
    string pokemonName, pokemonTranslation;
    int pokedexEntry;

    cout << "Enter Name: ";
    cin >> pokemonName;

    cout << "Entry Pokedex Number: ";
    cin >> pokedexEntry;

    cout << "Enter Translation: ";
    cin >> pokemonTranslation;

    Pokemon whosThatPokemon(pokemonName, pokedexEntry, pokemonTranslation);

    bst.add(bst.getRoot(), whosThatPokemon);

    cout << "\n\n";
    bst.inOrder(bst.getRoot());
    cout << "\n\n";
  }
  catch (runtime_error)
  {
    cout << "\nPokemon already added to Pokedex.\n\n";
  }
}

void TestPokedex::testRemoves(BinarySearchTree<Pokemon, std::string>& bst)
{
  try
  {
    string pokemonName;

    cout << "Enter name: ";
    cin >> pokemonName;

    cout << "\n";
    bst.remove(pokemonName);
    cout << "\nPokemon successfully removed.\n\n";
  }
  catch (runtime_error)
  {
    cout << "\nNo Pokemon exists in this Pokedex.\n\n";
  }

  cout << "\n\n";
  bst.inOrder(bst.getRoot());
  cout << "\n\n";
}

void TestPokedex::testWriteToFile(BinarySearchTree<Pokemon, std::string>& bst)
{
  string filename;

  cout << "Enter file name: ";
  cin >> filename;

  string inorder = "INORDER";

  bst.saveToFile(filename, inorder);

  cout <<"\nFile saved.\n\n";
}
