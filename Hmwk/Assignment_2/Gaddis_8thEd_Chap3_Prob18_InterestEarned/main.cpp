/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 29, 2017, 4:16 PM
 * Purpose:  Interest Earned
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Computation Library
#include <iomanip>
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    short unsigned int compYr; /*compYr is the number of times 
                              the interest is compounded in a year*/
    
    float prncpl, rate, amntInt, amntTot; /*prncpl is the balance in the savings 
                                           account at the start of the year, rate 
                                           is the interest rate,  amntTot is the 
                                           balance in the savings account after 
                                           one year, and amntInt is the dollar 
                                           amount of interest*/
    
    //Initialize variables
    cout<<"This program will calculate the balance in a savings account ";
    cout<<endl;
    cout<<"after one year given an interest rate, the number of times the ";
    cout<<endl;
    cout<<"interest is compounded during the year, and the principal.";
    cout<<endl<<endl;
    
    cout<<"Enter the principal below. Press enter when done."<<endl;
    cin>>prncpl;
    cout<<"Enter the interest rate below as a percentage. Press enter when ";
    cout<<"done."<<endl;
    cin>>rate;
    cout<<"Enter the number of times the interest is compounded during the ";
    cout<<"year. Press enter when done."<<endl;
    cin>>compYr;
    cout<<endl;
    /*Prompt the reader to input the principal, the interest rate percentage,
     and and the number of times the interest is compounded*/
    
    //Map inputs to outputs or process the data
    amntTot = prncpl*pow((1+(rate/100)/compYr),compYr);
    /*Amount in the account after 1 year is 
     principal x (1+InterestRate/NumberofCompounds)^Number of Compounds*/
    amntInt = amntTot - prncpl;
    /*The interest amount in dollars is the total in the account 
     after one year minus the principal*/
    
    //Output the transformed data
    cout<<"Interest Rate:           "<<setw(10)<<rate<<'%'<<endl;
    cout<<"Times Compounded:        "<<setw(10)<<compYr<<endl;
    cout<<"Principal:              $"<<fixed<<setw(10)<<setprecision(2);
    cout<<prncpl<<endl;
    cout<<"Interest:               $"<<fixed<<setw(10)<<setprecision(2);
    cout<<amntInt<<endl;
    cout<<"Amount in Savings:      $"<<fixed<<setw(10)<<setprecision(2);
    cout<<amntTot<<endl;
    
    
    
    //Exit stage right!
    return 0;
}