/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 29, 2017, 3:17 PM
 * Purpose:  Math Tutor
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Library for Time Function
#include <iomanip>   //Input - Output Manipulation Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Seed the random number generator using the system time
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    unsigned short int rand1, rand2, sum; /*rand1 is the first random
                                           number to be added, rand2 
                                           is the second random number
                                           to be added, and sum is 
                                           the sum of the two random
                                           numbers*/
    
    //Initialize variables
    rand1=rand()%501; /*The random number is initialized for the first
                        number to be in the range [0,500]*/
    rand2=rand()%501;  /*The random number is initialized for the second
                        number to be in the range [0,500]*/
                       /*Both random numbers are within the range [0,500] 
                        because it is assumed a "young student" will not be 
                        working with sums larger than 1000*/
    
    //Map inputs to outputs or process the data
    sum=rand1+rand2; /*The sum of the two random numbers is the first random
                      number added to the second random number*/
    
    //Output the transformed data
    cout<<"This program will serve as a math tutor, asking for two ";
    cout<<"random numbers to be added."<<endl;
    cout<<"The program will pause while the student adds the two numbers.";
    cout<<endl<<"When the student is ready to see the answer, they will press";
    cout<<" enter."<<endl<<endl;
   
    cout<<"Add the following and press enter to see the answer when ready:";
    cout<<endl;
    cout<<setw(4)<<rand1<<endl;
    cout<<'+'<<setw(3)<<rand2<<endl;
    cout<<"----";;
    /*Prompt the reader to add the two numbers and to press any key when 
     they are ready to see the answer*/
    
    cin.get();
    cout<<setw(4)<<sum<<endl;
    //Show the answer and use cin.get() so the user must press enter to do so
    
    //Exit stage right!
    return 0;
}