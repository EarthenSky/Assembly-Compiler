// TempestCompiler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>

// This is the code arranger that is used to arrange all the code in the assembly file.
#include "arranger.h"

// Inserter...
//#include "inserter.h"

// Separater...
#include "separater.h"

std::string convertCodeToAssembly(std::string tempestCode);
std::string getUserFilePath();

// Read tempest file (.tt) and write to assembly file (.asm)
std::string readFile(std::string path);
void writeFile(std::string writeString);

// Pause the program until user input and enter is pressed.
void pause()
{
	std::cout << "\nPress any key then the 'Enter' key to continue.";
	std::string nothing;
	std::cin >> nothing;
}

int main()
{
	// Query the user for file path.
	std::string filePath = getUserFilePath();

	// Get the tempest file (.tt) contents.
	std::string fileText = readFile(filePath);

	// Convert code into assembly.
	std::string outputCode = convertCodeToAssembly(fileText);

	// Write the assembly code to the input.asm code.
	writeFile(outputCode);
	
	// Print the code to assemble.
	std::cout << outputCode << '\n';

	pause();

	// Send info message before using external tools.
	std::cout << "Generating .EXE application file. (Passing assembly code to NASM [assembler]) \n";

	// Call the batch file that uses the edited input.asm file and give application control to the batch file.
	system("..\\resc\\MinGW\\bin\\NASM\\create_app.bat");

    return 0;
}

// Converts the tempest code into assembly.
std::string convertCodeToAssembly(std::string tempestCode) 
{
	// Loop through each character in the program.
	for (char c : tempestCode) 
	{
		// Check the next line of code in the separator.
		CodeSeparater::checkLine(c);
	}

	// TODO: make Separation and Insertion classes.
	return CodeArranger::getArrangedAssemblyCode();  // Return the arranged assembly code.
}

// Gets the file path of the Tempest script.
std::string getUserFilePath() 
{
	std::cout << "Insert path to the \".t\" file: ";

	std::string filePath;
	std::cin >> filePath;

	return filePath;
}

// This function reads all the text from a file and returns it as a large string.
// If there is an error, it returns "ERR"
std::string readFile(std::string path) 
{
	// File input stream.
	std::ifstream myfile(path);  
	if (myfile.is_open())
	{	
		// Function output string.
		std::string fileText;  

		std::string line;  // A single line.
		while (getline(myfile, line))
		{
			fileText += line;  // Create the total string.
			//fileText += '\x00';  // Add the next line char ... NOPE, end lines with ;
		}
		
		return fileText;
		myfile.close();
	}
	else
	{
		return "ERR";
	}
}

// This function writes to the input.asm file that gets sent to NASM.
void writeFile(std::string writeString)
{
	// File out stream.
	std::ofstream asmFile("..\\resc\\MinGW\\bin\\NASM\\input.asm");

	if (asmFile.is_open())
	{
		asmFile << writeString;
	}
	else
	{
		// You're in trouble now Monsieur!
		std::cout << "Oh shit... \n" << "The .asm file couldn't be written to. \n";
	}

	// Be nice and close the file.
	asmFile.close();
}
