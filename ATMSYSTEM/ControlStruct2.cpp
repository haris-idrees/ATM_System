#include "ControlStruct2.h"
#include"FastCash.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

ControlStruct2::ControlStruct2() {

	this->cash = 0;

}

bool ControlStruct2::isEqual(string s1, string s2) {

	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}

	return true;

}

void ControlStruct2::updateFile(string fileName, long int newCash) {

	//opening file and storing data in temporary variables
	string name, fName, contact, gender, PIN, cash, color, num, animal;
	ifstream file;
	file.open(fileName.c_str());
	getline(file, name);
	getline(file, fName);
	getline(file, contact);
	getline(file, gender);
	getline(file, PIN);
	getline(file, cash);
	getline(file, color);
	getline(file, num);
	getline(file, animal);
	file.close();

	//removing this file
	remove(fileName.c_str());

	//making new file of same name
	ofstream newFile;
	newFile.open(fileName.c_str());
	newFile << name << endl;
	newFile << fName << endl;
	newFile << contact << endl;
	newFile << gender << endl;
	newFile << PIN << endl;
	newFile << newCash << endl;
	newFile << color << endl;
	newFile << num << endl;
	newFile << animal << endl;
	newFile.close();


}

void ControlStruct2::setPIN(string PIN) {

	this->PIN = PIN;

}

string ControlStruct2::getPIN() {

	return this->PIN;

}

