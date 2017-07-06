/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 4, 2017,12:49 PM
 * Purpose:  Body Mass Index
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
 
    float height, weight, bmi; /* height is the height of the person whose BMI
                                is to be calculated, weight is the weight of 
                                the person whose BMI is to be calculated, 
                                and bmi is the person's calculated body 
                                mass index*/
                                
    //Input data
    
    cout<<"This program will calculate the BMI of a person with a sedentary ";
    cout<<endl;
    cout<<"lifestyle using their height in inches and weight in pounds.";
    cout<<endl<<endl;
   
    /*Prompt the reader to input their weight in pounds where acceptable 
     values are 1 lb to 1400 lbs*/
    cout<<"Input the person's weight in pounds below and hit enter when done.";
    cout<<" Acceptable range is 1 lb to 1400 lbs."<<endl;
    cin>>weight;
    
    /*Use an if statement to end the program if a value outside the range is
     inputted*/
    if (weight>1400 || weight<1)
    {
        cout<<"An invalid weight was entered. Program now shutting down.";
        return 0;
    }  
    
    /*Prompt the reader to input their height in inches where acceptable 
     values are 1 ins to 108 ins*/
    cout<<"Input the person's height in inches below and hit enter when done.";
    cout<<" Acceptable range is 1 inch to 108 inches."<<endl;
    cin>>height;
    
    /*Use an if statement to end the program if a value outside the range is
     inputted*/
    if (height>108 || height<1)
    {
        cout<<"An invalid height was entered. Program now shutting down.";
        return 0;
    }  
   
    //Map inputs to outputs or process the data
    
    //Calculate BMI, which is weight (lbs) x 703 / (height (in.))^2
    bmi = weight*703/(height*height);
    
    //Output if the person is underweight, optimal weight, or overweight 
    
    //Set the numeric output format
    cout<<fixed<<setprecision(2);
    
    /*Choose which is the appropriate output of string using if/else 
     if statements given that optimal weight range is from 18.5 to 25,
     underweight range is less than 18.5, and overweight range is more than 
     25*/
    if (bmi<=25 && bmi>=18.5)
    {    
        cout<<"This sedentary person has an optimal weight because their BMI ";
        cout<<"is "<<bmi<<", which is in the optimal range of 18.5 to 25.";
    }
    else if (bmi<25)
    { 
        cout<<"This sedentary person is underweight because their BMI is ";
        cout<<bmi<<", which is in the underweight range of below 18.5.";
    }   
    else 
    {
        cout<<"This sedentary person is overweight because their BMI is ";
        cout<<bmi<<", which is in the overweight range of above 25.";
    }   
    //Exit stage right!
    return 0;
}