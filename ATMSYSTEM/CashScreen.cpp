#include "CashScreen.h"
#include"Display.h"
#include<iostream>
#include<string>
using namespace std;

CashScreen::CashScreen() {



}

string CashScreen::display() {

	int  count = 0;
	string choice;

	do
	{

		cout << endl << "\t\t\t\t\t\tWELCOME TO USER ACCOUNT SYSTEM" << endl;
		cout << "***********************************************************************************************************************" << endl << endl;
		cout << "\t\t\t\t\t\t\tCASH SCREEN MENU (1-6)" << endl;
		cout << "\t\t\t\t\t\t\t_______________" << endl << endl << endl;

		if (count != 0)
			cout << "Enter Valid Choice!" << endl << endl;
		cout << "1: Fast Cash Withdrawal" << endl;
		cout << "2: Cash Withdrawal" << endl;
		cout << "3: Balance Inquiry" << endl;
		cout << "4: Mini Statement" << endl;
		cout << "5: Payments" << endl ;
		cout << "6: Other Services" << endl;
		cout << "7. Log Out" << endl << endl;
		cout << "Enter Your Choice(1-6):";
		getline(cin, choice);
		count++;
	} while (choice !="1" && choice !="2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "7");

	return choice;

}
