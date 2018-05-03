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
		std::string printBody = "push msg \ncall _printf \nadd esp, 4";
	}

	void insertPrint() 
	{
		// Check if function exists yet.
		if (printIsActive == false)
		{
			// insert the function into the function section.
		}

		// Add the function call to the code.
		CodeArranger::addToSection(TEXT_SECTION, printBody);
	}
}

#endif