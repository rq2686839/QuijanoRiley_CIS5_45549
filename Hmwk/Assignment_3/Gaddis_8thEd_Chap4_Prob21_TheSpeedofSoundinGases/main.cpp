/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July,5 2017, 7:24 PM
 * Purpose:  The Speed of Sound in Gases
 */

//System Libraries
#include <iostream>  //Input - Output Library
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants
const float SPD_CO2 = 258.0f; /*SPD_CO2 is the speed at which sound travels 
                              through carbon dioxide; this speed is 258.0
                              meters per second*/

const float SPD_AIR = 331.5f; /*SPD_AIR is the speed at which sound travels 
                             through air; this speed is 331.5 meters per 
                             second*/

const float SPD_HE = 972.0f;  /*SPD_HE is the speed at which sound travels 
                             through helium; this speed is 972.0 meters per 
                             second*/

const float SPD_H = 1270.0f; /*SPD_H is the speed at which sound travels 
                              through hydrogen; this speed is 1,270.0 meters per 
                              second*/

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    
    float time, dist; /*time is the time (in seconds) it takes for the sound to
                       travel from its source, through the medium, and to the
                       location at which it was detected; dist is how far away
                       (in meters) the source of the sound is from the 
                       detection location*/
   
    char medium;      /*medium is the variable into which the user will input 
                       the letter associated with a particular medium on the 
                       menu*/
   
    //Display a menu and have the user make a selection
    
    cout<<"This program will ask the user to select if a sound wave "<<endl;
    cout<<"travels through carbon dioxide, air, helium, or hydrogen."<<endl;
    cout<<"After the user selects one, they input how long it takes"<<endl;
    cout<<"for the";
    cout<<" sound wave to travel from its source, through the selected "<<endl;
    cout<<"medium, and to the location at which it was detected."<<endl;
    cout<<"The program ";
    cout<<"then will calculate the distance from the source of the sound"<<endl;
    cout<<"to the detection location."<<endl<<endl;
    
    cout<<"The menu below displays 4 mediums through which a sound wave can ";
    cout<<"travel."<<endl<<"Choose one medium by inputting";
    cout<<" the letter that comes "<<endl;
    cout<<"immediately before that medium and hitting enter after."<<endl;
    cout<<"A. Carbon Dioxide"<<endl;
    cout<<"B. Air"<<endl;
    cout<<"C. Helium"<<endl;
    cout<<"D. Hydrogen"<<endl;
    cin>>medium;
    
    //Use an if statement to end the program if an invalid letter is inputted
    if (!(medium == 'A' || medium == 'B' || medium == 'C' || medium == 'D'))
    {
       cout<<"Invalid menu choice. Program shutting down.";
       return 0;
    }      
    
    /*Prompt the user to input how long it takes for the sound wave to travel
     from its source to the location of detection*/
    cout<<"Input the time (in seconds) it takes for the sound wave to"<<endl;
    cout<<"travel from its source to its location of detection. Hit enter ";
    cout<<"when done."<<endl;
    cout<<"This value must be no less than 0 seconds and no more than 30 ";
    cout<<"seconds."<<endl;
    cin>>time;
    
    /*Use an if statement to end the program if a value outside the range is
     inputted*/
    if (time<0 || time>30)
    {
        cout<<"This is an invalid time. Program shutting down.";
        return 0;
    }
    
    /*Have a particular path of code be calculated and outputted depending on 
     the menu choice that was made*/
    
    //Use a switch statement to determine the output
    switch(medium)
    {
        case 'A':
            dist = time*SPD_CO2; /*The distance the sound wave traveled 
                                      from its source to the point of detection
                                      is the time it took to travel X the speed
                                      it traveled at*/
            cout<<"The distance the sound wave traveled from its source"<<endl;
            cout<<"through carbon dioxide, and to the detection location"<<endl;
            cout<<"given that it took "<<time<<" seconds is "<<dist;
            cout<<" meters.";
            break;
            
        case 'B':
            dist = time*SPD_AIR;      /*The distance the sound wave traveled 
                                      from its source to the point of detection
                                      is the time it took to travel X the speed
                                      it traveled at*/
            cout<<"The distance the sound wave traveled from its source"<<endl;
            cout<<"through air, and to the detection location"<<endl;
            cout<<"given that it took "<<time<<" seconds is "<<dist;
            cout<<" meters.";
            break;
            
        case 'C':
            dist = time*SPD_HE;       /*The distance the sound wave traveled 
                                      from its source to the point of detection
                                      is the time it took to travel X the speed
                                      it traveled at*/
            cout<<"The distance the sound wave traveled from its source"<<endl;
            cout<<"through helium, and to the detection location"<<endl;
            cout<<"given that it took "<<time<<" seconds is "<<dist;
            cout<<" meters.";
            break;
            
        default:
            dist = time*SPD_H;        /*The distance the sound wave traveled 
                                      from its source to the point of detection
                                      is the time it took to travel X the speed
                                      it traveled at*/
            cout<<"The distance the sound wave traveled from its source"<<endl;
            cout<<"through hydrogen, and to the detection location"<<endl;
            cout<<"given that it took "<<time<<" seconds is "<<dist;
            cout<<" meters.";
           
    }        
    
    //Exit stage right!
    return 0;
}