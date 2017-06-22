/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 21, 2017, 10:30 PM
 * Purpose:  Land Calculation
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
    float acre; 
    float tract; //tract refers to the large tract of land
    float trctAcr; //trctAcr refers to the large tract of land in acres
   
    //Initialize variables
    acre = 43560; //one acre is 43,560 square feet
    tract= 391876; //the large tract of land is 391,876 square feet
    
    
    //Map inputs to outputs or process the data
    trctAcr = tract/acre; /* To find the number of acres in the tract of land,
                           divide the amount of square feet in the tract by 
                           the amount of square feet in one acre*/
    
    //Output the transformed data
    cout<<"There are "<<trctAcr<<" acres in the tract of land.";
    
    //Exit stage right!
    return 0;
}