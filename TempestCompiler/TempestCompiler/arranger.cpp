#include "stdafx.h"
#include <iostream>

#include "arranger.h"

/// This function arranges all code sections and returns it.
/// The code returned from this function will be converted into an exe file.
std::string CodeArranger::getArrangedAssemblyCode()
{
	// Concatenates the sections and returns them.
	return initSection + externSection + dataSection + bssSection + textSection + endSection;
}

// Adds code to a specific section.
void CodeArranger::addToSection(int sectionNumber, std::string text) 
{
	if (sectionNumber == INIT_SECTION) {
		initSection += text;
	}
	else if (sectionNumber == EXTERN_SECTION) {
		externSection += text;
	}
	else if (sectionNumber == DATA_SECTION) {
		dataSection += text;
	}
	else if (sectionNumber == BSS_SECTION) {
		bssSection += text;
	}
	else if (sectionNumber == TEXT_SECTION) {
		textSection += text;
	}
	else if (sectionNumber == END_SECTION) {
		endSection += text;
	}
	std::cout << "ERR: wrong section number." << '\n';
}

// This function is used to read code from the different sections.
std::string CodeArranger::readSection(int sectionNumber)
{
	if (sectionNumber == INIT_SECTION) {
		return initSection;
	}
	else if (sectionNumber == EXTERN_SECTION) {
		return externSection;
	}
	else if (sectionNumber == DATA_SECTION) {
		return dataSection;
	}
	else if (sectionNumber == BSS_SECTION) {
		return bssSection;
	}
	else if (sectionNumber == TEXT_SECTION) {
		return textSection;
	}
	else if (sectionNumber == END_SECTION) {
		return endSection;
	}

	return "ERR";
}