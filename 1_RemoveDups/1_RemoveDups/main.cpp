#include <iostream>
#include "RemoveDups.h"

int main()
{
	// Test 1
	char pStr[] = "AAA BBB AAA";

	std::cout << "Source string: " << pStr << std::endl;
	RemoveDups(pStr);
	std::cout << "Edited string: " << pStr << std::endl;

	// Test 2
	char pStr2[] = "A";

	std::cout << "Source string: " << pStr2 << std::endl;
	RemoveDups(pStr2);
	std::cout << "Edited string: " << pStr2 << std::endl;

	// Test 3
	char pStr3[] = "";

	std::cout << "Source string: " << pStr3 << std::endl;
	RemoveDups(pStr3);
	std::cout << "Edited string: " << pStr3 << std::endl;

	// Test 4
	char pStr4[] = "AaaAAaaaaBBBbbbBBBCCccCC";

	std::cout << "Source string: " << pStr4 << std::endl;
	RemoveDups(pStr4);
	std::cout << "Edited string: " << pStr4 << std::endl;

	// Test 5
	char pStr5[] = "ABCD DBCA";

	std::cout << "Source string: " << pStr5 << std::endl;
	RemoveDups(pStr5);
	std::cout << "Edited string: " << pStr5 << std::endl;

	return 0;
}