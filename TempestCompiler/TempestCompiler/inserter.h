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
		std::string printExtern = "extern _printf\n";  //TODO: this.
		std::string printVariable = "msg: db \"\", 0xA, 0xD, 0 \n";  //TODO: this.
		std::string printFunction = "\tprint: \npush msg \ncall _printf \nadd esp, 4 \n\tret \n";
		std::string printCall = "call print\n";
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
		CodeArranger::addToSection(FUNCTION_SECTION, printFunction);
		CodeArranger::addToSection(EXTERN_SECTION, printExtern);

		// create a temp copy of the variable definition.
		std::string textStr = printVariable;

		CodeArranger::addToSection(DATA_SECTION, textStr.insert(9, printString));
	}

	// Add the function call to the code.
	CodeArranger::addToSection(COMMAND_SECTION, printCall);
	
}
#endif