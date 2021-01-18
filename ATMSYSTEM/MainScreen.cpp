#include "MainScreen.h"
#include<string>
#include<iostream>
using namespace std;

MainScreen::MainScreen() {



}

string MainScreen::display() {

	string choice;
	int count=0;
	
	do
	{

		cout << endl << "\t\t\t\t\t\tWELCOME TO USER ACCOUNT SYSTEM" << endl;
		cout << "***********************************************************************************************************************" << endl << endl;
		cout << "\t\t\t\t\t\t\tMAIN MENU (1-6)" << endl;
		cout << "\t\t\t\t\t\t\t_______________" << endl << endl << endl;

		if (count != 0)
			cout << "Enter Valid Choice!" << endl << endl;
		cout << "1: Create New Account" << endl;
		cout << "2: Log In" << endl;
		cout << "3: Check User Info" << endl;
		cout << "4: Forget Password" << endl;
		cout << "5: change Password" << endl;
		cout << "6: Exit ATM" << endl << endl;
		cout << "Enter Your Choice(1-6):";
		getline(cin, choice);
		count++;
	} while (choice !="1" && choice !="2" && choice != "3" && choice != "4" && choice != "5" && choice != "6");
	
	return choice;

}
