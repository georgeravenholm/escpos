#pragma once

#include <string>
#include <sstream>

#define NUL	'\x00'
#define LF	'\x0A'
#define ESC	'\x1B'
#define GS	'\x1D'


enum
{
	ESC_FONTA=0,
	ESC_FONTB=1,
	ESC_EMPHASISE=8,
	ESC_DUBTALL=16,
	ESC_DUBWIDE=32,
	ESC_UNDER=128,
};

class Printer
{
public:
	Printer();
	~Printer() = default;

	void ResetFormatting();
	void Append(const std::string s);
	void Append(const char c);
	void SetFont(const int flags); // The font modes are made from logically OR’ing together a selection of attributes.
	void Align(const int level); // 0 = left, 1 = centre, 2 = allahakbar
	void BreakBlast(const int count);
	//void Barcode(const std::string text);
	std::string GetString() const;
private:
	std::stringstream buffer;
};