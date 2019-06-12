#include <iostream>
#include "List.h"

// For correct compiling in VS
#pragma warning(disable: 4996)

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

	// Open file for Serialization
	FILE* file = fopen("serialized_list.bin", "wb");
	if (file != nullptr)
	{
		list->Serialize(file);
		fclose(file);
	}
	// And delete old list
	delete list;

	// Open file for Deserialization
	file = fopen("serialized_list.bin", "rb");
	if (file != nullptr)
	{
		// Create new list
		List* deserializedList = new List();
		// Deserilized it
		deserializedList->Deserialize(file);
		fclose(file);

		// Print new list
		std::cout << "List after Deserialization:" << std::endl;
		deserializedList->PrintList();
		// and delete it
		delete deserializedList;
	}

	return 0;
}