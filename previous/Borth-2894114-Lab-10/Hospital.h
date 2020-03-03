/* -----------------------------------------------------------------------------
*
* File Name:  Hospital.h
* Author: Marco Borth
* Assignment:   EECS-268 Lab 10 Program
* Description:  Hospital Class is defined.
* Date: 5/9/19
*
---------------------------------------------------------------------------- */

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "MaxHeap.h"
#include "Patient.h"
#include <string>
#include <stdexcept>
using namespace std;

class Hospital
{
private:
  string filename, command;
  MaxHeap<Patient*> docket;

public:
/**
* @pre none.
* @post stops running after code exits loop.
*/
	void run();

/*
* @pre Executive.cpp must construct Driver object.
* @param file is a valid string and an existing file.
* @post Hospital object is constructed.
*/
  Hospital(string file);
};
#endif
