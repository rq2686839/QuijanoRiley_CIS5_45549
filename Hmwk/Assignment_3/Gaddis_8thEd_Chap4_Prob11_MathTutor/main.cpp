/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 4, 2017,6:45 PM
 * Purpose:  Math Tutor
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <cstdlib>   //C Standard Library for use of rand() function
#include <ctime>     //C Time Library for Time Functions
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
   
    unsigned short int num1, num2, sum, answ; /*num1 is the first random number
                                               num2 is the second random number,
                                               sum is the sum of those two 
                                               random numbers to be added by the 
                                               student, and answ is the answer
                                               to the problem the student will
                                               input*/
    //Initialize variables
    
    num1 = rand() % 501; /*num1 is the first of the two random numbers to be 
                         added, having a range from 0 to 500*/
    
    num2 = rand() % 501; /*num2 is the second of the two random numbers to be 
                          added, having a range from 0 to 500; both random 
                          numbers have a maximum value of 500 because it is
                          assumed a young student will not work with sums 
                          larger than 1000*/
    
    
    //Input data
    
    cout<<"This program will display two random numbers to be added by a ";
    cout<<"young student. When the student is ready to answer, they will"<<endl;
    cout<<"input what they got as the sum. The program will then let them ";
    cout<<"know if their inputted answer is correct."<<endl<<endl;
    
    //Prompt the user to input their answer to the addition problem
    cout<<"Please do the following problem. When solved, type";
    cout<<" the answer and hit enter to find out if the answer is right!"<<endl;
    cout<<"  "<<setw(3)<<num1<<endl;
    cout<<"+ "<<setw(3)<<num2<<endl;
    cout<<"-----"<<endl;
    cin>>answ;
    
    //Map inputs to outputs or process the data
    
    sum = num1 + num2; //sum is the sum of the two random numbers
    
    //Output a particular path of code depending on the input
    
    /*Use a ternary operator to output either that the inputted answer is 
     correct or that it is incorrect */
    answ == sum ? cout<<"Congratulations! That is the correct answer." 
              : cout<<"That is incorrect. The answer is "<<sum<<'.';
    
    
    //Exit stage right!
    return 0;
}