 ///
 /// @file    colorprint
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-26 18:55:29
 ///

/*
 * the template class defined in colorprint
 */

#ifndef __MY_COLORPRINT__
#define __MY_COLORPRINT__
#include <string>
#include <iostream>

namespace Prince_CP{

#if 0
#define __DEBUG__
#endif

/*
 *  type define
 */
typedef unsigned int formatflag;	//type of formatflag

/*
 *  define
 */

//font colors
#define FONT_BLACK		1
#define FONT_RED		2
#define FONT_GREEN		4
#define FONT_YELLOW		8
#define FONT_BLUE		16
#define FONT_PURPLE		32
#define FONT_DEEPGREEN	64
#define FONT_WHITE		128
//background colors
#define BG_BLACK		256
#define BG_RED			512
#define BG_GREEN		1024
#define BG_YELLOW		2048
#define BG_BLUE			4096
#define BG_PURPLE		8192
#define BG_DEEPGREEN	16384
#define BG_WHITE		32768
//control
#define UNDERLINE		65536	
#define FLICKER			131072
#define HIGHLIGHT		262144
#define INVERT			524288
#define HIDE			1048576

/*
 * class:ColorFormat
 */
template <typename PrintType>
class ColorPrint;

template <typename Type>
std::ostream & operator << (std::ostream & os,const ColorPrint<Type> & rhs);

template <typename PrintType>
class ColorPrint
{
	//operator << overload
	friend std::ostream & operator << <> (std::ostream & os,const ColorPrint<PrintType> & rhs);
public:
	//constructor and destructor
	ColorPrint();
	~ColorPrint();

	//set format
	void setFormat(const formatflag & ff);
	//append format 
	void appendFormat(const formatflag & ff);
	//clean format
	void cleanFormat();
	void cleanBgColor();
	void cleanFontColor();
	void cleanUnderline();
	void cleanFlicker();
	void cleanHighlight();
	void cleanInvert();
	void cleanHide();
	void cleanControl();

	//make format by formatflag
	void makeFormatStr();

	//colorprint one PrintType
	ColorPrint<PrintType> & print(const PrintType pt);
	std::string & openFormat();
	std::string  closeFormat();
private:
	//debug printer
	void printdebug();
private:
	PrintType _printtype;			//printtype will be print
	std::string _format;			//format string 
	formatflag _format_flag;		//using bit store format
private:
	const static std::string _end;	//end flag string
	const static formatflag FONT_CLEAN = 16776960;
	const static formatflag BG_CLEAN = 16711935;
	const static formatflag CONTROL_CLEAN = 14745599;
	const static formatflag FONT_MASK = 255;
	const static formatflag BG_MASK = 65280;
};

template<typename PrintType>
void ColorPrint<PrintType>::printdebug()
{
	#ifdef __DEBUG__
	std::cout << _format_flag << std::endl;
	#endif
}

//function realize
template<typename PrintType>
const std::string ColorPrint<PrintType>::_end = "\033[0m";

template<typename PrintType>
ColorPrint<PrintType>::ColorPrint()
:_format_flag(0)
{}

template<typename PrintType>
ColorPrint<PrintType>::~ColorPrint(){}

template<typename PrintType>
std::ostream & operator << (std::ostream & os, const ColorPrint<PrintType> & rhs)
{
	std::cout << rhs._format << rhs._printtype << rhs._end;
}

template<typename PrintType>
ColorPrint<PrintType> & ColorPrint<PrintType>::print(const PrintType pt)
{
	_printtype = pt;
	return *this;
}

template<typename PrintType>
void ColorPrint<PrintType>::makeFormatStr()
{
	_format = "\033[";
	//set font color 
	if(_format_flag & FONT_BLACK)
		_format += "30;";
	else if(_format_flag & FONT_RED)
		_format += "31;";
	else if(_format_flag & FONT_GREEN)
		_format += "32;";
	else if(_format_flag & FONT_YELLOW)
		_format += "33;";
	else if(_format_flag & FONT_BLUE)
		_format += "34;";
	else if(_format_flag & FONT_PURPLE)
		_format += "35;";
	else if(_format_flag & FONT_DEEPGREEN)
		_format += "36;";
	else if(_format_flag & FONT_WHITE)
		_format += "37;";

	//set bg color
	if(_format_flag & BG_BLACK)
		_format += "40;";
	else if(_format_flag & BG_RED)
		_format += "41;";
	else if(_format_flag & BG_GREEN)
		_format += "42;";
	else if(_format_flag & BG_YELLOW)
		_format += "43;";
	else if(_format_flag & BG_BLUE)
		_format += "44;";
	else if(_format_flag & BG_PURPLE)
		_format += "45;";
	else if(_format_flag & BG_DEEPGREEN)
		_format += "46;";
	else if(_format_flag & BG_WHITE)
		_format += "47;";

	//set control
	if(_format_flag & UNDERLINE)
		_format += "4;";
	if(_format_flag & FLICKER)
		_format += "5;";
	if(_format_flag & HIGHLIGHT)
		_format += "1;";
	if(_format_flag & INVERT)
		_format += "7;";
	if(_format_flag & HIDE)
		_format += "8;";

	//add end character
	if(_format != "\033[")
		_format[_format.length()- 1] = 'm';
	else
		_format += 'm';
		printdebug();
}

template<typename PrintType>
void ColorPrint<PrintType>::setFormat(const formatflag & ff)
{
	_format_flag = ff; 
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::appendFormat(const formatflag & ff)
{
	if(ff & FONT_MASK)
		_format_flag &= FONT_CLEAN;
	if(ff & BG_MASK)
		_format_flag &= BG_CLEAN;
	_format_flag |= ff;
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanFormat()
{
	_format_flag = 0;
	_format.clear();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanBgColor()
{
	_format_flag &= BG_CLEAN; 
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanFontColor()
{
	_format_flag &= FONT_CLEAN;
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanUnderline()
{
	_format_flag &= (~UNDERLINE);
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanFlicker()
{
	_format_flag &= (~FLICKER);
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanHighlight()
{
	_format_flag &= (~HIGHLIGHT);
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanInvert()
{
	_format_flag &= (~INVERT);
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanHide()
{
	_format_flag &= (~HIDE);
	makeFormatStr();
}

template<typename PrintType>
void ColorPrint<PrintType>::cleanControl()
{
	_format_flag &= CONTROL_CLEAN;
	makeFormatStr();
}

template<typename PrintType>
std::string ColorPrint<PrintType>::closeFormat()
{
	return _end;
}

template<typename PrintType>
std::string & ColorPrint<PrintType>::openFormat()
{
	return _format;
}


/*namespace's brace*/}
#endif
