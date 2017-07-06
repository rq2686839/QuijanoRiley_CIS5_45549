/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July, 5 2017, 9:37 PM
 * Purpose:  Mobile Service Provider
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Input - Output Manipulation
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    //Declare variables
    
    float price;    /*price is the total amount due for the customer's monthly
                     bill*/
    
    char pckg;      /*pckg is the package that the customer has purchased
                     (to be inputted by user after a menu)*/
   
    short int mins;  //mins is the amount of minutes the customer used
    
    //Prompt the user to input data based on a menu
    
    cout<<"This program will calculate a customer's monthly mobile phone"<<endl;
    cout<<"service bill given the customer's subscription package and"<<endl;
    cout<<"the number of minutes they used."<<endl<<endl;
    
    cout<<"Which package has the customer purchased? Input the package"<<endl;
    cout<<"below by typing the letter to the left of the package type"<<endl;
    cout<<"and hitting enter when done. Only valid inputs are A, B, or C"<<endl;
    cout<<"A. Package A, which costs $39.99 per month with 450 minutes; ";
    cout<<"additional minutes are each $0.45."<<endl<<endl;
    cout<<"B. Package B, which costs $59.99 per month with 900 minutes; ";
    cout<<"additional minutes are each $0.40."<<endl<<endl;
    cout<<"C. Package C, which costs $69.99 per month with unlimited minutes";
    cout<<endl;
    cin>>pckg;
    
    //Use an if statement to end the program if an invalid letter is inputted
    if (!(pckg == 'A' || pckg == 'B' || pckg == 'C'))
    {
        cout<<"Invalid menu choice. Program shutting down.";
        return 0;
    }    
    
    //Prompt the user to input the minutes used by the customer
    cout<<"How many minutes were used by the customer? Input the amount"<<endl;
    cout<<"below and hit enter when done. Do not input a negative value."<<endl;
    cin>>mins;
    
    //Use an if statement to end the program if the input is invalid
    if (mins<0)
    {
        cout<<"Invalid input. Program shutting down.";
        return 0;
    }

    /*Have a particular path of code be calculated and outputted depending
     on the menu choice that was made*/
    
    
    /*Use a switch with nested if statements(that will determine additional 
     prices based on additional minutes) to determine the output*/
    switch (pckg)
    {
        case 'A':
            mins>450 ? price = 39.99f + (mins-450)*0.45f 
                     : price = 39.99;
            cout<<"The monthly bill is $"<<price<<'.';
        break;
        
        case 'B':
            mins>900 ? price = 59.99f + (mins-900)*0.4f 
                     : price = 59.99;
            cout<<"The monthly bill is $"<<price<<'.';
        break;
        
        default:
            price = 69.99;
            cout<<"The monthly bill is $"<<price<<'.';
    }        
    
    //Exit stage right!
    return 0;
}