void ControlStruct2::Execute(string choice) {

	if (isEqual(choice, "1"))
	{
		//--------------------------FAST CASH WITHDRAWAL-------------------------------------//

		FastCash fastCash;
		fastCash.setCash(this->cash);
		fastCash.Subtract();
		this->cash = fastCash.getCash();

		//now updating the file
		this->updateFile(this->getPIN().c_str(),this->cash);
		

	}
	else if (isEqual(choice, "2"))
	{

		//------------------------CASH WITHDRAWAL-----------------------------------------//

		long int amount; int count = 0;
		do
		{
			if (count != 0)
				cout << "Please Enter Valid Amount:";
			cout << "\n\nEnter Amount You Want To Withdraw: ";
			cin >> amount; count++;
			cin.ignore();
		} while (amount < 0);

		//checking if this amount is present in user's account or not
		if (amount <= this->cash)
		{
			cout << "Rs. " << amount << " Has Been Withrawn From Your Account!" << endl;
			this->cash -= amount;

			//updating file too
			this->updateFile(PIN.c_str(),this->cash);

			if (amount >= 1000)
			{
				cout << "\n\nYOU CAN HAVE NUMBER OF NOTES OF 50: " << amount / 50 << endl;
				cout << "YOU CAN HAVE NUMBER OF NOTES OF 100: " << amount / 100 << endl;
				cout << "YOU CAN HAVE NUMBER OF NOTES OF 1000: " << amount / 1000 << endl;
				cout << "THANK YOU!" << endl << endl;
			}

			//adding data in statement file
			ofstream myFile("statement.txt", ios::app);
			myFile << "Rs. " << amount << " was withdrwan from your account on 11/01/21" << endl;
			myFile << endl << endl;
			myFile.close();

		}
		else
			cout << "BALANCE TOO LOW FOR THIS INQUIRY!!" << endl << endl;
		

	}
	else if (isEqual(choice, "3"))
	{

		//----------------------------------BALANCE INQUIRY---------------------------------//

		cout << "\n\nYOUR CURRENT BALANCE IS:" << this->cash << endl <<endl ;

	}
	else if (isEqual(choice, "4"))
	{

		//----------------------------------MINI STATMENT----------------------------------//

		ifstream miniStatement;
		miniStatement.open("statement.txt");
		int counter = 0;
		while (miniStatement.eof() == false)
		{
			if (counter != 11)
			{
				string temp;
				getline(miniStatement, temp);
				cout << temp << endl;
				counter++;
			}
			else
				break;
		}
		miniStatement.close();

	}

	else if (isEqual(choice, "5"))
	{

		//-------------------------------PAYMENTS------------------------------------------//
		long int amount;
		string ref_no;
		string option = "0";

		do
		{
			cout << "Which bill do you want to pay? \n";
			cout << "A.Electricity\n";
			cout << "B.Water\n";
			cout << "C.Telephone\n";
			cout << "D.Sui gas\n";
			cout << "E.None.\n";
			cout << endl << endl;

			cout << "Enter Your Choice: ";
			getline(cin, option);

			//ELECTRICITY BILL
			if (isEqual(option, "A"))
			{
				cout << "ENTER THE REFERENCE NUMBER: ";
				getline(cin, ref_no);
				cout << "ENTER AMOUNT OF YOUR BILL: ";
				cin >> amount;
				if (amount >= this->cash)
				{
					cout<<"Oopss!!You do not have that much cash in your account." << endl;
				}
				else
				{
					this->cash -= amount;
					//updating in file too
					this->updateFile(this->getPIN().c_str(), this->cash);

					cout << "Rs. " << amount << " Has Been Subtracted From Your Account!" << endl << endl;

					//storing for statement file
					ofstream statement;
					statement.open("statement.txt",ios::app);
					statement << "Rs. " << amount << " Was Removed From Your Account Against Your Electricity Bill Reference Number: " << ref_no  << endl;
					statement.close();

					cin.ignore();
				}
			}

			//WATER BILL
			else if (isEqual(option, "B"))
			{
				cout << "ENTER THE REFERENCE NUMBER: ";
				getline(cin, ref_no);
				cout << "ENTER AMOUNT OF YOUR BILL: ";
				cin >> amount;
				if (amount >= this->cash)
				{
					cout << "Oopss!!You do not have that much cash in your account." << endl;
				}
				else
				{
					this->cash -= amount;
					//updating in file too
					this->updateFile(this->getPIN().c_str(), this->cash);

					cout << "Rs. " << amount << " Has Been Subtracted From Your Account!" << endl << endl;

					//storing for statement file
					ofstream statement;
					statement.open("statement.txt", ios::app);
					statement << "Rs. " << amount << " Was Removed From Your Account Against Your Water Bill Reference Number: " << ref_no << endl;
					statement.close();

					cin.ignore();
				}
			}
			//TELEPHONE BILL
			else if (isEqual(option, "C"))
			{
				cout << "ENTER THE REFERENCE NUMBER: ";
				getline(cin, ref_no);
				cout << "ENTER AMOUNT OF YOUR BILL: ";
				cin >> amount;
				if (amount >= this->cash)
				{
					cout << "Oopss!!You do not have that much cash in your account." << endl;
				}
				else
				{
					this->cash -= amount;
					//updating in file too
					this->updateFile(this->getPIN().c_str(), this->cash);

					cout << "Rs. " << amount << " Has Been Subtracted From Your Account!" << endl << endl;

					//storing for statement file
					ofstream statement;
					statement.open("statement.txt", ios::app);
					statement << "Rs. " << amount << " Was Removed From Your Account Against Your Telephone Bill Reference Number: " << ref_no << endl;
					statement.close();

					cin.ignore();
				}
			}
			//SUI GAS BILL
			else if (isEqual(option, "D"))
			{
				cout << "ENTER THE REFERENCE NUMBER: ";
				getline(cin, ref_no);
				cout << "ENTER AMOUNT OF YOUR BILL: ";
				cin >> amount;
				if (amount >= this->cash)
				{
					cout << "Oopss!!You do not have that much cash in your account." << endl;
				}
				else
				{
					this->cash -= amount;
					//updating in file too
					this->updateFile(this->getPIN().c_str(), this->cash);

					cout << "Rs. " << amount << " Has Been Subtracted From Your Account!" << endl << endl;

					//storing for statement file
					ofstream statement;
					statement.open("statement.txt", ios::app);
					statement << "Rs. " << amount << " Was Removed From Your Account Against Your Sui Gas Bill Reference Number: " << ref_no << endl;
					statement.close();

					cin.ignore();
				}
			}

		} while (!isEqual(option, "E"));
	}
	//Other Services
	else if (isEqual(choice, "6"))
	{

		//--------------------------------OTHER SERVICES---------------------------------//
		string option;
		long int amount;
		do
		{
			cout << "\t\t\tOTHER SERVICES\t\t\t" << endl;
			cout << endl << endl;
			cout << "Choose the service you want: " << endl;
			cout << "1.SMS Alert" << endl;
			cout << "2.Bus Tickets" << endl;
			cout << "3.Add Amount" << endl;
			cout << "4.Exit" << endl;

			cout << "Enter Your Choice: ";
			getline(cin, option);

			//SMS Alert
			if (isEqual(option, "1"))
			{
				amount = 200;
				if (amount >= this->cash)
				{
					cout << "Oopss!!You do not have that much cash in your account." << endl;
				}
				else
				{
					this->cash -= amount;
					//updating in file too
					this->updateFile(this->getPIN().c_str(), this->cash);

					cout << "SMS Alert Has Been Activated On Your Account for Rs." << amount << endl << endl;

					//storing for statement file
					ofstream statement;
					statement.open("statement.txt", ios::app);
					statement << "Rs. " << amount << " Was Removed From Your Account For SMS Alert " << endl;
					statement.close();

					cin.ignore();
				}
			}

			//Bus Tickets
			else if (isEqual(option, "2"))
			{
				cout << "\t\t\t\tTICKET BOOKING\t\t\t" << endl << endl;
				string opt;
				do
				{
					cout << "Select the ticket you want to book: \n";
					cout << "1.Daewoo\n";
					cout << "2.SkyWays\n";
					cout << "3.Bilal Travels\n";
					cout << "4.Nadir\n";
					cout << "5.None.\n";

					cout << endl << endl;
					cout << "Enter Your Choice: " << endl;
					cin >> opt;

					//DAEWOO
					if (isEqual(opt, "1"))
					{
						int count;
						cout << "\t\t\tDAEWOO TICKETS\t\t\t" << endl << endl;

						cout << "Enter Number Of Tickets You Want To Book: ";
						cin >> count;
						while (count <= 0)
						{
							cout << "Enter a valid number." << endl;
							cout << "Enter the number of Tickets: ";
							cin >> count;
						}
						amount = 610 * count;
						if (amount >= this->cash)
						{
							cout << "Oopss!!You do not have that much cash in your account." << endl;
						}
						else
						{
							this->cash -= amount;
							//updating in file too
							this->updateFile(this->getPIN().c_str(), this->cash);

							cout << "Tickets Confirmed for Rs." << amount << endl << endl;

							//storing for statement file
							ofstream statement;
							statement.open("statement.txt", ios::app);
							statement << "Rs. " << amount << " Was Removed From Your Account For Booking Bus Tickets " << endl;
							statement.close();

							cin.ignore();
						}
					}

					//SKYWAYS
					else if (isEqual(opt, "2"))
					{
						int count;
						cout << "\t\t\tSKYWAYS TICKETS\t\t\t" << endl << endl;

						cout << "Enter Number Of Tickets You Want To Book: ";
						cin >> count;
						while (count <= 0)
						{
							cout << "Enter a valid number." << endl;
							cout << "Enter the number of Tickets: ";
							cin >> count;
						}
						amount = 580 * count;
						if (amount >= this->cash)
						{
							cout << "Oopss!!You do not have that much cash in your account." << endl;
						}
						else
						{
							this->cash -= amount;
							//updating in file too
							this->updateFile(this->getPIN().c_str(), this->cash);

							cout << "Tickets Confirmed for Rs." << amount << endl << endl;

							//storing for statement file
							ofstream statement;
							statement.open("statement.txt", ios::app);
							statement << "Rs. " << amount << " Was Removed From Your Account For Booking Bus Tickets " << endl;
							statement.close();

							cin.ignore();
						}
					}

					//BILAL TRAVELS
					else if (isEqual(opt, "3"))
					{
						int count;
						cout << "\t\t\tBILAL TRAVELS\t\t\t" << endl << endl;
						cout << "Enter Number Of Tickets You Want To Book: ";
						cin >> count;
						while (count <= 0)
						{
							cout << "Enter a valid number." << endl;
							cout << "Enter the number of Tickets: ";
							cin >> count;
						}
						amount = 550 * count;
						if (amount >= this->cash)
						{
							cout << "Oopss!!You do not have that much cash in your account." << endl;
						}
						else
						{
							this->cash -= amount;
							//updating in file too
							this->updateFile(this->getPIN().c_str(), this->cash);

							cout << "Tickets Confirmed for Rs." << amount << endl << endl;

							//storing for statement file
							ofstream statement;
							statement.open("statement.txt", ios::app);
							statement << "Rs. " << amount << " Was Removed From Your Account For Booking Bus Tickets " << endl;
							statement.close();

							cin.ignore();
						}
					}

					//	Nadir travles
					else if (isEqual(opt, "4"))
					{
						int count;
						cout << "\t\t\tNADIR TRAVELS\t\t\t" << endl << endl;
						cout << "Enter Number Of Tickets You Want To Book: ";
						cin >> count;
						while (count < 0)
						{
							cout << "Enter a valid number." << endl;
							cout << "Enter the number of Tickets: ";
							cin >> count;
						}
						amount = 520 * count;
						if (amount >= this->cash)
						{
							cout << "Oopss!!You do not have that much cash in your account." << endl;
						}
						else
						{
							this->cash -= amount;
							//updating in file too
							this->updateFile(this->getPIN().c_str(), this->cash);

							cout << "Tickets Confirmed for Rs." << amount << endl << endl;

							//storing for statement file
							ofstream statement;
							statement.open("statement.txt", ios::app);
							statement << "Rs. " << amount << " Was Removed From Your Account For Booking Bus Tickets " << endl;
							statement.close();

							cin.ignore();
						}
					}

					//log out
					else if (isEqual(opt, "5"))
					{

					}

				} while (!isEqual(opt, "5"));
				
			}

			//ADD AMOUNT
			else if (isEqual(option, "3"))
			{
				long int amount;
				cout << "ENTER AMOUNT YOU WANT TO ADD: ";
				cin >> amount;
				while (amount <= 0)
				{
					cout << "Please Enter Valid Amount!" << endl << endl;
					cout << "\n\nENTER AMOUNT YOU WANT TO ADD: ";
					cin >> amount;
				}

				cout << endl << endl << "Please Insert The Cash In The Box On Your Left" << endl;
				this->cash += amount;

				//updating in file too
				this->updateFile(this->getPIN().c_str(), this->cash);

				cout << "Rs. " << amount << " Has Been Added To Your Account!" << endl << endl;

				//storing for statement file
				ofstream statement;
				statement.open("statement.txt",ios::app);
				statement << "Rs. " << amount << " Has Been Added To Your Account!" << endl;
				statement.close();
			}
			//logout
			else if (isEqual(option, "4"))
			{
				//log out
			}


		} while (!isEqual(option, "4"));

	}
	else if (isEqual(choice, "7"))
	{
		//logout
	}


}


void ControlStruct2::setCash(long int cash) {

	this->cash = cash;

}

long int ControlStruct2::getCash() {

	return this->cash;

}
