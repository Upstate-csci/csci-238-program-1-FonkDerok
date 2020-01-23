# program-1: money, money, money!
Congratulations and welcome to the software engineering world of GitHub and your first C++ programming assignment. This readme file contains the details of the problem you are asked to solve on this assignment. Of course, you are to solve this using the C++ programming language. 


Title: Money, money, money

Terms: 
-  change format - 0 hundreds, 5 tens, 0 fives, 2 ones, 1 quarter, 1 dime, 0 nickels, 0 pennies
-  dollar format - $52.35
-  float format - 52.35
-  check format - fifty two dollars and 35 cents
  
Problem: Money can be represented in various formats. For example, $52.35, fifty two dollars and thirty five cents or even 5 tens, 2 ones, 1 quarter and 10 cents. All of these formats represent the same amount, 52.35. Fast food restaurants have an ongoing challenge of training young employees how to handle dealing with money in its various formats - making change, knowing how much to charge for something, understanding the relationship between a number, like 52.35, and the various ways of representing that amount using the US monetary system. They need your help training the next generation of workers until these somewhat simplistic jobs are turned over to robots. 

The currency in each store consists of only hundreds, tens, ones, quarters, dimes, nickels and pennies. Make the least amount of change possible. For example, $11.25 should be 1 ten, 1 one, 1 quarter.

1. when you see the word "change" take in the change format, output in dollar format
2. when you see the word "float" take in the float format, output in change format
3. when you see the word "check" take in the float format, output in check format
4. when you see the word "change-change" take in the amount given by the customer in change format and the cost of the transaction in float format, output the change to be given to the customer in change format
5. when you see the word "change-float" take in the amount given by the customer in float format and the cost of the transaction in float format, output the change to be given to the customer in change format

In the repository you will find 2 starting files along with several test files as follows:
1. testMoney.java - the main test driver that handles reading in the command and calling the appropriate money method
2. Money.java - the Money class which is where you will place all of your code
3. testFloat.txt - several "float" command tests
4. testChange.txt - several "change" command tests
5. testChangeChange.txt - several "change-change" command tests
6. testChangeFloat.txt - several "change-float" command tests
7. testCheck.txt - several "check" command tests
8. testAll.txt - several different command tests

Sample test data:
```
change 
0 5 0 2 1 1 1 5
change
3 8 0 0 0 99 1 3
float 
427.99
float 
25.33
check 
32.18
check 
100
change-float 
100.00 52.17
change-change 
1 0 0 0 0 0 0 52.17
change 
1 1 1 1 1 1 1
change-float
5 .99
change-float 
100 .01
```

Sample output:
```
0 hundreds 5 tens 0 fives 2 ones 1 quarters 1 dimes 1 nickels 5 pennies = $52.45
3 hundreds 8 tens 0 fives 0 ones 0 quarters 99 dimes 1 nickels 3 pennies = $389.98
427.99 = 4 hundreds 2 tens 1 fives 2 ones 3 quarters 2 dimes 0 nickels 4 pennies
25.33 = 0 hundreds 2 tens 1 fives 0 ones 1 quarters 0 dimes 1 nickels 3 pennies
check for $32.18 = 32 dollars and 18 cents
check for $100.00 = 100 dollars and 0 cents
change back on $100.00 for purchase of $52.17 is 47.83 which is 0 hundreds 4 tens 1 fives 2 ones 3 quarters 0 dimes 1 nickels 3 pennies
change back on 1 hundreds 0 tens 0 fives 0 ones 0 quarters 0 dimes 0 nickels 0 pennies for purchase of $52.17 is 47.83 which is 0 hundreds 4 tens 1 fives 2 ones 3 quarters 0 dimes 1 nickels 3 pennies
1 hundreds 1 tens 0 fives 1 ones 1 quarters 1 dimes 1 nickels 1 pennies = $111.41
change back on $5.00 for purchase of $0.99 is 4.01 which is 0 hundreds 0 tens 0 fives 4 ones 0 quarters 0 dimes 0 nickels 1 pennies
change back on $100.00 is 99.99 0 hundreds 9 tens 1 fives 4 ones 3 quarters 2 dimes 0 nickels 4 pennies
```
**Be sure to take notice of the output format for each command. Your program must follow the exact format presented above.** 

- [ ] For a grade of A your program must support change-float, change-change, float, change
- [ ] For a grade of B your program must support change-change, currency, float
- [ ] For a grade of C your program must support change-float, float
- [ ] For extra credit your program must support everything

