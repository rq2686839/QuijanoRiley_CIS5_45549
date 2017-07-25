/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 24, 2017, 7:05 PM
 * Purpose:  Chapter 7&8 Homework Menu
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Input - Output Manipulation Library
#include <cstdlib>   //C Standard Library for Using rand()
#include <ctime>     //C Time Library for Seeding the Random Number Generator
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//*****************************************************************************
//                      FUNCTION PROTOTYPES FOR MENU CHOICE 9
void linear (int [], int , int);
void binary (int [], int , int);


//Execution begins here
int main(int argc, char** argv) {
    
    //Declare variables 
    
    char choice;
    
    //Use a do-while loop to display contents of the menu 
    
    do
    {
        //Prompt the user to input a value for a menu choice
        cout<<"Choose a problem from the list to execute by typing the"<<endl;
        cout<<"number that corresponds with it on the menu."<<endl;
        cout<<"Type any other character to exit."<<endl<<endl;
        cout<<"1. Gaddis, 8th Edition, Chapter 7, Problem 2 (Rainfall ";
        cout<<"Statistics)";
        cout<<endl;
        cout<<"2. Gaddis, 8th Edition, Chapter 7, Problem 3 (Chips and";
        cout<<" Salsa)"<<endl;
        cout<<"3. Gaddis, 8th Edition, Chapter 7, Problem 5 (Monkey Business)";
        cout<<endl;
        cout<<"4. Gaddis, 8th Edition, Chapter 7, Problem 9 (Payroll) ";
        cout<<endl;
        cout<<"5. Gaddis, 8th Edition, Chapter 7, Problem 14 (Lottery ";
        cout<<"Application)"<<endl;
        cout<<"6. Gaddis, 8th Edition, Chapter 8, Problem 1 (Charge Account";
        cout<<" Validation)"<<endl;
        cout<<"7. Gaddis, 8th Edition, Chapter 8, Problem 2 (Lottery Winners)";
        cout<<endl;
        cout<<"8. Gaddis, 8th Edition, Chapter 8, Problem 4 (Charge Account ";
        cout<<"Validation Modification)"<<endl;
        cout<<"9. Gaddis, 8th Edition, Chapter 8, Problem 8 (Search Benchmarks";
        cout<<")"<<endl;
        cin>>choice;
        
        //Use a switch to display the problem chosen on the menu
        switch(choice)
        {
            case '1':{
                //Declare variables here
                
                int SIZE = 12;

                float rainAry [SIZE]; /*rainAry is the array into which the user
                                       will enter the total rainfall (in inches)
                                       for each month; each month is 1 element*/

                //Declare and initialize variables

                float rainTot = 0.0f; /*rainTot is the total rain (in inches) 
                                       for the whole 12 month period; it is
                                       initialized at 0.0 because
                                       it will be an accumulator variable*/

                //Briefly explain the program

                cout<<"This program will let the user enter the total ";
                cout<<"rainfall (in "<<endl;
                cout<<"inches) each month for 12 months. It will then display";
                cout<<endl;
                cout<<"the total rainfall for the year, the average monthly ";
                cout<<"rainfall"<<endl;
                cout<<"and the month numbers that had the highest and lowest ";
                cout<<"amounts.";
                cout<<endl<<endl;

                //Prompt the user to input data

                /*Have the user input the rainfall for each of the 12 months 
                 using a for loop*/
                for (short i = 0; i < SIZE; i++)
                {
                    cout<<"Input the amount of rainfall in inches for month ";
                    cout<<i+1<<endl;
                    cout<<"below. This number cannot be negative."<<endl;
                    cin>>rainAry[i];

                    /* Use a while loop to continuously prompt the user to input
                     so long as their input is negative*/
                    while (rainAry[i]<0)
                    {
                        cout<<"This is an invalid input. Input the amount of";
                        cout<<endl;
                        cout<<"rainfall in inches for month "<<i+1<<" below, ";
                        cout<<"making"<<endl;
                        cout<<"sure it is not negative."<<endl;
                        cin>>rainAry[i];
                    }    
                }

                //Declare and initialize more variables

                float highest = rainAry[0]; /*highest will be the highest amount
                                             of rainfall in any one particular 
                                             month; this must be initialized to
                                             the rainfall amount of the first 
                                             month so the for loop can compare
                                             the rainfall amount for every month
                                             to this and replace highest with 
                                             higher and higher rainfall amounts*/

                float lowest = rainAry [0]; /*lowest will be the lowest amount 
                                             of rainfall in any one particular 
                                             month; this will be 
                                             initialized to the rainfall amount 
                                             of the first month for the same 
                                             reason that highest was*/

                short highMth, lowMth; /*highMth is the month number that will
                                        have the highest amount of rainfall, and
                                        lowMth is the month number that will 
                                        have the lowest*/

                highMth = lowMth = 1; /*The lowest and highest months are 
                                       initially set to 1 for the same reason 
                                       that the highest and lowest
                                       rainfall amounts are set to the rainfall 
                                       amount for month 1*/

                //Process calculations

                /*Use a for loop to calculate the total rainfall for the whole 
                 year and the months with the highest and lowest amounts*/
                for (short i = 1; i < SIZE; i++)
                {
                    rainTot += rainAry[i]; /*The total rainfall for the year is 
                                            the rainfall of all the months added
                                            together*/

                    if (rainAry[i] > highest) /*If the rainfall of one month is
                                               higher than the current highest,
                                               it becomes the highest*/
                    {
                        highest = rainAry[i];
                        highMth = i + 1;
                    } 

                    if(rainAry[i]<lowest) /*If the rainfall of one month is 
                                           lower than the current lowest, it 
                                           becomes the lowest*/
                    {
                        lowest = rainAry[i];
                        lowMth = i + 1;
                    }    
                }   

                //Output the results

                cout<<"The total rainfall for the year is "<<rainTot;
                cout<<" inches, and the";
                cout<<endl;
                cout<<"average monthly rainfall is "<<rainTot/12;
                cout<<" inches."<<endl;
                cout<<"Month with highest rainfall is month "<<highMth;
                cout<<" with "<<highest;
                cout<<" inches."<<endl;
                cout<<"Month with lowest rainfall is month "<<lowMth;
                cout<<" with "<<lowest;
                cout<<" inches."<<endl;
                break;
            }
            
            case '2':{
                
                //Declare and initialize variables here
                
                int SIZE = 5;
                
                string salType [SIZE] = {"mild", "medium", //salType is an array
                                           "sweet", "hot",   //that holds the
                                                    "zesty"};//names of each of
                                                             //the five salsa 
                                                             //types that are to
                                                             //be sold

                int jarSold [SIZE]; /*jarSold is the array that will contain the
                                     number of jars sold during the past month 
                                     for each salsa type*/

                unsigned int totSale; /*totSale is the total number of all types
                                       of salsas sold*/


                unsigned short index; /*Index will serve as the counter for the 
                                       for loops that will be used to input 
                                       contents into and display these arrays*/

                unsigned short highidx, lowidx; /*highidx will be the index for 
                                                 the highest value in the 
                                                 jarSold array and lowidx will
                                                 be the lowest*/

                int highest, lowest; /*Highest is the highest number of jars 
                                      sold, lowest is the lowest number of jars 
                                      sold*/

                //Briefly explain the program

                cout<<"This program will ask the user to input the number of ";
                cout<<"jars"<<endl;
                cout<<"sold for five different types of salsa. A report will ";
                cout<<"then"<<endl;
                cout<<"be produced that displays sales for each type of ";
                cout<<"salsa,"<<endl;
                cout<<"the total sales, and the names of the highest and ";
                cout<<"lowest"<<endl;
                cout<<"selling products."<<endl<<endl;

                //Initialize variables

                totSale = 0; /*The total amount of all jars sold is initialized 
                              at 0 because it will serve as a counter*/

                //Prompt the user to input data

                /*Use a for loop to have the reader input jars sold for each 
                 type of salsa*/
                for (index = 0; index<SIZE; index++)
                {
                    cout<<"Input the number of jars sold for "<<salType[index];
                    cout<<" salsa";
                    cout<<" below."<<endl;
                    cin>>jarSold[index];

                    /*Prompt the user to continuously input the value if it is 
                    negative*/
                    while (jarSold[index]<0)
                    {
                        cout<<"Invalid input. Please input the number of jars ";
                        cout<<"sold for ";
                        cout<<salType[index]<<" salsa below,"<<endl;
                        cout<<"making sure it is not negative."<<endl;
                        cin>>jarSold[index];
                    }    
                }

                //Initialize more variables

                highest = jarSold[0]; 
                              /*Highest must be initialized at the value 
                              associated with the first index so values 
                              associated with following indexes in
                              the loop have something to be compared to*/

                lowest = jarSold[0]; 
                            /*Lowest must be initialized at the value associated
                             with the first index for the same reason as
                             highest*/

                /*Use a for loop to output a report that displays sales for each
                 type of salsa, properly initializes the highidx and lowidx 
                 variables, and accumulates total jars sold*/
                for (index = 0; index<SIZE; index++)
                {
                    cout<<"The number of jars sold for "<<salType[index]<<" = ";
                    cout<<jarSold[index];
                    cout<<endl;

                    if (jarSold[index]>highest) /*If the value for this index is
                                                 higher than the previous
                                                 highest, it becomes the
                                                 highest and its associated 
                                                 index becomes highidx*/
                    {
                        highest = jarSold[index];
                        highidx = index;
                    }

                    if (jarSold[index]<lowest) /*If the value for this index is 
                                                lower than the previous lowest,
                                                it becomes the lowest
                                                and its associated index becomes
                                                lowidx*/
                    {
                        lowest = jarSold[index];
                        lowidx = index;
                    }  
                    totSale += jarSold[index];
                }

                //Output the total sales and names of highest and lowest selling products
                cout<<"The total sales of all the salsas combined is ";
                cout<<totSale<<endl;
                cout<<"The highest selling salsa is "<<salType[highidx]<<endl;
                cout<<"The lowest selling salsa is "<<salType[lowidx]<<endl;
                break;   
            }
            case '3':{
            
               //Declare and initialize variables here 
                
                int MONKEY = 3;
                int DAY = 5;
    
                float monkAry[MONKEY][DAY]; /*monkAry is an array that stores 
                                             information about food for each of 
                                             the three monkeys; it holds the 
                                             pounds of food each monkey eats
                                             each day during a typical 
                                             week*/

                float lowFd, highFd; /*lowFd is the lowest amount of food
                                       eaten during the week by any one 
                                       monkey, highFd is the highest amount of 
                                       food eaten 
                                       during the week by any one monkey*/ 


                unsigned short lowMnk, highMnk; /*lowMnk is the monkey that ate
                                                 the lowest amount of food 
                                                 during the week, highMnk 
                                                 is that which at the highest
                                                 amount*/

                //Briefly explain program

                cout<<"This program will have the user input the amount of ";
                cout<<"food"<<endl;
                cout<<"three different monkeys each eats on a certain day ";
                cout<<"during"<<endl;
                cout<<"a typical week. It will then output the average amount ";
                cout<<"of"<<endl;
                cout<<"food eaten per day by the whole family of monkeys, the ";
                cout<<"least"<<endl;
                cout<<"amount of food eaten during the week by any one monkey,";
                cout<<" and"<<endl;
                cout<<"The greatest amount eaten during the week by any one ";
                cout<<"monkey."<<endl;
                cout<<endl;

                //Prompt the user to input data

                //Declare and initialize variable

                float totFood = 0.0f; /*totFood is the total amount of food 
                                       eaten by the whole family of monkeys in
                                       all 5 days; it is
                                       initialize at 0 because it will serve
                                       as an accumulator*/

                /*Use nesting with for loops to have the user input the amount
                  of food (in pounds) each monkey eats during each week day*/

                for(short i = 0; i < MONKEY; i++)
                    for (short j = 0; j < DAY; j++)
                    {
                        cout<<"Input the amount of food eaten by monkey ";
                        cout<<i+1<<" on day ";
                        cout<<j+1<<endl;
                        cout<<"This value cannot be negative."<<endl;
                        cin>>monkAry[i][j];

                        /*Use a while loop to keep prompting the user to input 
                         a value so long as their input is negative*/
                        while(monkAry[i][j]<0)
                        {
                            cout<<"This is an invalid input. Input the amount ";
                            cout<<"of"<<endl;
                            cout<<"food eaten by monkey "<<i+1<<" on day, ";
                            cout<<j+1<<endl;
                            cout<<"making sure this value is not negative.";
                            cout<<endl;
                            cin>>monkAry[i][j];
                        }

                        totFood += monkAry[i][j]; /*The total food eaten is 
                                                   always the the amount of food
                                                   eaten by a certain
                                                   monkey on a certain day added
                                                   to the amount of food eaten 
                                                   that has already
                                                   been accounted for*/
                    } 

                //Declare and Initialize Variables

                float fdPWeek = 0.0f; /*fdPWeek if the amount of food eaten by 
                                      any one monkey in the week; this must be 
                                      initialized at 0.0 to serve as an
                                       accumulator variable*/

                //Process Calculations with Inputted Data

                /*Use a for loop to find the amount of food eaten in a week by
                 the first monkey*/
                for (short j = 0; j < DAY; j++)
                {
                    fdPWeek += monkAry[0][j];
                }   

                /*Set the amount of food eaten by the first monkey in a week to
                 the lowest and highest food amount eaten during the week by any
                 one monkey; this is so the next nested for loop has an amount 
                 of food to compare to those which are eaten by monkeys 2 and 
                 3*/
                lowFd = fdPWeek; 
                highFd = fdPWeek;
                lowMnk = 1;
                highMnk = 1;

                /*Use nested for loops to figure out the least amount of food 
                 eaten during the week and by which monkey and the most amount
                 of food eaten during the week and by which monkey*/
                for (short i = 1; i < MONKEY; i++)
                {    

                    fdPWeek = 0.0f; /*Each time the outer loop iterates, reset 
                                     the fdPWeek to 0.0f to be an accumulator
                                     that adds up the amount of food eaten per
                                     week by each monkey*/

                    for (short j = 0; j < DAY; j++)
                    {
                        //Find food eaten in a week by any one monkey
                        fdPWeek+=monkAry[i][j];
                    }

                    /*If the food eaten in a week is less than the amount for 
                     monkey 1, the lowest amount eaten becomes refreshed and the
                     monkey that ate that amount becomes determined*/
                    if (fdPWeek < lowFd)
                    {
                        lowFd = fdPWeek;
                        lowMnk = i + 1;
                    }

                    /*If the food eaten in a week is more than the amount for
                      monkey 1, the highest amount eaten becomes refreshed and 
                     the monkey that ate that 
                      amount becomes determined*/
                    if (fdPWeek > highFd)
                    {
                        highFd = fdPWeek;
                        highMnk = i + 1;
                    }

                }    

                //Output the results

                /*Output the monkey that ate the most and that amount, the 
                 monkey that ate the least and that amount, and the average \
                 amount of food eaten per day by the whole family of monkeys*/
                cout<<"The monkey that ate the most was monkey "<<highMnk;
                cout<<", which ate ";
                cout<<highFd<<" pounds."<<endl;
                cout<<"The monkey that ate the least was monkey "<<lowMnk;
                cout<<", which ate ";
                cout<<lowFd<<" pounds."<<endl;
                cout<<"The average amount of food eaten per day by the whole ";
                cout<<"family was ";
                cout<<totFood/5<<'.'<<endl;
                break;
            }
            case '4':{
                
               //Declare and Initialize variables here
    
                int SIZE = 7;
                
                unsigned int empId[] = {5658845, 4520125, 7895122, 8777541,
                                        8451277, 1302850, 7580489};  /*empId is 
                                                                     the array 
                                                                     that stores
                                                                     the 7 
                                                                     employee
                                                                  identification
                                                                   numbers*/

                int hours[SIZE];       /*hours is the array that holds the 
                                        number of hours worked by each 
                                        employee*/ 

                float payRate [SIZE]; /*payRate is the array that holds each 
                                       employee's hourly pay rate*/

                float wages [SIZE]; //wages holds each employee's gross wages

                //Briefly explain the program

                cout<<"This program will ask the user to enter a certain ";
                cout<<"employee's"<<endl;
                cout<<"hours and pay rate (referring to the employee by ";
                cout<<"their ID)."<<endl;
                cout<<"It will then calculate and display gross wages for ";
                cout<<"each employee.";
                cout<<endl<<endl;

                //Prompt the user to input data

                /*Use a for loop to get the user to input the hours and pay rate
                 for each employee*/
                for (short i = 0; i < SIZE; i++)
                {
                    cout<<"Input the hours for employee "<<empId[i];
                    cout<<". This cannot be ";
                    cout<<"negative."<<endl;
                    cin>>hours[i];

                    /*Use a while loop to keep prompting for input of hours if 
                     the input is negative*/
                    while (hours[i]<0)
                    {
                        cout<<"This is an invalid input. Input the number ";
                        cout<<"of hours"<<endl;
                        cout<<"for employee "<<empId[i]<<" below, making sure ";
                        cout<<"it's not ";
                        cout<<"negative."<<endl;
                        cin>>hours[i];
                    }  

                    cout<<"Input the pay rate for employee "<<empId[i];
                    cout<<" in dollars.";
                    cout<<endl;
                    cout<<"This cannot be less than $15.00."<<endl;
                    cin>>payRate[i];

                    /*Use a while loop to keep prompting for input of pay rate 
                     if the input is less than $15.00*/
                    while (payRate[i]<15.00)
                    {
                        cout<<"This is an invalid input. Please input the pay ";
                        cout<<"rate"<<endl;
                        cout<<"for employee "<<empId[i]<<" below, making sure ";
                        cout<<"it is not ";
                        cout<<"less than $15.00."<<endl;
                        cin>>payRate[i];
                        break;
                    }    
                }
       
                //Process Calculations

                //Use a for loop to calculate the gross wages for each employee
                for (short i = 0; i < SIZE; i++)
                {
                    /*The gross wages for each employee is the pay rate of that 
                     employee times the hours worked  by that employee*/
                    wages [i] = payRate[i] * hours[i];
                }    

                //Output results

                //Set the numerical output format
                cout<<fixed<<setprecision(2)<<showpoint;

                /*Use a for loop to output each element of the gross wages array
                 next to the appropriate corresponding employee ID numbers*/
                for (short i = 0; i < SIZE; i++)
                {
                    cout<<"Employee: "<<empId[i]<<endl;
                    cout<<"Gross Wages: $"<<wages[i]<<endl<<endl;
                } 
                break;
            }
            case '5':{
                  
                //Seed the random number generator
    
                srand(static_cast<unsigned int>(time(0)));

                //Declare variables here

                int SIZE = 5;
                
                int lottery [SIZE]; /*lottery is an array that will contain a 
                                     random number in the range of 0 to 9 for 
                                     each of its elements*/

                int user [SIZE]; /*user is an array that will contain five 
                                  numbers inputted by the user in an attempt to
                                  match the lottery array*/

                //Briefly explain program

                cout<<"This program will contain a series of random numbers. ";
                cout<<"The"<<endl;
                cout<<"user is to try to match these random numbers using ";
                cout<<"their"<<endl;
                cout<<"inputs. If some numbers are matching, the program will";
                cout<<endl;
                cout<<"tell them the amount of numbers that are matching and";
                cout<<endl;
                cout<<"prompt them to keep guessing until they win.";
                cout<<endl<<endl;

                //Initialize variables

                /*Initialize the random elements of the lottery array using a 
                for loop*/
                for (short i = 0; i < SIZE; i++)
                {
                    lottery [i] = rand()%10; /*Each element will have one random
                                              number from the range of 0 to 9*/
                }

                /*Prompt the user to input five digits to try to guess the 
                 random number using a for loop*/
                cout<<"Input 5 digits below, each one followed by hitting ";
                cout<<"enter,"<<endl;
                cout<<"to match the lottery ticket!"<<endl;
                for (short i = 0; i < SIZE; i++)
                    cin>>user[i];

                //Declare and Initialize Variables

                short numCnt = 0; /*numCnt is the variable that will keep track 
                                   of the total number of digits that match;
                                   it must be initialized at 0 because it is an 
                                   accumulator*/

                bool win = true; /*win will be used in the for loop and will be 
                                    initialized to false if the user loses; this
                                    will then prevent an if statement from
                                    displaying a winning message; it will be 
                                   initialized to true unless the user loses*/

                //Process Calculations

                //Compare the user array to the lottery array using a for loop
                for (short i = 0; i < SIZE; i++)
                {
                    /*If one digit does not match, the user lost, so loss is 
                     made to be true*/
                    if (lottery[i]!=user[i])
                        win = false;

                    //If a digit does match:
                    if (lottery[i]==user[i])
                    {
                        numCnt++; /*The number of digits that match gets 
                                   incremented*/

                        cout<<"Digit "<<i+1<<" matches"<<endl; /*An output is 
                                                                displayed 
                                                                that tells the 
                                                                user the place 
                                                                of the digit
                                                                that matches*/      
                    }
                }

                //Output the results

                cout<<"Winning lottery number: ";

                //Use a for loop to output the lottery number
                for (short i = 0; i < SIZE; i++)
                    cout<<lottery[i];

                cout<<endl<<"Your number:            ";

                //Use a for loop to output the user's inputted number
                for (short i = 0; i < SIZE; i++)
                    cout<<user[i];

                //Output the number of digits that match 
                cout<<endl<<"The number of digits that match = "<<numCnt;

                //Use an if statement to display that the user won if they did
                if (win)
                {    
                    cout<<endl<<"CONGRATULATIONS! YOU ARE A GRAND PRIZE ";
                    cout<<"WINNER!!"<<endl;
                }  
                cout<<endl<<endl;
               
                break;
            }
            case '6':{
                
                //Declare and initialize variables
                
                int SIZE = 18;
    
                /*accNum is an array that will hold the list of charge account 
                 numbers; this is what will be searched when the user enters a 
                 number and that number is determined to be valid or invalid; 
                 the validity will depend on if it is one of these*/
                int accNum [SIZE] = {5658845, 4520125, 7895122, 8777541, 
                                     8451277, 1302850, 8080152, 4562555, 
                                     5552012, 5050552, 7825877, 1250255,
                                     1005231, 6545231, 3852085, 7576651, 
                                                       7881200, 4581002};

                int userIpt; /*userIpt is the variable into which the user will
                              input their number; this number will be compared 
                              to the numbers in the array to determine if it's 
                              valid or invalid*/

                //Briefly explain program

                cout<<"This program will have the user enter a charge account";
                cout<<endl;
                cout<<"number. It will then determine if the number is valid ";
                cout<<"by"<<endl;
                cout<<"checking for it in a list of given numbers."<<endl<<endl;

                //Prompt the user to input data 

                /*Prompt the user to input a charge account number to be 
                 compared to the list of charge account numbers*/ 
                cout<<"Input a charge account number below to determine if it ";
                cout<<"is"<<endl;
                cout<<"valid or invalid."<<endl;
                cin>>userIpt;

                //Declare and initialize variables

                bool found = false; /*found will determine if the number 
                                     inputted by the user is found in the array;
                                     initialized to false, but if the inputted
                                     number is found, initialized to true
                                     in the while loop*/

                unsigned short index = 0;/*index will be the counter in the 
                                        while loop that will search through the
                                        array and serve as the index
                                       of the array being searched*/

                /*Use a while loop to search the array for a number that matches
                 the input*/
                while (index < SIZE && !found)
                {
                    if (userIpt == accNum[index]) /*Use an if statement to set
                                                   found to true if the userIpt
                                                   matches an element of the
                                                   array*/
                        found = true;

                    index++; /*Increment the index after every loop iteration to
                              test a new element*/
                } 

                //Output data

                /*Use an if/else to output that the entered data is a valid or 
                 invalid account number based on whether found is true or 
                 false*/
                if (found)
                {
                    cout<<"The entered number is a valid charge account ";
                    cout<<"number.";
                }
                else
                {    
                    cout<<"The entered number is an invalid charge account ";
                    cout<<"number.";
                }    
                cout<<endl<<endl;
              break;
            }
            case '7':{
                
                //Declare and initialize variables
                
                int SIZE = 10;
    
                /*ticks is an array that will hold the list of the lottery 
                 ticket combinations the buyer always chooses; this is what will
                 be searched when the user enters this week's winning 5-digit 
                 number to determine if the buyer was a winner this week*/ 
                int ticks  [SIZE] = {13579, 26791, 26792, 33445, 55555,
                                     62483, 77777, 79422, 85647, 93121};

                int userIpt; /*userIpt is the variable into which the user will
                              input this week's winning 5-digit number; this 
                              number will be compared to the numbers in the 
                              array to determine if the lottery ticket
                              buyer is a winner this week*/

                //Briefly explain program

                cout<<"This program will have the user enter this week's ";
                cout<<"winning"<<endl;
                cout<<"5-digit lottery number. It will then determine if the ";
                cout<<"number is the";
                cout<<endl;
                cout<<"same as one of the lottery ticket buyer's 10 tickets. ";
                cout<<"If it"<<endl;
                cout<<"is, it will report the buyer a winner, and if it is ";
                cout<<"not,"<<endl;
                cout<<"it will report that they did not win."<<endl<<endl;

                //Prompt the user to input data 

                /*Prompt the user to input this week's winning lottery ticket*/ 
                cout<<"Input this week's winning lottery ticket below. If it ";
                cout<<"is the"<<endl;
                cout<<"same as one of the 10 tickets of the ticket buyer, ";
                cout<<"they will"<<endl;
                cout<<"be declared a winner."<<endl;
                cin>>userIpt;

                //Declare and initialize variables

                bool found = false; /*found will determine if the number 
                                     inputted by the user is found in the array;
                                     initialized to false, but if the inputted 
                                     number is found, initialized to true
                                     in the while loop*/

                unsigned short index=0; /*index will be the counter in the while 
                                       loop that will search through the array
                                       and serve as the index
                                       of the array being searched*/

                /*Use a while loop to search the array for a number that matches
                 the input*/
                while (index < SIZE && !found)
                {
                    if (userIpt == ticks[index]) /*Use an if statement to set 
                                                  found to true if the userIpt
                                                  matches an element of the
                                                  array*/
                    found = true;

                    index++; /*Increment the index after every loop iteration to
                              test a new element*/
                } 

                //Output data

                /*Use an if/else to output that the lottery ticket buyer is a 
                 winner or not based on whether found is true or false*/
                if (found)
                {
                    cout<<"One of the buyer's tickets was a winner this week!!";
                }
                else
                {    
                    cout<<"None of the buyer's tickets were a winner this ";
                    cout<<"week.";
                }
                cout<<endl<<endl;
                break;
            }
            case '8':{
            
                 //Declare and initialize variables
                
                int SIZE = 18;
    
                /*accNum is an array that will hold the list of charge account 
                 numbers; this is what will be searched when the user enters a 
                 number and that number is determined to be valid or invalid;
                 the validity will depend on if it is one of these*/
                int accNum [SIZE] = {5658845, 4520125, 7895122, 8777541, 
                                                       8451277, 1302850,
                                     8080152, 4562555, 5552012, 5050552,
                                                       7825877, 1250255,
                                     1005231, 6545231, 3852085, 7576651, 
                                                       7881200, 4581002};

                int userIpt; /*userIpt is the variable into which the user will
                              input their number; this number will be compared
                              to the numbers in the array to determine if it's
                              valid or invalid*/

                //Briefly explain program

                cout<<"This program will have the user enter a charge account";
                cout<<endl;
                cout<<"number. It will then determine if the number is valid ";
                cout<<"by"<<endl;
                cout<<"checking for it in a list of given numbers."<<endl<<endl;

                //Prompt the user to input data 

                /*Prompt the user to input a charge account number to be 
                 compared to the list of charge account numbers*/ 
                cout<<"Input a charge account number below to determine if it ";
                cout<<"is"<<endl;
                cout<<"valid or invalid."<<endl;
                cin>>userIpt;

                //Declare and initialize variables

                bool found = false; /*found will determine if the number 
                                     inputted by the user is found in the array;
                                     initialized to false, but if the inputted
                                     number is found, initialized to true
                                     in the while loop*/

                unsigned short index; /*index will be the counter in the for 
                                       loop nested in the outer for loop that is
                                       used for a selection sort of the array*/

                unsigned short scan; /*scan will be the counter for the outer 
                                      for loop that is used for a selection sort
                                      of the array*/

                unsigned short minIdx; /*minIdx will be used in the selection 
                                        sort method to set a new minimum index 
                                        each time one is come across*/

                int minVal; /*minVal will be used in the selection sort method 
                             to set a new minimum value each time one is come 
                             across*/

                int lowest = 0; /*lowest will be the index of the lowest element
                                 found in the array, being continuously 
                                 determined by the binary search*/

                int highest = SIZE - 1; /*highest will be the index of the
                                         highest element found in the array 
                                         being continuously determined by
                                         the binary search*/

                int middle; /*middle will be the middle element found in the
                             array being continuously updated b y the binary 
                             search*/

                //Process Calculations

                /*Use the selection sort method to sort the array full of 
                 account numbers*/
                for (scan = 0; scan < SIZE - 1; scan++)
                {
                    minIdx = scan;
                    minVal = accNum[scan];
                    for(index = scan + 1; index < SIZE; index++)
                    {
                        if (accNum[index] < minVal)
                        {
                            minVal = accNum[index];
                            minIdx = index;
                        }
                    }
                        accNum[minIdx] = accNum[scan];
                        accNum[scan] = minVal;
                }    

                /*Use the binary search method to search the sorted array to see
                 if one of its values is equal to the value inputted by the user*/

                while (lowest <= highest && !found)
                {
                    middle = (highest + lowest)/2;
                    if (accNum[middle] > userIpt)
                        highest = middle - 1;

                    else if (accNum[middle] == userIpt)
                        found = true;

                    else
                        lowest = middle + 1;
                }    
                
                //Output data

                /*Use an if/else to output that the entered data is a valid or
                 invalid account number based on whether found is true or 
                 false*/
                if (found)
                {
                    cout<<"The entered number is a valid charge account ";
                    cout<<"number."<<endl<<endl;
                }
                else
                {
                    cout<<"The entered number is an invalid charge account ";
                    cout<<"number."<<endl<<endl;
                }
                break;
            }
            
            case '9':{
                
               //Declare and initialize variables here
                
                int SIZE = 25;

                /*array is the array of 25 integers that will be searched 
                 through by the linear search algorithm and binary search 
                 algorithm*/
                int array[SIZE] = {111, 222, 333, 444, 555, 667, 777, 888, 999, 
                                   1000, 1111, 1222, 1333, 1444, 1555, 1667, 
                                   1777, 1888, 1999, 2000, 2111, 2222, 2333, 
                                                                 2444, 2555};

                int value; /*value will be the variable into which the user 
                            enters a value that they want the searching
                            algorithms for search for*/

                //Briefly explain program

                cout<<"This program will call two separate functions. One ";
                cout<<"will use"<<endl;
                cout<<"the linear search algorithm to locate one of the ";
                cout<<"values and"<<endl;
                cout<<"another will use the binary search algorithm to ";
                cout<<"locate the"<<endl;
                cout<<"same value. The number of comparisons made by each ";
                cout<<"respective"<<endl;
                cout<<"algorithm will then be displayed."<<endl<<endl;

                //Output information

                /*Output the former half of the array so the user knows what 
                 values to choose from; use a for loop to do so*/
                for (int i = 0; i < SIZE - 12; i++)
                    cout<<array[i]<<"   ";

                cout<<endl;

                /*Output the latter half of the array so the user knows what 
                 values to choose from*/
                for (int i = SIZE - 12; i < SIZE; i++)
                    cout<<array[i]<<"   ";

                cout<<endl; 

               //Prompt the user to input data

                cout<<"Input the value you want the search algorithms to ";
                cout<<"locate. The"<<endl;
                cout<<"value should be one that is displayed above."<<endl;
                cin>>value;

                //Output the results 

                /*Call the linear function to display the number of comparisons
                 made using linear search*/
                linear (array, SIZE, value);

                /*Call the binary fuction to display the number of comparisons
                 made using binary search*/
                binary (array, SIZE, value);
                break;
            }
            default: 
                cout<<"You are now exiting the program.";
        }        
        
        
    }
    while (choice>='1' && choice<='9');
    //Exit stage right!
    return 0;
}

