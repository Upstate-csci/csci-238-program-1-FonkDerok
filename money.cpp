/*************************************************\
* Author:   Ashton Little                         *
* Program:  Money class - program assignment #1   *
* Due Date: Feb 3, 2020                           *
* Purpose:  To do stuff and things to make change *
\*************************************************/
#include "money.h"

// All those numbers you type in? Confusing and unreadable. This output? In a string format and readable.
string Money::toString() {
    stringstream String;
    String << hundreds << " hundreds, " << tens << " tens, " << fives << " fives, " << ones << " ones, " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << cents << " pennies";
    return String.str();
}

// Takes your number and gives you something better (a string number w/ a $ and all that jazz)
string Money::toCurrency(double amount) {
    stringstream ss;
    ss.imbue(locale(""));

    ss << showbase << put_money(amount * 100);
    return ss.str();
}

// takes your confusing integers and crams them all together into a single number
string Money::processChange() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
    stringstream String;

    //forcefeeding the denominations into total hoping it doesn't explode
    total = hundreds * 100.0 + tens * 10.0 + fives * 5.0 + ones + quarters * 0.25 + dimes * 0.1 + nickels * 0.05 + cents * 0.01;
    String << toString() << " == " << toCurrency(total) << endl;
    return String.str();
}

// Wanna see the money stretched out in all the denominations? Give this thing a double
string Money::processFloat() {
    cin >> total;
    double ammount = total;
    stringstream String;

    //slicing and dicing ammount into denominations
    hundreds = ammount / 100;
    ammount -= hundreds * 100;
    tens = ammount / 10;
    ammount -= tens * 10;
    fives = ammount / 5;
    ammount -= fives * 5;
    ones = ammount;

    ammount = (ammount - ones) * 100;
    quarters = ammount / 25;
    ammount -= quarters * 25;
    dimes = ammount / 10;
    ammount -= dimes * 10;
    nickels = ammount / 5;
    ammount -= nickels * 5;
    cents = ammount;

    //double checking to fix some rounding error that shows up sometimes
    ammount = hundreds * 100.0 + tens * 10.0 + fives * 5.0 + ones + quarters * 0.25 + dimes * 0.1 + nickels * 0.05 + cents * 0.01;
    if (total - ammount != 0)
        cents++;

    String << toCurrency(total) << " = " << toString() << endl;

    return String.str();
}

//You thought processFloat was cool? Give this a double and it's ALL words
string Money::processCheck() {
    int dollars, change;
    int numbers [4];
    string words[4];
    stringstream String, otherString;
    cin >> total;

    //splitting up the dollars and change like a nasty divorce
    dollars = total;
    change = total * 100 - dollars * 100;

    //forcefeeding the numbers array with pieces of dollars
    numbers[0] = dollars / 1000;
    dollars -= numbers[0]*1000;
    numbers[1] = dollars / 100;
    dollars -= numbers[1]*100;
    numbers[3] = dollars / 10;
    dollars -= numbers[3]*10;
    numbers[2] = dollars;

    //putting the right words in the word array to match the number array
    for (int i = 0; i < 3; i++)
    {
        switch (numbers[i])
        {
        case 0:
            words[i] = "zero";
            break;
        case 1:
            words[i] = "one";
            break;
        case 2:
            words[i] = "two";
            break;
        case 3:
            words[i] = "three";
            break;
        case 4:
            words[i] = "four";
            break;
        case 5:
            words[i] = "five";
            break;
        case 6:
            words[i] = "six";
            break;
        case 7:
            words[i] = "seven";
            break;
        case 8:
            words[i] = "eight";
            break;
        case 9:
            words[i] = "nine";
            break;
        }
    }

    //tens place is weird
    switch (numbers[3])
    {
    case 0:
        words[3] = "zero";
        break;
    case 1:
        words[3] = "ten";
        break;
    case 2:
        words[3] = "twenty";
        break;
    case 3:
        words[3] = "thirty";
        break;
    case 4:
        words[3] = "fourty";
        break;
    case 5:
        words[3] = "fifty";
        break;
    case 6:
        words[3] = "sixty";
        break;
    case 7:
        words[3] = "seventy";
        break;
    case 8:
        words[3] = "eighty";
        break;
    case 9:
        words[3] = "ninety";
        break;
    }

    //the teens make ones even weirder than tens
    if (numbers[3] == 1)
    {
        switch (numbers[2])
        {
        case 0:
            words[2] = "zero";
            break;
        case 1:
            words[2] = "eleven";
            words[3] = "zero";
            break;
        case 2:
            words[2] = "twelve";
            words[3] = "zero";
            break;
        case 3:
            words[2] = "thirteen";
            words[3] = "zero";
            break;
        case 4:
            words[2] = "fourteen";
            words[3] = "zero";
            break;
        case 5:
            words[2] = "fifteen";
            words[3] = "zero";
            break;
        case 6:
            words[2] = "sixteen";
            words[3] = "zero";
            break;
        case 7:
            words[2] = "seventeen";
            words[3] = "zero";
            break;
        case 8:
            words[2] = "eighteen";
            words[3] = "zero";
            break;
        case 9:
            words[2] = "nineteen";
            words[3] = "zero";
            break;
        }
    }

    //why dont we string this out
    if (words[0] != "zero")
        String << words[0] << " thousand ";
    if (words[1] != "zero")
        String << words[1] << " hundred ";
    if (words[3] != "zero")
        String << words[3] << " ";
    if (words[2] != "zero")
        String << words[2] << " ";

    //Voila, it works
    otherString << "Check for " << toCurrency(total) << " = " << String.str() << "dollars and " << change << " cents" << endl;
    return otherString.str();
}

