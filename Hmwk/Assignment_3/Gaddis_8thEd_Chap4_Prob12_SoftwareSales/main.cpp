/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July, 5 2017,6:38 AM
 * Purpose:  Software Sales
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
    
    short int pckCost, pckAmnt;          /*pckCost is the amount one package
                                          retails for and pckAmnt is the number
                                          of units (packages) sold in a 
                                          purchase*/
    
    unsigned int totCost;                 /*totCost is the total cost of a 
                                          purchase of a certain number of 
                                          packages without taking discounts
                                          into account*/ 
    
     //Initialize variables
    
    pckCost = 99; //the amount one package retails for is $99
    
    //Input data
    
    cout<<"This program will calculate the total cost of a purchase of ";
    cout<<"packages that individually retail for $99"<<endl;
    cout<<"but get discounted by a certain percentage depending on the ";
    cout<<"quantity bought."<<endl<<endl;
    
    //Prompt the user to input the amount of packages sold in the purchase 
    cout<<"How many packages were sold in the purchase? Input the number ";
    cout<<"below. This number must be greater than 0."<<endl;
    cin>>pckAmnt;
    
    /*Use an if statement to not allow numbers 0 or lower to be inputted; 
     if the number is 0 or lower, end the program*/
    if (pckAmnt<=0)
    {    
        cout<<"This is an invalid input. Program shutting down.";
        return 0;
    }    
    
    //Map inputs to outputs or process the data
    
    totCost = pckCost*pckAmnt; /*The total cost of a certain number of packages
                                is the number of packages purchased X the cost
                                of one individual package*/
    
    //Output the transformed data
    
    //Set the numeric output formatting
    cout<<fixed<<setprecision(2);
    
    /*Output a specific path of code depending on the input of the amount of 
     packages purchased*/
    if (pckAmnt>0 && pckAmnt<10)
    {    
        cout<<"The total cost of the purchase has no discount with this amount";
        cout<<" of packages, so it is $"<<totCost*1.0f<<'.';
        //There is no discount when 0 to 9 packages are purchased
    }
    else if (pckAmnt>=10 && pckAmnt<=19)
    {    
        cout<<"Because "<<pckAmnt<<" packages were bought, there is a 20% ";
        cout<<"discount on this purchase, so the total cost is $";
        cout<<totCost-totCost*0.2f<<'.';
        //There is a 20% discount when 10 to 19 packages are purchased
    }
    else if (pckAmnt>=20 && pckAmnt<=49)
    {
        cout<<"Because "<<pckAmnt<<" packages were bought, there is a 30% ";
        cout<<"discount on this purchase, so the total cost is $";
        cout<<totCost-totCost*0.3f<<'.';
        //There is a 30% discount when 20 to 49 packages are purchased
    } 
    else if (pckAmnt>=50 && pckAmnt<=99)
    {
        cout<<"Because "<<pckAmnt<<" packages were bought, there is a 40% ";
        cout<<"discount on this purchase, so the total cost is $";
        cout<<totCost-totCost*0.4f<<'.';
        //There is a 40% discount when 50 to 99 packages are purchased
    }
    else
    {
        cout<<"Because "<<pckAmnt<<" packages were bought, there is a 50% ";
        cout<<"discount on this purchase, so the total cost is $";
        cout<<totCost-totCost*0.5f<<'.';
        //There is a 50% discount when 100 or more packages are purchased
    }
                
    //Exit stage right!
    return 0;
}