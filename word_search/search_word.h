 ///
 /// @file    search_word.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-23 16:19:27
 ///
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::istringstream;

//word's place class
class wordPlace
{
	//operator "<" overload
	friend bool operator < (const wordPlace & lhs,const wordPlace & rhs);
public:
	//constructor and destructor
	wordPlace();
	~wordPlace();
	//copy constroctor
	wordPlace(const wordPlace & wp);
public:
	int _line;			//witch line the word appear
	string _sentence;	//witch sentence the word appear
};

//word's information class
class wordInfo
{
public:
	//constructor and destructor
	wordInfo();
	~wordInfo();
	//copy constructor
	wordInfo(const wordInfo & wif);
	//print word infomation
	void printWordInfo();
public:
	string _word;				//word
	set<wordPlace> _wordplace;	//word appear place
	int _count;					//word count;
};

