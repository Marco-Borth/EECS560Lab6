/* -----------------------------------------------------------------------------
 *
 * File Name:  BinarySearchTree.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 9 Program
 * Description:  BinarySearchTree methods are defined.
 * Date: 5/3/19
 *
 ---------------------------------------------------------------------------- */

template <typename T, typename K>
BinarySearchTree<T, K>::BinarySearchTree()
{
	m_root = nullptr;
	nodeCount = 0;
	orderCount = 0;
}

template <typename T, typename K>
BinarySearchTree<T, K>::BinarySearchTree(const BinarySearchTree<T, K>& original)
{
	m_root = recCopyHelper(original.getRoot());
}

template <typename T, typename K>
BinarySearchTree<T, K>::~BinarySearchTree()
{
	clear();
	m_root = nullptr;
	//delete nodeCount;
}

template<typename T, typename K>
BinaryNode<T>* BinarySearchTree<T, K>::recCopyHelper(const BinaryNode<T>* subTreeCopy)
{
  if(subTreeCopy == nullptr)
  {
    return nullptr;
  }
  BinaryNode<T>* nodeCopy = new BinaryNode<T>(subTreeCopy->getEntry());
	nodeCopy->inheritLeft(recCopyHelper(subTreeCopy->getLeft()));
	nodeCopy->inheritRight(recCopyHelper(subTreeCopy->getRight()));
	return nodeCopy;
}

template <typename T, typename K>
BinarySearchTree<T, K>& BinarySearchTree<T, K>::operator=(const BinarySearchTree<T, K>& original)
{
	m_root = nullptr;
	nodeCount = 0;
  m_root = recCopyHelper(original.getRoot());
}

