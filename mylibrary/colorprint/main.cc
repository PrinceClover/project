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
	cp.setFormat(BG_RED|FONT_GREEN|HIDE|INVERT|FLICKER|UNDERLINE|HIGHLIGHT);
	//cp.cleanControl();
	int a = 999999;
	cout << "\033[47;30mhi\033[0m " << endl;
	cout << cp.openFormat() << "hello " << cp.print(a) << a 
		 << cp.closeFormat() << " hello" << endl;
	return 0;
}
