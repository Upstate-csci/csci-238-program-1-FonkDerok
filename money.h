/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;
class Money
{
private:
    double total;
    int hundreds, tens, fives, ones, quarters, dimes, nickels, cents;
public:
    string toString();
    string toCurrency(double amount);
    string processChange();
    string processFloat();
    string processCheck();
    string processChangeFloat();
    string processChangeChange();
};
#endif
