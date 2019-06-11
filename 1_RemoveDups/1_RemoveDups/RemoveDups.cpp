#include "RemoveDups.h"

void RemoveDups(char* pStr)
{
	// If the string is NULL or empty, then return from the function
	if ((pStr == nullptr) || (*pStr == '\0'))
	{
		return;
	}

	// Initializing the cursor for checking and writing
	unsigned originCursor = 1, editableCursor = 1;

	do
	{
		// If the previous character is not equal to the current
		if (*(pStr + originCursor - 1) != *(pStr + originCursor))
		{
			// Then write it char as the next character in the edited string
			*(pStr + editableCursor++) = *(pStr + originCursor);
		}
	}
	// We continue to the end of the line and increase the cursor by one.
	while (*(pStr + originCursor++) != '\0');
}
