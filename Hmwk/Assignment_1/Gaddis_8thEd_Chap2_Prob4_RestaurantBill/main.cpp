/* 
 * File:   main.cpp
 * Author: Riley Qujano
 * Created on June 21, 2017, 7:42PM
 * Purpose:  Calculate Restaurant Bill
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
    float mlcost; //mlcost is the meal cost on the restaurant bill
    float tax;
    float tip;
    float totCost; //totCost is the total bill 
    //Initialize variables
    mlcost=88.67;
           
    //Input data
    tax=mlcost*0.0675; /*Multiply the meal cost by the tax percentage
                       6.75% to get the tax amount in dollars*/
    tip=(mlcost+tax)*0.2; /*Multiply the meal cost plus the tax amount
                          by the tip percentage 20% to get the tip amount
                          in dollars*/ 
    totCost=mlcost+tax+tip; /*Add the meal cost, the tax amount, and the tip
                             amount to get the total bill*/
    //Map inputs to outputs or process the data
    
    //Output the transformed data
    cout<<"The meal cost is $"<<mlcost<<"."<<endl;
    cout<<"The tax amount is $"<<tax<<"."<<endl;
    cout<<"The tip amount is $"<<tip<<"."<<endl;
    cout<<"The total bill is $"<<totCost<<".";
    //Exit stage right!
    return 0;
}