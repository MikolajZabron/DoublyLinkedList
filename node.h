#pragma once

/**
* @class DoublyLinkedList
* @brief A template class that implements a doubly linked list
*
* This class provides a doubly linked list data structure, which is a collection of nodes.
* Each node contains a value (template parameter T) and pointers to the previous and next nodes.
*/
template <typename T>
class DoublyLinkedList
{
	/**
	* @class Node
	* @brief A nested class that represents a node in the doubly linked list
	*/
	class Node
	{
	public:
		/**
		* @var data
		* @brief The value stored in the node
		*/
		T data;

		/**
		* @var next
		* @brief A pointer to the next node in the list
		*/
		Node* next;

		/**
		* @var previous
		* @brief A pointer to the previous node in the list
		*/
		Node* previous;
	};

	/**
	* @var head
	* @brief A pointer to the first node in the list
	*/
	Node* head;

	/**
	* @var tail
	* @brief A pointer to the last node in the list
	*/
	Node* tail;

public:
	/**
	* @brief Constructor that creates an empty doubly linked list
	*/
	DoublyLinkedList();

	/**
	* @brief Copy constructor
	* @param list The list to copy
	*/
	DoublyLinkedList(const DoublyLinkedList<T>& list);

	/**
	* @brief Move constructor
	* @param list The list to move
	*/
	DoublyLinkedList(DoublyLinkedList<T>&& list);

	/**
	* @brief Move assignment operator
	* @param list The list to move
	* @return A reference to the moved list
	*/
	DoublyLinkedList<T>& operator= (DoublyLinkedList<T>&& list);

	/**
	* @brief Copy assignment operator
	* @param list The list to copy
	* @return A reference to the copied list
	*/
	DoublyLinkedList<T>& operator= (const DoublyLinkedList<T>& list);

	/**
	* @brief Destructor that frees the memory used by the list
	*/
	~DoublyLinkedList();

	/**
	* @brief Sorts the elements in the list using the bubble sort algorithm
	*/
	void sort();

	/**
	* @brief Searching for a element in the list
	* @param data The data to search
	* @return A pointer to the node containing the data, or nullptr if not found
	*/
	Node* searchEle(T data);

	/**
	* @brief Deletes an element from the list
	* @param data The data to delete
	* @return true if the element was deleted, false if not found
	*/
	bool popEle(T data);

	/**
	* @brief Creates a new head for the list
	* @param input_data The data to insert at the front of the list
	*/
	void pushAtFront(T input_data);

	/**
	* @brief Creates a new tail for the list
	* @param input_data The data to insert at the back of the list
	*/
	void pushAtBack(T input_data);

	/**
	* @brief Prints the list from head to tail
	*/
	void printForward() const;

	/**
	* @brief Prints the list from tail to head
	*/
	void printBackward() const;

	/**
	* @brief Writes the list to a file
	* @param fileName The name of the file to write to
	*/
	void writeToFile(std::string fileName);

	/**
	* @brief Reads the list from a file
	* @param fileName The name of the file to read from
	*/
	void readFromFile(std::string fileName);

	/**
	* @brief Checks if the list is empty
	* @return true if the list is empty, false otherwise
	*/
	bool isEmpty() const;

	/**
	* @brief Clears the list
	*/
	void clear();
};