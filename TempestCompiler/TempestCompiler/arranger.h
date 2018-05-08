#include "stdafx.h"
#include <string>

#ifndef CODEARRANGER23
#define CODEARRANGER23

/*
"segment.data" //COMPLETE
"msg : db \"Enter your ID\", 0xA, 0xD, 0"

"segment.bss"
"id : resb 10"

"segment.text"

"_main :"

"push msg"
"call _printf"
"call _printf"
"call _printf"
"add esp, 4"

"ret";
*/

const int INIT_SECTION = 0;
const int EXTERN_SECTION = 1;
const int DATA_SECTION = 2;
const int BSS_SECTION = 3;
const int TEXT_SECTION = 4;
const int FUNCTION_SECTION = 5;
const int COMMAND_SECTION = 6;
const int END_SECTION = 7;

/// Applies additions to the assembly code and arranges it together.
namespace CodeArranger 
{
	// The Private Section.
	namespace
	{
		// The strings that hold the code for each section.
		std::string initSection = "global _main \n";  // For the initial header stuff at the top
		std::string externSection = "extern _scanf \n";  // This section is for external C funtions that might be needed.
		std::string dataSection = "segment .data \nscanIn: db \"%s\", 0 \n";  // For const variables.
		std::string bssSection = "segment .bss \nid: resb 10 \n";  // For regular variables.
		std::string textSection = "segment .text \n\t_main: \n\njmp code \n\n";  // The text header.
		std::string functionSection = "\tpause: \npush id \npush scanIn \ncall _scanf \nadd esp, 8 \n\tret \n\n";  // The text header.
		std::string commandSection = "\tcode: \n";  // The text header.
		std::string endSection = "\ncall pause \nret";  // This is needed at the end.  // DON'T CHANGE THIS! 
	}

	std::string getArrangedAssemblyCode();  // Returns all code sections mashed together.
	
	// This function is used to add code to the different sections.
	void addToSection(int sectionNumber, std::string text);

	// This function is used to read code from the different sections.
	std::string readSection(int sectionNumber);
};

#endif 