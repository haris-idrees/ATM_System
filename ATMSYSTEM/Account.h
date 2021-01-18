#include<iostream>
using namespace std;
#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{

	string to_lower(string s);
	protected:
		string name;
		string fatherName;
		string contact;
		string gender;
		string password;
		string fvtColor;
		string fvtNumber;
		string fvtAnimal;
		long int cash;
		static int numOfAccounts;
	public:
		Account();
		Account(string name, string fatherName, string contact, char gender, string pass, string fvtColor, string fvtNumber, string fvtAnimal, long int cash);

		//GETTERS
		string getName();
		string getFathername();
		string getContact();
		string getGender();
		string getPassword();
		string getFvtColor();
		string getFvtNumber();
		string getFvtAnimal();
		long int getCash();


};


#endif

