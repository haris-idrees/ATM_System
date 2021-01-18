#include "Account.h"
#include<iostream>
using namespace std;

int Account::numOfAccounts = 0;

Account::Account() {

}

Account::Account(string name, string fatherName, string contact, char gender, string pass, string fvtColor, string fvtNumber, string fvtAnimal,long int cash) {

	this->name = name;
	this->fatherName = fatherName;
	this->contact = contact;
	this->gender = gender;
	this->password = pass;
	this->fvtColor = fvtColor;
	this->fvtNumber = fvtNumber;
	this->fvtAnimal = fvtAnimal;
	this->cash = cash;
}

string Account::to_lower(string s) {

	string final = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (int(s[i]) != 32)  //excluding space
			final += tolower(s[i]);

	}
	return final;
}

string Account::getName() {

	return this->name;

}

string Account::getFathername() {

	return this->fatherName;

}

string Account::getContact() {

	return this->contact;

}

string Account::getGender() {

	return this->gender;

}

string Account::getPassword() {

	return this->password;

}

long int Account::getCash() {

	return this->cash;

}

string Account::getFvtColor() {

	return this->fvtColor;

}

string Account::getFvtAnimal() {

	return this->fvtAnimal;

}

string Account::getFvtNumber() {

	return this->fvtNumber;

}
