#include "List.h"
#include <iostream>

void List::Serialize(FILE* file)
{
}

void List::Deserialize(FILE* file)
{
}

void List::PushHead(std::string newData)
{
	ListNode* newNode = new ListNode{ nullptr, nullptr, nullptr, newData };
	
	ListNode* oldHead = head;
	
	if (head != nullptr)
	{
		head->prev = newNode;
		newNode->next = head;
	}
	head = newNode;
	head->rand = GetRandomListNode();

	if (oldHead == nullptr)
	{
		tail = head;
	}

	count++;
}

void List::PopHead()
{
	if (head != nullptr) 
	{
		if (head != tail) {
			head->next->prev = head->prev;
			head = head->next;
		} else
		{
			tail->prev = nullptr;
			head = tail;
		}

		count--;
	}
}

void List::PushTail(std::string newData)
{
	ListNode* newNode = new ListNode{ nullptr, nullptr, nullptr, newData };

	ListNode* oldTail = tail;

	if (tail != nullptr)
	{
		tail->next = newNode;
		newNode->prev = tail;
	}
	tail = newNode;
	tail->rand = GetRandomListNode();

	if (oldTail == nullptr)
	{
		head = tail;
	}

	count++;
}

void List::PopTail()
{
	if (tail != nullptr)
	{
		if (head != tail) {
			tail->prev->next = tail->next;
			tail = tail->prev;
		}
		else
		{
			head->next = nullptr;
			tail = head;
		}

		count--;
	}
}

void List::PrintList()
{
	auto currNode = head;
	while (currNode != nullptr)
	{
		std::cout << "Data: " << currNode->data << " Current: " << currNode << " Next: " << currNode->next << " Prev: " << currNode->prev << " Rand: " << currNode->rand << std::endl;
		currNode = currNode->next;
	}
}

ListNode* List::GetRandomListNode()
{


	return nullptr;
}
