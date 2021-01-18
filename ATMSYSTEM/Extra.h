#pragma once
#ifndef EXTRA_H
#define EXTRA_H

#include<string>
#include<conio.h>
#include<iostream>
#pragma warning( disable : 4996 )

using namespace std;

inline void My_Aesterick_Pin(string& Pin)
{
	char password = getch();
	while (password != '\r')
	{

		cout << "*";
		Pin = Pin + password;
		password = getch();

	}
}


#endif

