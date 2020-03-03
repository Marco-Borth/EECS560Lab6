/* -----------------------------------------------------------------------------
 *
 * File Name:  Pokedex.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  Pokedex Class will allow user to Add, Search, and Remove Pokemon until user quits program.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

#include "Pokedex.h"
#include "TestPokedex.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

Pokedex::Pokedex(string filename)
{
  file = filename;
}

Pokedex::~Pokedex()
{

}

void Pokedex::run()
{
  cout << "\nWelcome to your Pokedex!\n\n";

  ifstream inFile;

  //Open File.
  inFile.open(file);

  if (!inFile.is_open())
	{
		cout << "File name not valid!\n";
	}

  string name, alias;
  int number;
  Pokemon* whosThatPokemon = nullptr;

  do
  {
    inFile >> name >> number >> alias;
    if (inFile.eof())
    {
      break;
    }

    //cout << name << ", " << number << ", " << alias << "\n";
    Pokemon whosThatPokemon(name, number, alias);

    originalPlayerDex.add(originalPlayerDex.getRoot(), whosThatPokemon);
  } while (!inFile.eof());

  // Close File.
  inFile.close();

  /*
  cout << "\n\n";
  playerDex.inOrder(playerDex.getRoot());
  cout << "\n\n";
  */

  do
  {
    cout << "Make a selection:\n\n";
    cout << "S) Search\n";
    cout << "A) Add\n";
    cout << "C) Copy\n";
    cout << "R) Remove\n";
    cout << "P) Print\n";
    cout << "V) Save\n";
    cout << "T) Test\n";
    cout << "Q) Quit\n";

    cout << "\nChoice: ";
    cin >> command;

    transform(command.begin(), command.end(), command.begin(), ::toupper);

    if (command == "S" || command == "SEARCH")
    {
      string pokemonName;

      cout << "Enter name: ";
      cin >> pokemonName;

      cout << "\n";
      if(PlayerDexCopy.getRoot() == nullptr)
      {
        originalPlayerDex.search(pokemonName);
      }
      else
      {
        PlayerDexCopy.search(pokemonName);
      }
    }
    else if (command == "A" || command == "ADD" )
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

        if (PlayerDexCopy.getRoot() == nullptr)
        {
          originalPlayerDex.add(originalPlayerDex.getRoot(), whosThatPokemon);
        }
        else
        {
          PlayerDexCopy.add(PlayerDexCopy.getRoot(), whosThatPokemon);
        }
      }
      catch (runtime_error)
      {
        cout << "\nPokemon already added to Pokedex.\n\n";
      }
    }
    else if (command == "C" || command == "COPY")
    {
      if(PlayerDexCopy.getRoot() == nullptr)
      {
        cout << "\nMaking Pokedex Copy.\n\n";
        PlayerDexCopy = originalPlayerDex;
      }
      else
      {
        cout << "\nPokedex Copy already exists.\n\n";
      }
    }
    else if (command == "R" || command == "REMOVE")
    {
      try
      {
        string pokemonName;

        cout << "Enter name: ";
        cin >> pokemonName;

        cout << "\n";
        originalPlayerDex.remove(pokemonName);

        /*
        if(PlayerDexCopy.getRoot() == nullptr)
        {
          cout << "\nNeed to make a copy of the Pokedex first.\n\n";
        }
        else
        {
          PlayerDexCopy.remove(pokemonName);
          cout << "\nPokemon successfully removed.\n\n";
        }
        */
      }
      catch (runtime_error)
      {
        cout << "\nNo Pokemon exists in this Pokedex.\n\n";
      }
    }
    else if (command == "P" || command == "PRINT")
    {
      cout << "\n\n";
      if(PlayerDexCopy.getRoot() == nullptr)
      {
        originalPlayerDex.inOrder(originalPlayerDex.getRoot());
        cout << "\n\n";
        //cout << originalPlayerDex.getOrderCount() << " out of " << originalPlayerDex.getNumberCount() << "\n\n";
        originalPlayerDex.resetOrderCount();
      }
      else
      {
        PlayerDexCopy.inOrder(PlayerDexCopy.getRoot());
        cout << "\n\n";
        //cout << PlayerDexCopy.getOrderCount() << " out of " << PlayerDexCopy.getNumberCount() << "\n\n";
        PlayerDexCopy.resetOrderCount();
      }
    }
    else if (command == "V" || command == "SAVE")
    {
      string filename, version, order;

      cout << "Enter file name: ";
      cin >> filename;

      cout << "Would you like to save the original Pokedex or the Pokedex copy?\n\n";
      cout << "O) Original Pokedex\n";
      cout << "C) Pokedex Copy\n";

      cout << "\nChoice: ";
      cin >> version;

      transform(version.begin(), version.end(), version.begin(), ::toupper);

      cout << "In what order would you like to save this Pokedex version?\n\n";
      cout << "PRE) Preorder\n";
      cout << "IN) Inorder\n";
      cout << "POST) Postorder\n";

      cout << "\nChoice: ";
      cin >> order;

      transform(order.begin(), order.end(), order.begin(), ::toupper);

      if (version == "O" || command == "ORIGINAL")
      {
        originalPlayerDex.saveToFile(filename, order);
        cout <<"\nFile saved.\n\n";
      }
      else if (version == "C" || command == "COPY")
      {
        if (PlayerDexCopy.getRoot() != nullptr)
        {
          PlayerDexCopy.saveToFile(filename, order);
          cout <<"\nFile saved.\n\n";
        }
        else
        {
          cout << "\nPokedex Copy not found.\n\n";
        }
      }
    }
    else if (command == "T" || command == "TEST")
    {
      TestPokedex test;
      string testSelection;

      cout << "What would you like to test?\n\n";
      cout << "A) Add\n";
      cout << "R) Remove\n";
      cout << "V) Save\n";

      cout << "\nChoice: ";
      cin >> testSelection;

      transform(testSelection.begin(), testSelection.end(), testSelection.begin(), ::toupper);

      if (testSelection == "A" || testSelection == "ADD" )
      {
        test.testAdds(originalPlayerDex);
      }
      else if (testSelection == "R" || testSelection == "REMOVE")
      {
        test.testRemoves(originalPlayerDex);
      }
      else if (testSelection == "V" || testSelection == "SAVE")
      {
        test.testWriteToFile(originalPlayerDex);
      }
      else
      {
        cout << "\nInvalid Test option.\n\n";
      }
    }
    else if (command == "Q" || command == "QUIT")
    {
      cout << "Exiting Program....\n";
    }
    else
    {
      cout << "Invalid Command.\n\n";
    }
  } while (command != "Q" && command != "QUIT");

  cout << "\nHave a nice day!...\n\n";

  if(PlayerDexCopy.getRoot() != nullptr)
  {
    PlayerDexCopy.~BinarySearchTree();
  }

  originalPlayerDex.~BinarySearchTree();
}