// Give this thing the money you got and the price for your wildest dreams (doubles) and it gives the denominations of the change
string Money::processChangeFloat() {
    double cost, change;
    cin >> total >> cost;
    change = total - cost;
    stringstream String;

    //slicing and dicing change into denominations
    hundreds = change / 100;
    change -= hundreds * 100;
    tens = change / 10;
    change -= tens * 10;
    fives = change / 5;
    change -= fives * 5;
    ones = change;

    change = (change - ones) * 100;
    quarters = change / 25;
    change -= quarters * 25;
    dimes = change / 10;
    change -= dimes * 10;
    nickels = change / 5;
    change -= nickels * 5;
    cents = change;

    //I hate rounding errors, even if they're only by a penny. This gets rid of them
    change = hundreds * 100.0 + tens * 10.0 + fives * 5.0 + ones + quarters * 0.25 + dimes * 0.1 + nickels * 0.05 + cents * 0.01;
    if ((total - cost) - change != 0)
        cents++;

    String << "Change back on " << toCurrency(total) << " for purchase of " << toCurrency(cost) << " is " << toCurrency(total - cost) << " which is " << toString() << endl;
    return String.str();
}

// Paying with cash? Want your change in denominations? This is the method for you
string Money::processChangeChange() {
    double cost, change;

    //Figuring out what you paid with. Would call processChange() but it doesn't just return the double
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents >> cost;
    total = hundreds * 100.0 + tens * 10.0 + fives * 5.0 + ones + quarters * 0.25 + dimes * 0.1 + nickels * 0.05 + cents * 0.01;
    change = total - cost;
    stringstream String;

    //getting the first output before we change all the values
    String << "Change back on " << toString() << " for purchase of " << toCurrency(cost) << " is " << toCurrency(change) << " which is ";

    //slicing and dicing change into denominations
    hundreds = change / 100;
    change -= hundreds * 100;
    tens = change / 10;
    change -= tens * 10;
    fives = change / 5;
    change -= fives * 5;
    ones = change;

    change = (change - ones) * 100;
    quarters = change / 25;
    change -= quarters * 25;
    dimes = change / 10;
    change -= dimes * 10;
    nickels = change / 5;
    change -= nickels * 5;
    cents = change;

    //Idek what causes the rounding error but this is the fix
    change = hundreds * 100.0 + tens * 10.0 + fives * 5.0 + ones + quarters * 0.25 + dimes * 0.1 + nickels * 0.05 + cents * 0.01;
    if ((total - cost) - change != 0)
        cents++;
    //Error was more persistent in this method, double checking to make sure
    change = hundreds * 100.0 + tens * 10.0 + fives * 5.0 + ones + quarters * 0.25 + dimes * 0.1 + nickels * 0.05 + cents * 0.01;
    if ((total - cost) - change != 0)
        cents--;


    String << toString() << endl;
    return String.str();
}
//That's all, Folks