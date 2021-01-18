#include "ControlStructure.h"
#include"Display.h"
#include"MainScreen.h"
#include"CashScreen.h"
#include"Account.h"
#include"NewAccount.h"
#include"LogIn.h"
#include"UserInfo.h"
#include "FastCash.h"
#include"Extra.h"
#include"ControlStruct2.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

ControlStructure::ControlStructure() {

	this->choice = "1";

}

bool ControlStructure::isEqual(string s1, string s2) {

	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}

	return true;

}


string ControlStructure::Execute() {

	Display* mainScreen = new MainScreen();
	this->choice = mainScreen->display();

	Display* cashScreen = new CashScreen();
	UserInfo obj;

	
	

	if (isEqual(choice,"1"))
	{
		
		//creating object of NewAccount
		NewAccount obj;
		obj.createNewAccount();
		//this->Execute();
		return "1";
	}
	else if (isEqual(choice, "2"))
	{
		LogIn obj1;
		bool flag=obj1.logIn();
		if (flag)
		{
			//NOW USER HAS BEEN LOGGED IN
			cout << endl << endl <<endl;
			cout << "\t\t\t\t\t\tYou Are Succesfully Logged In" << endl;
			cout << "\t\t\t\t\t\tWelcome " << obj1.getUsername() << endl << endl;

			
			/* INFROMATION OF LOGGED IN ACCOUNT IS STORED IN THESE VARIABLES BELOW*/
			string name, fatherName, contact, gender, pin, scash, color, num, animal;
			ifstream read;
			read.open(obj1.getPIN().c_str());
			getline(read, name);
			getline(read, fatherName);
			getline(read, contact);
			getline(read, gender);
			getline(read, pin);
			getline(read, scash);
			getline(read, color);
			getline(read, num);
			getline(read, animal);
			read.close();
			long int cash = stoi(scash);
			/* INFROMATION OF LOGGED IN ACCOUNT IS STORED IN THESE VARIABLES BELOW*/

			//cout << scash << endl;
			 
			//NOW SHOWING CASH SCREEN
			string choice=cashScreen->display();
			ControlStruct2 control;
			control.setCash(cash);
			control.setPIN(pin);
			control.Execute(choice);
			while (choice != "6")
			{
				choice = cashScreen->display();
				control.setCash(control.getCash());
				control.setPIN(pin);
				control.Execute(choice);
				//cin.ignore();
			}

			
			
			
			
		}
		
		//this->Execute();
		return "2";
	}
	else if (isEqual(choice, "3"))
	{
		string temp=obj.displayUserInfo();
		//if (temp == "1")
			//this->Execute();
		return "3";

	}
	else if (isEqual(choice, "4"))
	{
		string username;
		cout << "Enter Your Username:  ";
		getline(cin, username); username = obj.to_lower(username);

		//checking if this username exists or not
		bool isUserExists = false;

		ifstream checkUser; string tempUser, tempPass;
		checkUser.open("customers.txt");
		while (!checkUser.eof())
		{
			getline(checkUser, tempUser);
			getline(checkUser, tempPass);
			if (obj.isEqual(tempUser, username))
			{
				isUserExists = true;
			}
			if (isUserExists)
				break;
		}
		checkUser.close();

		if (!isUserExists)
		{
			cout << "User Not Found!" << endl;
			return "4";
		}

		//now reading data from his old file
		string fName, checkFather, checkContact, checkGender, checkPass, checkAmount, checkColor, checkNumber, checkAnimal;
		ifstream oldFile;
		oldFile.open(tempPass.c_str());
		
			
				getline(oldFile, fName);  
				getline(oldFile, checkFather); 
				getline(oldFile, checkContact);
				getline(oldFile, checkGender);
				getline(oldFile, checkPass);
				getline(oldFile, checkAmount);
				getline(oldFile, checkColor);
				getline(oldFile, checkNumber);
				getline(oldFile, checkAnimal);
			

			
		
		oldFile.close();

		//now asking user his security questions
		string sColor, sNum, sAnimal;
		cout << "Enter Your Favourite Colour:  ";
		getline(cin, sColor); sColor = obj.to_lower(sColor);
		cout << "Enter Your Favourite Number:  ";
		getline(cin, sNum);
		cout << "Enter your Favourite Animal:  ";
		getline(cin, sAnimal); sAnimal = obj.to_lower(sAnimal);

		string newPIN;
		//now check if these answers are true or not
		if (obj.isEqual(sColor, checkColor) && obj.isEqual(sNum, checkNumber) && obj.isEqual(sAnimal, checkAnimal))
		{
			cout << "INFORMATION MATCHED!" << endl << endl;
			cout << "ENTER YOUR NEW PIN:  ";
			My_Aesterick_Pin(newPIN); cout << endl;
			//getline(cin, newPIN);
			while (!obj.validate_password(newPIN))
			{
				cout << "Please Enter VALID 4 DIGIT PIN!" << endl;   
				cout << "ENTER YOUR NEW PIN:  ";  newPIN.clear();
				My_Aesterick_Pin(newPIN); cout << endl << endl;
			}

			//now deleting old file
			remove(tempPass.c_str());

			//creating new file of this user with new PIN
			cout << fName << endl;
			ofstream newUser;
			newUser.open(newPIN.c_str());
			newUser << fName << endl;
			newUser << checkFather << endl;
			newUser << checkContact << endl; 
			newUser << checkGender << endl;
			newUser << newPIN << endl;   //new PIN
			newUser << checkAmount << endl;
			newUser << checkColor << endl;
			newUser << checkNumber << endl;
			newUser << checkAnimal <<endl;
			newUser.close();


			//now changing PIN in CUSTOMERS file too
			string tempString[5000];int index = 0;
			ifstream  customers;
			customers.open("customers.txt");
			while (!customers.eof())
			{
				getline(customers, tempString[index]); index++;
			}
			customers.close();

			ofstream newCustomers;
			newCustomers.open("customers.txt");
			int counter = 0;
			while (counter < index)
			{
				newCustomers << tempString[counter] << endl;
				if (isEqual(tempString[counter], username))
				{
					newCustomers << newPIN << endl;
					for (int p = counter + 1; p < index - 1; p++)
					{
						tempString[p] = tempString[p + 1];
					}
					index--;
				}
				counter++;
			}
			newCustomers.close();

			cout << "Congratulations!Your PIN Has Been Changed!" << endl << endl;
			return "4";
		}
		else
		{
			cout << "INFORMATION NOT MATCHED!" << endl << endl;
			return "4";
		}
	}
	else if (isEqual(choice, "5"))
	{
		bool PINchanged = false;
		string username, oldPIN;
		cout << "Enter Your Username:  ";
		getline(cin, username);
		username = obj.to_lower(username);
		//checking if this username exists or not using customers file.
		ifstream checkUsername; string trash; bool isNamePresent = false;
		checkUsername.open("customers.txt");
		while (!checkUsername.eof())
		{
			getline(checkUsername, trash);
			if (obj.isEqual(trash, username))
			{
				isNamePresent = true;
				break;
			}
		}
		checkUsername.close();


		cout << "Enter OLD PIN: ";
		My_Aesterick_Pin(oldPIN); cout << endl;
		//getline(cin, oldPIN);
		while (!obj.validate_password(oldPIN))
		{
			cout << "\nPlease Enter VALID 4 DIGIT PIN" << endl;
			cout << "Enter OLD PIN: ";   oldPIN.clear();
			getline(cin, oldPIN);
			cout << endl << endl;
		}

		//opening file of given PIN
		string checkName, checkFather, checkContact, checkGender, checkPass, checkAmount, checkColor, checkNumber, checkAnimal;
		ifstream oldFile;
		oldFile.open(oldPIN.c_str());
		if (oldFile && isNamePresent)
		{
			
				getline(oldFile, checkName);
				getline(oldFile, checkFather);
				getline(oldFile, checkContact);
				getline(oldFile, checkGender);
				getline(oldFile, checkPass);
				getline(oldFile, checkAmount);
				getline(oldFile, checkColor);
				getline(oldFile, checkNumber);
				getline(oldFile, checkAnimal);
			
			

			//creating new file of new PIN
			string newPIN;
			cout << "\n\nPIN MATCHED!" << endl << endl;
			cout << "Enter your new PIN: ";
			My_Aesterick_Pin(newPIN); cout << endl;
			//getline(cin, newPIN);
			while (!obj.validate_password(newPIN))
			{
				cout << "\nPlease Enter VALID 4 DIGIT PIN" << endl;
				cout << "Enter your new PIN: ";    newPIN.clear();
				My_Aesterick_Pin(newPIN);  cout << endl << endl;
			}

			//creating new file of this PIN(customer)
			ofstream newFile;

			newFile.open(newPIN.c_str());
			newFile << checkName << endl;
			newFile << checkFather << endl;
			newFile << checkContact << endl;
			newFile << checkGender << endl;
			newFile << newPIN << endl;   //new PIN
			newFile << checkAmount << endl;
			newFile << checkColor << endl;
			newFile << checkNumber << endl;
			newFile << checkAnimal << endl;

			newFile.close();


			//now changing PIN in CUSTOMERS file too
			string tempString[5000];int index = 0;
			ifstream  customers;
			customers.open("customers.txt");
			while (!customers.eof())
			{
				getline(customers, tempString[index]); index++;
			}
			customers.close();

			ofstream newCustomers;
			newCustomers.open("customers.txt");
			int counter = 0;
			while (counter < index)
			{
				newCustomers << tempString[counter] << endl;
				if (isEqual(tempString[counter], username))
				{
					newCustomers << newPIN << endl;
					for (int p = counter + 1; p < index - 1; p++)
					{
						tempString[p] = tempString[p + 1];
					}
					index--;
				}
				counter++;
			}
			newCustomers.close();

			cout << "Your PIN Has Been Changed Successfully!" << endl;
			PINchanged = true;
		}
		else
		{
			cout << "User Does Not Exist!" << endl << endl ;
			//this->Execute();
		}
		oldFile.close();
		if (PINchanged)
		{
			//removing old file
			remove(oldPIN.c_str());
		}
		return "5";
	}

	else if (obj.isEqual(choice, "6"))
	{

		cout << endl << endl;
		cout << "\t\t\t\t\t\tTHANK YOU FOR VISITING US!" << endl ;
		cout << "***********************************************************************************************************************" << endl;
		cout << "\t\t\t\t\t\tHAVE A NICE DAY!" << endl << endl;
		return "6" ;
	}
}
