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
void BinarySearchTree<T, K>::add(BinaryNode<T>* curSubTree, T entry) {
	if (m_root == nullptr) {
		m_root = new BinaryNode<T>(entry);
		nodeCount++;
	} else {
		addRec(m_root, entry);
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::addRec(BinaryNode<T>* curSubTree, T entry) {
	if (entry < curSubTree->getEntry()) {
		if (curSubTree->getLeft() == nullptr) {
			curSubTree->setLeft(entry);
			nodeCount++;
		} else {
			addRec(curSubTree->getLeft(), entry);
		}
	} else {
		if (curSubTree->getRight() == nullptr) {
			curSubTree->setRight(entry);
			nodeCount++;
		} else {
			addRec(curSubTree->getRight(), entry);
		}
	}
}

template <typename T, typename K>
bool BinarySearchTree<T, K>::search(K key) const {
	if(m_root != nullptr) {
    return(searchRec(key, m_root));
  } else {
    return false;
  }
}

template <typename T, typename K>
bool BinarySearchTree<T, K>::searchRec(K key, BinaryNode<T>* curSubTree) const {
	if (key == curSubTree->getEntry()) {
		cout << "Element " << curSubTree->getEntry() << " is found\n\n";
    return true;
	} else if (key < curSubTree->getEntry()) {
		if(curSubTree->getLeft() != nullptr) {
      return(searchRec(key,curSubTree->getLeft()));
    } else {
      return false;
    }
	} else {
		if(curSubTree->getRight() != nullptr) {
      return(searchRec(key,curSubTree->getRight()));
    } else {
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
void BinarySearchTree<T, K>::remove(K key) {
	if(search(key)) {
		if (key == m_root->getEntry()) {
			if (m_root->getLeft() == nullptr && m_root->getRight() == nullptr) // m_root has no children.
			{
				BinaryNode<T>* temp = m_root;
				m_root = nullptr;
				temp->~BinaryNode();
				nodeCount = 0;
			}
			else if (m_root->getLeft() != nullptr && m_root->getRight() == nullptr) // m_root has only left child.
			{
				BinaryNode<T>* temp = m_root;
				BinaryNode<T>* leftChild = m_root->getLeft();
	      m_root->inheritLeft(leftChild);
	      temp->~BinaryNode();
				nodeCount--;

				/*
				BinaryNode<T>* leftChild = curSubTree->getLeft();
				curSubTree->~BinaryNode();
				curSubTree = leftChild;
				nodeCount--;
				*/
			}
			else if (m_root->getLeft() == nullptr && m_root->getRight() != nullptr) // m_root has only right child.
			{
				BinaryNode<T>* temp = m_root;
				BinaryNode<T>* rightChild = m_root->getRight();
	      m_root->inheritRight(rightChild);
	      temp->~BinaryNode();
				nodeCount--;

				/*
				BinaryNode<T>* rightChild = curSubTree->getRight();
				curSubTree->~BinaryNode();
				curSubTree = rightChild;
				nodeCount--;
				*/
			}
			else // m_root has 2 children.
			{
				/*
				BinaryNode<T>* rightChild = m_root->getRight();
				minNode = minPriority(rightChild);
				minNodeParent = minPriorityParent(rightChild);
				BinaryNode<T>* minRightChild = minNode->getRight();

				minNodeParent->setLeft(minRightChild);
				delete minNode;
				m_root->setEntry(minNode->getEntry());
				nodeCount--;
				*/

				BinaryNode<T>* rightChild = m_root->getRight();
				BinaryNode<T>* minChild = minPriority(rightChild);
				int entry = minChild->getEntry();
				removeRec(m_root, entry);
				m_root->setEntry(entry);
			}
		} else {
			removeRec(m_root, key);
		}
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::removeRec(BinaryNode<T>* curSubTree, K key) {
	// removeRec should only be called if remove successfully finds a BinaryNode.
	if(key == curSubTree->getEntry()) {
		if(curSubTree->getLeft() == nullptr && curSubTree->getRight() == nullptr) // curSubTree has no children.
		{
			BinaryNode<T>* temp = curSubTree;
			curSubTree = nullptr;
			temp->~BinaryNode();
			nodeCount--;
		}
		else if(curSubTree->getLeft() != nullptr && curSubTree->getRight() == nullptr) // curSubTree has left child.
		{
			BinaryNode<T>* temp = m_root;
			BinaryNode<T>* leftChild = curSubTree->getLeft();
			curSubTree->inheritLeft(leftChild);
			temp->~BinaryNode();
			nodeCount--;

			/*
			BinaryNode<T>* leftChild = curSubTree->getLeft();
			curSubTree->~BinaryNode();
			curSubTree = leftChild;
			nodeCount--;
			*/
		}
		else if(curSubTree->getLeft() == nullptr && curSubTree->getRight() != nullptr) // curSubTree has right child.
		{
			BinaryNode<T>* temp = curSubTree;
			BinaryNode<T>* rightChild = curSubTree->getRight();
			curSubTree->inheritRight(rightChild);
			temp->~BinaryNode();
			nodeCount--;

			/*
			BinaryNode<T>* rightChild = curSubTree->getRight();
			curSubTree->~BinaryNode();
			curSubTree = rightChild;
			nodeCount--;
			*/
		}
		else  // curSubTree has 2 children.
		{
			BinaryNode<T>* rightChild = curSubTree->getRight();
			BinaryNode<T>* minChild = minPriority(rightChild);
			int entry = minChild->getEntry();
			removeRec(m_root, entry);
			curSubTree->setEntry(entry);
			/*
			BinaryNode<T>* rightMinChild = minChild->getRight();
			minChild->setEntry(rightMinChild->getEntry());
			rightMinChild->~BinaryNode();
			nodeCount--;
			*/
		}
	} else if(key < curSubTree->getEntry() && curSubTree->getLeft() != nullptr) {
    removeRec(curSubTree->getLeft(), key);
  } else if(key > curSubTree->getEntry() && curSubTree->getRight() != nullptr) {
    removeRec(curSubTree->getRight(), key);
  }
}

template<typename T, typename K>
BinaryNode<T>* BinarySearchTree<T, K>::minPriority(BinaryNode<T>* curSubTree) {
	if(curSubTree->getLeft() == nullptr) {
		return curSubTree;
	} else {
		return minPriority(curSubTree->getLeft());
	}
}

template<typename T, typename K>
BinaryNode<T>* BinarySearchTree<T, K>::minPriorityParent(BinaryNode<T>* curSubTree) {
	if(curSubTree->getLeft() == nullptr) {
		return curSubTree;
	} else if(curSubTree->getLeft() == minNode) {
		return curSubTree;
	} else {
		return minPriorityParent(curSubTree->getLeft());
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
	if (curSubTree->getEntry() != m_root->getEntry())
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
void BinarySearchTree<T, K>::preOrder(BinaryNode<T>* curSubTree) {
	cout << curSubTree->getEntry() << " ";

	if (curSubTree->getLeft() != nullptr) {
		preOrder(curSubTree->getLeft());
	}

	if (curSubTree->getRight() != nullptr) {
		preOrder(curSubTree->getRight());
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::inOrder(BinaryNode<T>* curSubTree) {
	if (curSubTree->getLeft() != nullptr) {
		inOrder(curSubTree->getLeft());
	}

	cout << curSubTree->getEntry() << " ";

	if (curSubTree->getRight() != nullptr) {
		inOrder(curSubTree->getRight());
	}
}

template <typename T, typename K>
void BinarySearchTree<T, K>::postOrder(BinaryNode<T>* curSubTree) {
	if (curSubTree->getLeft() != nullptr) {
		postOrder(curSubTree->getLeft());
	}

	if (curSubTree->getRight() != nullptr) {
		postOrder(curSubTree->getRight());
	}

	cout << curSubTree->getEntry() << " ";
}

/*
template <typename T, typename K>
void BinarySearchTree<T, K>::levelOrder() {
	orderList.clear();
	if (!isEmpty()) {
		for (int i = 1; i <= nodeCount; i++) {
			orderList.getEntry(i)->setTitle(myTree.getEntry(i)->getTitle());
			orderList.getEntry(i)->setRating(myTree.getEntry(i)->getRating());
		}
	} else {
		throw(std::runtime_error("ERROR: Tree is empty.\n"));
	}
}
*/

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

template <typename T, typename K>
bool BinarySearchTree<T, K>::isEmpty() const {
	if (m_root == nullptr)
		return true;
	else
		return false;
}