//*****************************************************************************
//*****************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 9

/*This function linear will accept the array, the size of the array, and the 
 value that is to be searched for as arguments; it will then display the number
 of comparisons it made using linear search until it found the value*/
void linear (int ary[], int size, int value)
{
    
    /*Declare and initialize the variables that are needed for a linear search 
     algorithm*/
    
    bool found = false; /*found will be set to false initially; once the value
                         is found, it will be set to true and it will cause the
                         while loop to stop iterating*/
    
    int numComp = 0; /*numComp will serve as the accumulator variable, 
                      keeping track of the number of comparisons made by the 
                      searching algoithm*/
    
    int index = 0; /*index will be used in the while loop to analyze each 
                    different element of the array each time the loop iterates*/
    
    /*Use the while loop with nested if statement to make comparisons 
     between the value and the elements of the array*/
    while (index < size && !found)
    {
        if (ary [index] == value)
        {
            found = true; /*if the element of an array at a particular index is 
                           equal to the value, found is set to true and the 
                           while loop stops iterating to stop searching*/
        }
        
        /*At the end of each iteration of the while loop, the index is 
         incremented so a new array element can be analyzed and the numComp
         is  incremented to keep track of the number of comparisons made*/
        index++;
        numComp++;
    }  
    
    /*Use an if/else statement to either display the number of comparisons made
     or display that the value was never found*/ 
    if (found)
    {
        //Output the number of comparisons made
        cout<<"The number of comparisons made with the linear search"<<endl;
        cout<<"algorithm was "<<numComp<<'.'<<endl;
    }
    else
        cout<<"The inputted value was never found in the array."<<endl;
        
}

