/********
 Author: Professor Wooster
 Program: test program for Money class
 Due Date:
 Time Spent:
 Purpose: provide a test driver for the Money class of program assignment #1
 Accomplishments: provide a test driver program for my C++ students to be able to test their first program assignment
 ********/

#include <iostream>
#include <string>
#include "money.h"

using namespace std;

int main(int argv, char **argc)
{
    string command;
    Money money;
    //
    // read each command and call the appropriate Money method
    //
    cin >> command;
    while (!cin.eof()) {
        //
        // based on the value read into command, call a Money method
        //
        if (command.compare("change") == 0)
            cout << money.processChange() << endl;
        else if (command.compare("float") == 0)
            cout << money.processFloat();
        else if (command.compare("check") == 0)
            cout << money.processCheck();
        else if (command.compare("change-float") == 0)
            cout << money.processChangeFloat();
        else if (command.compare("change-change") == 0)
            cout << money.processChangeChange();
        else {
            cout << "invalid command: " + command;
            return 1;
        } 
        cin >> command;
    }
}
