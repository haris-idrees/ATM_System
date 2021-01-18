#include "NewAccount.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Extra.h"
using namespace std;

NewAccount::NewAccount() :Account() {



}

bool NewAccount::isEqual(string s1, string s2) {

	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}

	return true;

}

string NewAccount::to_lower(string s) {

	string final = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (int(s[i]) != 32)  //excluding space
			final += tolower(s[i]);

	}
	return final;
}

bool NewAccount::validatePassword(string pass) {

	//PIN must be of 4 digits. If it is not of 4 digits, password is not valid
	//cout << pass.length()<<endl;
	if (pass.length() != 4)
		return false;

	//given string must contain all the 4 numbers. if there is any characters
	//except numbers, password is not valid


	for (int i = 0; i < 4; i++)
	{
		if (!isdigit(pass[i]))
			return false;
	}

	return true;

}

void NewAccount::createNewAccount() {

	//cin.ignore();
	//taking input from user
	cout << endl << "\t\t\t\t\t\tWELCOME TO USER ACCOUNT SYSTEM" << endl;
	cout << "***********************************************************************************************************************" << endl << endl;
	cout << "\t\t\t\t\t\t\tNEW ACCOUNT" << endl;
	cout << "\t\t\t\t\t\t\t___________" << endl << endl << endl;

	string tname, tfatherName, tcontact, tpassword, tcpass, tfvtColor, tfvtNumber, tfvtAnimal;
	string tgender; long int tcash;

	cout << "Enter Your Name: ";
	getline(cin, tname);
	//cin.ignore();

	cout << "Enter Your Father's Name:  ";
	getline(cin, tfatherName);
	//cin.ignore();

	cout << "Enter Your Phone Number:  ";
	getline(cin, tcontact);
	//cin.ignore();

	cout << "Enter Your Gender(M/F):  ";
	getline(cin, tgender);
	//cin.ignore();

	cout << "Enter 4 digit PIN(Password):  ";
	My_Aesterick_Pin(tpassword);
	// getline(cin, tpassword);
	while (!validatePassword(tpassword))
	{
		cout << "\nEnter Valid 4 Digit PIN!" << endl;
		cout << "Enter 4 digit PIN(Password):  ";
		tpassword.clear();
		My_Aesterick_Pin(tpassword); cout << endl;
		//getline(cin,tpassword); cout << endl;
	}

	cout << "\nRe-Enter Your PIN(Password):  ";
	//getline(cin, tcpass);
	My_Aesterick_Pin(tcpass);
	while (!validatePassword(tcpass))
	{
		cout << "\nEnter Valid 4 Digit PIN!" << endl;
		cout << "\nRe-Enter 4 digit PIN(Password):  ";
		tcpass.clear();
		My_Aesterick_Pin(tcpass); cout << endl;
		//getline(cin,tcpass); cout << endl;
	}

	//checking if password and confirm password is same or not
	while (!isEqual(tpassword, tcpass))
	{
		cout << "\n\nYour Passwords Do Not Match!" << endl << endl;
		tpassword.clear(); tcpass.clear();
		cout << "Enter 4 digit PIN(Password):  ";
		My_Aesterick_Pin(tpassword);
		// getline(cin, tpassword);
		while (!validatePassword(tpassword))
		{
			cout << "\nEnter Valid 4 Digit PIN!" << endl;
			cout << "\nEnter 4 digit PIN(Password):  ";
			tpassword.clear();
			My_Aesterick_Pin(tpassword); cout << endl;
			//getline(cin,tpassword); cout << endl;
		}
		
		cout << "\nRe-Enter Your PIN(Password):  ";
		//getline(cin, tcpass);
		My_Aesterick_Pin(tcpass);
		while (!validatePassword(tcpass))
		{
			cout << "\nEnter Valid 4 Digit PIN!" << endl;
			cout << "\nRe-Enter 4 digit PIN(Password):  ";
			tcpass.clear();
			My_Aesterick_Pin(tcpass); cout << endl;
			//getline(cin,tcpass); cout << endl;
		}
		
		cout << endl << endl;
	}

	cout << "\nYou Need To Add ATLEAST RS.500/ For Creating a new Account!" << endl;
	cout << "Enter Amount You Want To Add In Your Account:  ";
	cin >> tcash;
	while (tcash < 500)
	{
		cout << "Please Enter Valid Amount Of Cash!" << endl;
		cout << "\nYou Need To Add ATLEAST RS.500/ For Creating a new Account!" << endl;
		cout << "Enter Amount You Want To Add In Your Account:  ";
		cin >> tcash; cout << endl;
	}

	cin.ignore();
	cout << "Enter Your Favourite Colour:  ";
	getline(cin, tfvtColor);
	tfvtColor = this->to_lower(tfvtColor);
	//cin.ignore();

	cout << "Enter Your Favourite Number:  ";
	getline(cin, tfvtNumber);
	//tfvtNumber = this->to_lower(tfvtNumber);
	//cin.ignore();

	cout << "Enter Your Favourite Animal:  ";
	getline(cin, tfvtAnimal);
	tfvtAnimal = this->to_lower(tfvtAnimal);
	//cin.ignore();

	this->name = to_lower(tname);
	this->fatherName = tfatherName;
	this->contact = tcontact;
	this->gender = tgender;
	this->password = tpassword;
	this->fvtColor = tfvtColor;
	this->fvtNumber = tfvtNumber;
	this->fvtAnimal = tfvtAnimal;
	this->cash = tcash;

	//retrieving number of acccounts in numOfAccount variable
	ifstream ifile;
	ifile.open("accounts.txt");
	ifile >> this->numOfAccounts;
	ifile.close();

	this->numOfAccounts++;

	//storing number of accounts in account file
	ofstream accounts;
	accounts.open("accounts.txt");
	accounts << this->numOfAccounts << endl;
	accounts.close();

	ofstream ofile;
	ofile.open("customers.txt", ios::app);


	ofile << this->name << endl;
	ofile << tpassword << endl;
	ofile.close();


	//creating file of new Customer
	ofstream file;
	file.open(tpassword.c_str());

	file << this->name << endl;
	file << tfatherName << endl;
	file << tcontact << endl;
	file << tgender << endl;
	file << tpassword << endl;
	file << tcash << endl;
	file << tfvtColor << endl;
	file << tfvtNumber << endl;
	file << tfvtAnimal << endl;


	file.close();

	cout << "\n\nCongratulations! Your New Account Has Been Created Successfully!" << endl << endl;

}
