#include <iostream>
#include "List.h"

int main()
{
	List* list = new List();

	list->PrintList();

	list->PushHead("First in");
	list->PushHead("Second in");
	list->PushHead("Some data");
	list->PushTail("I am a tail");

	list->PrintList();

	list->PopHead();
	list->PopHead();

	list->PrintList();
	list->CheckTail();

	list->PopHead();
	list->PopHead();

	list->PrintList();

	delete list;

	return 0;
}