#pragma once
#ifndef CASHSCREEN_H
#define CASHSCREEN_H
#include "Display.h"
#include<iostream>
using namespace std;
class CashScreen :
    public Display
{
    public:
        CashScreen();
        string display();

};


#endif

