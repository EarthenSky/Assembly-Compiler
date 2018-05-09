#include "stdafx.h"
#include <string>

#include "arranger.h"

#ifndef CODEINSERTER2
#define CODEINSERTER2

/// Choses code to give to the arranger and insert into assembly, based off what the separater tells it.
/// i.e. inserts 'sort of' code snipets and fills them out, before passing them to the arranger.
namespace CodeInserter
{
	// The Private Section.
	namespace
	{
		bool printIsActive = false;

		int varNameCounter = 0;

		std::string printExtern = "extern _printf\n";  //TODO: this.
		std::string printVariable = "printMsg: db \"\", 0xA, 0xD, 0 \n";  //TODO: this.
		//std::string printFunction = "\tprint:  \n\tret \n\n";
		std::string printCall = "push printMsg \ncall _printf \nadd esp, 4 \n";

	}
	
	void insertPrint(std::string printString);
}

void CodeInserter::insertPrint(std::string printString)
{
	// Check if function exists yet.
	if (printIsActive == false)
	{
		printIsActive = true;

		// Insert the function into the function section and add the extern reference.
		//CodeArranger::addToSection(FUNCTION_SECTION, printFunction);
		CodeArranger::addToSection(EXTERN_SECTION, printExtern);
	}


	// create a temp copy of the variable definition.
	std::string textStr = printVariable;
	textStr.insert(8, std::to_string(varNameCounter));

	CodeArranger::addToSection(DATA_SECTION, textStr.insert(15, printString));

	// Change the variable name with the unique id counter.
	textStr = printCall;
	textStr.insert(13, std::to_string(varNameCounter));

	// Add the function call to the code.
	CodeArranger::addToSection(COMMAND_SECTION, textStr);

	// Inc the unique id counter.
	varNameCounter++;
	
}
#endif