/*This function binary will accept the array, the size of the array, and the 
 value that is to be searched for as arguments; it will then display the number
 of comparisons it made using binary search until it found the value*/
void binary (int ary[], int size, int value)
{
    /*Declare and initialize the variables that are needed for a binary search
     algorithm*/
    
    /*highest and lowest are variables that hold the index values of the lowest
     and highest elements of the array that have the value being searched for in
     their range ; continuously updated as while loop 
     keep searching through values*/
    int highest = size - 1; 
    int lowest = 0; 
    
    int medium; /*medium is the index of the medium most element value in the 
                 range in the array that can still hold the value being searched
                 for; continuously updated as the highest and lowest values 
                 are continuously updated*/
    
    bool found = false; /*found will be set to false initially; once the value
                         is found, it will be set to true and it will cause the
                         while loop to stop iterating*/ 
    
    int numComp = 0; //reinitialize numComp to 0
    
    /*Use a while loop to search through different elements of the array; nest
     if statements to update the highest, lowest, and medium indexes*/
    while (lowest <= highest && !found)
    {
        medium = (lowest+highest)/2;
        if (ary[medium]<value) /*If the value of the medium element in the array
                                is lower than the value being searched for,
                                the lowest in the possible range of the value 
                                becomes the element that is 1 index place 
                                greater than that of the initial medium*/
        {
            lowest = medium + 1;
        }
        
        else if (ary[medium] == value) /*If the value of the medium element in
                                        the array is the value being searched
                                        for, set found equal to true to stop
                                        the while loop from iterating*/
        {   
            found = true;
        }
        
        else  /*If the value of the medium element is higher than the value 
               being searched for, then the new highest element in the range
               of elements that can have the value is that which is associated
               with the index value 1 lower than that of the previous medium 
               element*/
        {
            highest = medium - 1;
        } 
        numComp++; /*Add 1 to the number of comparisons made each time the 
                    loop iterates*/
    }

    /*Use an if/else statement to either display the number of comparisons made
     or display that the value was never found*/ 
    if (found)
    {
        //Output the number of comparisons made
        cout<<"The number of comparisons made with the binary search"<<endl;
        cout<<"algorithm was "<<numComp<<'.'<<endl;
    }   
}   