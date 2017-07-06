/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on June 29, 2017,7:15 PM
 * Purpose:  Word Game
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
    char name[40], age[4], city[40], college[100], prfsn[30], animal[25],
            petName[40];
    /*name is the user's name to be inputted, age is their age to be inputted,
     city is their choice of city to be inputted, college is their choice 
     of college to be inputted, prfsn is their choice of profession to be 
     inputted, animal is a type of animal to be inputted, and petName is 
     a pet name to be inputted*/
   
    //Input data
    cout<<"This program will play a word game with the user! Enter the ";
    cout<<"information"<<endl;
    cout<<"requested in the following lines to have a story ";
    cout<<"generated using these names."<<endl<<endl;
    
    cout<<"Enter your name below and hit enter when done."<<endl;
    cin.getline(name, 40);
    cout<<endl;
    
    cout<<"Enter your age below and hit enter when done."<<endl;
    cin.getline(age, 4);
    cout<<endl;
    
    cout<<"Enter the name of a city below and hit enter when done."<<endl;
    cin.getline(city, 40);
    cout<<endl;
    
    cout<<"Enter the name of a college below and hit enter when done."<<endl;
    cin.getline(college, 100);
    cout<<endl;
    
    cout<<"Enter a profession below and hit enter when done."<<endl;
    cin.getline(prfsn, 30);
    cout<<endl;
    
    cout<<"Enter a type of animal below and hit enter when done."<<endl;
    cin.getline(animal,25);
    cout<<endl;
    
    cout<<"Enter a pet's name below and hit enter when done."<<endl;
    cin.getline(petName, 40);
    cout<<endl;
    /*Prompt the user to input all of the information needed to fill out the 
     story in the next chunk of output*/
    
    //Output the transformed data
    cout<<"There once was a person named "<<name<<" who lived in "<<city<<'.';
    cout<<endl;
    cout<<"At the age of "<<age<<", "<<name;
    cout<<" went to college at "<<college<<'.'<<endl;
    cout<<name<<" graduated and went to work as a "<<prfsn<<'.';
    cout<<endl<<"Then, "<<name;
    cout<<" adopted a(n) "<<animal<<" named "<<petName<<". They both"<<endl;
    cout<<"lived happily ever after!"<<endl;
            
            
    
    
    //Exit stage right!
    return 0;
}