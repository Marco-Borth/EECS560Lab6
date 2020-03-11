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
        BST.add(BST.getRoot(), input);
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
          cout << "\nPreparing to Insert a New Element...\n";

          cout << "\n> Enter the element to be added: ";
          cin >> input;

          while(1) {
            if(cin.fail()) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              cout << "\n\nERROR! Invalid entry!\n\n";
              cout << "\n> Enter the element to be added: ";
              cin >> input;

            } else {
              BST.add(BST.getRoot(), input);
              cout << "\n> Element " << input << " was successfully added.\n\n";

              break;
            }
          }

        }
        // 2. RemoveItem - Complete!
        else if (option == 2) {
          if(!BST.isEmpty()) {
            cout << "\nPreparing to Delete a New Element...\n";

            cout << "\n> Enter the element to be deleted: ";
            cin >> input;

            while(1) {
              if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "\n\nERROR! Invalid entry!\n\n";
                cout << "\n> Enter the element to be deleted: ";
                cin >> input;

              } else {
                try {
                  BST.remove(input);
                  cout << "\n> Element " << input << " was successfully deleted.\n\n";
                } catch (runtime_error) {
                  cout << "\n> Output: ERROR! input not found.\n\n";
                }

                break;
              }
            }
          } else {
            cout << "\n> Output: ERROR! Tree is Empty.\n\n";
          }

        }
        // 3. InorderSuccessor - Complete!
        else if (option == 3) {
          if(BST.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {

          }
        }
        // 4. Levelorder - Complete!
        else if (option == 4) {
          if(BST.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            /*
            cout << "\nPrinting Elements in...\n\nPre-Order - ";
            BST.preOrder(BST.getRoot());

            cout << "\nPrinting Elements in...\n\nIn-Order - ";
            BST.inOrder(BST.getRoot());

            cout << "\nPrinting Elements in...\n\nPost-Order - ";
            BST.postOrder(BST.getRoot());
            */

            cout << "\nPrinting Elements in...\n\nLevel-Order - ";
            BST.levelOrder();
            cout << "\n\n";
          }
        }
        // 5. SpiralLevelOrder - Complete!
        else if (option == 5) {
          if(BST.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting Elements in...\n\nSpiral-Level-Order - ";
            BST.spiralLevelOrder();
            cout << "\n\n";
          }
        }
        // 6. LeftSideView - Complete!
        else if (option == 6) {
          if(BST.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting Elements from the left side view: ";
            BST.leftSideView(BST.getRoot());
            cout << "\n\n";
          }
        }
        // 7. RightSideView - Complete!
        else if (option == 7) {
          if(BST.isEmpty()) {
            cout << "ERROR! Tree is Empty!\n\n";
          } else {
            cout << "\nPrinting Elements from the left side view: ";
            BST.rightSideView(BST.getRoot());
            cout << "\n\n";
          }
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
