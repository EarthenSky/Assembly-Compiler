#include "stdafx.h"
#include <string>

#ifndef CODESEPARATER2
#define CODESEPARATER2

const int FIND_INIT_KEYWORD = 0;
const int FIND_GLOBAL_ITEM = 1;  // Looks for a variable or function in the global (or 'tem' [tempest]) namespace.
const int READ_TEXT = 2;
const int FUNCTION_DEFINITION = 4;
const int VARIABLE_DEFINITION = 5;

/// Reads the tempest file and separates it into sections.
namespace CodeSeparater
{
	// The Private Section.
	namespace
	{
		// The current thing that the separater is looking for / doing.
		int currentTask = FIND_INIT_KEYWORD;

		// Hold the text that was parsed before a key point was reached.
		std::string lastKeyword = "";
		std::string printString = "";

		// The name of the print function.
		std::string printFunctionName = "print";
		
	}

	// Parses the next character of Tempest code.
	void checkLine(char c);
	
	// Looks for a variable in the input variable.
	void lookForNamespaceVar(std::string namespaceName);

	// Looks for the inital keyword and target character (':', ';', or '/').
	void findInitKeyword(char c);

	// Looks for a tempest built in function, like print() or add().
	void findGlobalItem(char c);

	// This function looks for a global (or tempest/pre-built namespace) function.  ex. 'print()'
	void lookForGlobalFunction(std::string functionName);

	// This code reads the text that is in a call to the print function.
	void readText(char c);
}

#endif