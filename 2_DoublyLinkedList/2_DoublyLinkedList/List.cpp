#include "List.h"
#include <iostream>
#include <random>
#include <ctime>
#include <map>

void List::Serialize(FILE* file)
{
	// For serialization, we write down all the nodes from head to tail.
	auto currentNode = head;
	while (currentNode != nullptr)
	{
		// Write the address in the memory of the node and the address of the rand pointer into the file,
		// and then write the data from the new line
		// The newline character ('\n') will mean the end of the data.
		fprintf(file, "%u %u\n%s\n", 
			reinterpret_cast<std::uintptr_t>(currentNode), 
			reinterpret_cast<std::uintptr_t>(currentNode->rand), 
			currentNode->data.c_str());
		currentNode = currentNode->next;
	}
}

void List::Deserialize(FILE* file)
{
	// To restore the structure, we will use the map, where the key will be the old address in memory
	std::map<std::uintptr_t, ListNode*> nodesMap;
	// Add nullptr key
	nodesMap[reinterpret_cast<std::uintptr_t>(nullptr)] = nullptr;

	// Variables for reading from the file the old address (as the key for map) and the old address rand pointer (as the key)
	std::uintptr_t keyNode, randKey;
	// In the vector, we will store the keys for the pointer by rand in the order from the head to the tail.
	std::vector<std::uintptr_t> randKeysOrder;
	// We read the keys first (old addresses in memory)
	while (fscanf_s(file, "%u %u\n", &keyNode, &randKey) != EOF)
	{
		// We will literally read the data and save to the buffer
		char bufferChar, buffer[256];
		int cursoreLineIndex = 0;
		// We read one character until we meet the transfer to a new line.
		while ((bufferChar = fgetc(file)) != '\n' )
		{
			buffer[cursoreLineIndex] = bufferChar;
			cursoreLineIndex++;
		}
		// Mark the end of the line with the \0 character so that the buffer is correctly translated into std::string
		buffer[cursoreLineIndex] = '\0';
		// Add the read data to the tail of the list so that the order is restored to the correct one.
		// At the same time, the prev and next pointers will be restored correctly, indicating the necessary nodes.
		PushTail(buffer);
		// Write the new pointer just added to the map using the old key
		nodesMap[keyNode] = tail;
		// And remember his old address for rand pointer
		randKeysOrder.push_back(randKey);
	}

	// Now we will restore all the pointers to rand from the map in the order they follow.
	auto currNode = head;
	int keyOrderIndex = 0;
	while (currNode != nullptr)
	{
		currNode->rand = nodesMap[randKeysOrder[keyOrderIndex]];
		currNode = currNode->next;
		keyOrderIndex++;
	}
}

void List::PushHead(std::string newData)
{
	// Create new node
	ListNode* newNode = new ListNode{ nullptr, nullptr, nullptr, newData };
	// Remember current head
	ListNode* oldHead = head;
	// If List not empty
	if (head != nullptr)
	{
		// For the current head pointer, set the previous pointer to a new pointer.
		head->prev = newNode;
		// For the new pointer, set the next pointer to a current head pointer.
		newNode->next = head;
	}
	// Set current head pointer to a new pointer
	head = newNode;
	// Increase the counter
	count++;
	// If old head pointer is NULL
	if (oldHead == nullptr)
	{
		// Then tail = head
		tail = head;
	}
}

void List::PopHead()
{
	// If list not empty
	if (head != nullptr) 
	{
		// If list count > 1
		if (head != tail) {
			// Set the pointer to the previous pointer for the second from the head to NULL
			head->next->prev = head->prev;
			// Remember current head
			auto oldHead = head;
			// Set head pointer to the second from head
			head = head->next;
			// delete old head
			delete oldHead;
		} 
		else
		{
			// If list count == 1
			// Then delete head
			delete head;
			// Set head and tail pointers to the NULL
			head = nullptr;
			tail = nullptr;
		}
		// Decrease the counter
		count--;
	}
}

void List::PushTail(std::string newData)
{
	// Create new node
	ListNode* newNode = new ListNode{ nullptr, nullptr, nullptr, newData };
	// Remember current tail
	ListNode* oldTail = tail;
	// If List not empty
	if (tail != nullptr)
	{
		// For the current tail pointer, set the next pointer to a new pointer.
		tail->next = newNode;
		// For the new pointer, set the prev pointer to a current tail pointer.
		newNode->prev = tail;
	}
	// Set current tail pointer to a new pointer
	tail = newNode;
	// Increase the counter
	count++;
	// If old tail == NULL
	if (oldTail == nullptr)
	{
		// Set head pointer to a tail pointer
		head = tail;
	}

}

void List::PopTail()
{
	// If list not empty
	if (tail != nullptr)
	{
		// If list count > 1
		if (head != tail) {
			// Set the pointer to the next pointer for the second from the tail to NULL
			tail->prev->next = tail->next; // tail->next always NULL
			// Remember old tail
			auto oldTail = tail;
			// Set tail pointer to the second from tail
			tail = tail->prev;
			// delete old tail
			delete oldTail;
		}
		else
		{
			// If list count == 1
			// Then delete head and set head and tail to NULL
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		// Decrease the counter
		count--;
	}
}

void List::PrintList()
{
	std::cout << "// Head" << std::endl << "//-------------" << std::endl;
	auto currNode = head;
	while (currNode != nullptr)
	{
		std::cout << "Data: " << currNode->data <<
			" Current: " << currNode << 
			" Next: " << currNode->next << 
			" Prev: " << currNode->prev << 
			" Rand: " << currNode->rand << std::endl;
		currNode = currNode->next;
	}
	std::cout << "//-------------" << std::endl << "// Tail" << std::endl << std::endl;
}

void List::UpdateRandomPointers()
{
	// Set random pointers for all nodes from head to tail
	auto currentPointer = head;

	// Init random generator
	std::default_random_engine generator(time(0));
	std::uniform_int_distribution<int> distribution(0, count);
	
	while (currentPointer != nullptr)
	{
		// Get random index from 0 to count inclusive
		int dice_roll = distribution(generator);

		currentPointer->rand = GetRandomListNode(dice_roll);
		currentPointer = currentPointer->next;
	}
}

ListNode* List::GetRandomListNode(int dice_roll)
{
	// If list not empty
	if (count > 0) 
	{
		// If random index == count
		if (dice_roll == count)
		{
			// Then random pointer is NULL
			return nullptr;
		}
		// Find pointer from head to random index 
		int index = 0;
		ListNode* rand = head;
		while (index < dice_roll)
		{
			rand = rand->next;
			index++;
		}
		// And return random pointer
		return rand;
	}
	// Return NULL if list empty
	return nullptr;
}
