 //
 /// @file    offline.h
 /// @author  PrinceClover(871353611@qq.com)
 /// @date    2016-07-12 19:38:38
 ///
 
#ifndef __MY_OFFLINE_H__
#define __MY_OFFLINE_H__
#include "pub_head.h"

class Configuration
{
public:
	Configuration(const string& filepath);
	map<string,string> & getConfigMap();
private:
	string _filepath;
	map<string,string> _configMap;
}

#endif
