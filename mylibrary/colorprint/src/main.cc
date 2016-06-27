 ///
 /// @file    main.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-26 23:09:00
 ///

#include "colorprint.cc"
#include <iostream>
using std::cout;
using std::endl;
using Prince_CP::ColorPrint;

int main(void)
{
	ColorPrint<int> cp;
	cp.setFormat(BG_RED);
	cp.appendFormat(FONT_BLUE);
	cp.appendFormat(UNDERLINE);

	int testint = 1024;
	cout << cp.print(testint) << endl;
	cout << cp.openFormat() << "hello " << testint  << cp.closeFormat() << endl;
	return 0;
}
