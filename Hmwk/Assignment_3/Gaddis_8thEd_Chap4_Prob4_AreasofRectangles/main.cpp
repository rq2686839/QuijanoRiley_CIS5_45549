/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 4, 2017, 11:12 AM
 * Purpose:  Areas of Rectangles
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
    
    float width1, length1, area1;    /*width1 is the width of the first 
                                      rectangle, length1 is the length of 
                                      the first rectangle, and area1 is the
                                      area of the first rectangle*/
    
    float width2, length2, area2;    /*width2 is the width of the second
                                      rectangle, length2 is the length of 
                                      the second rectangle, and area2 is the 
                                      area of the second rectangle*/
    
    //Input data
    
    //Prompt the user to input the width and length for the first rectangle
    cout<<"This program will ask the user for the lengths and widths of two";
    cout<<" different rectangles and then compare their areas."<<endl<<endl;
    
    cout<<"What is the length and width of the first rectangle?"<<endl;
    cout<<"Enter the length and hit enter once. Then, enter the width and";
    cout<<" hit enter once."<<endl;
    cin>>length1>>width1;
    
    /*Use an if statement to not allow negative numbers to be inputted for 
     width1 or length1; if either is negative, end the program*/  
    if (length1<0 || width1<0)
    {
        cout<<"One or both of the inputs are invalid because they are negative.";
        cout<<"Program shutting down.";
        return 0;
    }
        
    //Prompt the user to input the width and length for the second rectangle
    cout<<"What is the length and width of the second rectangle?"<<endl;
    cout<<"Enter the length and hit enter once. Then, enter the width and";
    cout<<" hit enter once."<<endl;
    cin>>length2>>width2;
    
    /*Use an if statement to not allow negative numbers to be inputted for 
     width2 or length2; if either is negative, end the program*/ 
    if (length2<0 || width2<0)
    {
        cout<<"One or both of the inputs are invalid because they are negative.";
        cout<<"Program shutting down.";
        return 0;
    }
    
    //Map inputs to outputs or process the data
    
    area1 = length1*width1; /*The area of the first rectangle equals its width
                             times its length*/
     
    area2 = length2*width2; /*The area of the second rectangle equals its width
                            times its length*/
    
    //Output which area is larger or if the areas are equal
    
    //Choose which is the appropriate output of string using if/else if statements
    if (area1>area2)
    {
        cout<<"The area of the first rectangle, "<<area1<<",is bigger than the";
        cout<<"area of the second rectangle, "<<area2<<'.'<<endl;
    }
    else if (area2>area1)
    {
        cout<<"The area of the the second rectangle, "<<area2<<", is bigger";
        cout<<" than the area of the first rectangle,"<<area1<<'.';
    }  
    else
    {    
        cout<<"The two rectangles have equal areas of "<<area1<<'.';
    }
    
     //Exit stage right!
    return 0;
}