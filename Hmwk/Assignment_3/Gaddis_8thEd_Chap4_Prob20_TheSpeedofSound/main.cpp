/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 5, 2017,5:21PM
 * Purpose:  The Speed of Sound
 */

//System Libraries
#include<iostream>  //Input - Output Library
#include<iomanip>   //Input - Output Manipulation Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const unsigned short int SPD_AIR = 1100; /*SPD_AIR is the speed at which sound 
                                         travels through air; this speed is 
                                         1,100 feet per second*/

const unsigned short int SPD_WTR = 4900;  /*SPD_WTR is the speed at which sound
                                         travels through water; this speed is
                                         4,900 feet per second*/

const unsigned short int SPD_STL = 16400; /*SPD_STL is the speed at which sound 
                                         travels through steel; this speed is
                                         16,400 feet per second*/
//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    
    float dist, time; /*dist is the inputted distance (in feet) a sound wave 
                       will travel in a particular medium, and time is the time 
                       (in seconds) it takes for the sound wave to travel the
                       inputted distance*/
   
    char medium;      /*medium is the variable into which the user will input 
                       the letter associated with a particular medium on
                       the menu*/
   
    //Display a menu and have the user make a selection
   
    cout<<"This program will ask the user to select if a sound wave travels";
    cout<<" through air, water, or steel. "<<endl;
    cout<<"After the user selects one, ";
    cout<<"they input a distance. The program will calculate how "<<endl;
    cout<<"long it takes sound to travel that distance through the "<<endl;
    cout<<"selected medium."<<endl;
    cout<<endl;
    
    cout<<"The menu below displays 3 mediums through which a sound wave can ";
    cout<<"travel."<<endl<<"Choose one medium by inputting";
    cout<<" the letter that comes"<<endl;
    cout<<"immediately before that medium and hitting enter after."<<endl;
    cout<<"A. Air"<<endl;
    cout<<"B. Water"<<endl;
    cout<<"C. Steel"<<endl;
    cin>>medium;
   
    //Use an if statement to end the program if an invalid letter is inputted
    if (!(medium == 'A' || medium == 'B' || medium == 'C'))
    {    
        cout<<"Invalid menu choice. Program shutting down.";
        return 0;
    }
    
    //Prompt the user to input the distance for the sound wave to travel
    cout<<"Input the distance (in feet) the sound wave is to travel and hit ";
    cout<<"enter when done."<<endl;
    cout<<"This value must be 0 or greater."<<endl;
    cin>>dist;
    
    //Use an if statement to end the program if a value less than 0 is inputted
    if (dist<0)
    {
        cout<<"This is an invalid distance. Program shutting down.";
        return 0;
    }
  
    /*Have a particular path of code be calculated and outputted
     depending on the menu choice that was made*/
    
    //Set the output formatting for numeric values
    cout<<fixed<<setprecision(4);
    
    //Use a switch statement to determine the output 
    switch (medium)
    {
        case 'A': 
            time = dist/SPD_AIR; /*The time the sound wave will travel is
                                     the distance it must travel divided by
                                     the speed it travels through air*/
            
            cout<<"The time it takes for a sound wave to travel "<<dist;
            cout<<" feet through air is "<<time<<" seconds.";
            break;
       
        case 'B':
            time = dist/SPD_WTR; /*The time the sound wave will travel is
                                     the distance it must travel divided by
                                     the speed it travels through water*/
            
            cout<<"The time it takes for a sound wave to travel "<<dist;
            cout<<" feet through water is "<<time<<" seconds.";
            break;
            
        default:
            time = dist/SPD_STL; /*The time the sound wave will travel is
                                     the distance it must travel divided by
                                     the speed it travels through steel*/
            cout<<"The time it takes for a sound wave to travel "<<dist;
            cout<<" feet through steel is "<<time<<" seconds.";
    }   
            
            
    
    
    
    
    
    //Exit stage right!
    return 0;
}