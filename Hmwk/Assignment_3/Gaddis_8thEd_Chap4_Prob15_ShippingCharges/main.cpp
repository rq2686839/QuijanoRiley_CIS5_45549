/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July, 5 2017, 3:59 PM
 * Purpose:  Shipping Charges
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
    float rate, dist, weight, totChrg; /*rate is the rate charged per 500 
                                        miles shipped, dist is the total 
                                        distance the package is shipped, weight
                                        is the weight of the package being 
                                        shipped, and totChrg is the total 
                                        charges of the shipping*/ 
  
                                       
    //Input data
    
    cout<<"This program will calculate the shipping charges for a package ";
    cout<<"being shipped by the Fast Freight Shipping Company "<<endl;
    cout<<"by taking into consideration the distance the package is being ";
    cout<<"shipped and how heavy the package is."<<endl<<endl;
    
    //Prompt the reader to input the distance the package will be shipped
    cout<<"Input the distance the package will be shipped in miles below. ";
    cout<<"The distance must be at least 10 miles but no more than"<<endl;
    cout<<"3,000 miles, as the Fast Freight Shipping Company only ships in ";
    cout<<"this range."<<endl;
    cin>>dist;
    
    /*Use an if statement to end the program if the inputted distance is 
     less than 10 miles or more than 3,000 miles*/
    if (dist<10 || dist>3000)
    {
        cout<<"The package cannot be shipped over this distance. Program ";
        cout<<"shutting down.";
        return 0;
    }    
            
    
    //Prompt the reader to input the weight of the package in kilograms*/
    cout<<"Input the weight of the package in kilograms below. The weight";
    cout<<" must be higher than 0 and no higher than 20kg, the maximum"<<endl;
    cout<<"the Fast Freight Shipping Company will ship."<<endl;
    cin>>weight;

    //Output the transformed data
    
    //Set the format of numerical output
    cout<<fixed<<setprecision(2);

    /*Output a specific path of code depending on the weight that is inputted
     by using a series of if/else if statements*/
     if (weight>0 && weight<=2)
     {
         rate = 1.10f;              /*If the weight is more than 0 but not more
                                      than 2kg, the rate is $1.10
                                      per 500 miles shipped*/
         
         totChrg = (rate/500)*dist; /*The total charges in $ of the shipping is 
                                     whatever the rate is per 500 miles shipped  
                                     divided by 500 X the distance shipped in
                                     miles; it is important to note that this
                                     calculation assumes that even though the 
                                     rate per 500 miles is given,
                                     charges at this rate are accumulated 
                                     per each mile driven*/
         
         cout<<"The total charges of this shipping is $"<<totChrg<<" as this ";
         cout<<"package weight means there is a shipping rate of $"<<rate<<endl;
         cout<<"per 500 miles.";
     }
     else if (weight>2 && weight<=6)
     {
         rate = 2.20f;  /*If the weight is more than 2kg but not more than
                         6kg, the rate is $2.20 per 500 miles shipped*/
         
         totChrg = (rate/500)*dist; 
         
         cout<<"The total charges of this shipping is $"<<totChrg<<" as this ";
         cout<<"package weight means there is a shipping rate of $"<<rate<<endl;
         cout<<"per 500 miles.";
     } 
     else if (weight>6 && weight<=10)
     {
         rate = 3.70f;  /*If the weight is more than 6kg but not more than
                         10kg, the rate is $3.70 per 500 miles shipped*/
         
         totChrg = (rate/500)*dist; 
         
         cout<<"The total charges of this shipping is $"<<totChrg<<" as this ";
         cout<<"package weight means there is a shipping rate of $"<<rate<<endl;
         cout<<"per 500 miles.";
     } 
     else if (weight>10 && weight<=20)
     {
         rate = 4.80f;  /*If the weight is more than 10kg but not more than
                         20kg, the rate is $4.80 per 500 miles shipped*/
         
         totChrg = (rate/500)*dist; 
         
         cout<<"The total charges of this shipping is $"<<totChrg<<" as this ";
         cout<<"package weight means there is a shipping rate of $"<<rate<<endl;
         cout<<"per 500 miles.";
     } 
     else
         cout<<"This is an invalid input. Program now ending.";
     
    //Exit stage right!
    return 0;
}