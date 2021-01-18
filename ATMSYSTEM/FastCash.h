#pragma once
#include<iostream>
using namespace std;
class FastCash
{
	long int cash;
	public:
		FastCash();
		void Subtract();
		void setCash(long int s);
		bool isEqual(string s1, string s2);
		long int getCash();
};

