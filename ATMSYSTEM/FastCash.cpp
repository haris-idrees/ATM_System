#include<iostream>
#include<fstream>
#include"FastCash.h"
//#include"Withdraw.h"

using namespace std;

FastCash::FastCash() {
	this->cash = 0;
}



void FastCash::setCash(long int s){
	this->cash = s;
}

bool FastCash::isEqual(string s1, string s2) {

	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}

	return true;

}

long int FastCash::getCash() {
	return this->cash;
}

void FastCash::Subtract()
{
	long int amount, withdrawCash;
	
	
	string choice="0";
	do
	{
		cout << "\n\nSelect the amount you want to withdraw from your account: \n";
		cout << "1.20000                                           2.15000" << endl;
		cout << "3.10000                                           4.5000" << endl;
		cout << "5.2000                                            6.500" << endl;

		cout << endl;
		cout << "Enter your choice: ";
		cin >> choice;
	} while (choice!="1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6");


	
	

	if (isEqual(choice, "1"))
	{
		if (this->cash < 20000)
		{
			cout << "Oopss!! You do not have that much cash in your account." << endl;
		}
		else {
			amount = 20000;
			this->cash = this->cash - amount;
			cout << "Rs. 20000 has been withdrawn from your account.\n";
			ofstream myFile("statement.txt",ios::app);
			myFile << "Rs. " << amount << " was withdrwan from your account on 11/01/21" << endl;
			//myFile << endl << endl;
			myFile.close();
		}
	}
		
	else if (isEqual(choice, "2"))
	{
		if (this->cash < 15000)
		{
			cout << "Oopss!! You do not have that much cash in your account." << endl;
		}
		else {
			amount = 15000;
			this->cash -= amount;
			cout << "Rs. 15000 has been withdrawn from your account.\n";
			ofstream myFile("statement.txt", ios::app);
			myFile << "Rs. " << amount << " was withdrwan from your account on 11/01/21" << endl;
			//myFile << endl << endl;
			myFile.close();
		}
	}
		
	else if (isEqual(choice, "3"))
	{
		if (this->cash < 10000)
		{
			cout << "Oopss!! You do not have that much cash in your account." << endl;
		}
		else {
			amount = 10000;
			this->cash -= amount;
			cout << "Rs. 10000 has been withdrawn from your account.\n";
			ofstream myFile("statement.txt", ios::app);
			myFile << "Rs. " << amount << " was withdrwan from your account on 11/01/21" << endl;
			//myFile << endl << endl;
			myFile.close();
		}
	}
	else if (isEqual(choice, "4"))
	{
		if (this->cash < 5000)
		{
			cout << "Oopss!! You do not have that much cash in your account." << endl;
		}
		else {
			amount = 5000;
			this->cash -= amount;
			cout << "Rs. 5000 has been withdrawn from your account.\n";
			ofstream myFile("statement.txt", ios::app);
			myFile << "Rs. " << amount << " was withdrwan from your account on 11/01/21" << endl;
			//myFile << endl << endl;
			myFile.close();
		}
	}
	else if (isEqual(choice, "5"))
	{
		if (cash < 2000)
		{
			cout << "Oopss!! You do not have that much cash in your account." << endl;
		}
		else {
			amount = 2000;
			this->cash -= amount;
			cout << "Rs. 2000 has been withdrawn from your account.\n";
			ofstream myFile("statement.txt", ios::app);
			myFile << "Rs. " << amount << " was withdrwan from your account on 11/01/21" << endl;
			//myFile << endl << endl;
			myFile.close();
		}
	}
	else if (isEqual(choice, "6"))
	{
		if (this->cash < 500)
		{
			cout << "Oopss!! You do not have that much cash in your account." << endl;
		}
		else {
			amount = 500;
			this->cash -= amount;
			cout << "Rs. 500 has been withdrawn from your account.\n";
			ofstream myFile("statement.txt", ios::app);
			myFile << "Rs. " << amount << " was withdrawn from your account on 11/01/21" << endl;
			myFile.close();
		}
	}
	cin.ignore();
}