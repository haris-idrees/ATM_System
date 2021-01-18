#pragma once
#ifndef MAINSCREEN_H
#define MAINSCREEN_H
#include "Display.h"
#include<iostream>
using namespace std;
class MainScreen :
    public Display
{
public:
    MainScreen();
    virtual string display();
};




#endif

