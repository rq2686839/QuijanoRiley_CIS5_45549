/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 29, 2017, 5:33 PM
 * Purpose:  Pizza Pi
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Computation Library
#include <iomanip>   //Input - Output Manipulation Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float pi = 3.14159; //pi is a global constant 

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float diam, rad, area, lftover; /*diam is the diameter of the pizza
                                     in inches, rad is the radius of 
                                     the pizza in inches, area is the 
                                     area of the pizza in inches squared,
                                     and lftover is the amount of area left
                                     over after making a certain amount of
                                     slices of area 14.125 inches squared*/
    
    unsigned short int slcAmnt;     /*slcAmnt is the number of slices that may
                                     be taken from the pizza*/
    
    float slcArea;                  //slcArea is the area of each slice of pizza
                                    
                                   
    //Initialize variables
    slcArea = 14.125;               /*The area of each slice of pizza is
                                     14.125 inches*/
    
    cout<<"This program will calculate the number of slices a pizza "<<endl;
    cout<<"of any size can be divided into by using the diameter of that"<<endl;
    cout<<"pizza and assuming each slice should have an area of 14.125"<<endl;
    cout<<"inches squared."<<endl<<endl;
    
    cout<<"Input the diameter of the pizza in inches below. Hit enter when ";
    cout<<"done."<<endl;
    cin>>diam;
    cout<<endl;
    //Prompt the reader to input the diameter of the pizza
       
    //Map inputs to outputs or process the data
    rad = diam/2;                    /*The radius of the pizza is half the 
                                      diameter*/
    
    area = pi*pow(rad, 2);           /*The area of the pizza in inches squared
                                      is pi times the radius (in inches)
                                      squared*/
    
    slcAmnt = area/slcArea;          /* The number of slices of area 14.125
                                      inches squared that can be made is the 
                                      area of the whole pizza divided by the 
                                     14.125 inches squared*/
    
    lftover = area - slcAmnt*slcArea;/*The area of the pizza left over that is 
                                      not large enough to be made into a whole 
                                      slice of area 14.125 inches squared is
                                      the area of the whole pizza minus the 
                                      product of the amount of slices and 
                                      the area of each of those slices*/
    
    //Output the transformed data
    cout<<"The amount of slices that can be taken from a pizza of diameter ";
    cout<<diam<<"in"<<endl;
    cout<<"assuming each slice is 14.125in^2 is "<<slcAmnt<<'.'<<endl;
    cout<<"The total area of the pizza is "<<fixed<<setprecision(3)<<area;
    cout<<"in^2,"<<endl;
    cout<<"and the total area of the "<<slcAmnt <<" slices is ";
    cout<<slcAmnt*slcArea<<"in^2,"<<endl;
    cout<<"so there is an area of "<<lftover<<"in^2 that";
    cout<<" is not designated to a slice."<<endl;
    
    //Exit stage right!
    return 0;
}