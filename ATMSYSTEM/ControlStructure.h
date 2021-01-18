#pragma once
#include<iostream>
using namespace std;
#ifndef CONTROLSTRUCTURE_H
#define CONTROLSTRUCTURE_H
class ControlStructure
{

	private:
		string choice;
		//long int cash;
	public:
		ControlStructure();
		string Execute();
		bool isEqual(string s1,string s2);

};

#endif

