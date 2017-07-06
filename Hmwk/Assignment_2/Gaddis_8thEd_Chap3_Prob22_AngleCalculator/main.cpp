/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 29, 2017, 6:57 PM
 * Purpose:  Template
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cmath>     //Math Computation Library
#include <iomanip>   //Input - Output Manipulation Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    float angle, sine, cosine, tangent; /*Angle is angle inputted  by
                                         the user in radians, sine is 
                                         the sine of that inputted angle,
                                         cosine is the cosine of that inputted
                                         angle, and tangent is the tangent 
                                         of that inputted angle*/
    
    //Initialize variables
    cout<<"This program will calculate the sine, cosine, and tangent of an ";
    cout<<"angle inputted in radians."<<endl<<endl;
    
    cout<<"Input the angle in radian below. Press enter when done."<<endl;
    cin>>angle;
    cout<<endl;
            
    //Map inputs to outputs or process the data
    sine = sin(angle);
    cosine = cos(angle);
    tangent = tan(angle);
    
    //Output the transformed data
    cout<<"The sine of the angle = "<<fixed<<setprecision(4)<<sine<<endl;
    cout<<"The cosine of the angle = "<<fixed<<setprecision(4)<<cosine<<endl;
    cout<<"The tangent of the angle = "<<fixed<<setprecision(4)<<tangent<<endl;
    
    
    //Exit stage right!
    return 0;
}