template <typename T, typename K>
void BinarySearchTree<T, K>::add(BinaryNode<T>* curSubTree, T entry)
{
	if (m_root == nullptr)
	{
		m_root = new BinaryNode<T>(entry);
		nodeCount++;
	}
	else
	{
		addRec(m_root, entry);
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::addRec(BinaryNode<T>* curSubTree, T entry)
{
	if(curSubTree->getRight() != nullptr)
  {
    if(entry == curSubTree->getRight()->getEntry())
    {
      throw(std::runtime_error("ERROR: Cannot add duplicate of an existing Pokemon.\n"));
    }
  }

  if(curSubTree->getLeft() != nullptr)
  {
    if(entry == curSubTree->getLeft()->getEntry())
    {
      throw(std::runtime_error("ERROR: Cannot add duplicate of an existing Pokemon.\n"));
    }
  }

	if (entry < curSubTree->getEntry())
	{
		if (curSubTree->getLeft() == nullptr)
		{
			curSubTree->setLeft(entry);
			nodeCount++;
		}
		else
		{
			addRec(curSubTree->getLeft(), entry);
		}
	}
	else if (entry > curSubTree->getEntry())
	{
		if (curSubTree->getRight() == nullptr)
		{
			curSubTree->setRight(entry);
			nodeCount++;
		}
		else
		{
			addRec(curSubTree->getRight(), entry);
		}
	}
}

template <typename T, typename K>
bool BinarySearchTree<T, K>::search(K key) const
{
	if(m_root != nullptr)
  {
    return(searchRec(key, m_root));
  }
  else
  {
    return false;
  }
}

template <typename T, typename K>
bool BinarySearchTree<T, K>::searchRec(K key, BinaryNode<T>* curSubTree) const
{
	if (key == curSubTree->getEntry().getName())
	{
		cout << key << ", " << curSubTree->getEntry().getNumber() << ", " << curSubTree->getEntry().Translation() << "\n\n";
    return true;
	}
	else if (key < curSubTree->getEntry().getName())
	{
		if(curSubTree->getLeft() != nullptr)
    {
			//cout << curSubTree->getEntry().getName() << ", " << curSubTree->getEntry().getNumber() << ", " << curSubTree->getEntry().Translation() << "\n\n";
      return(searchRec(key,curSubTree->getLeft()));
    }
    else
    {
      cout << "Pokemon not found.\n\n";
      return false;
    }
	}
	else if (key > curSubTree->getEntry().getName())
	{
		if(curSubTree->getRight() != nullptr)
    {
			//cout << curSubTree->getEntry().getName() << ", " << curSubTree->getEntry().getNumber() << ", " << curSubTree->getEntry().Translation() << "\n\n";
      return(searchRec(key,curSubTree->getRight()));
    }
    else
    {
      cout << "Pokemon not found.\n\n";
      return false;
    }
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::clear()
{
	postOrderDelete(m_root);
	//delete m_root;
	m_root = nullptr;
}

template <typename T, typename K>
void BinarySearchTree<T, K>::remove(K key)
{
	if(search(key))
	{
		if (key == m_root->getEntry().getName())
		{
			if (m_root->getLeft() == nullptr && m_root->getRight() == nullptr) // m_root has no children.
			{
				m_root->~BinaryNode();
				nodeCount = 0;
			}
			else if (m_root->getLeft() != nullptr && m_root->getRight() == nullptr) // m_root has only left child.
			{
				BinaryNode<T>* temp = m_root;
				BinaryNode<T>* leftChild = m_root->getLeft();
	      m_root->inheritLeft(leftChild);
	      temp->~BinaryNode();
				nodeCount--;
			}
			else if (m_root->getLeft() == nullptr && m_root->getRight() != nullptr) // m_root has only right child.
			{
				BinaryNode<T>* temp = m_root;
				BinaryNode<T>* rightChild = m_root->getRight();
	      m_root->inheritRight(rightChild);
	      temp->~BinaryNode();
				nodeCount--;
			}
			else // m_root has 2 children.
			{
				BinaryNode<T>* LeftChild = m_root->getLeft();
				BinaryNode<T>* temp = rightMostSwapNode(m_root,false);
				//BinaryNode<T>* temp = inOrderSuccessor(m_root);
        temp->setEntry(rightMostSwapNode(m_root,false)->getEntry());
				//temp->setEntry(inOrderSuccessor(m_root)->getEntry());
        m_root->setEntry(temp->getEntry());
				m_root->inheritLeft(LeftChild);
        deleteSwapNode(m_root,false);
				nodeCount--;
			}
		}
		else
		{
			removeRec(m_root, key, false);
		}
	}
}

template<typename T, typename K>
BinaryNode<T>* BinarySearchTree<T, K>::rightMostSwapNode(BinaryNode<T>* curSubTree, bool ranOnce)
{
  if(!ranOnce)
  {
    return(rightMostSwapNode(curSubTree->getLeft(),true));
  }
  else
  {
    if(curSubTree->getRight() != nullptr)
    {
      return(rightMostSwapNode(curSubTree->getRight(),true));
    }
    else
    {
      return curSubTree;
    }
  }
}

template<typename T, typename K>
void BinarySearchTree<T, K>::deleteSwapNode(BinaryNode<T>* curSubTree, bool ranOnce)
{
  if(!ranOnce)
  {
    deleteSwapNode(curSubTree->getLeft(),true);
  }
  else
  {
    if(curSubTree->getRight() != nullptr)
    {
      deleteSwapNode(curSubTree->getRight(),true);
    }
    else
    {
      if(curSubTree->getLeft() == nullptr)
      {
        curSubTree->~BinaryNode();
      }
      else
      {
				/*
				BinaryNode<T>* temp = subtree;
				BinaryNode<T>* leftChild = subtree->getLeft();
	      subtree->inheritLeft(leftChild);
	      temp->~BinaryNode();
				*/

				curSubTree->setEntry(curSubTree->getLeft()->getEntry());
        curSubTree->getLeft()->~BinaryNode();
      }
    }
  }
}

template <typename T, typename K>
void BinarySearchTree<T, K>::removeRec(BinaryNode<T>* curSubTree, K key, bool twoChildren)
{
	// removeRec should only be called if remove successfully finds a BinaryNode.
	if(twoChildren)
  {
		BinaryNode<T>* LeftChild = curSubTree->getLeft();
    BinaryNode<T>* temp = rightMostSwapNode(curSubTree, false);
		//BinaryNode<T>* temp = inOrderSuccessor(curSubTree);
    temp->setEntry(rightMostSwapNode(curSubTree, false)->getEntry());
		//temp->setEntry(inOrderSuccessor(curSubTree)->getEntry());
    curSubTree->setEntry(temp->getEntry());
		curSubTree->inheritLeft(LeftChild);
    deleteSwapNode(curSubTree, false);
		nodeCount--;
  }
	if(key < curSubTree->getEntry().getName())
  {
    if(curSubTree->getLeft() != nullptr)
    {
      if(key == curSubTree->getLeft()->getEntry().getName())
      {
        if(curSubTree->getLeft()->getLeft() == nullptr && curSubTree->getLeft()->getRight() == nullptr) // curSubTree->getRight() has no children.
        {
          curSubTree->getLeft()->~BinaryNode();
          curSubTree->inheritLeft(nullptr);
					nodeCount--;
        }
        else if(curSubTree->getLeft()->getLeft() != nullptr && curSubTree->getLeft()->getRight() == nullptr) // curSubTree->getRight() has left child.
        {
          BinaryNode<T>* temp = curSubTree->getLeft()->getLeft();
        	curSubTree->getLeft()->~BinaryNode();
          curSubTree->inheritLeft(temp);
					nodeCount--;
        }
        else if(curSubTree->getLeft()->getLeft() == nullptr && curSubTree->getLeft()->getRight() != nullptr) // curSubTree->getRight() has right child.
        {
          BinaryNode<T>* temp = curSubTree->getLeft()->getRight();
          curSubTree->getLeft()->~BinaryNode();
          curSubTree->inheritLeft(temp);
					nodeCount--;
        }
        else if(curSubTree->getLeft()->getLeft() != nullptr && curSubTree->getLeft()->getRight() != nullptr) // curSubTree->getRight() has 2 children.
        {
          removeRec(curSubTree->getLeft(), key, true);
        }
      }
      else
      {
        removeRec(curSubTree->getLeft(), key, false);
      }
    }
  }
  else
  {
    if(curSubTree->getRight() != nullptr)
    {
      if(key == curSubTree->getRight()->getEntry().getName())
      {
        if(curSubTree->getRight()->getRight() == nullptr && curSubTree->getRight()->getLeft() == nullptr) // curSubTree->getRight() has no children.
        {
          curSubTree->getRight()->~BinaryNode();
          curSubTree->inheritRight(nullptr);
					nodeCount--;
        }
        else if(curSubTree->getRight()->getRight() != nullptr && curSubTree->getRight()->getLeft() == nullptr) // curSubTree->getRight() has left child.
        {
          BinaryNode<T>* temp = curSubTree->getRight()->getRight();
          curSubTree->getRight()->~BinaryNode();
          curSubTree->inheritRight(temp);
					nodeCount--;
        }
        else if(curSubTree->getRight()->getRight() == nullptr && curSubTree->getRight()->getLeft() != nullptr) // curSubTree->getRight() has right child.
        {
          BinaryNode<T>* temp = curSubTree->getRight()->getLeft();
          curSubTree->getRight()->~BinaryNode();
          curSubTree->inheritRight(temp);
					nodeCount--;
        }
        else if(curSubTree->getRight()->getRight() != nullptr && curSubTree->getRight()->getLeft() != nullptr) // curSubTree->getRight() has 2 children.
        {
          removeRec(curSubTree->getRight(), key, true);
        }
      }
      else
      {
        removeRec(curSubTree->getRight(), key, false);
      }
    }
  }
}

template <typename T, typename K>
BinaryNode<T>* BinarySearchTree<T, K>::inOrderSuccessor(BinaryNode<T>* curSubTree)
{
	BinaryNode<T>* current = curSubTree;

  while (current->getLeft() != NULL)
	{
		current = current->getLeft();
	}

  return current;
}

template <typename T, typename K>
void BinarySearchTree<T, K>::inOrder(BinaryNode<T>* curSubTree)
{
	if (curSubTree->getLeft() != nullptr)
	{
		inOrder(curSubTree->getLeft());
	}
	cout << curSubTree->getEntry().getName() << ", " << curSubTree->getEntry().getNumber() << ", " << curSubTree->getEntry().Translation() << "\n";
	orderCount++;
	if (curSubTree->getRight() != nullptr)
	{
		inOrder(curSubTree->getRight());
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::postOrderDelete(BinaryNode<T>* curSubTree)
{
	if (curSubTree->getLeft() != nullptr)
	{
		postOrderDelete(curSubTree->getLeft());
	}
	if (curSubTree->getRight() != nullptr)
	{
		postOrderDelete(curSubTree->getRight());
	}
	if (curSubTree->getEntry().getName() != m_root->getEntry().getName())
	{
		curSubTree->~BinaryNode();
	}
	else
	{
		m_root->~BinaryNode();
		m_root = nullptr;
	}
	nodeCount--;
}

template <typename T, typename K>
void BinarySearchTree<T, K>::preOrderAdd(BinaryNode<T>* curSubTree, T entry)
{
	add(curSubTree, curSubTree->getEntry());
	if (curSubTree->getLeft() != nullptr)
	{
		preOrderAdd(curSubTree->getLeft(), curSubTree->getLeft()->getEntry());
	}
	if (curSubTree->getRight() != nullptr)
	{
		preOrderAdd(curSubTree->getRight(), curSubTree->getRight()->getEntry());
	}
}

template <typename T, typename K>
BinaryNode<T>* BinarySearchTree<T, K>::getRoot() const
{
	return m_root;
}

template <typename T, typename K>
void BinarySearchTree<T, K>::saveToFile(string filename, string traversalOrder)
{
	if (traversalOrder == "PRE" || traversalOrder == "PREORDER" || traversalOrder == "IN" || traversalOrder == "INORDER" || traversalOrder == "POST" || traversalOrder == "POSTORDER")
	{
		//Open File.
	  outFile.open(filename);

		if (traversalOrder == "PRE" || traversalOrder == "PREORDER")
		{
			preOrderWrite(m_root);
		}
		else if (traversalOrder == "IN" || traversalOrder == "INORDER")
		{
			inOrderWrite(m_root);
		}
		else if (traversalOrder == "POST" || traversalOrder == "POSTORDER")
		{
			postOrderWrite(m_root);
		}

	  // Close File.
	  outFile.close();
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::preOrderWrite(BinaryNode<T>* curSubTree)
{
	outFile << curSubTree->getEntry().getName() << " " << curSubTree->getEntry().getNumber() << " " << curSubTree->getEntry().Translation() << "\n";
	if (curSubTree->getLeft() != nullptr)
	{
		preOrderWrite(curSubTree->getLeft());
	}
	if (curSubTree->getRight() != nullptr)
	{
		preOrderWrite(curSubTree->getRight());
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::inOrderWrite(BinaryNode<T>* curSubTree)
{
	if (curSubTree->getLeft() != nullptr)
	{
		inOrderWrite(curSubTree->getLeft());
	}
	outFile << curSubTree->getEntry().getName() << " " << curSubTree->getEntry().getNumber() << " " << curSubTree->getEntry().Translation() << "\n";
	if (curSubTree->getRight() != nullptr)
	{
		inOrderWrite(curSubTree->getRight());
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::postOrderWrite(BinaryNode<T>* curSubTree)
{
	if (curSubTree->getLeft() != nullptr)
	{
		postOrderWrite(curSubTree->getLeft());
	}
	if (curSubTree->getRight() != nullptr)
	{
		postOrderWrite(curSubTree->getRight());
	}
	outFile << curSubTree->getEntry().getName() << " " << curSubTree->getEntry().getNumber() << " " << curSubTree->getEntry().Translation() << "\n";
}

template <typename T, typename K>
int BinarySearchTree<T, K>::getOrderCount()
{
	return orderCount;
}

template <typename T, typename K>
void BinarySearchTree<T, K>::resetOrderCount()
{
	orderCount = 0;
}

template <typename T, typename K>
int BinarySearchTree<T, K>::getNumberCount() const
{
	return nodeCount;
}
