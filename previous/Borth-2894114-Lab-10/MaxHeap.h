/* -----------------------------------------------------------------------------
 *
 * File Name:  MaxHeap.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 10 Program
 * Description:  MaxHeap Template Class is defined.
 * Date: 5/9/19
 *
 ---------------------------------------------------------------------------- */

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept> //For runtime_error
using namespace std;

template <typename T>
class MaxHeap
{
private:
  T* m_arr;
  int m_size, m_heapSize;

/*
* @pre upHeap or add must call upHeap.
* @param index is a valid int between 0 and m_size.
* @post swaps m_arr[index] with its parent BinaryNode if m_arr[parent] < m_arr[index].
*/
  void upHeap(int index);

/*
* @pre downHeap or remove must call downHeap.
* @param index is a valid int between 0 and m_size.
* @post swaps m_arr[index] with the smallest of either leftChild or rightChild BinaryNode if m_arr[leftChild] < m_arr[index] or m_arr[rightChild] < m_arr[index].
*/
  void downHeap(int index);

/*
* @pre add must call downHeap.
* @post increments the size of m_arr by 1 and retains its elements.
*/
  void resize();

public:
/*
* @pre define T object.
* @post MaxHeap object is constructed.
*/
  MaxHeap();

/*
* @pre none.
* @post ~MaxHeap clears all BinaryNodes and deletes m_arr.
*/
  ~MaxHeap();

/*
* @pre none.
* @post isEmpty returns false if m_heapSize > 0, returns true otherwise.
*/
  bool isEmpty() const;

/*
* @pre none.
* @post getNumberOfNodes returns m_heapSize.
*/
  int getNumberOfNodes() const;

/*
* @pre none.
* @post getHeight returns the number of levels of MaxHeap.
*/
  int getHeight() const;

/*
* @pre none.
* @post peekTop returns m_arr[0].
*/
  T peekTop() const; //Can throw std::runtime_error

/*
* @pre none.
* @param data is a valid T object.
* @post adds a BinaryNode to m_arr and upHeaps the BinaryNode as necessary.
* @post resizes m_arr if necessary to add BinaryNode to m_arr.
*/
  void add(T data);

/*
* @pre none.
* @param key is a valid K object.
* @post calls search to confirm if a BinaryNode entry == key, removes that very BinaryNode if true.
* @post if BinaryNode is not the root node, calls removeRec.
*/
  void remove(); //Can throw std::runtime_error

/*
* @pre none.
* @post deletes all BinaryNodes within m_arr.
*/
  void clear();
};

#include "MaxHeap.cpp"

#endif
