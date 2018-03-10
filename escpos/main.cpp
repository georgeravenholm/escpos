// escpos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "escpos.h"
#include <fstream>
#include <iostream>
#include "getopt.h"

int main(int argc , char** argv)
{
	opterr = 0;

	// Retrieve the options:
	int opt;
	
	int flags = 0; // All of the font flags
	int justify = 0; // justification
	int 

	opterr = 0;
	while ((opt = getopt(argc, argv, "hcreuwtb")) != -1) {  // for each option...
		switch (opt) {
		case 'h':
			// Help!!!
			std::cout << argv[0] << " flags:" << std::endl;
			std::cout << "-h\tthis help thing u autist" << std::endl;
			std::cout << "-c\tcentre" << std::endl;
			std::cout << "-r\tarab mode" << std::endl;
			std::cout << "-e\temphasis" << std::endl;
			std::cout << "-u\tunderline" << std::endl;
			std::cout << "-w\tdouble wide" << std::endl;
			std::cout << "-t\tdouble tall" << std::endl;
			//std::cout << "-a\tdoes this" << std::endl;
			std::cout << "-b\tfont B (smaller)" << std::endl;
			return 0;
			break;
		case '?':  // unknown option...
			std::cerr << "oFRICK!!! badd option: '" << char(optopt) << "'!" << std::endl;
			return 1;
			break;

			// actual sgit here lole
		case 'c':
			justify = 1;
			break;
		case 'r':
			justify = 2;
			break;
		case 'e':
			flags |= ESC_EMPHASISE;
			break;
		case 'u':
			flags |= ESC_UNDER;
			break;
		case 'w':
			flags |= ESC_DUBWIDE;
			break;
		case 't':
			flags |= ESC_DUBTALL;
			break;
		case 'b':
			flags |= ESC_FONTB;
			break;
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	
	Printer caner;
	caner.Align(justify);
	caner.SetFont(flags);
	caner.Append("Big Heading\n");
	//caner.BreakBlast(4);

	//std::ofstream file("auto.pos");
	std::cout << caner.GetString();

    return 0;
}

