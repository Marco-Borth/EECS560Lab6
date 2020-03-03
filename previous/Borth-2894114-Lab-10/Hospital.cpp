/* -----------------------------------------------------------------------------
*
* File Name:  Hospital.cpp
* Author: Marco Borth
* Assignment:   EECS-268 Lab 10 Program
* Description:  Hospital Class will ....
* Date: 5/9/19
*
---------------------------------------------------------------------------- */

#include "Hospital.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Hospital::Hospital(string file)
{
  filename = file;
}

void Hospital::run()
{
  cout << "Welcome to the Hospital Simulator Program.\n\n";
  Patient* patientX = nullptr;

  ifstream inFile;

  //Open File.
  inFile.open(filename);

  if (!inFile.is_open())
	{
		cout << "File name not valid!\n\n";
	}
  else if (inFile.is_open())
  {
    do
    {
      inFile >> command;
      if (inFile.eof())
      {
        break;
      }

      //cout << command << "\n\n";

      if (command == "ARRIVE")
      {
        string name, surname, sickness;
        int seniority, priority;

        inFile >> name >> surname >> seniority >> sickness >> priority;

        //cout << name << " " << surname << ", "<< seniority << ", " << sickness << ", " << priority << "\n\n";

        patientX = new Patient(name, surname, seniority, sickness, priority);

        docket.add(patientX);
      }
      else if (command == "NEXT")
      {
        try
        {
          patientX = docket.peekTop();
          cout << "Next patient:\n";
          cout << "\tName: " << patientX->getLastName() << ", " << patientX->getFirstName() << ".\n";
          cout << "\tAge: " << patientX->getAge() << "\n";
          cout << "\tSuffers from: " << patientX->getIllness() << "\n";
          cout << "\tIllness severity: " << patientX->getSeverity() << "\n\n";
        }
        catch (runtime_error)
        {
          cout << "There are no more patients listed.\n\n";
        }
      }
      else if (command == "TREAT")
      {
        try
        {
          docket.remove();
        }
        catch (runtime_error)
        {
          cout << "There are no more patients to treat.\n\n";
        }
      }
      else if (command == "COUNT")
      {
        if (docket.getNumberOfNodes() != 1)
        {
          cout << "There are " << docket.getNumberOfNodes() << " patients waiting.\n\n";
        }
        else
        {
          cout << "There is " << docket.getNumberOfNodes() << " patient waiting.\n\n";
        }
      }
    } while (!inFile.eof());
  }

  // Close File.
  inFile.close();

  cout << "Have a nice day!...\n\n";

  patientX = nullptr;
  delete patientX;

  docket.clear();

  //docket.~MaxHeap();
}
