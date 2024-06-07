#pragma once
#include <iostream>
#include "clsDoubleLinkedList.h"

template <class T>

class clsMyQueue
{

protected:

	clsDoubleLinkedList<T> _list;

public:

	void push(T value)
	{
		_list.insertAtEnd(value);
	}

	void pop()
	{
		_list.deleteFirstNode();
	}


	void print(string newLine = "\n")
	{
		_list.printList(newLine);
	}


	int size()
	{
		return _list.size();
	}

	bool isEmpty()
	{
		return _list.isEmpty();
	}

	T front()
	{
		return _list.getItem(0);
	}

	T back()
	{
		return _list.getItem(size() - 1);
	}

	T getItem(T value)
	{
		return _list.getItem(value);
	}

	void reverse()
	{
		_list.reverse();
	}


	void updateItem(int index, T value)
	{
		_list.updateItem(index, value);
	}

	//This is has nothing to do with standard queue data structure
	void insertAfter(int index, T value)
	{
		_list.insertAfter(index, value);
	}

	//This is has nothing to do with standard queue data structur
	void insertAtFront(T value)
	{
		_list.insertAtBeginning(value);
	}

	//This is has nothing to do with standard queue data structure
	void insertAtBack(T value)
	{
		push(value);
	}

	void clear()
	{
		_list.clear();
	}
};

