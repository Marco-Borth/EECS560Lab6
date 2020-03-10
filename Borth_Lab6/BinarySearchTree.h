/* -----------------------------------------------------------------------------
 *
 * File Name:  BinarySearchTree.h
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  BinarySearchTree Template Class is defined.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryNode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept> //For runtime_error
using namespace std;

template <typename T, typename K>
class BinarySearchTree
{
private:
  BinaryNode<T>* m_root;
  int nodeCount, orderCount;
  ofstream outFile;

/*
* @pre add calls addRec.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param entry is a valid T object.
* @post if entry < curSubTree->getEntry(), a BinaryNode is added to the left pointer of curSubTree if left == nullptr.
* @post else if entry > curSubTree->getEntry(), a BinaryNode is added to the right pointer of curSubTree if right == nullptr.
* @post if left or right != nullptr, the BinaryNode is to be then added to either curSubTree->getLeft or curSubTree-> getRight.
* @post no duplicates are to be allowed.
*/
  void addRec(BinaryNode<T>* curSubTree, T entry);

/*
* @pre search calls searchRec.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param key is a valid K object.
* @post searches for BinaryNode with entry == key, returns true if found and prints BinaryNode object, false otherwise.
*/
  bool searchRec(K key, BinaryNode<T>* curSubTree) const;

/*
* @pre remove calls removeRec.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param key is a valid K object.
* @param twoChildren is true if curSubTree has both leftChild and rightChild.
* @post removes a BinaryNode from BinarySearchTree and restructures BinarySearchTree Accordingly.
*/
  void removeRec(BinaryNode<T>* curSubTree, K key, bool twoChildren);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @post deletes every BinaryNode in BinarySearchTree in postOrder.
*/
  void postOrderDelete(BinaryNode<T>* curSubTree);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param entry is a valid T object.
* @post adds every BinaryNode in curSubTree in preOrder.
*/
  void preOrderAdd(BinaryNode<T>* curSubTree, T entry);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param entry is a valid T object.
* @post returns the Binary node to replace the one to be deleted as the inOrder successor.
*/
  BinaryNode<T>* inOrderSuccessor(BinaryNode<T>* curSubTree);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @post prints all BinaryNodes in the BinarySearchTree preOrder into file.
*/
  void preOrderWrite(BinaryNode<T>* curSubTree);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @post prints all BinaryNodes in the BinarySearchTree inOrder into file.
*/
  void inOrderWrite(BinaryNode<T>* curSubTree);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @post prints all BinaryNodes in the BinarySearchTree postOrder into file.
*/
  void postOrderWrite(BinaryNode<T>* curSubTree);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param ranOnce checks if rightMostSwapNode has been initally called.
* @post returns the BinaryNode to replace the one to be deleted as the rightMostNode to swap with.
*/
  BinaryNode<T>* rightMostSwapNode(BinaryNode<T>* curSubTree, bool ranOnce);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param ranOnce checks if rightMostSwapNode has been initally called.
* @post deletes the BinaryNode previously swapped with in rightMostSwapNode.
*/
  void deleteSwapNode(BinaryNode<T>* curSubTree, bool ranOnce);

/*
* @pre none.
* @param subTreeCopy is a valid BinaryNode<T> pointer.
* @post copies the BinaryNodes from subTreeCopy onto this BinarySearchTree.
*/
  BinaryNode<T>* recCopyHelper(const BinaryNode<T>* subTreeCopy);

public:
/*
* @pre Executive.cpp must construct driverClass object.
* @post BinarySearchTree object is constructed.
*/
  BinarySearchTree();

/*
* @pre a BinarySearchTree must be constructed.
* @param original is a valid BinarySearchTree.
* @post BinarySearchTree object copy is constructed.
*/
  BinarySearchTree(const BinarySearchTree<T, K>& original);

/*
* @pre none.
* @post ~BinarySearchTree clears all BinaryNodes and deletes m_root and nodeCount.
*/
  ~BinarySearchTree();

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param entry is a valid T object.
* @post adds a BinaryNode to m_root if m_root == nullptr, calls on addRec otherwise.
*/
  void add(BinaryNode<T>* curSubTree, T entry);

/*
* @pre none.
* @param curSubTree is a valid BinaryNode<T> pointer.
* @param key is a valid K object.
* @post searches for BinaryNode with entry == key, returns true if found and prints BinaryNode object, false otherwise.
* @post calls searchRec, search itself is only concerned with m_root.
*/
  bool search(K key) const;

/*
* @pre none.
* @post calls postOrderDelete.
*/
  void clear();

/*
* @pre none.
* @param key is a valid K object.
* @post calls search to confirm if a BinaryNode entry == key, removes that very BinaryNode if true.
* @post if BinaryNode is not the root node, calls removeRec.
*/
  void remove(K key);

/*
* @pre none.
* @post operator= inserts original nodes onto the LinkedList.
*/
  BinarySearchTree<T, K>& operator=(const BinarySearchTree<T, K>& original);

/*
* @pre none.
* @post prints all BinaryNodes in the BinarySearchTree inOrder.
*/
  void inOrder(BinaryNode<T>* curSubTree);

/*
* @param filename is the name of an output file.
* @param traversalOrder is either preOrder, inOrder or postOrder.
* @post writes BinarySearchTree Nodes into file based on traversalOrder order.
*/
  void saveToFile(string filename, string traversalOrder);

/*
* @pre none.
* @post returns m_root.
*/
  BinaryNode<T>* getRoot() const;

/*
* @post returns the count of BinaryNodes after ordered printing.
*/
  int getOrderCount();

/*
* @post sets orderCount = 0.
*/
  void resetOrderCount();

/*
* @post returns the number of BinaryNodes.
*/
  int getNumberCount() const;
};

#include "BinarySearchTree.cpp"

#endif
