#pragma once
#include <iostream>
using namespace std;

template <class T>

class clsDoubleLinkedList
{

protected:

	int _size = 0;

public:

	class Node
	{
	public:

		T value;
		Node* next;
		Node* prev;
	};


	Node* head = NULL;

	void insertAtBeginning(T value)
	{

		Node* newNode = new Node();

		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL)
		{
			head->prev = newNode;
		}

		head = newNode;

		_size++;
	}


	void printList(string newLine = "\n")
	{
		Node* current = head;

		while (current != NULL)
		{
			cout << current->value << "  ";
			current = current->next;
		}

		cout << newLine;
	}


	Node* find(T value)
	{
		Node* current = head;

		while (current != NULL)
		{
			if (current->value == value)
				return current;

			current = current->next;
		}

		return NULL;
	}


	//Node* getNode(int index)
	//{
	//	Node* current = head;

	//	if (index > _size - 1 || index < 0)
	//		return NULL;

	//	int indexOf = 0;

	//	while (current != NULL)
	//	{
	//		if (indexOf == index)
	//			return current;

	//		current = current->next;

	//		indexOf++;
	//	}

	//	return NULL;
	//}


	Node* getNode(int index)
	{
		int counter = 0;

		if (index > _size - 1 || index < 0)
			return NULL;

		Node* current = head;

		while (current != NULL && (current->next != NULL))
		{
			if (counter == index)
				return current;

			current = current->next;

			counter++;
		}

		return current;
	}

	T getItem(int index)
	{
		/*	if (index > _size - 1 || index < 0)
				return -1;*/

		Node* node = getNode(index);

		return (node != NULL) ? node->value : NULL;
	}


	void updateItem(int index, T value)
	{
		Node* itemNode = getNode(index);

		if (itemNode == NULL)
			return;

		itemNode->value = value;
	}

	//bool updateItem(int index, T value)
	//{
	//	Node* itemNode = getNode(index);

	//	if (itemNode != NULL) 
	//	{
	//		itemNode->value = value;
	//		return true;
	//	}
	//	else 
	//	{
	//		return false;
	//	}
	//}

	//T getItem(int index)
	//{

	//	Node* itemNode = getNode(index);

	//	return (itemNode != NULL) ? itemNode->value : NULL;
	//  
	// if (itemNode == NULL)
	//		return NULL;
	// else 
	//		return itemNode->value;
	//}

	//T getItem(int index) 
	//{
	//	if (index > _size - 1 || index < 0)
	//		return -1;

	//	Node* current = head;

	//	int counter = 0;

	//	while (current != NULL && (current->next != NULL)) 
	//	{
	//		if (index == counter)
	//			return current->value;

	//		current = current->next;

	//		counter++;
	//	}
	//	
	//	return current->value;
	//}


	/*T getItemMoreOptimized(int index)
	{
		if (index > _size - 1 || index < 0)
			return -1;

		if (index == 0)
			return head->value;

		Node* current = head;



		if (index % 2 == 0)
		{
			current = current->next->next;

			for (int i = 2; i <= index; i += 2)
			{
				if (index == i)
					return current->value;

				current = current->next->next;
			}
		}

		else
		{
			current = current->next;

			for (int i = 1; i <= index; i += 2)
			{
				if (index == i)
					return current->value;

				current = current->next->next;
			}
		}
	}*/


	T getItemMoreOptimized(int index)
	{
		if (index > _size - 1 || index < 0)
			return -1;

		return getNodeMoreOptimized(index)->value;
	}


	Node* getNodeMoreOptimized(int index)
	{
		if (index > _size - 1 || index < 0)
			return NULL;

		if (index == 0)
			return head;

		Node* current = head;

		if (index % 2 == 0)
		{
			current = current->next->next;

			for (int i = 2; i <= index; i += 2)
			{
				if (i == index)
					return current;

				current = current->next->next;
			}
		}
		else
		{
			current = current->next;
			for (int i = 1; i <= index; i += 2)
			{
				if (i == index)
					return current;

				current = current->next->next;
			}
		}

		return NULL;
	}


	void insertAfter(Node* prev, T value)
	{
		if (prev == NULL || head == NULL)
			return;


		Node* newNode = new Node();

		newNode->value = value;
		newNode->next = prev->next;
		newNode->prev = prev;

		if (prev->next != NULL)
			prev->next->prev = newNode;

		prev->next = newNode;

		_size++;
	}


	void insertAfter(int index, T value)
	{
		Node* itemNode = getNode(index);

		insertAfter(itemNode, value);
	}

	//bool insertAfter(int index, T value)
	//{
	//	Node* itemNode = getNode(index);

	//	if (itemNode != NULL) 
	//	{
	//		insertAfter(itemNode, value);
	//		return true;
	//	}

	//	else
	//	{
	//		return false;
	//	}
	//}

	void insertAtEnd(T value)
	{
		Node* newNode = new Node();

		newNode->value = value;
		newNode->next = NULL;

		if (head == NULL)
		{
			newNode->prev = NULL;
			head = newNode;
		}


		else
		{
			Node* lastNode = head;

			while (lastNode->next != NULL)
			{
				lastNode = lastNode->next;
			}


			lastNode->next = newNode;

			newNode->prev = lastNode;

		}

		_size++;
	}


	void deleteNode(Node*& node)
	{
		//There's no need the condition of head == NULL cause if the node you got  via the parameter is NULL Then the list is empty
		if (node == NULL)
		{
			return;
		}


		if (node == head)
		{
			head = node->next;
		}

		if (node->next != NULL)
		{
			node->next->prev = node->prev;
		}

		if (node->prev != NULL)
		{
			node->prev->next = node->next;
		}

		delete node;

		_size--;
	}


	void deleteFirstNode()
	{
		if (head == NULL)
			return;

		Node* current = head;


		head = head->next;

		if (head != NULL)
			head->prev = NULL;

		delete current;

		_size--;
	}


	void deleteLastNode()
	{
		if (head == NULL)
			return;

		Node* lastNode = head;

		if (head->next == NULL)
		{
			delete head;
			head = NULL;

			//_size--;

			return;
		}

		while (lastNode->next->next != NULL)
		{
			lastNode = lastNode->next;
		}

		Node* temp = lastNode->next;

		lastNode->next = NULL;

		delete temp;

		_size--;
	}


	int size()
	{
		return _size;
	}


	//bool isEmpty()
	//{
	//	return (head == NULL);
	//}

	bool isEmpty()

	{
		//cout << _size << endl << endl;
		return ((_size == 0) ? true : false);
	}


	//void clear() 
	//{
	//	int size = _size;
	//	
	//	for (int i = 1; i <=   size; i++) 
	//	{
	//		deleteFirstNode();
	//	}
	//}

	void clear()
	{
		while (_size > 0)
		{
			deleteFirstNode();
		}
	}


	//void reverse() 
	//{
	//	Node* current = head;
	//	Node* temp = NULL;

	//	while (current != NULL) 
	//	{
	//		temp = current->prev;
	//		current->prev = current->next;
	//		current->next = temp;

	//		current = current->prev;
	//	}
	//	
	//	/*
	//	
	//		It will break out of the loop when the temp pointer stored the reference to the second node object 
	//	    So we need to assign the head pointer to the first node object which is the previous node object for the temp
	//	   	Temp(second node object) in our exmaple 50 the previous node to it point in the first node object which is 60
	//		So temp->prev->value = 60 and the next node to it is,
	//		temp->prev->next->value = 50 and the previous of it point to the NULL
	//		temp->prev->prev = NULL it will not appear as output so don't do this 
	//		temp->prev->prev->value   unless you want to get null pointer exception so be careful when you dealing with memory
	//		and pointers
	//		
	//	*/

	//	if (temp != NULL)
	//		head = temp->prev;
	//}


	void reverse()
	{
		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->prev;
		}

		/*

			It will break out of the loop when the temp pointer stored the reference to the second node object
			So we need to assign the head pointer to the first node object which is the previous node object for the temp
			Temp(second node object) in our exmaple 50 the previous node to it point in the first node object which is 60
			So temp->prev->value = 60 and the next node to it is,
			temp->prev->next->value = 50 and the previous of it point to the NULL
			temp->prev->prev = NULL it will not appear as output so don't do this
			temp->prev->prev->value   unless you want to get null pointer exception so be careful when you dealing with memory
			and pointers

		*/

		if (temp != nullptr)
			head = temp->prev;
	}



	//Good Example of Recursion.
	//But Don't Use It Unless You Want To Get Stack Overflow Exception.

	//Node* _Reverse(Node* head)
	//{
	//	if (head == NULL || head->next == NULL)
	//		return head;
	//	Node* NwHead = _Reverse(head->next);
	//	NwHead->prev = NULL;
	//	head->next->next = head;
	//	head->prev = head->next;
	//	head->next = NULL;
	//	return NwHead;
	//}

	//void reverse()
	//{
	//	head = _Reverse(head);
	//}
};