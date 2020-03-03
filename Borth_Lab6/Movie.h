/* -----------------------------------------------------------------------------
*
* File Name:  Movie.h
* Author: Marco Borth
* Assignment:   EECS-560 Lab 4 – Implementation of Binary Tree
* Description:  Movie Class is defined.
* Date: 2/22/20
*
---------------------------------------------------------------------------- */

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <stdexcept>
using namespace std;

class Movie
{
private:
  string title;
  float rating;

public:
/*
* @pre none.
* @param alias must be a string value.
* @post title is set to alias.
*/
  void setTitle(string alias);

/*
* @pre none.
* @post return title.
*/
  string getTitle() const;

/*
* @pre none.
* @param stars must be a valid int value.
* @post rating is set to stars.
*/
  void setRating(float stars);

/*
* @pre none.
* @post return rating.
*/
  float getRating() const;

  Movie();

  ~Movie();

  Movie(const Movie &other);

  Movie(string alias, float stars);
};
#endif
