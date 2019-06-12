#include <iostream>
#include "List.h"

int main()
{
	// Test
	List* list = new List();
	// Init nodes
	list->PushHead("First in");
	list->PushHead("Second in");
	list->PushHead("Some data");
	list->PushTail("I am a tail");
	// Update random pointers for all nodes
	list->UpdateRandomPointers();
	// Print list
	std::cout << "List before Serialization:" << std::endl;
	list->PrintList();


	delete list;

	return 0;
}