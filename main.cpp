#include <iostream>
#include "node.h"
#include "node.cpp"

//Function used for testing doubly linked list
void musicPlayer()
{
	std::cout << "\n----------------------TEST 1----------------------\n";

	//Creating playlist named "polish80s" using deafault constructor
	DoublyLinkedList<std::string> polish80s;

	//Reading elements from file playList and copying them to a list "polish80s"
	polish80s.readFromFile("playList.txt");

	//Printing list from head to tail after reading it from file
	std::cout << "\n[17]Playlist polish80s printed from head to tail after reading it from file:\n";
	polish80s.printForward();

	//Creating and copying elements from polish80s to worldwide80s list
	DoublyLinkedList<std::string> worldwide80s(polish80s);

	//Printing list worldwide80s from head to tail after creating it and copying from polish80s
	std::cout << "\n[24]Playlist worldwide80s printed from head to tail after creating it and copying from polish80s:\n";
	worldwide80s.printForward();

	//Sorting list polish80s
	polish80s.sort();

	//Printing list from head to tail after sorting
	std::cout << "\n[31]Playlist polish80s printed from head to tail after sorting:\n";
	polish80s.printForward();

	//Adding a node at front to a worldwide80s list
	worldwide80s.pushAtFront("I_Wanna_Dance_with_Somebody");

	//Printing list worldwide80s from head to tail after adding a node at head
	std::cout << "\n[38]Playlist worldwide80s printed from head to tail after adding a node at head:\n";
	worldwide80s.printForward();

	//Creating using constructor list worldwide80s2
	DoublyLinkedList<std::string> worldwide80s2;

	//Using assign operator to copy content from list worldwide80s to previously created list worldwide80s2
	worldwide80s2 = worldwide80s;

	//Printing list worldwide80s from head to tail after assigning worldwide80s to it
	std::cout << "\n[48]Playlist worldwide80s2 printed from head to tail after assigning worldwide80s to it:\n";
	worldwide80s2.printForward();

	//Poping a node from a list worldwide80s2
	worldwide80s2.popEle("Chalupy_welcome_to");

	//Printing list worldwide80s from tail to head after popping a node at tail
	std::cout << "\n[55]Playlist worldwide80s2 printed from tail to head:\n";
	worldwide80s2.printBackward();

	//Using move constructor, creating another list and moving from existing list worldwide80s2 to a new list allout80s
	DoublyLinkedList<std::string> allout80s(std::move(worldwide80s2));

	//Checking if worldwide80s2 is empty
	std::cout << "\n[62]If list worldwide80s2 is empty it is going to print true: " << std::boolalpha << worldwide80s2.isEmpty() << std::endl;

	//Printing list allout80s from head to tail after using move constructor worldwide80s2
	std::cout << "\n[65]Playlist allout80s printed from head to tail after using move constructor worldwide80s2:\n";
	allout80s.printForward();

	//Adding element at the tail to list allout80s
	allout80s.pushAtBack("Take_on_Me");

	//Printing allout80s with added at the end element from tail to head
	std::cout << "\n[72]Playlist allout80s with added at the end element printed from tail to head:\n";
	allout80s.printBackward();

	//Using move operator moving nodes to a previously created list polish80s
	polish80s = std::move(allout80s);

	//Checking if allout80s is empty
	std::cout << "\n[79]If list allout80s is empty it is going to print true: " << std::boolalpha << allout80s.isEmpty() << std::endl;

	//Printing polish80s after moving nodes from allout80s
	std::cout << "\n[82]Playlist polish80s printed from head to tail after moving nodes from allout80s:\n";
	polish80s.printForward();

	//Writing list polish80s to a file playList2.txt
	polish80s.writeToFile("playList2.txt");

	//Clearing list after writing it to a file
	polish80s.clear();

	//Reading list polish80s from a file playList2.txt
	polish80s.readFromFile("playList2.txt");

	//Printing polish80s after reading from a file playList2.txt
	std::cout << "\n[95]Playlist polish80s printed from head to tail after reading from a file playList2.txt:\n";
	polish80s.printForward();
}

//2nd Function used for testing doubly linked list
void id()
{
	std::cout << "\n----------------------TEST 2----------------------\n";

	//Creating list named "idList" using deafault constructor
	DoublyLinkedList<int> idList;

	//Adding some nodes to the list
	idList.pushAtBack(67);
	idList.pushAtBack(44);
	idList.pushAtBack(75);
	idList.pushAtBack(61);
	idList.pushAtFront(98);

	//Printing list idList after adding few nodes
	std::cout << "\n[115]List idList printed from head to tail after adding few nodes:\n";
	idList.printForward();

	//Creating and copying elements from idList to idListover50
	DoublyLinkedList<int> idListover50(idList);

	//Deleting node with 44 value so that all id's are over 50
	idListover50.popEle(44);

	//Printing list idListover50 after copying it and poping one element
	std::cout << "\n[125]List idListover50 printed from head to tail after poping one element:\n";
	idListover50.printForward();

	//Sorting list idListover50
	idListover50.sort();

	//Printing list from head to tail after sorting
	std::cout << "\n[132]List idListover50 printed from head to tail after sorting:\n";
	idListover50.printForward();

	//Creating using move constructor list idListless100
	DoublyLinkedList<int> idListless100(std::move(idListover50));

	//Checking if idListover50 is empty
	std::cout << "\n[139]If idListover50 is empty it is going to print true: " << std::boolalpha << idListover50.isEmpty() << std::endl;

	//Constructing another list called idList2
	DoublyLinkedList<int> idList2;

	//Using assign operator to copy content from list worldwide80s to previously created list worldwide80s2
	idList2 = idList;

	//Printing list idList2 from tail to head after using assigned operator
	std::cout << "\n[148]List idList2 printed from tail to head after using assinged operator:\n";
	idList2.printBackward();

	//Using move operator moving nodes to a previously created list idList
	idList = std::move(idListless100);

	//Checking if idListless100 is empty
	std::cout << "\n[155]If idListless100 is empty it is going to print true: " << std::boolalpha << idListless100.isEmpty() << std::endl;

	//Printing list idList from head to tail
	std::cout << "\n[158]List idList printed from head to tail after using move operator:\n";
	idList.printForward();

	//Adding few nodes to a idList and sorting them
	idList.pushAtBack(121);
	idList.pushAtBack(4);
	idList.pushAtBack(17);
	idList.pushAtBack(38);
	idList.pushAtFront(44);
	idList.sort();

	//Printing list idList from head to tail
	std::cout << "\n[170]List idList printed from head to tail after using move operator:\n";
	idList.printForward();


	//Writing idList to a file idFile.txt
	idList.writeToFile("idFile.txt");

	//Clearing idList
	idList.clear();

	//Checking if idList is empty
	std::cout << "\n[181]If idList is empty it is going to print true: " << std::boolalpha << idList.isEmpty() << std::endl;

	//Reading from file and printing idList
	idList.readFromFile("idFile.txt");
	std::cout << "\n[185]List idList printed from head to tail after reading from a file:\n";
	idList.printForward();
}

int main()
{
	////TEST 1////
	//musicPlayer();

	////TEST 2////
	//id();

	return 0;
}