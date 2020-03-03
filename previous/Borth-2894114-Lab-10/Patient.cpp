/* -----------------------------------------------------------------------------
 *
 * File Name:  Patient.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 10 Program
 * Description:  Patient Class will return the Patient information.
 * Date: 5/9/19
 *
 ---------------------------------------------------------------------------- */

#include "Patient.h"

Patient::Patient(string first, string last, int years, string symptoms, int rating)
{
  firstName = first;
  lastName = last;
  age = years;
  illness = symptoms;
  severity = rating;
}

Patient::~Patient()
{

}

string Patient::getFirstName() const
{
  return firstName;
}

string Patient::getLastName() const
{
  return lastName;
}

int Patient::getAge() const
{
  return age;
}

string Patient::getIllness() const
{
  return illness;
}

int Patient::getSeverity() const
{
  return severity;
}
