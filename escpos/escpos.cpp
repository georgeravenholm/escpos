#include "stdafx.h"
#include "escpos.h"

Printer::Printer()
	:
	buffer()
{
	ResetFormatting();
}

void Printer::ResetFormatting()
{
	Append(ESC);
	Append('@');
}

void Printer::Append(const std::string s)
{
	buffer << s;
}

void Printer::Append(const char c)
{
	buffer << c;
}

void Printer::SetFont(const int flags)
{
	buffer << ESC << '!' << (char)flags;
}

void Printer::Align(const int level)
{
	buffer << ESC << '\x61' << (char)level;
}

void Printer::BreakBlast(const int count)
{
	for (int i = 0; i < count; ++i)
		Append(LF);
}

/*void Printer::Barcode(const std::string text)
{
	// Set barcode height
	buffer << GS << 'h' << (char) 48;
	buffer << ESC << 'k' << '\0x02' << text << NUL << LF;
}*/

std::string Printer::GetString() const
{
	return buffer.str();
}

