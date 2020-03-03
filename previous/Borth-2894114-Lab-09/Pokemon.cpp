/* -----------------------------------------------------------------------------
 *
 * File Name:  Pokemon.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  Pokemon Class will return the Pokemon characteristics.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon(string English, int number, string Japanese)
{
  EnglishName = English;
  JapaneseName = Japanese;
  pokedexNumber = number;
}

Pokemon::~Pokemon()
{
  /*
  int* index = &pokedexNumber;
  delete index;
  string* alias = &EnglishName;
  delete alias;
  alias = &JapaneseName;
  delete alias;
  */
}

string Pokemon::Translation() const
{
  return JapaneseName;
}

string Pokemon::getName() const
{
  return EnglishName;
}

int Pokemon::getNumber() const
{
  return pokedexNumber;
}

bool Pokemon::operator==(const Pokemon& other)
{
  return(EnglishName == other.getName());
}

bool Pokemon::operator>(const Pokemon& other)
{
  return(EnglishName > other.getName());
}

bool Pokemon::operator<(const Pokemon& other)
{
  return(EnglishName < other.getName());
}

bool Pokemon::operator==(const string& key)
{
  return(EnglishName == key);
}

bool Pokemon::operator>(const string& key)
{
  return(EnglishName > key);
}

bool Pokemon::operator<(const string& key)
{
  return(EnglishName < key);
}
