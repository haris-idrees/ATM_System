#pragma once
#ifndef NEWACOUNT_H
#define NEWACOUNT_H
#include "Account.h"
class NewAccount:public Account
    //public Account
{

    public:
        NewAccount();
        bool isEqual(string s1, string s2);
        bool validatePassword(string pass);
        string to_lower(string s);
        void createNewAccount();


};


#endif

