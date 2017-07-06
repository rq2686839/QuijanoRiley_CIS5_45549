/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 28, 2017, 4:54 PM
 * Purpose:  How Many Calories?
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
    unsigned short totCook, srvings, calpsrv; /*totCook is the total number of 
                                               cookies a bag holds, srvings is
                                               the number of servings in the
                                               bag, and calpsrv is the number
                                               of calories per serving*/
    
    float cookEat, calEat;                    /* cookEat is the total number of
                                               cookies eaten and calEat is 
                                               the total calories consumed*/
    unsigned short totCal, calpcki;           /* totCal is the total number of
                                              calories in the bag and calpcki
                                              is the total number of calories
                                              per cookie*/ 
                                              
    
    
    //Initialize variables
    totCook = 30;  //The total number of cookies the bag holds is 30
    srvings = 10;  //The total number of servings in the bag is 10
    calpsrv = 300; //The number of calories per serving is 300
            
    //Input data
    cout<<"This program will calculate the total calories consumed by someone";
    cout<<" based on the amount of cookies they eat."<<endl<<"This is based on the";
    cout<<" knowledge that they are eating cookies from a bag with 30 cookies,";
    cout<<" 10 servings, and 300 calories per serving."<<endl<<endl;
    //Explain what the calculation is based on
    
    cout<<"Type the amount of cookies eaten below and press enter when done:";
    cout<<endl;
    cin>>cookEat;
    //Prompt the reader to input the amount of cookies eaten
            
    //Map inputs to outputs or process the data
    totCal = srvings*calpsrv;   /*Calculate total calories in the bag by
                                multiplying servings in the bag by calories
                                per serving*/
    calpcki = totCal / totCook; /*Calculate the calories per cookie by dividing
                                the total calories in the bag by the total 
                                cookies in the bag*/
    calEat = calpcki*cookEat;   /* Calculate the number of calories eaten by 
                                multiplying the calories per cookie by the 
                                number of cookies eaten*/       
    //Output the transformed data
    cout<<"The total number of calories eaten by someone who has eaten ";
    cout<<cookEat<<" cookie(s) is "<<calEat<<'.'<<endl;
    
    //Exit stage right!
    return 0;
}