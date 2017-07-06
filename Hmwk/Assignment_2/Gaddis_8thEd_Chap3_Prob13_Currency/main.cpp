/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 28, 2017, 5:59 PM
 * Purpose: Currency
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Input - Output Manipulation Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float YEN_PER_DOLLAR   = 98.93; //There is 98.93 yen per US Dollar
const float EUROS_PER_DOLLAR =  0.74; //There is 0.74 euros per US Dollar 

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float usdlr, yen, euros;  /*usdlr represents US Dollars, yen represents 
                               the yen currency, and euros represents the 
                               euro currency*/
    
   
    //Initialize variables
    cout<<"This program converts any U.S. Dollar amount to its equivalent ";
    cout<<"amount in both yen and euros."<<endl<<endl;
    cout<<"Type the amount of U.S. Dollars to be converted to yen and euros ";
    cout<<"below."<<endl;
    cin>>usdlr;
    //Prompts the reader to input a certain amount of US Dollars to be converted
    
    //Map inputs to outputs or process the data
    yen = usdlr*YEN_PER_DOLLAR;     /*Calculate the amount of yen by multiplying
                                     the US Dollar amount by the amount of yen 
                                     per US Dollar*/
    
    euros = usdlr*EUROS_PER_DOLLAR; /*Calculate the amount of euros by multiplying
                                     the US Dollar amount by the amount of euros 
                                     per US Dollar*/
   
    //Output the transformed data    
    cout<<"The amount of yen in "<<fixed<<setprecision(2)<<usdlr<<" U.S."; 
    cout<<" Dollars is ";
    cout<<fixed<<setprecision(2)<<yen<<'.'<<endl;
    //Display the amount of yen to two decimals places
    
    cout<<"The amount of euros in "<<fixed<<setprecision(2)<<usdlr<<" U.S.";
    cout<<" Dollars is ";
    cout<<fixed<<setprecision(2)<<euros<<'.'<<endl;
            
    
    //Exit stage right!
    return 0;
}