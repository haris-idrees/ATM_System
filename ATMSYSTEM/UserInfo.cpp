#include "UserInfo.h"
#include"LogIn.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

UserInfo::UserInfo() {

	this->login;

}

string UserInfo::displayUserInfo() {

	//first user must LOG IN to see his all information

	bool flag=this->login.logIn();
	while (!flag)
	{
		cout << endl << endl;
		flag = this->login.logIn();
	}

	//now we have to get logged in user's username and PIN to display his all information
	string username, PIN;
	username = login.getUsername();
	PIN = login.getPIN();

	//now displaying information of this user.

	cout << endl << endl;
	cout << endl << "\t\t\t\t\t\tWELCOME " << username << endl;
	cout << "***********************************************************************************************************************" << endl << endl;
	cout << "\t\t\t\t\t\tUSER INFO" << endl;
	cout << "\t\t\t\t\t\t_________" << endl << endl;
	//string name, fatherName, contact, gender, password, fvtColor, fvtNumber, fvtAnimal;
	//long int cash;
	//opening his file
	ifstream read;
	read.open(PIN.c_str());
	cout << "Name: "; getline(read,this->name); cout << this->name << endl;
	cout << "Father Name: "; getline(read, this->fatherName); cout << this->fatherName << endl;
	cout << "Contact: "; getline(read, this->contact); cout << this->contact << endl;
	cout << "Gender: "; getline(read,this->gender);  cout << this->gender << endl;
	cout << "Password: "; getline(read,this->password); cout << this->password << endl;
	//cin.ignore(); 
	string temp;
	cout << "Present Amount: ";getline(read, temp); this->cash = stoi(temp);cout << this->cash << endl;
	cout << "Favourite Colour: "; getline(read,this->fvtColor); cout <<this-> fvtColor << endl;
	cout << "Favourite Number: ";getline(read,this->fvtNumber); cout << this->fvtNumber << endl;
	cout << "Favourite Animal: ";getline(read,this->fvtAnimal); cout << this->fvtAnimal << endl;
	read.close();

	cout << endl << endl;
	string end;
	cout << "Press 1 to LOG OUT!" << endl;
	getline(cin, end);
	while (end != "1")
	{
		cout << "INVALID MOVE!" << endl;
		cout << "Press 1 to LOG OUT!:" << endl;
		getline(cin, end);
	}
	return end;
}


void UserInfo::setPassword(string s) {

	this->password = s;

}

void UserInfo::setCash(long int s) {

	this->cash = s;

}

void UserInfo::setName(string s) {

	this->name = s;

}

void UserInfo::setFatherName(string s) {

	this->fatherName = s;

}
void UserInfo::setContact(string s) {

	this->contact = s;

}

void UserInfo::setGender(string s) {

	this->gender = s;

}

void UserInfo::setColor(string s) {

	this->fvtColor = s;

}

void UserInfo::setNumber(string s) {

	this->fvtNumber = s;

}

void UserInfo::setAnimal(string s) {

	this->fvtAnimal = s;

}

string UserInfo::getName() {

	return this->name;

}

string UserInfo::getFathername() {

	return this->fatherName;

}

string UserInfo::getContact() {

	return this->contact;

}

string UserInfo::getGender() {

	return this->gender;

}

string UserInfo::getPassword() {

	return this->password;

}

long int UserInfo::getCash() {

	return this->cash;

}

string UserInfo::getFvtColor() {

	return this->fvtColor;

}

string UserInfo::getFvtAnimal() {

	return this->fvtAnimal;

}

string UserInfo::getFvtNumber() {

	return this->fvtNumber;

}
string UserInfo::to_lower(string s) {

	string final = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (int(s[i]) != 32)  //excluding space
			final += tolower(s[i]);

	}
	return final;
}

bool UserInfo::validate_password(string pass) {

	//PIN must be of 4 digits. If it is not of 4 digits, password is not valid
	if (pass.length() != 4)
		return false;

	//given string must contain all the 4 numbers. if there is any characters
	//except numbers, password is nt valid


	for (int i = 0; i < 4; i++)
	{
		if (!isdigit(pass[i]))
			return false;
	}


	return true;
}

bool UserInfo::isEqual(string s1, string s2) {

	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}

	return true;

}