#include <iostream>
#include <string>
#include "node.h"
#include <fstream>

//Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

//Copy Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& list)
{
	if (list.head == nullptr)
		head = nullptr;
	else
	{
		Node* node = list.head;
		head = tail = new Node();
		head->previous = nullptr;
		head->data = node->data;
		node = node->next;

		if (node == nullptr)
			head->next = nullptr;
		else
		{
			Node* node2 = head;

			while (node != nullptr) 
			{
				node2->next = new Node();
				node2->next->previous = node2;
				node2 = node2->next;
				node2->data = node->data;
				node = node->next;
			}

			node2->next = nullptr;
			tail = node2;
		}
	}
}

//Move constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& list)
{
	if (list.head == nullptr)
		head = nullptr;
	else 
	{
		Node* node = list.head;
		head = tail = new Node();
		head->previous = nullptr;
		head->data = node->data;
		node = node->next;

		if (node == nullptr)
			head->next = nullptr;
		else 
		{
			Node* node2 = head;

			while (node != nullptr) 
			{
				node2->next = new Node();
				node2->next->previous = node2;
				node2 = node2->next;
				node2->data = node->data;
				node = node->next;
			}

			node2->next = nullptr;
			tail = node2;
			list.clear();
		}
	}
}

//Assigned operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator= (const DoublyLinkedList<T>& list)
{
	if (&list != this)
	{
		clear();

		if (list.head == nullptr)
			head = nullptr;
		else
		{
			Node* node = list.head;
			head = tail = new Node();
			head->previous = nullptr;
			head->data = node->data;
			node = node->next;

			if (node == nullptr)
				head->next = nullptr;
			else
			{
				Node* node2 = head;

				while (node != nullptr)
				{
					node2->next = new Node();
					node2->next->previous = node2;
					node2 = node2->next;
					node2->data = node->data;
					node = node->next;
				}

				node2->next = nullptr;
				tail = node2;
			}
		}
	}
	else
	{
		return *this;
	}
}

//Move operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator= (DoublyLinkedList<T>&& list)
{
	if (&list != this)
	{
		clear();

		if (list.head == nullptr)
			head = nullptr;
		else
		{
			Node* node = list.head;
			head = tail = new Node();
			head->previous = nullptr;
			head->data = node->data;
			node = node->next;

			if (node == nullptr)
				head->next = nullptr;
			else
			{
				Node* node2 = head;

				while (node != nullptr)
				{
					node2->next = new Node();
					node2->next->previous = node2;
					node2 = node2->next;
					node2->data = node->data;
					node = node->next;
				}

				node2->next = nullptr;
				tail = node2;
			}
			list.clear();
		}
	}
	else
	{
		list.clear();
		return *this;
	}
}

//Deconstructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	while (isEmpty() != true)
	{
		Node* next = head;
		head = head->next;
		delete next;
	}
}

//Sorting function with bubble sort algorithm
template <typename T>
void DoublyLinkedList<T>::sort()
{
	int s_num;
	Node* node;
	Node* node1 = nullptr;

	do
	{
		s_num = 0;
		node = head;

		while (node->next != node1)
		{
			if (node->data > node->next->data)
			{
				T temp = node->data;
				node->data = node->next->data;
				node->next->data = temp;
				s_num = 1;
			}
			node = node->next;
		}
		node1 = node;
	} while (s_num);
}

//Searching for a element of a list
template <typename T>
DoublyLinkedList<T>::Node* DoublyLinkedList<T>::searchEle(T data)
{
	Node* node = head;

	while (node != nullptr) 
	{
		if (node->data == data) 
		{
			return node;
		}
		node = node->next;
	}

	return nullptr;
}

//Deleting element of a list
template <typename T>
bool DoublyLinkedList<T>::popEle(T data)
{
	Node* node = searchEle(data);

	if (node == nullptr)
		return false;

	if (node->previous != nullptr)
		node->previous->next = node->next;

	if (node->next != nullptr)
		node->next->previous = node->previous;

	if (node == head)
		head = node->next;

	if (node == tail)
		tail = node->previous;

	delete node;
	return true;
}

//Creates new head of a list
template <typename T>
void DoublyLinkedList<T>::pushAtFront(T input_data)
{
	Node* temp = new Node();
	temp->data = input_data;
	temp->next = head;
	temp->previous = nullptr;

	if (head != nullptr)
		temp->next->previous = temp;
	else
		tail = temp;

	head = temp;
}

//Creates new tail of a list
template <typename T>
void DoublyLinkedList<T>::pushAtBack(T input_data)
{
	Node* temp = new Node();
	temp->data = input_data;
	temp->next = nullptr;
	temp->previous = tail;

	if (tail != nullptr)
		temp->previous->next = temp;
	else
		head = temp;

	tail = temp;
}

//Printing list from head to tail
template<typename T>
void DoublyLinkedList<T>::printForward() const
{
	for (Node* node = head; node != nullptr; node = node->next)
		std::cout << node->data << " ";
	std::cout << std::endl;
}

//Printing list from tail to head
template <typename T>
void DoublyLinkedList<T>::printBackward() const
{
	for (Node* node = tail; node != nullptr; node = node->previous)
		std::cout << node->data << " ";
	std::cout << std::endl;
}

//Function that write List Into a File
template<typename T>
void DoublyLinkedList<T>::writeToFile(std::string fileName)
{
	std::ofstream outFile;
	outFile.open(fileName);
	Node* node = head;

	while (node != nullptr)
	{
		outFile << node->data << " ";
		node = node->next;
	}

	outFile.close();
}

//Function that read List from a File
template<typename T>
void DoublyLinkedList<T>::readFromFile(std::string fileName)
{
	std::ifstream inFile;
	inFile.open(fileName);
	T value;

	while (inFile >> value)
		pushAtBack(value);

	inFile.close();
}

//Checking if list is empty
template<typename T>
bool DoublyLinkedList<T>::isEmpty() const
{
	return head == nullptr;
}

//Clearing List
template<typename T>
void DoublyLinkedList<T>::clear()
{
	Node* temp = head;

	while (temp != nullptr)
	{
		Node* next = temp->next;
		delete temp;
		temp = next;
	}

	head = nullptr;
	tail = nullptr;
}