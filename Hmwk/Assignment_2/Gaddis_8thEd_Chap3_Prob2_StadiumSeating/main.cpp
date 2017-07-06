/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 28, 2017, 1:00 PM
 * Purpose:  Stadium Seating 
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare all Variables Here
    float priceA, priceB, priceC;              /*priceA represents the price of 
                                                class A seats, priceB
                                                represents the price of class B
                                                seats, and priceC represents 
                                                the price of class C seats*/

    unsigned int classA, classB, classC;       /*classA is the number of class A
                                                seats, classB is the number of 
                                                class B seats, and classC is the
                                                number of class C seats*/
    
    float totSale;                             /*totSale is the total income
                                                generated from ticket sales*/
    
    
    //Input or initialize values Here
    priceA = 15.00;  //Class A seats are $15 a seat
    priceB = 12.00;  //Class B seats are $12 a seat
    priceC = 9.00;   //Class C seats are $9 a seat
    
    cout<<"This program will calculate the amount of income generated";
    cout<<" at a stadium "<<endl;
    cout<<"selling three different kinds of tickets.";
    cout<<endl<<endl; 
    cout<<"How many tickets for class A seats were sold? ";
    cout<<"Type the number below ";
    cout<<"and hit enter when done:"<<endl;
    //Ask the user to input how many class A seats were sold
    
    cin>>classA; //Input the amount of class A seats that were sold
    
    cout<<"How many tickets for class B seats were sold? ";
    cout<<"Type the number below ";
    cout<<"and hit enter when done:"<<endl;
    //Ask the user to input how many class B seats that were sold
    
    cin>>classB; //Input the amount of class B seats that were sold
    
    cout<<"How many tickets for class C seats were sold? ";
    cout<<"Type the number below ";
    cout<<"and hit enter when done:"<<endl;
    //Ask the user to input how many class C seats that were 
    
    cin>>classC; //Input the amount of class C seats that were sold
   
    //Process/Calculations Here
    totSale = priceA*classA + priceB*classB + priceC*classC;
    /*The total income generated from ticket sales is the amount of 
    seat A tickets sold times the price of each seat A ticket plus
    the amount of seat B tickets sold times the price of each seat B
    ticket plus the amount of seat C tickets sold times the price
    of each seat C ticket*/
    
    //Output Located Here
    cout<<"The amount of income generated from ticket sales = $";
    cout<<fixed<<setprecision(2)<<totSale<<'.'<<endl;
    //Output the total income value as a decimal to two places
    
    cout<<"This is when "<<classA<<" A tickets are sold at $"<<priceA;
    cout<<" each, "<<endl<<classB<<" B tickets are sold at $" <<priceB;
    cout<<" each, and "<<classC<<" C tickets"<<endl;
    cout<<"are sold at $"<<priceC<<" each.";
    cout<<endl;

    //Exit
    return 0;
}

