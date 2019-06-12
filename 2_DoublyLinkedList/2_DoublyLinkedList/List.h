#pragma once

#include <string>
#include <vector>

struct ListNode {
	ListNode* prev;
	ListNode* next;
	ListNode* rand;						// указатель на произвольный элемент данного списка либо NULL
	std::string data;
};

class List 
{
	public:
		List() : head(nullptr), tail(nullptr), count(0) {}

		void Serialize(FILE* file);		// сохранение в файл (файл открыт с помощью fopen(path, "wb"))
		void Deserialize(FILE* file);	// загрузка из файла (файл открыт с помощью fopen(path, "rb"))

		void PushHead(std::string newData);
		void PopHead();
		void PushTail(std::string newData);
		void PopTail();

		void PrintList();

		void UpdateRandomPointers();
	private:
		ListNode* GetRandomListNode(int dice_roll);

		ListNode* head;
		ListNode* tail;
		int count;
};

