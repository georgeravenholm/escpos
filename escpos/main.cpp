// escpos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "escpos.h"
#include <fstream>

int main()
{
	Printer caner;
	caner.Align(1);
	caner.SetFont(ESC_UNDER | ESC_DUBTALL | ESC_EMPHASISE );
	caner.Append("Big Heading\n");
	caner.SetFont(0); // reset font
	//caner.Barcode("meme");
	caner.BreakBlast(4);

	// This is a teeest!

	std::ofstream file("auto.pos");
	file << caner.GetString();

    return 0;
}

