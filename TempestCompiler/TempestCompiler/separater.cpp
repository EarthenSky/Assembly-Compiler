#include "stdafx.h"

#include <iostream>
#include <string>

#include "separater.h"

// Parses the next character of Tempest code.
void CodeSeparater::checkLine(char c)
{
	// Check which task needs to be run.
	if (currentTask == FIND_INIT_KEYWORD) {
		findInitKeyword(c);
	}
	else if(currentTask == FIND_GLOBAL_ITEM) {
		findGlobalItem(c);
	}
	else if (currentTask == READ_TEXT) {
		readText(c);
	}
}

// Looks for the inital keyword and target character (':', ';', or '/').
void CodeSeparater::findInitKeyword(char c) {
	if (c == ':') {
		// if the parser finds a colon, that means that the line is a variable definition.

	}
	else if (c == ';') {
		// if the parser finds a semicolon, that means that the line is a function.

	}
	else if (c == '/') {
		// if the parser finds a forward slash, that means that the line is a namespace reference.
		lookForNamespaceVar(lastKeyword);
	}
	else {
		// Only add a char to the keyword if it is not whitespace.  Keywords cannot be whitespace.
		if (c != ' ') {
			lastKeyword += c;
		}

		std::cout << lastKeyword;
	}
}

// Can only find the print function right now.
void CodeSeparater::findGlobalItem(char c) {
	if (c == '(') {
		// If the parser finds a start paren, that means that the last section of code was a function's name.
		lookForGlobalFunction(lastKeyword);
	}
	else if (c == ' ') {
		// White space is not allowed in function names.  Give error.
		std::cout << "ERR 4: Improper placement of white space.  Did you put whitespace before or in a variable's name?" << '\n';
	}
	else {
		lastKeyword += c;
	}
}

void CodeSeparater::lookForNamespaceVar(std::string namespaceName)
{
	// If the namespace name is tem, (aka tempest or the global namespace,) change the current task.
	if (namespaceName == "tem") {
		currentTask = FIND_GLOBAL_ITEM;
		lastKeyword = "";  // Reset the last keyword. (the namespace's name is no longer needed.)
	}
	else {
		// Give error message if namespace name is wrong.
		std::cout << "ERR 3: Incorrect namespace name. User defined namespaces not yet added."  << '\n' 
		          << "You may have misspeled 'tem' or have insterted a '/' in the wrong place." << '\n';
	}

	//TODO: insert user defined namespaces.
}

void CodeSeparater::lookForGlobalFunction(std::string functionName)
{
	// If the namespace name is tem, (aka tempest or the global namespace,) change the current task.
	if (functionName == printFunctionName) {
		currentTask = FIND_GLOBAL_ITEM;
		lastKeyword = "";  // Reset the last keyword.
	}
	else {
		// Give error message if function name is wrong.
		std::cout << "ERR 2: Incorrect function name. There is no function in the 'tem' namespace with the name: " << lastKeyword << '\n';
	}

	//TODO: insert user defined namespaces.
}

void CodeSeparater::readText(char c)
{
	if (c == ')') {
		// Insert the print statement with the inserter.
		//CodeInserter::insertPrint();

		currentTask = FIND_INIT_KEYWORD;

		lastKeyword = "";  // Reset the last keyword.
		printString = "";  // Flush last string.
	}	
	else {
		printString += c;
	}
}