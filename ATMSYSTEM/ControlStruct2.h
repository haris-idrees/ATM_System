#pragma once
#include<iostream>
#include<string>
#ifndef CONTROLSTRUCT2
#define CONTROLSTRUCT2
using namespace std;
class ControlStruct2
{

	private:
		long int cash;
		string PIN;

	public:
		ControlStruct2();
		void Execute(string choice);

		bool isEqual(string s1, string s2);
		void updateFile(string fileName, long int newCash);
		void setCash(long int cash);
		void setPIN(string pin);
		string getPIN();
		long int getCash();

};



#endif

