/* -----------------------------------------------------------------------------
 *
 * File Name:  Operator.cpp
 * Author: Marco Borth
 * Assignment:   EECS-560 Lab 4 – Implementation of Binary Tree
 * Description:  Operator Class will either run the Interactive program for a Hash Table (Closed Hashing)
 * Date: 2/22/20
 *
 ---------------------------------------------------------------------------- */

#include "Operator.h"
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

Operator::Operator(string filename){
  file = filename;
}

void Operator::printCommands() {
  cout << "Please choose one of the following commands:\n\n";
  cout << "1. AddItem\n";
  cout << "2. DeleteItem\n";
  cout << "3. InorderSuccessor\n";
  cout << "4. Levelorder\n";
  cout << "5. SpiralLevelOrder\n";
  cout << "6. LeftSideView\n";
  cout << "7. RightSideView\n";
  cout << "8. KthSmallestItem\n";
  cout << "9. Exit\n\n> ";
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Binary Search Tree Program!\n\n";
  ifstream inFile;

  //Open File.
  inFile.open(file);

  if (!inFile.is_open()) {
    cout << "File name not valid!\n\n";
  } else {
    int RatingInputFailures = 0;
    while (!inFile.eof()) {
      inFile >> input;

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        RatingInputFailures++;
      } else {
        /*
        if(!BST.isEmpty()) {

          IMDB.add(input);

          newMovie = new Movie(tagline, review);
          IMDB.addTemp(newMovie);

        } else {

          bool isUnique = true;

          for (int i = 1; i <= IMDB.getLength(); i++) {
            if(tagline == IMDB.getEntry(i)->getTitle())
              isUnique = false;
          }

          if(isUnique) {
            newMovie = new Movie(tagline, review);
            IMDB.add(newMovie);

            newMovie = new Movie(tagline, review);
            IMDB.addTemp(newMovie);
          }

        }
        */
      }
    }

    if(RatingInputFailures > 1)
      cout << "ERROR! Invalid Input for Movie Ratings Detected: " << RatingInputFailures << "\n";
  }

  // Close File.
  inFile.close();

  do {
    printCommands();
    cin >> option;

    while(1) {
      // Error Handling for an non-number entry.
      if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nERROR! Invalid Option!\n\n"; //if not an int, must try again.
        printCommands();
        cin >> option;
      }
      // Operation Number has been selected.
      else {
        // 1. AddItem - Complete!
        if (option == 1) {
          cout << "\nPreparing to Insert a New Movie...\n";
          /*
          cout << "\nPlease enter the movie title which you want to enter into the tree:\n> ";
          cin >> tagline;
          cout << "\nPlease enter the rating of your movie:\n> ";
          cin >> review;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nPlease enter the movie title which you want to enter into the tree:\n> ";
              cin >> tagline;
              cout << "\nPlease enter the rating of your movie:\n> ";
              cin >> stars;

            } else {
              bool isInserted = false;
              bool isUnique = true;

              try {
                if(!IMDB.isEmpty()) {
                  newMovie = new Movie(tagline, review);
                  IMDB.add(newMovie);

                  newMovie = new Movie(tagline, review);
                  IMDB.addTemp(newMovie);
                } else {
                  bool isUnique = true;

                  for (int i = 1; i <= IMDB.getLength(); i++) {
                    if(tagline == IMDB.getEntry(i)->getTitle())
                      isUnique = false;
                  }

                  if(isUnique) {
                    newMovie = new Movie(tagline, review);
                    IMDB.add(newMovie);

                    newMovie = new Movie(tagline, review);
                    IMDB.addTemp(newMovie);
                    isInserted = true;
                  } else
                    throw(std::runtime_error("ERROR: Movie Record is not unique.\n"));
                }
              } catch (runtime_error) {
                cout << "\n> Output: ERROR! cannot place record\n\n";
              }

              if (isInserted)
                cout << "\n> Output: Record has been added successfully\n\n";

              break;
            }
          }
          */
        }
        // 2. RemoveItem - Complete!
        else if (option == 2) {
          /*
          try {
            if(!IMDB.isEmpty()) {
              cout << "\nPreparing to Delete a New Movie...\n";

              tagline = IMDB.getEntry(IMDB.getLength())->getTitle();
              review = IMDB.getEntry(IMDB.getLength())->getRating();
              IMDB.remove();

              IMDB.removeTemp();
              cout << "Record successfully removed\n\n";
                cout << "The last movie with title " << tagline << " and rating " << review << " has been deleted.\n\n";

            } else
              cout << "\n> Output: ERROR! Tree is Empty.\n\n";
          } catch (runtime_error) {
            cout << "\n> Output: ERROR! Tree is Empty.\n\n";
          }
          */
        }
        // 3. InorderSuccessor - Complete!
        else if (option == 3) {
          /*
          if(IMDB.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting List of Movies in...\n\nIn-Order - ";
            IMDB.inOrder();
            IMDB.print();
          }
          */
        }
        // 4. Levelorder - Complete!
        else if (option == 4) {
          /*
          if(IMDB.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting List of Movies in...\n\nLevel-Order - ";
            IMDB.levelOrder();
            IMDB.print();
          }
          */
        }
        // 9. Exit - Complete!
        else if (option == 9) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 9);

  /*
  do {
    try {
      if(!IMDB.isEmpty()) {
        IMDB.remove();

        IMDB.removeTemp();
      }
    } catch (runtime_error) {

    }
  } while(!IMDB.isEmpty());
  */

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}
