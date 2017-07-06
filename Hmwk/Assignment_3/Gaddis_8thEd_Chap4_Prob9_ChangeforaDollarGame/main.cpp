/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 5, 2017,8:52 PM
 * Purpose:  Change for a Dollar Game
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
    
    short int pnyAmnt, nklAmnt, dmAmnt, qrtAmnt; /*pnyAmnt is the amount of 
                                                  pennies to be inputted by the
                                                  user, nklAmnt is the amount 
                                                  of nickels to be inputted by
                                                  the user, dmAmnt is the amount
                                                  of dimes  to be inputted by
                                                  the user, and qrtAmnt is the 
                                                  amount of quarters to be 
                                                  inputted by the user*/
    
    unsigned short int pnyPrc, nklPrc, dmPrc, 
                       qrtPrc, dlrPrc, total;     /*pnyPrc is how much a penny 
                                                  is worth in cents, nklPrc is
                                                  how much a nickel is worth
                                                  in cents, dmPrc is how much
                                                  a dime is worth in cents, 
                                                  qrtPrc is how much a 
                                                  quarter is worth in cents, 
                                                  dlrPrc is how much 
                                                  a dollar is worth in cents,
                                                  and total is how many cents 
                                                  user inputted through
                                                  their coin inputs*/ 
           
    //Initialize variables

    pnyPrc = 1; //A penny is worth 1 cent
    nklPrc = 5; //A nickel is worth 5 cents
    dmPrc = 10; //A dime is worth 10 cents
    qrtPrc = 25; //A quarter is worth 25 cents
    dlrPrc = 100; //A dollar is worth 100 cents
    
    //Input data
    
    cout<<"This program will ask for the user to input a certain amount"<<endl;
    cout<<"of pennies, nickels, dimes, and quarters. The user must try"<<endl;
    cout<<"to input a proper combination of the coins to get exactly one ";
    cout<<"dollar."<<endl<<endl;
    
    /*Prompt the user to input a certain amount of pennies */
    cout<<"Input an amount of pennies below. Keep in mind, the goal is"<<endl;
    cout<<"to try to get all of your coins to add up to exactly 1 dollar.";
    cout<<endl;
    cin>>pnyAmnt;
    
    //Use an if statement to end the program in the input is negative
    if (pnyAmnt<0)
    {
        cout<<"That is an invalid input. Program ending.";
        return 0;
    }
    
     /*Prompt the user to input a certain amount of nickels */
    cout<<"Input an amount of nickels below."<<endl;
    cin>>nklAmnt;
    
    //Use an if statement to end the program in the input is negative
    if (nklAmnt<0)
    {
        cout<<"That is an invalid input. Program ending.";
        return 0;
    }
    
    /*Prompt the user to input a certain amount of dimes */
    cout<<"Input an amount of dimes below."<<endl;
    cin>>dmAmnt;
    
    //Use an if statement to end the program in the input is negative
    if (dmAmnt<0)
    {
        cout<<"That is an invalid input. Program ending.";
        return 0;
    }
    
    /*Prompt the user to input a certain amount of quarters*/
    cout<<"Input an amount of quarters below."<<endl;
    cin>>qrtAmnt;
    
    //Use an if statement to end the program in the input is negative
    if (qrtAmnt<0)
    {
        cout<<"That is an invalid input. Program ending.";
        return 0;
    }
    
    //Map inputs to outputs or process the data
    
    /*The total amount of cents the user inputs is equal to all of the coin
     amount they inputted multiplied by their respective values*/
    total = pnyAmnt*pnyPrc + nklAmnt*nklPrc + dmAmnt*dmPrc + qrtAmnt*qrtPrc;
    
    //Output a specific path of code depending on the inputs
    
    /*Use if/else if statements to output if the total cents inputted 
     is equal to, less than, or more than 1 dollar*/
    if (total == dlrPrc)
    {
        cout<<pnyAmnt<<" pennies, "<<nklAmnt<<" nickels, "<<dmAmnt<<" dimes, ";
        cout<<"and "<<qrtAmnt<<" quarters equals 1 dollar."<<endl;
        cout<<"Congratulations, you won the game!!";
    } 
    else if (total<dlrPrc)
    {
        cout<<pnyAmnt<<" pennies, "<<nklAmnt<<" nickels, "<<dmAmnt<<" dimes, ";
        cout<<"and "<<qrtAmnt<<" quarters is less than 1 dollar."<<endl;
        cout<<"Sorry, you did not win.";
    }
    else
    {
        cout<<pnyAmnt<<" pennies, "<<nklAmnt<<" nickels, "<<dmAmnt<<" dimes, ";
        cout<<"and "<<qrtAmnt<<" quarters is more than 1 dollar."<<endl;
        cout<<"Sorry, you did not win.";
    }
    
    //Exit stage right!
    return 0;
}