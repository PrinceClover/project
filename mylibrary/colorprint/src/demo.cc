 ///
 /// @file    main.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-26 23:09:00
 ///

#include <iostream>
#include "colorprint.hpp"
using std::cout;
using std::endl;

int main(void)
{
	colorprint::ColorPrint<int> cp;
	cp.setFormat(colorprint::BG_RED);
	cp.appendFormat(colorprint::FONT_BLUE);
	cp.appendFormat(colorprint::UNDERLINE);

	int testint = 1024;
	cout << cp.printOne(testint) << endl;
	cout << cp.openFormat() << "hello " << testint << cp.closeFormat() << endl;
	return 0;
}
