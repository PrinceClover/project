 ///
 /// @file    pigLatin.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-26 13:57:46
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(void)
{
	string s;
	int flag;
	cout << "please input a word,input \"#exit\" to exit:" << endl;
	while(cin >> s)
	{
		if(s == "#exit")
		{
			cout << "bye-bye ^w^" << endl;
			break;
		}
		flag = 0;
		string pigs;
		for(int i = 0;i < s.length();++i)
		{
			if((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] >'Z'))
			{
				flag = 1;
				break;
			}
			else if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
			        s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
					s[i] == 'u' || s[i] == 'U')
			{
				pigs += s[i];
			}
			else
			{
				for(int j = i + 1 ; j < s.length();++j)
				{
					if((s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] >'Z'))
					{
						flag = 1;
						break;
					}
					pigs += s[j];
				}
				pigs += s[i];
				pigs += "ay";
				break;
			}
		}
		if(flag)
		{
			cout << "\"" << s << "\"" << " include illegal character" << endl; 
			cout << endl;
		}
		else
		{
			cout << "Pig Latin word is: "  << pigs << endl;
			cout <<  endl;
		}
	}
	return 0;
}
