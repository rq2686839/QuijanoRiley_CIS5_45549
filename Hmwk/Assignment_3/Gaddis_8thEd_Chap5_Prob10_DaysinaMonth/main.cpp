/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 4, 2017,4:25 PM
 * Purpose:  Days in a Month
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    short int month;          /*month is the variable into which the user will 
                                put a month 1-12, where 1 is January, 2 is 
                                February, etc.*/
                              
    
    int year;                 /*year is the variable into which the user will
                                put any year from 1582 to  2,000,000,000 */
    
    //Input data
    
    cout<<"This program will display the number of days in a month of any ";
    cout<<"inputted year from 1582"<<endl;
    cout<<"(when the Gregorian calendar was put into ";
    cout<<"effect) to 2,000,000,000, taking into account leap years."<<endl<<endl;
           
    //Prompt the reader to input the year 
    cout<<"Input a year below and hit enter when done. This year must be"<<endl;
    cout<<"within the range 1582 to 2,000,000,000."<<endl;
    cin>>year;
    
    /*Use an if statement to make sure years only from 1582 to 2,000,000 are
    inputted; if a year does not meet this criteria, end the program*/
    if (year>2000000000 || year<1582 )
    {    
        cout<<"This is an invalid input. The program will now end.";
        return 0;
    }
    /*Prompt the reader to input a number associated with a month January 
     through December*/
    cout<<"Input a month below by typing a number from 1 to 12, where 1";
    cout<<" is January, 2 is February, etc."<<endl;
    cin>>month;
    
    /*Use an if statement to make sure months only from 1 to 12
      are inputted; if a month number is outside this range, end the program*/
    if (month<1 || month>12)
    {    
        cout<<"This is an invalid input. The program will now end.";
        return 0;
    }    
    
    
    //Process the data/output the results 
    
    /*Use a switch statement to determine what the  output will be for a 
     given inputted month*/
    switch (month)
    {        
            case 1: 
                cout<<"There are 31 days in this month of the inputted ";
                cout<<"year.";
                break;
            
            case 2:
                /*It is a leap year if the year is 1752 or higher 
                 because that was the first leap year, the year has no
                 remainder when divided by 100, and the year has no 
                 remainders when divided by 400*/
                if ((year>=1752)&&(year % 100 == 0)&&(year % 400 == 0)) 
                    
                {
                    cout<<"This is a leap year, so there are 29 days in ";
                    cout<<"this month of the inputted year.";
                }
                /*It is a leap year if the year is 1752 or higher, the year 
                 has a remainder when divided by 100, and the year has 
                 no remainder when divided by 4*/
                else if ((year>=1752)&&(year % 100 != 0)&&(year % 4 == 0))    
                {
                    cout<<"This is a leap year, so there are 29 days in ";
                    cout<<"this month of the inputted year.";
                }
                else 
                {
                    cout<<"There are 28 days in this month of the inputted ";
                    cout<<"year.";
                }    
                break;            
            
             case 3:
                cout<<"There are 31 days in this month of the inputted ";
                cout<<"year.";
                break;
                
             case 4:
                 cout<<"There are 30 days in this month of the inputted ";
                 cout<<"year.";
                 break;
                 
            case 5:
                cout<<"There are 31 days in this month of the inputted ";
                cout<<"year.";
                break;
                
            case 6:
                cout<<"There are 30 days in this month of the inputted ";
                cout<<"year.";
                break;
                
            case 7:
                cout<<"There are 31 days in this month of the inputted ";
                cout<<"year.";
                break;
             
            case 8:
                cout<<"There are 31 days in this month of the inputted ";
                cout<<"year.";
                break;
                
            case 9:
                cout<<"There are 30 days in this month of the inputted ";
                cout<<"year.";
                break;
                
            case 10:
                cout<<"There are 31 days in this month of the inputted ";
                cout<<"year.";
                break;
                
            case 11:
                cout<<"There are 30 days in this month of the inputted ";
                cout<<"year.";
                break; 
                
            case 12:
                cout<<"There are 31 days in this month of the inputted ";
                cout<<"year.";
                break;
    }
    //Output the transformed data
    
    
    //Exit stage right!
    return 0;
}