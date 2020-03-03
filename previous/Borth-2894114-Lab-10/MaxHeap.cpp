/* -----------------------------------------------------------------------------
 *
 * File Name:  MaxHeap.cpp
 * Author: Marco Borth
 * Assignment:   EECS-268 Lab 10 Program
 * Description:  MaxHeap methods are defined.
 * Date: 5/9/19
 *
 ---------------------------------------------------------------------------- */

template <typename T>
MaxHeap<T>::MaxHeap()
{
	m_size = 1;
	m_heapSize = 0;
	m_arr = new T [m_size];
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
	clear();
	delete[] m_arr;
}

template <typename T>
bool MaxHeap<T>::isEmpty() const
{
	if (m_heapSize > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <typename T>
int MaxHeap<T>::getNumberOfNodes() const
{
	return m_heapSize;
}

template <typename T>
int MaxHeap<T>::getHeight() const
{
	int height = 0;

	while (2 * height + 2 < m_heapSize)
	{
		height++;
	}

	return height;
}

template <typename T>
T MaxHeap<T>::peekTop() const
{
	if (!isEmpty())
	{
		return m_arr[0];
	}
	else
	{
		throw(std::runtime_error("ERROR: Heap is empty.\n"));
	}
}

template <typename T>
void MaxHeap<T>::resize()
{
	T* tempArr = new T [m_size + 1];

	for(int i = 0; i < m_size; i++)
	{
		tempArr[i] = m_arr[i];
	}

	T* swap = m_arr;
	m_arr = tempArr;
	tempArr = swap;

	delete[] tempArr;
	swap = nullptr;
	delete swap;
	m_size++;
}

template <typename T>
void MaxHeap<T>::add(T data)
{
	if (m_heapSize == m_size)
	{
		resize();
		add(data);
	}
	else
	{
		m_arr[m_heapSize] = data;
		upHeap(m_heapSize);
		m_heapSize++;
	}
}

template <typename T>
void MaxHeap<T>::upHeap(int index)
{
	int parent = (index - 1) / 2;

	if (index && m_arr[parent]->getSeverity() < m_arr[index]->getSeverity())
	{
		T temp = m_arr[index];
		m_arr[index] = m_arr[parent];
		m_arr[parent] = temp;

		upHeap(parent);
	}
	else if (index && m_arr[parent]->getSeverity() == m_arr[index]->getSeverity())
	{
		if (index && m_arr[parent]->getAge() < m_arr[index]->getAge())
		{
			T temp = m_arr[index];
			m_arr[index] = m_arr[parent];
			m_arr[parent] = temp;

			upHeap(parent);
		}
	}
}

template <typename T>
void MaxHeap<T>::clear()
{
	if (!isEmpty())
	{
		for(int i = 0; i < m_size; i++)
		{
			m_arr[i]->~Patient();
		}
	}

	m_heapSize = 0;
}

template <typename T>
void MaxHeap<T>::remove()
{
	if (!isEmpty())
	{
		m_arr[0]->~Patient();

		int heapBound = getNumberOfNodes() - 1;

		T temp = m_arr[heapBound];
		m_arr[heapBound] = m_arr[0];
		m_arr[0] = temp;

		m_heapSize--;
		downHeap(0);
	}
	else
	{
		throw(std::runtime_error("ERROR: Heap is empty.\n"));
	}
}

template <typename T>
void MaxHeap<T>::downHeap(int index)
{
	int leftChild = (2 * index) + 1;
  int rightChild = (2 * index) + 1;

	int largest = index;

	if (leftChild < getNumberOfNodes() && m_arr[leftChild]->getSeverity() > m_arr[index]->getSeverity())
	{
		largest = leftChild;
	}
	else if (leftChild < getNumberOfNodes() && m_arr[leftChild]->getSeverity() == m_arr[index]->getSeverity())
	{
		if (leftChild < getNumberOfNodes() && m_arr[leftChild]->getAge() > m_arr[index]->getAge())
		{
			largest = leftChild;
		}
	}

	if (rightChild < getNumberOfNodes() && m_arr[rightChild]->getSeverity() > m_arr[largest]->getSeverity())
	{
		largest = rightChild;
	}
	else if (rightChild < getNumberOfNodes() && m_arr[rightChild]->getSeverity() == m_arr[index]->getSeverity())
	{
		if (rightChild < getNumberOfNodes() && m_arr[rightChild]->getAge() > m_arr[index]->getAge())
		{
			largest = rightChild;
		}
	}

	if (largest != index)
	{
		T temp = m_arr[index];
  	m_arr[index] = m_arr[largest];
  	m_arr[largest] = temp;
		downHeap(largest);
	}
}
