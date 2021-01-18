#include "LogIn.h"
#include"Extra.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

LogIn::LogIn() {

	this->Pin = "";
	this->username = "";
}

void LogIn::setUsername(string s) {
	
	this->username = s;

}

void LogIn::setPIN(string s) {

	this->Pin = s;

}

string LogIn::getUsername() {

	return this->username;

}

string LogIn::getPIN() {

	return this->Pin;

}

string LogIn::to_lower(string s) {

	string final = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (int(s[i]) != 32)  //excluding space
			final += tolower(s[i]);

	}
	return final;
}

bool LogIn::validate_password(string pass) {

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

bool LogIn::isEqual(string s1, string s2) {

	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}

	return true;

}

bool LogIn::logIn() {

	cout << endl << "\t\t\t\t\t\tWELCOME TO USER ACCOUNT SYSTEM" << endl;
	cout << "***********************************************************************************************************************" << endl << endl;
	cout << "\t\t\t\t\t\t\tLOG IN" << endl;
	cout << "\t\t\t\t\t\t\t______" << endl << endl << endl;


	//taking username and PIN input from user.
	string tname,tPIN;
	cout << "Enter Username:  ";
	getline(cin, tname);
	tname = to_lower(tname);
	cout << "Enter PIN: ";
	My_Aesterick_Pin(tPIN);
	//getline(cin,tPIN);
	while (!validate_password(tPIN))
	{
		cout << "\nPlease Enter Valid 4 DIGIT PIN!" << endl;
		tPIN.clear();
		cout << "Enter PIN: "; 
		My_Aesterick_Pin(tPIN);
		cout << endl<<endl;
	}

	//now checking if such user exists or not
	//all the usernames and PINS are present in Customers file

	string username, PIN;
	ifstream file;
	file.open("customers.txt");
	while (!file.eof())
	{
		file >> username;
		file >> PIN;

		if (isEqual(username, tname) && isEqual(PIN, tPIN))
		{
			cout << "Congratulations! You are Succesfully Logged In!" << endl;
			this->setUsername(tname);
			this->setPIN(tPIN);

		

			return true;
		}
	}

	

	file.close();

	cout << "\nINVALID USERNAME OR PIN!" << endl;
	return false;

	cin.ignore();
}
