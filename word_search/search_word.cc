 ///
 /// @file    search_word.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-23 15:08:34
 ///
 
#include "search_word.h"
//@CLASS:wordPlace
//operator "<" overload
bool operator < (const wordPlace & lhs,const wordPlace & rhs)
{
	return lhs._line < rhs._line;
}

//copy constructor
wordPlace::wordPlace(const wordPlace & wp)
:_line(wp._line)
,_sentence(wp._sentence)
{}

//constructor and destructor
wordPlace::wordPlace()
{}
wordPlace::~wordPlace()
{}

//@CLASS:wordInfo
//copy constructor
wordInfo::wordInfo(const wordInfo & wif)
:_count(wif._count)
,_word(wif._word)
,_wordplace(wif._wordplace)
{}

//constructor and destructor
wordInfo::wordInfo()
{}
wordInfo::~wordInfo()
{}
//print word infomation
void wordInfo::printWordInfo()
{
	set<wordPlace>::iterator wpit = _wordplace.begin();
	for(;wpit != _wordplace.end();++wpit)
	{
		cout << "\t" 
			 << "(line" << wpit->_line << ")" 
			 << wpit->_sentence
			 << endl;
	}
}


