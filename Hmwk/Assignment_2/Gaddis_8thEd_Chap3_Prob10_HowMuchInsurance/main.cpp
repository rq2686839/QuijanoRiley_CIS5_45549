/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 29, 2017, 6:38 AM
 * Purpose:  How Much Insurance
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Input - Output Manipulation Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float rplcCst, insPrct, insTot; /*rplcCst is the amount it would cost to 
                                    replace the structure, insPrct is the 
                                    the percent of the replace cost that one
                                    should pay toward insurance, and insTot
                                    is the minimum dollar amount one pays toward
                                    their insurance*/
   
    //Initialize variables
    insPrct = 0.8; /*The percentage of of the replace cost that should go 
                    toward insurance is 80%, or 0.8*/
    
    cout<<"This program will calculate the minimum amount of "<<endl;
    cout<<"insurance one should buy for a property "<<endl;
    cout<<"based on the replacement cost of the structure.";
    cout<<endl<<endl;
    
    cout<<"What is the replacement cost of the structure? "<<endl;
    cout<<"Enter the value below and hit enter when done."<<endl;
    cin>>rplcCst;
    //Prompt the reader to input the replacement cost of a structure
    
    //Map inputs to outputs or process the data
    insTot = rplcCst*insPrct; /*The minimum total amount of dollars one pays
                               to their insurance is the replacement cost
                               of the structure times the percentage of that 
                               cost that should go toward insurance*/
                                
    //Output the transformed data
    cout<<"The minimum amount of insurance that should be bought for ";
    cout<<"the property is $"<<fixed<<setprecision(2)<<insTot<<'.'<<endl;
    
    //Exit stage right!
    return 0;
}