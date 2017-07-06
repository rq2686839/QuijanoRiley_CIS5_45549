/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 28, 2017, 3:59 PM
 * Purpose:  Male and Female Percentages
 */

//System Libraries
#include <iostream> //Input - Output Library
#include <iomanip>  //Input - Output Manipulation Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    unsigned short int mlAmnt, fmlAmnt, totAmnt; /*mlAmnt is the number of males 
                                                  registered in the class,
                                                  fmlAmnt is the number of 
                                                  females registered in the 
                                                  class, and totAmnt is the 
                                                  total number of students 
                                                  registered in the class*/
    
    float mlprct, fmlprct;                       /*mlprct is the percentage of 
                                                  males in the class and fmlprct
                                                  is the percentage of females
                                                  in the class*/
    
    //Initialize variables
    cout<<"This program will give the percentages of males and females";
    cout<<" registered in a class."<<endl<<endl;
    
    cout<<"Type the number of males registered in the class below and ";
    cout<<"hit enter when done."<<endl;
    cin>>mlAmnt;
    //Prompts the reader to input the number of males registered in the class 
    
    cout<<endl<<"Type the number of females registered in the class below ";
    cout<<"and hit enter when done."<<endl;
    cin>>fmlAmnt;
    cout<<endl;
    //Prompts the reader to input the number of females registered in the class
            
    //Map inputs to outputs or process the data
    totAmnt = mlAmnt + fmlAmnt; /* The total amount of students registered 
                                 in the class is the amount of males 
                                 registered plus the amount of females 
                                 registered*/
    
    mlprct = (static_cast<float>(mlAmnt) / totAmnt)*100;
    /*The percentage of males registered is calculated by dividing the amount
     of males in the class by the total amount of students in the class; 
     static cast done on amount of males to ensure male percentage comes out
     as float*/
    
    fmlprct = (static_cast<float>(fmlAmnt) / totAmnt)*100;
    /*The percentage of females registered is calculated by dividing the amount
     of females in the class by the total amount of students in the class; 
     static cast done on amount of females to ensure male percentage comes out
     as float*/
    
    //Output the transformed data
    cout<<"The percentage of males in the class is ";
    cout<<setprecision(4)<<mlprct<<"%."<<endl;
    cout<<"The percentage of females in the class is ";
    cout<<setprecision(4)<<fmlprct<<"%."<<endl;
    /*Output the percentage of males and females registered in the class to
     two decimal places*/
    
    //Exit stage right!
    return 0;
}