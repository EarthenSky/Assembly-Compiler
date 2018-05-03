#include "stdafx.h"
#include <string>

#include "arranger.h"

#ifndef CODEINSERTER
#define CODEINSERTER

/// Choses code to give to the arranger and insert into assembly, based off what the separater tells it.
/// i.e. inserts 'sort of' code snipets and fills them out, before passing them to the arranger.
namespace CodeInserter
{
	// The Private Section.
	namespace
	{	
		bool printIsActive = false;
		std::string printExtern = "extern _printf";  //TODO: this.
		std::string printVariable = "msg: db \"Enter your ID\", 0xA, 0xD, 0";  //TODO: this.
		std::string printFunction = "\tprint: \npush msg \ncall _printf \nadd esp, 4 \n\tret";
	}

	void insertPrint() 
	{
		// Check if function exists yet.
		if (printIsActive == false)
		{
			// insert the function into the function section.
		}

		// Add the function call to the code.
		CodeArranger::addToSection(FUNCTION_SECTION, printFunction);
	}
}

#endif