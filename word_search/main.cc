 ///
 /// @file    main.cc
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-06-23 16:24:51
 ///
 
#include "search_word.cc"



int main(int argc,char * argv[])
{
	//check args
	if(argc != 2)
	{
		cout << "error args!" << endl;
		return -1;
	}

	//open file
	ifstream ifs(argv[1],std::ios::in);
	if(!ifs.good())
	{
		cout << "file open error" << endl;
		return -1;
	}
	cout << "Please wait" << endl;
	cout << "counting..." << endl;
	//read file and count words
	map<string,wordInfo> words;
	map<string,wordInfo>::iterator wit;
	wordPlace wp;
	set<wordPlace>::iterator wpit;
	string line,tword,word;
	int linenum = 0;
	int i,j;
	char dword[30];
	while(getline(ifs,line))  //or getline(ifs,str,'.').stoped by reading '.'
	{
		++linenum;
		istringstream iss(line);
		while(iss >> tword)
		{
			//delete other character
			string word;
			for(i = 0,j = 0;i < tword.length();++i)
			{
				if((tword[i] > 'a' && tword[i] < 'z') ||
				   (tword[i] > 'A' && tword[i] < 'Z')
				  )
				{
					dword[j++] = tword[i];
				}
			}
			dword[j] = '\0';
			word = dword;
			//search word
			wit = words.find(word);
			//if the word in this map
			if(wit->second._word == word)
			{
				++(wit->second._count);
				wpit = wit->second._wordplace.end();
				if((*wpit)._line == linenum)
				{
					continue;
				}
				wp._line = linenum;
				wp._sentence = line;
				wit->second._wordplace.insert(wp);
			}
			//add the word as new one
			else
			{
				wordInfo wif;
				wp._line = linenum;
				wp._sentence = line;
				wif._word = word;
				wif._count = 1;
				wif._wordplace.insert(wp);
				words[word] = wif;
			}
		}
	}
	//search word
	cout << "Words count complete!"<< endl;
	cout << "Please input the WORD you want to SEARCH,input \"#exit\" to EXIT!" << endl;
	while(1)
	{
		cin >> tword;
		if(tword == "#exit")
			break;
		cout << "____________________________________________" << endl;
		wit = words.find(tword);
		//if the word in this map
		if(wit->second._word == tword)
		{
			cout << tword << " occors " << wit->second._count << " times." << endl;
			wit->second.printWordInfo();
		}
		else
		{
			cout << "no such word in this text!" << endl;
		}
		cout << endl << endl;
	}
	
	return 0;
}

