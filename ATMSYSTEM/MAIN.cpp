#include<iostream>
#include"Display.h"
#include"CashScreen.h"
#include"MainScreen.h"
#include"NewAccount.h"
#include"LogIn.h"
#include"UserInfo.h"
#include<fstream>
#include<string>
#include"ControlStructure.h"
#include<time.h>
#include<cmath>
using namespace std;



bool isEqual(string s1, string s2) {

	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}

	return true;

}


int main()
{
	
	ControlStructure obj;
	string exit=obj.Execute();
	while (!isEqual(exit, "6"))
	{
		
		exit = obj.Execute();
		//cin.ignore();
	}



	

	return  0;
	
}