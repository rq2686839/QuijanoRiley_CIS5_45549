/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 21, 2017, 9:55 PM
 * Purpose:  Find the Distance per One Tank of Gas
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
    short int tnkSize;  /*tnkSize is the size of the gas tank in regard
                         to how many gallons it holds*/ 
    float mpgTown;      /*mpgTown is the miles per gallon the car gets
                         when driven in town*/
    float mpgHw;        /*mpgHw is the miles per gallon the car gets
                         when driven on the highway*/
    float disTown;      /*disTown is the distance the car can travel
                         on one tank of gas when driven in town*/
    float disHw;        /*disHw is the distance the car can travel on one tank  
                          of gas when driven on the highway*/
    //Initialize variables
    tnkSize = 20;  //the gas tank holds 20 gallons of gas
    mpgTown = 23.5; //the car gets 23.5 miles per gallon when driven in town
    mpgHw = 28.9;   //the car gets 28.9 miles per gallon when driven on highway
            
    //Map inputs to outputs or process the data
    disTown = tnkSize*mpgTown; /* the distance the car can travel on one tank 
                                when driven in town is the amount of gallons 
                                its tank holds, or tank size, multiplied by
                                its miles per gallon when driven in town*/
    disHw = tnkSize*mpgHw;     /* the distance the car can travel on one tank 
                                when driven on highway is the amount of gallons 
                                its tank holds, or tank size, multiplied by
                                its miles per gallon when driven on highway*/
    
    //Output the transformed data
    cout <<"The distance the car can travel on one tank of gas when driven";
    cout <<"in town is "<<disTown<<"."<<endl;
    cout <<"The distance the car can travel on one tank of gas when driven";
    cout <<" on highway is "<<disHw<<".";
    
    //Exit stage right!
    return 0;
}