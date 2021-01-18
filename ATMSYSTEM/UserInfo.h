#include<iostream>
using namespace std;
#pragma once
#ifndef USERINFO_H
#define USERINFO_H
#include"LogIn.h"
class UserInfo
{
	private:
		LogIn login;
		//data members containing information of user
		string name;
		string fatherName;
		string contact;
		string gender;
		string password;
		string fvtColor;
		string fvtNumber;
		string fvtAnimal;
		long int cash;
	public:
		UserInfo();
		string displayUserInfo();

		//getters
		string getName();
		string getFathername();
		string getContact();
		string getGender();
		string getPassword();
		string getFvtColor();
		string getFvtNumber();
		string getFvtAnimal();
		long int getCash();

		//setters
		void setPassword(string s);
		void setName(string);
		void setFatherName(string);
		void setContact(string);
		void setGender(string);
		void setColor(string);
		void setNumber(string);
		void setAnimal(string);
		void setCash(long int);

		string to_lower(string s);
		bool validate_password(string pass);
		bool isEqual(string s1, string s2);




};


#endif

