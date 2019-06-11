#pragma once

#include <string>
#include <map>
#include <vector>

struct ListNode {
	ListNode* prev;
	ListNode* next;
	ListNode* rand;						// ��������� �� ������������ ������� ������� ������ ���� NULL
	std::string data;
};

class List 
{
	public:
		List() : head(nullptr), tail(nullptr), count(0) {}

		void Serialize(FILE* file);		// ���������� � ���� (���� ������ � ������� fopen(path, "wb"))
		void Deserialize(FILE* file);	// �������� �� ����� (���� ������ � ������� fopen(path, "rb"))

		void PushHead(std::string newData);
		void PopHead();
		void PushTail(std::string newData);
		void PopTail();

		void PrintList();
		void CheckTail();

	private:
		ListNode* GetRandomListNode();

		ListNode* head;
		ListNode* tail;
		int count;
};

