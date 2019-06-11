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

	delete list;

	return 0;
}