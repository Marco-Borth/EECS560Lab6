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
  tagline = "\0";
  review = 0;
}

void Operator::printCommands() {
  cout << "Please choose one of the following commands:\n\n";
  cout << "1-  IsFull\n";
  cout << "2-  AddMovie\n";
  cout << "3-  RemoveMovie\n";
  cout << "4-  Leaf\n";
  cout << "5-  PrintLeaves\n";
  cout << "6-  PrintTreeHeight\n";
  cout << "7-  Preorder\n";
  cout << "8-  Postorder\n";
  cout << "9-  Inorder\n";
  cout << "10- Levelorder\n";
  cout << "11- Exit\n\n> ";
}

void Operator::parseTitle(string parse) {
  tagline = "\0";

  for (int i = 0; i < parse.length(); i++) {
    if (parse.at(i) < parse.length() - 1 && parse.at(i) == ',')
      tagline = tagline + parse.at(i);
    else {
      if (parse.at(i) == ',')
        tagline = tagline;
      else
        tagline = tagline + parse.at(i);
    }
  }
}

void Operator::run() {
  cout << "\nWelcome to the Interactive Hash Table Program!\n\n";
  ifstream inFile;

  //Open File.
  inFile.open(file);

  if (!inFile.is_open()) {
    cout << "File name not valid!\n\n";
  } else {
    int RatingInputFailures = 0;
    while (!inFile.eof()) {
      inFile >> tagline >> stars;

      if(inFile.fail()) {
        inFile.clear();
        inFile.ignore(numeric_limits<streamsize>::max(),'\n');
        RatingInputFailures++;
      } else {
        parseTitle(tagline);
        review = stof(stars);

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
          }
        }

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
        // 1. Is Empty - Complete!
        if (option == 1) {
          cout << "\nBinary Tree is: ";
          if(IMDB.isFull()) {
            cout << "Full!\n\n";
          } else {
            cout << "NOT Full!\n\n";
          }
        }
        // 2- AddMovie - Complete!
        else if (option == 2) {
          cout << "\nPreparing to Insert a New Movie...\n";

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
              parseTitle(tagline);

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

        }
        // 3- RemoveMovie - Complete!
        else if (option == 3) {
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

        }
        // 4- Leaf - Complete!
        else if (option == 4) {
          cout << "\nPlease enter the name of your movie which you want to test as a leaf node:\n> ";
          cin >> tagline;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\nPlease enter the name of your movie which you want to test as a leaf node:\n> ";
              cin >> tagline;

            } else {
              parseTitle(tagline);

              int index = 1;
              bool isFound = false;

              for (int i = 1; i <= IMDB.getLength(); i++) {
                if(IMDB.getEntry(i)->getTitle() == tagline) {
                  index = i;
                  isFound = true;
                }
              }

              if (isFound) {
                if(IMDB.isALeaf(index))
                  cout << "\n>Output:The record with movie title " << tagline << " is a leaf node.\n\n";
                else
                  cout << "\n>Output:The record with movie title " << tagline << " is NOT a leaf node.\n\n";
              } else
                cout << "\nERROR! Movie not found in Tree.\n\n";

              break;
            }
          }
        }
        // 5- PrintLeaves - Complete!
        else if (option == 5) {
          cout << "\nOutput:  The leaf nodes are: ";
          IMDB.printLeaves();
        }
        // 6- TreeHeight - Complete!
        else if (option == 6) {
          cout << "\nOutput: The height of the tree is " << IMDB.getHeight() << "\n\n";
        }
        // 7- Postorder - Complete!
        else if (option == 7) {
          if(IMDB.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting List of Movies in...\n\nPre-Order - ";
            IMDB.preOrder();
            IMDB.print();
          }
        }
        // 8- Postorder - Complete!
        else if (option == 8) {
          if(IMDB.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting List of Movies in...\n\nPost-Order - ";
            IMDB.postOrder();
            IMDB.print();
          }
        }
        // 9- Inorder - Complete!
        else if (option == 9) {
          if(IMDB.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting List of Movies in...\n\nIn-Order - ";
            IMDB.inOrder();
            IMDB.print();
          }
        }
        // 10- Levelorder - Complete!
        else if (option == 10) {
          if(IMDB.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting List of Movies in...\n\nLevel-Order - ";
            IMDB.levelOrder();
            IMDB.print();
          }
        }
        // 11- Exit - Complete!
        else if (option == 11) {
          cout << "\nClosing Program...\n";
        }
        // Otherwise - Complete!
        else {
          cout << "\nERROR! Invalid Option!\n\n";
        }

        break;
      }
    }
  } while(option != 11);

  do {
    try {
      if(!IMDB.isEmpty()) {
        IMDB.remove();

        IMDB.removeTemp();
      }
    } catch (runtime_error) {

    }
  } while(!IMDB.isEmpty());

  tagline = "\0";
  review = 0;

  cout << "\nBye Bye!\n";
  cout << "\nHave a nice day!...\n\n";
}
