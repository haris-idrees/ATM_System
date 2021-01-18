#include<iostream>
#include"userInfo.h"
using namespace std;
#pragma once
#ifndef LOGIN_H
#define LOGIN_H
class LogIn
{
	private:
		//UserInfo userInfo;
		string username;
		string Pin;
	string to_lower(string s);
	bool validate_password(string pass);
	bool isEqual(string s1, string s2);
	public:
		LogIn();
		void setUsername(string s);
		void setPIN(string s);
		string getUsername();
		string getPIN();
		bool logIn();

};


#endif

