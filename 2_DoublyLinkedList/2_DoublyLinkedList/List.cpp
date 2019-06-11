#include "List.h"
#include <iostream>
#include <random>
#include <ctime>

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
	count++;

	head->rand = GetRandomListNode();

	if (oldHead == nullptr)
	{
		tail = head;
	}

}

void List::PopHead()
{
	if (head != nullptr) 
	{
		if (head != tail) {
			head->next->prev = head->prev;
			auto oldHead = head;
			head = head->next;
			delete oldHead;
			oldHead = nullptr;
		} else
		{
			delete head;
			head = nullptr;
			tail = nullptr;
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
	count++;
	tail->rand = GetRandomListNode();

	if (oldTail == nullptr)
	{
		head = tail;
	}

}

void List::PopTail()
{
	if (tail != nullptr)
	{
		if (head != tail) {
			tail->prev->next = tail->next;
			auto oldTail = tail;
			tail = tail->prev;
			delete oldTail;
			oldTail = nullptr;
		}
		else
		{
			delete head;
			head = nullptr;
			tail = nullptr;
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

void List::CheckTail()
{
	if (tail->rand == nullptr)
	{
		std::cout << "NULL" << std::endl;
	} 
	else
	{
		std::cout << tail->rand->data << std::endl;
	}
}

ListNode* List::GetRandomListNode()
{
	if (count > 0) 
	{
		std::default_random_engine generator(time(0));
		std::uniform_int_distribution<int> distribution(0, count);
		int dice_roll = distribution(generator);

		std::cout << dice_roll << " ";
		if (dice_roll == count)
			return nullptr;

		int index = 0;
		ListNode* rand = head;
		while (index < dice_roll)
		{
			rand = rand->next;
			index++;
		}
		return rand;
	}

	return nullptr;
}
