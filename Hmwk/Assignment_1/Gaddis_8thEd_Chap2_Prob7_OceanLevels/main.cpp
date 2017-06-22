/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 21, 2017, 8:57 PM
 * Purpose:  Ocean Levels
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
    float riserat; //riserat is the rate the ocean's level is rising per year
    float fivyear; //fivyear represents five years 
    float sevyear; //sevyear represents seven years
    float tenyear; //tenyear represents ten years
   
    //Initialize variables
    riserat=1.5; //the ocean's level is rising 1.5 millimeters per year
    
    //Map inputs to outputs or process the data
    fivyear=riserat*5; /*Multiply the rate the ocean rises each year by 
                        five years to find out how much it has risen in five
                        years*/
    sevyear=riserat*7; /*Multiply the rate the ocean rises each year by 
                        seven years to find out how much it has risen in seven
                        years*/
    tenyear=riserat*10; /*Multiply the rate the ocean rises each year by 
                        ten years to find out how much it has risen in ten
                        years*/
    //Output the transformed data
    cout<<"After five years, the ocean will have risen "<<fivyear;
    cout<<" millimeters."<<endl;
    cout<<"After seven years, the ocean will have risen "<<sevyear;
    cout<<" millimeters."<<endl;
    cout<<"After ten years, the ocean will have risen "<<tenyear;
    cout<<" millimeters."<<endl;
    //Exit stage right!
    return 0;
}

