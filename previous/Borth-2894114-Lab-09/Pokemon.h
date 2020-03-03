/* -----------------------------------------------------------------------------
 *
 * File Name:  Pokemon.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  Pokemon Class is defined.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>
using namespace std;

class Pokemon
{
private:
  string EnglishName, JapaneseName;
  int pokedexNumber;

public:

/**
* @return the JapaneseName of our Pokemon.
*/
  string Translation() const;

/**
* @return the EnglishName of our Pokemon.
*/
  string getName() const;

/**
* @return the pokedexNumber of our Pokemon.
*/
  int getNumber() const;

/**
* @param English and Japanese are valid strings, number is a valid int.
* @post construct Pokemon with EnglishName = English, pokedexNumber = number, and JapaneseName = Japanese.
*/
  Pokemon(string English, int number, string Japanese);

/**
* @post deletes Pokemon and its properties.
*/
  ~Pokemon();

/**
* @pre there are two Pokemon to compare
* @param other is a Pokemon on the right hand side of the comparrison.
* @post returns true if Pokemon.getName == other.getName, false otherwise.
*/
  bool operator==(const Pokemon& other);

/**
* @pre there are two Pokemon to compare
* @param other is a Pokemon on the right hand side of the comparrison.
* @post returns true if Pokemon.getName > other.getName, false otherwise.
*/
  bool operator>(const Pokemon& other);

/**
* @pre there are two Pokemon to compare
* @param other is a Pokemon on the right hand side of the comparrison.
* @post returns true if Pokemon.getName > other.getName, false otherwise.
*/
  bool operator<(const Pokemon& other);

/**
* @param key is a valid string.
* @post returns true if EnglishName == key, false otherwise.
*/
  bool operator==(const string& key);

/**
* @param key is a valid string.
* @post returns true if EnglishName > key, false otherwise.
*/
  bool operator>(const string& key);

/**
* @param key is a valid string.
* @post returns true if EnglishName < key, false otherwise.
*/
  bool operator<(const string& key);
};

#endif
