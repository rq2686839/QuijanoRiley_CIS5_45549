/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 21, 2017, 6:49 PM
 * Purpose:  Sales Prediction
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
    int yrSales; /*yrSales represents the amount the company has made 
                  in sales this year*/
    float prcnt; /*prcnt represents the percentage the sales
                  division will generate*/
    float ecGen; /* ecGen represents how much money the sales division
                  will generate*/
    
    //Initialize variables
    yrSales=8600000; //There is $8,600,000 in sales this year
    prcnt=0.58;      //The sales division will generate 58%
  
    //Input data
    ecGen=prcnt*yrSales; /* The amount of money the sales division
                          will generate is the amount the company has 
                          made in sales multiplied by the percentage
                          the sales division will generate*/
    
    
    //Output the transformed data
    cout<<"The East Coast division will generate $"<<ecGen;
    cout<<" if the company has $8.6 million in sales this year."<<endl;
    
    //Exit stage right!
    return 0;
}