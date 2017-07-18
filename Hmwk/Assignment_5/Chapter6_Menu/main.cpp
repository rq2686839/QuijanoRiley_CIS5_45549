/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 17, 2017, 6:08 PM
 * Purpose:  Chapter 6 Homework Menu
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Input - Output Manipulation Library
#include <cstdlib>   //C Standard Library for Using rand()
#include <ctime>     //C Time Library for Seeding the Random Number Generator
#include <cmath>     //C Math Library Needed for Power Function
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes


//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 1
float getSale (string);
void fndHigh (float, float, float, float);
//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 2
float fallDis (unsigned short);
//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 3
float celsius (unsigned short);
//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 4
void coinTos ();
//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 5
float presVal (float, float, short int);
//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 6
void getScor(short int &);
void calcAvg (unsigned short, unsigned short, unsigned short, unsigned short,
                                                              unsigned short);
int findLow (unsigned short isLow1, unsigned short isLow2, 
           unsigned short isLow3, unsigned short isLow4, unsigned short isLow5); 
//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 7
void orderIP (short int &, short int &, float &);
void orderOP (short int, short int, float);
//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 8
float totCost (short int, float, float, float);
float totCost (float, float);
//******************************************************************************
//                     FUNCTION PROTOTYPES FOR MENU CHOICE 9
bool isPrime (int);
//******************************************************************************

//Execution begins here
int main(int argc, char** argv) {
    
    //Declare variables 
    
    char choice;
    
    //Use a do-while loop to display contents of the menu 
    
    do
    {
        //Prompt the user to input a value for a menu choice
        cout<<"Choose a problem from the list to execute by typing the"<<endl;
        cout<<"number that corresponds with it on the menu."<<endl;
        cout<<"Type any other character to exit."<<endl<<endl;
        cout<<"1. Gaddis, 8th Edition, Chapter 6, Problem 3 (Winning Division)";
        cout<<endl;
        cout<<"2. Gaddis, 8th Edition, Chapter 6, Problem 5 (Falling Distance)";
        cout<<endl;
        cout<<"3. Gaddis, 8th Edition, Chapter 6, Problem 7 (Celsius ";
        cout<<"Temperature Table)"<<endl;
        cout<<"4. Gaddis, 8th Edition, Chapter 6, Problem 8 (Coin Toss)";
        cout<<endl;
        cout<<"5. Gaddis, 8th Edition, Chapter 6, Problem 9 (Present Value)";
        cout<<endl;
        cout<<"6. Gaddis, 8th Edition, Chapter 6, Problem 11 (Lowest Score ";
        cout<<"Drop)"<<endl;
        cout<<"7. Gaddis, 8th Edition, Chapter 6, Problem 14 (Order Status)";
        cout<<endl;
        cout<<"8. Gaddis, 8th Edition, Chapter 6, Problem 15 (Overloaded ";
        cout<<"Hospital)"<<endl;
        cout<<"9. Gaddis, 8th Edition, Chapter 6, Problem 22 (isPrime ";
        cout<<"Function)"<<endl;
        cin>>choice;
        
        //Use a switch to display the problem chosen on the menu
        switch(choice)
        {
            case '1':{
                 
                //Declare variables here

                string divNE, divSE, divNW, divSW; /*divNE is the Northeast 
                                                    division of the  company, 
                                                    divSE is the Southeast 
                                                    division of the company, 
                                                    divNW is the Northwest
                                                    division of the company, and
                                                    divSW is the Southwest 
                                                    division of the company*/

                float saleNE, saleSE, saleNW, saleSW; /*saleNE is the quarterly 
                                                      sales of the Northeast
                                                      division, saleSE for the 
                                                      Southeast division, 
                                                      salesNW for the Northeast 
                                                      division, and saleSW for
                                                      the Southwest division*/ 

                //Briefly explain program

                cout<<"This program will determine which of a company's four";
                cout<<endl;
                cout<<"divisions (Northeast, Southeast, Northwest, and ";
                cout<<"Southwest) "<<endl;
                cout<<"had the greatest sales for a quarter."<<endl<<endl;

                //Initialize variables 

                divNE = "The Northeast division"; //divNE is The Northeast div. 

                divSE = "The Southeast division"; //divSE is The Southeast div.

                divNW = "The Northwest division"; //divNW is the Northwest div.

                divSW = "The Southwest division"; //divSW is the Southwest div.

                //Call to functions to initialize other variables

                saleNE = getSale(divNE); /*saleNE will be the quarterly sales 
                                          returned from the getSale function*/

                saleSE = getSale(divSE); /*saleSE will be the quarterly sales
                                          returned from the getSale function*/

                saleNW = getSale(divNW); /*saleNW will be the quarterly sales
                                          returned from the getSale function*/

                saleSW = getSale (divSW); /*divSW will be the quarterly sales 
                                          returned from the getSale function*/

                //Output the results by calling to a function

                //Set the numerical output formatting
                cout<<fixed<<setprecision(2)<<showpoint;

                //Output the actual information
                fndHigh(saleNE, saleSE, saleNW, saleSW);
                
                cout<<endl;
            break;
            }
            
            case '2':{
                
                //Declare variables
                
                unsigned short time; /*time is the time an object has been 
                                     falling (seconds)*/

                //Briefly explain the program

                cout<<"This program uses a function to accept an object's ";
                cout<<"falling"<<endl;
                cout<<"time (in seconds) and return the distance in meters ";
                cout<<"the"<<endl;
                cout<<"object has fallen during that time. The arguments used ";
                cout<<"in"<<endl;
                cout<<"the program are times 1 through 10."<<endl<<endl;

                /*Use a for loop that calls a function each time it iterates to 
                 display the data; the counter of the loop will be time the
                 object has been falling initialized at 1 and will be 
                 incremented after each iteration until it reaches 10; this 
                 counter will serve as the argument in the call for the 
                 function in each iteration*/
                for (time = 1; time<=10; time++)
                {
                    cout<<"After the object falls for "<<time;
                    cout<<"s, it falls a distance of ";
                    cout<<fallDis (time)<<" meters."<<endl;
                }
                
                cout<<endl; 
            break;   
            }
            
            case '3':{
            
                //Declare variables
    
                unsigned short fahr; /*fahr is the temperature in degrees 
                                      Fahrenheit*/
    
                //Briefly explain the program

                cout<<"This program will display a table of Fahrenheit ";
                cout<<"temperatures"<<endl;
                cout<<"0 through 20 and provide their Celsius equivalents. ";
                cout<<"This will"<<endl;
                cout<<"be done by calling a function that converts Fahrenheit ";
                cout<<"to"<<endl;
                cout<<"Celsius in a loop."<<endl<<endl;

                //Output a data table

                //Display the titles of the data table
                cout<<"FAHRENHEIT TEMPERATURES 0 THROUGH 20 AND THEIR CELSIUS ";
                cout<<"EQUIVALENTS";
                cout<<endl<<endl;
                cout<<"Fahrenheit Temperature                 Celsius ";
                cout<<"Equivalent"<<endl;
                cout<<"----------------------                 ---------------";
                cout<<"---"<<endl;

                /*Output the actual information in the data table using a for 
                 loop; the loop will have the counter as degrees Fahrenheit and
                 will have this counter initialized at 0; it will be incremented
                 after each iteration until it reaches 20 and will serve as the 
                 argument for the function call that occurs during each 
                 iteration*/
                for (fahr = 0; fahr<=20; fahr++)
                {
                    /*Use setw() for proper table alignment and set the Celsius
                     temperature to show 4 places after decimal*/
                    cout<<setw(10)<<fahr<<setw(42)<<fixed<<setprecision(4);
                    cout<<showpoint; 
                    cout<<celsius(fahr)<<endl; 
                }
                
            break;
            }
            
            case '4':{
                
                //Seed the random number generator
    
                srand(static_cast<unsigned int>(time(0)));

                //Declare variables here

                int flipCnt, counter; /*flipCnt is the number of times the coin 
                                       is to be tossed as inputted by the user
                                       and counter will be the counter for the 
                                       loop that calls the function the amount 
                                       of times ordered by flipCnt*/

                //Briefly explain the program

                cout<<"This program will simulate the tossing of a coin by ";
                cout<<"calling a"<<endl;
                cout<<"function. The times the coin is tossed is inputted by ";
                cout<<"the user.";
                cout<<endl<<endl;

                //Prompt the user to input data

                cout<<"Input the times the coin is tossed below. This number ";
                cout<<"cannot be ";
                cout<<"negative."<<endl;
                cin>>flipCnt;

                /*Use a while statement to continuously prompt the user to input
                 data so long as their input is invalid*/
                while(flipCnt<0)
                {
                    cout<<"This is an invalid input. Please input the times ";
                    cout<<"the coin"<<endl;
                    cout<<"is flipped below, making sure it is not negative.";
                    cout<<endl;
                    cin>>flipCnt;
                }  

                //Output the data

                /*Use a for loop where the counter is initialized at 1 and that
                 increments after every iteration; the loop should continue to 
                 iterate until the counter has surpassed the number input into 
                 flipCnt*/
                for(counter = 1; counter<=flipCnt; counter++)
                {
                    //Call the function that flips the coin every loop iteration
                    coinTos();
                    cout<<endl;
                }
                
            break;
            }
            
            case '5':{
                
                //Declare variables
                
                float F, r; /*F is the future value in dollars that is desired 
                             to be in the account and r is the annual interest 
                             rate that the money in the account is stored 
                             under*/

                short int n; /*n is the number of years that is planned to let 
                             the money sit in the account before the desired 
                             value is reached*/

                //Briefly explain the program

                cout<<"This program will determine how much money needs to be";
                cout<<endl;
                cout<<"inputted into a bank account with a certain interest ";
                cout<<"rate and"<<endl;
                cout<<"the number of years this money must sit in the account ";
                cout<<"in"<<endl;
                cout<<"order to reach a certain desired future value."<<endl;
                cout<<endl;

                //Prompt the user to input data

                /*Prompt for input of the future value that is desired to be in 
                 the account*/
                cout<<"Input the future value in dollars that is desired to ";
                cout<<"be in"<<endl;
                cout<<"the bank account. This value cannot be negative."<<endl;
                cin>>F;

                /*Use a while statement to continuously prompt the user to input
                 data so long as their input is invalid*/
                while (F<0)
                {
                    cout<<"This is an invalid input. Please input the future ";
                    cout<<"value"<<endl;
                    cout<<"in dollars that is desired to be in the bank ";
                    cout<<"account,"<<endl;
                    cout<<"making sure the value is not negative."<<endl;
                    cin>>F;
                }    

                /*Prompt for input of the annual interest rate the money in the 
                 account will sit under*/
                cout<<"Input the annual interest rate the money in the account";
                cout<<" will sit";
                cout<<" under."<<endl;
                cout<<"This value cannot be negative."<<endl;
                cin>>r;

                /*Use a while statement to continuously prompt the user to input
                 data so long as their input in invalid*/
                while (r<0)
                {
                    cout<<"This is an invalid input. Please input the ";
                    cout<<"interest rate"<<endl;
                    cout<<"that the money will sit under in the bank account,";
                    cout<<endl;
                    cout<<"making sure the value is not negative."<<endl;
                    cin>>r;
                } 

                /*Prompt the user to input the number of years the money will 
                 sit in the bank account*/
                cout<<"Input the number of years the money will sit in the ";
                cout<<"bank"<<endl;
                cout<<"account for. This value cannot be negative."<<endl;
                cin>>n;

                /*Use a while statement to continuously prompt the user to input
                 data so long as their input in invalid*/
                while (n<0)
                {
                    cout<<"This is an invalid input. Please input the number ";
                    cout<<"of years"<<endl;
                    cout<<"that the money will sit in the bank account for,";
                    cout<<endl;
                    cout<<"making sure the value is not negative."<<endl;
                    cin>>n;
                }

                //Output the results by calling a function

                cout<<"The present value, or the amount that needs to be ";
                cout<<"deposited"<<endl;
                cout<<"today, given that the desired future value is $";
                cout<<fixed<<setprecision(2)<<showpoint<<F;
                cout<<", the"<<endl;
                cout<<"interest rate is "<<r<<"%, and the number of years the";
                cout<<endl;
                cout<<"money will sit is "<<n<<" = $";
                //Output the present value with 2 decimals of precision
                cout<<fixed<<setprecision(2)<<showpoint<<presVal(F, r, n);
              
                cout<<endl<<endl;
            break;
            }
            
            case '6':{
                
                //Briefly explain the program

                cout<<"This program will calculate the average of a group of ";
                cout<<"test"<<endl;
                cout<<"scores, where the lowest score in the group is dropped";
                cout<<endl;
                cout<<"This will be done by calling multiple different ";
                cout<<"functions"<<endl;
                cout<<"throughout the program."<<endl<<endl;

                //Declare variables
                short int score1, score2, score3, score4, score5; /*score1 is 
                                                                   where the 
                                                                   first test 
                                                                   score will be 
                                                                   inputted by
                                                                   calling a
                                                                   function, 
                                                                   score2 is 
                                                                   where the 
                                                                   second test
                                                                   score will be
                                                                   inputted by
                                                                   calling a 
                                                                   function,
                                                                   score3 where
                                                                   the third 
                                                                   will be 
                                                                   inputted, 
                                                                   score4
                                                                   the fourth, 
                                                                   and score5
                                                                   the fifth*/

               //Call a function to initialize variables 

                getScor(score1);//Use getScor function to assign score to score1
                getScor(score2);//Use getScor function to assign score to score2
                getScor(score3);//Use getScor function to assign score to score3
                getScor(score4);//Use getScor function to assign score to score4
                getScor(score5);//Use getScor function to assign score to score5

                //Call a function to display results using initialized variables

                calcAvg (score1, score2, score3, score4, score5);
                
                cout<<endl;
            break;
            }
            
            case '7':{
                
                //Declare variables
    
                short int ordSpl, stckSpl;      /*ordSpl is the number of spools
                                                 ordered which will be inputted
                                                 by the user after calling a 
                                                 function and stckSpl is the
                                                 number in stock which will be
                                                 inputted after calling the same
                                                 function*/

                float shpHndl; /*shpHndl is the price of shipping and handling 
                                in dollars and will have a value after the 
                                calling of a function*/

                //Briefly explain the program

                cout<<"This program will display the status of an order of ";
                cout<<"spools of"<<endl;
                cout<<"copper wiring ordered from the Middletown Wholesale ";
                cout<<"Copper"<<endl;
                cout<<"Wire Company. The status will display information about";
                cout<<endl;
                cout<<"prices and information about current stock and ";
                cout<<"backorder."<<endl;
                cout<<endl;

                //Call a function that has the user input data

                orderIP(ordSpl, stckSpl, shpHndl);

                /*Call another function with the newly inputted data to output 
                 data*/

                orderOP (ordSpl, stckSpl, shpHndl);
    
                cout<<endl<<endl;
            break;
            }
            
            case '8':{
                
                //Declare all Variables Here
                 
                char patient; /*patient into which the user types a letter to 
                               decide if a patient is admitted as an 
                               in-patient or an out-patient*/
    
                short int days; /*days is the number of days spent in the 
                                 hospital by an in-patient*/

                float rate, medChg, servChg, totChg; /*rate is the daily rate at
                                                      which the hospital charges
                                                      an in-patient, medChg is 
                                                      the hospital medication
                                                      charges, servChg is the 
                                                      charges for hospital 
                                                      services, and totChg is 
                                                      the total charges for the
                                                      patient's stay*/

                //Briefly explain program here

                cout<<"This program will compute and display the charges for ";
                cout<<"a"<<endl;
                cout<<"patient's hospital stay by first determining if the ";
                cout<<"patient"<<endl;
                cout<<"is an in-patient or an out-patient and then adding ";
                cout<<"together";
                cout<<" appropriate costs."<<endl<<endl;

                //Prompt the user to input data/make a choice

                cout<<"Was the patient at the hospital admitted as an ";
                cout<<"in-patient or"<<endl;
                cout<<"an out-patient? Type 'I' below if they were admitted ";
                cout<<"as an"<<endl;
                cout<<"in-patient or any other character if they were ";
                cout<<"admitted as a out-patient."<<endl;
                cin>>patient;

                /*Use a switch statement to ask for more data input depending on
                 the user's choice*/
                switch (patient)
                {
                    case 'I':
                        /*Prompt the user to input the number of days spent in
                         the hospital*/
                        cout<<"Please input the number of days spent in the ";
                        cout<<"hospital"<<endl;
                        cout<<"below. This number cannot be negative."<<endl;
                        cin>>days;

                        /*Use a while statement to continuously prompt the user 
                         to input data so long as their input is invalid*/
                        while(days<0)
                        {
                            cout<<"This is an invalid input. Input the number ";
                            cout<<"of"<<endl;
                            cout<<"days spent in the hospital, making sure its";
                            cout<<" not";
                            cout<<" negative."<<endl;
                            cin>>days;
                        }

                        /*Prompt the user to input the daily rate charged by the
                         hospital*/
                        cout<<"Please input the daily rate charged by the ";
                        cout<<"hospital"<<endl;
                        cout<<"below. This number cannot be negative."<<endl;
                        cin>>rate;

                        /*Use a while statement to continuously prompt the user 
                        to input data so long as their input is invalid*/
                        while(rate<0)
                        {
                            cout<<"This is an invalid input. Input the daily ";
                            cout<<"rate"<<endl;
                            cout<<"charged by the hospital, making sure its ";
                            cout<<"not";
                            cout<<" negative."<<endl;
                            cin>>rate;
                        }

                        //Prompt the user to input hospital medication charges
                        cout<<"Please input the hospital medication charges ";
                        cout<<"below."<<endl;
                        cout<<"This number cannot be negative."<<endl;
                        cin>>medChg;

                        /*Use a while statement to continuously prompt the user 
                        to input data so long as their input is invalid*/
                        while(medChg<0)
                        {
                            cout<<"This is an invalid input. Input the ";
                            cout<<"hospital"<<endl;
                            cout<<"medication charges below, making sure its ";
                            cout<<"not";
                            cout<<" negative."<<endl;
                            cin>>medChg;
                        }

                        //Prompt the user to input charges for hospital services
                        cout<<"Please input the charges for hospital services ";
                        cout<<"below."<<endl;
                        cout<<"This number cannot be negative."<<endl;
                        cin>>servChg;

                        /*Use a while statement to continuously prompt the user
                         to input data so long as their input is invalid*/
                        while(servChg<0)
                        {
                            cout<<"This is an invalid input. Input the ";
                            cout<<"hospital"<<endl;
                            cout<<"service charge below, making sure its not";
                            cout<<" negative."<<endl;
                            cin>>servChg;
                        }

                        //Calculate the total cost by calling a function
                        totChg = totCost(days, rate, medChg, servChg);

                    break;

                    default:
                        //Prompt the user to input hospital medication charges
                        cout<<"Please input the hospital medication charges ";
                        cout<<"below."<<endl;
                        cout<<"This number cannot be negative."<<endl;
                        cin>>medChg;

                        /*Use a while statement to continuously prompt the user 
                        to input data so long as their input is invalid*/
                        while(medChg<0)
                        {
                            cout<<"This is an invalid input. Input the ";
                            cout<<"hospital"<<endl;
                            cout<<"medication charges below, making sure its ";
                            cout<<"not";
                            cout<<" negative."<<endl;
                            cin>>medChg;
                        }

                        //Prompt the user to input charges for hospital services
                        cout<<"Please input the charges for hospital services ";
                        cout<<"below."<<endl;
                        cout<<"This number cannot be negative."<<endl;
                        cin>>servChg;

                        /*Use a while statement to continuously prompt the user 
                        to input data so long as their input is invalid*/
                        while(servChg<0)
                        {
                            cout<<"This is an invalid input. Input the ";
                            cout<<"hospital"<<endl;
                            cout<<"service charge below, making sure its not";
                            cout<<" negative."<<endl;
                            cin>>servChg;
                        }

                        //Calculate the total cost by calling a function
                        totChg = totCost(medChg, servChg);

                }

                cout<<endl;

                //Output the results

                //Set the numerical output format
                cout<<fixed<<setprecision(2)<<showpoint;

                //Output the total cost
                cout<<"The total charges for the patient's hospital stay = $";
                cout<<totChg;

                cout<<endl<<endl;
            break;
            }
            
            case '9':{
                
                //Declare variables
                
                int inptNmb; /*inptNmb is where the user will input a number to 
                              determine if it is prime or not*/

                bool numPrim; /*numPrim is what the return value of the function
                               will be put into*/

                //Briefly explain the program

                cout<<"This program will have the user input an integer and ";
                cout<<"will"<<endl;
                cout<<"output whether the integer is prime or not."<<endl<<endl;

                //Prompt the user to input data

                cout<<"Input an integer below to determine if it is prime or ";
                cout<<"not."<<endl;
                cout<<"This number cannot be negative because there are no ";
                cout<<"negative"<<endl;
                cout<<"prime numbers."<<endl;
                cin>>inptNmb;

                /*Use a while statement to keep prompting the user to input a
                 value so long as it is negative*/
                while (inptNmb<0)
                {
                    cout<<"Prime numbers cannot be negative. Please input a ";
                    cout<<"non-negative";
                    cout<<endl;
                    cout<<"integer below to determine if it is prime."<<endl;
                    cin>>inptNmb;        
                }

                //Call a function to process calculations

                numPrim = isPrime (inptNmb);

                //Output the results

                /*Use an if/else statement to output that the number is prime if
                 the return value on the function is true and to output that it
                 is not if the return value is false*/

                if (numPrim == true)
                    cout<<"This number is prime.";

                else
                    cout<<"This number is not prime.";
                
                cout<<endl<<endl;
            break;
            }
            default: 
                cout<<"You are now exiting the program.";
        }          
    }
    while (choice>='1' && choice<='9');
    //Exit stage right!
    return 0;
}
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 1
/*This function is passed the name of a division, asks for that division's 
 sales figure, and returns it*/
float getSale (string div) 
{  
    float qrtSale; /*qrtSale is the quarterly sales figure (in $'s) to be 
                    inputted for the division*/
    
    cout<<"What is "<<div<<"'s quarterly sales figure? Input the "<<endl;
    cout<<"value in dollars below. This input must not be less than 0."<<endl;
    cin>>qrtSale;
    
    /*Use a while loop to keep prompting the user to input a value so long
     as their input is invalid*/
    while (qrtSale<0)
    {
        cout<<"This input is invalid. Please input "<<div<<"'s quarterly sales";
        cout<<endl;
        cout<<"figure, making sure it is not less than 0."<<endl;
        cin>>qrtSale;
    }    
    return qrtSale;
}
/*This function is passed the quarterly sales for each of the four divisions 
 and outputs the name of the highest grossing division*/
void fndHigh(float saleNE, float saleSE, float saleNW, float saleSW)
{
    /*Use a series of if/else if statements to output the name and sales figure
     of the highest grossing division*/
    if (saleNE>saleSE && saleNE>saleNW && saleNE>saleSW)
    {
        cout<<"The Northeast division is the highest grossing division"<<endl;
        cout<<"with a quarterly sales figure of $"<<saleNE<<'.'<<endl;
    }
    
    else if (saleSE>saleNE && saleSE>saleNW && saleSE>saleSW)
    {
        cout<<"The Southeast division is the highest grossing division"<<endl;
        cout<<"with a quarterly sales figure of $"<<saleSE<<'.'<<endl;
    }
    
    else if (saleNW>saleNE && saleNW>saleSE && saleNW>saleSW)
    {
        cout<<"The Northwest division is the highest grossing division"<<endl;
        cout<<"with a quarterly sales figure of $"<<saleNW<<'.'<<endl;
    }
    
    else
    {
        cout<<"The Southwest division is the highest grossing division"<<endl;
        cout<<"with a quarterly sales figure of $"<<saleSW<<'.'<<endl;
    }
}
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 2
/*This function fallDis() accepts an object's falling time (in seconds) as an 
 argument and returns the distance (in meters) the object has fallen in that 
 time*/
float fallDis(unsigned short falTime)
{
    float d; //d is the distance in meters an object falls
    
    d = (1.0f/2)*9.8f*falTime*falTime; /*The distance in meters an object falls 
                                        is 1/2 times 9.8 (gravity's acceleration 
                                        in m/s) times the time the object has
                                         been falling squared*/
    return d;
}
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 3
/*This function accepts a Fahrenheit temperature as an argument and returns the 
 temperature converted to Celsius*/
float celsius(unsigned short fahr)
{
    float cels; /*cels is the temperature in degrees Celsius*/
    
    cels = (5.0f/9)*(fahr - 32); /*Degrees Celsius is (5/9)(Degrees Fahrenheit -
                                  32)*/
    
    return cels;
}
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 4
/*This function will simulate the tossing of a coin, outputting whether a coin
 landed on heads or tails when it is called*/
void coinTos ()
{      
    //Declare variables
    
    unsigned int side;   /*Side is where either 1 or 2 gets inputted into to 
                          determine if the coin is heads or tails*/
    
    //Initialize variables
    
    side = (rand()%2)+1; /*side is either a 1 or a 2, which is what modding rand
                           by 2 and adding the result by 1causes to be 
                           outputted*/
    
    //Output results 
    
    /*Use a switch statement to output "heads" if 1 was the random number 
     generated or to output "tails" if 2 was the random number generated*/
    switch (side)
    {
        case 1:
            cout<<"heads";
        break;
        
        default:
            cout<<"tails";
    }   
}
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 5   
/*This function presVal accepts the future value (futVal) one would like to have
 in a savings account, the annual interest rate(rate) for that savings account, 
 and the number of years that is planned to let the money sit in the account
 (nYears) as arguments; it then returns the present value that must be deposited
 today to reach the future value*/
float presVal (float futVal, float rate, short int nYears)
{
    float P; /*P is the present value, or the amount that needs to be deposited
              today in dollars*/
    
    P = futVal/pow(1+rate/100, nYears);/*the amount in dollars that needs to be 
                                     deposited today is the future dollar value 
                                     desired in a savings account /
                                     (1+interest rate)^ number of years planned 
                                     to let the money sit in the account*/
    
    return P;
}
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 6
//This function getScor will be used to input each of the five test scores
void getScor(short int &score)
{
   static short int testNum = 1; /*testNum is the number of the test that 
                                  the user will input a score for; 
                                  initialized at 1 because the first test 
                                  score to be inputted for is test 1*/
   
   cout<<"Input a score for test "<<testNum<<". This score must be a value";
   cout<<"from 0 to 100."<<endl;
   cin>>score;
   
   /*Use a while loop to keep prompting the reader to enter a score so long
    as their input is invalid*/
   while (score<0 || score>100)
   {
       cout<<"This is not a valid input. Please input a score from 0 to 100";
       cout<<endl;
       cin>>score;
   }    
   
   testNum++; /*Increment testNum so that the next execution of this function 
              will ask for input into test 2, then test 3, etc.*/
}

/*This function calcAvg() will calculate and display the average of the four
 highest scores after being passed the scores of all of the tests*/
void calcAvg (unsigned short s1, unsigned short s2, unsigned short s3,
                                 unsigned short s4, unsigned short s5)
{
    float testAvg; /*testAvg is the average of the four highest test scores that
                    are passed into the function*/
    
    /*The average of the 4 highest test scores is all of the test scores added
     up minus the lowest score (determined after calling the findLow function)
     divided by 4*/
    testAvg = (s1 + s2 + s3 + s4 + s5 - findLow(s1, s2, s3, s4, s5))/4.0f;
    
    //Output the average to 1 decimal place
    cout<<"The average of the 4 highest test scores is ";
    cout<<fixed<<setprecision(1)<<showpoint<<testAvg<<'.'<<endl;
}

/*This function findLow() will determine which of the test scores is the lowest
 of the five that are passed into it and will return this value to the 
 calcAvg function to be subtracted from the average being taken*/
int findLow (unsigned short isLow1, unsigned short isLow2, 
            unsigned short isLow3, unsigned short isLow4, unsigned short isLow5)
{
    unsigned short lowest; /*Lowest is what the value of the lowest test score 
                            will be put into it*/
    
    /*Use a series of if/else if statements to determine which test score is
     lowest*/
    if (isLow1<isLow2 && isLow1<isLow3 && isLow1<isLow4 && isLow1<isLow5)
        lowest = isLow1;               /*If the first test's score is lower than
                                        all the others', it is the lowest*/
    
    else if (isLow2<isLow1 && isLow2<isLow3 && isLow2<isLow4 && isLow2<isLow5)
        lowest = isLow2;               /*If the second test's score is lower 
                                       than all the others', it is the lowest*/
    
    else if (isLow3<isLow1 && isLow3<isLow2 && isLow3<isLow4 && isLow3<isLow5)
        lowest = isLow3;               /*If the third test's score is lower 
                                       than all the others', it is the lowest*/
    
    else if (isLow4<isLow1 && isLow4<isLow3 && isLow4<isLow2 && isLow4<isLow5)
        lowest = isLow4;               /*If the fourth test's score is lower 
                                       than all the others', it is the lowest*/
    
    else if (isLow5<isLow1 && isLow5<isLow3 && isLow5<isLow4 && isLow5<isLow2)
        lowest = isLow5;               /*If the fifth test's score is lower 
                                       than all the others', it is the lowest*/
    else 
        lowest = isLow1;
 
    return lowest;
}
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 7
/*This function orderIP prompts the user to input information about the order
 of spools of copper wiring; this information includes the number of spools 
 ordered (splNum), the number of spools in stock(splStck), whether there are
 special shipping and handling charges, and what the price of that shipping 
 and handling in dollars (sah) is*/
void orderIP (short int &splNum, short int &splStck, float &sah)
{
    //Declare variables in this function

    char special; /*The user will input a character into special to determine 
                   whether there are special shipping and handling charges*/

    //Prompt the user to input data
    
    //Prompt for the input of the number of spools ordered
    cout<<"How many spools were ordered? Input the number below."<<endl;
    cout<<"This order must be 1 or more."<<endl;
    cin>>splNum;
    
    /*Use a while statement to keep prompting the user to input a value so long
     as their input is invalid*/
    while (splNum<1)
    {
        cout<<"This is an invalid input. Please input the amount of"<<endl;
        cout<<"spools that were ordered, making sure it is 1 or more."<<endl;
        cin>>splNum;
    } 
    
    //Prompt for the input of the number of spools in stock
    cout<<"How many spools are in stock? Input the number below."<<endl;
    cout<<"This input must be 0 or more."<<endl;
    cin>>splStck;
    
    /*Use a while statement to keep prompting the user to input a value so long
     as their input is invalid*/
    while (splStck<0)
    {
        cout<<"This is an invalid input. Please input the amount of"<<endl;
        cout<<"spools that are in stock, making sure it is 0 or more."<<endl;
        cin>>splStck;
    }

    /*Use an if statement to either initialize or input the cost of shipping and
     handling*/
    cout<<"Are there special shipping and handling charges? If there"<<endl;
    cout<<"are, type 'Y', and if there are not, type any other character.";
    cout<<endl;
    cin>>special;
    if (special == 'Y')
    {
        /*Prompt the user to input the special shipping and handling charges per
         spool*/
        cout<<"What are the special charges? Input the price of shipping"<<endl;
        cout<<"and handling per spool. Make sure this is not less than"<<endl;
        cout<<"0."<<endl;
        cin>>sah;
        
        /*Use a while statement to keep prompting the user to input a value so 
         long as their input is invalid*/
        while (sah<0)
        {
            cout<<"This is an invalid input. Please input the price of"<<endl;
            cout<<"shipping and handling per spool, making sure it is"<<endl;
            cout<<"not less than 0."<<endl;
            cin>>sah;
        }
    }
    
    else
    {
        cout<<"There are no special charges, so shipping and handling is $10";
        cout<<" per spool."<<endl<<endl;
        
        sah = 10.0f; //Standard shipping and handling is $10 per spool
    }    
}

/*This function orderOP outputs information based on what was inputted about 
 the number of spools ordered (ordered), the number in stock (stock), and the 
 price of shipping and handling per spool (shpAhdl)*/
void orderOP (short int ordered, short int stock, float shpAhdl)
{
    /*Output the number of spools ready to ship from stock; use an if statement
     to make this number equal to stock if the number ordered is more than in
     stock or to make this number equal to ordered if the number ordered is 
     less*/
    if (ordered>stock)
    {    
        cout<<"The number of spools ready to ship from current stock      =  ";
        cout<<setw(9)<<stock;
        cout<<endl<<endl;
    }
    else
    {
        cout<<"The number of spools ready to ship from current stock      =  ";
        cout<<setw(9)<<ordered;
        cout<<endl<<endl;
    }
    /*Output the number on backorder (if number ordered is greater than what
     is in stock, then this is the number ordered minus the number in stock*/
    if (ordered>stock)
    {    
        cout<<"The number of spools on backorder                          =  ";
        cout<<setw(9)<<ordered-stock<<endl<<endl;
    }
    
    //Set the numerical output formatting for the rest of the outputs
    cout<<fixed<<setprecision(2)<<showpoint;
    
    /*Output the subtotal of the portion of spools ready to ship; use an if 
     statement to multiply the number in stock by 100 if they are back oredered
     and an else to multiply the number ordered by 100 if they are not*/
    if(ordered>stock)
    {    
        cout<<"The subtotal of the portion of spools ready to ship        = $";
        cout<<setw(9)<<stock*100.0f;
        cout<<endl;
    }    
    else
    {
        cout<<"The subtotal of the portion of spools ready to ship        = $";
        cout<<setw(9)<<ordered*100.0f;
        cout<<endl;
    }
    
    cout<<endl;
    
    /*Output the total shipping and handling charges on the portion of spools
     ready to ship; use an if statement to multiply the number in stock by the
     shipping and handling charges per spool if they are back ordered and an
     else to multiply the number ordered by the s & h charges per spool if 
     they are not*/
    if (ordered>stock)
    {
        cout<<"The total shipping and handling charges on the portion of"<<endl;
        cout<<"spools ready to ship                                       = $";
        cout<<setw(9)<<stock*shpAhdl<<endl;
    }
    else
    {
        cout<<"The total shipping and handling charges on the portion of"<<endl;
        cout<<"spools ready to ship                                       = $";
        cout<<setw(9)<<ordered*shpAhdl<<endl;
    } 
    
    cout<<endl;
    
    /*Output the total of the order ready to ship; follow the same procedures 
     about calculations as the last two outputs when it comes to using the if
     else statement*/
    if(ordered>stock)
    {
        cout<<"The total of the order ready to ship                       = $";
        cout<<setw(9)<<stock*shpAhdl + stock*100.0f;
    }
    else
    {
        cout<<"The total of the order ready to ship                       = $";
        cout<<setw(9)<<ordered*shpAhdl + ordered*100.0f;
    }
}    
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 8
/*This version of the function totCost () calculates the total cost for a
 patient at the hospital admitted as an in-patient and returns this total cost*/
float totCost (short int dayCnt, float dayRate, float meds, float service)
{
    float totIn; //totIn is the total cost for the in-patient's stay
    
    totIn = dayCnt*dayRate + meds + service; /*the total cost for the 
                                              in-patient's stay is the product
                                              of the days they stayed and the
                                              daily charge rate added to the 
                                              medication charges and the charges
                                              for services*/
    
    return totIn;
}

/*This version of the function totCost calculates the total cost for a patient
 at the hospital admitted as an out-patient and returns this total cost*/
float totCost (float meds, float service)
{
    float totOut; //totOut is the total cost for the out-patient's stay
    
    totOut = meds + service; /*the total cost for the out-patient's stay is the 
                              sum of the medication charges and the charges for 
                              services*/
    
    return totOut;
}
//******************************************************************************
//******************************************************************************
//                      FUNCTIONS FOR MENU CHOICE 9
/*This function isPrime will accept an integer as an argument and will determine
 whether the argument is or is not a prime number; if it is prime, it will
 return true and if it is not prime, it will return false*/
bool isPrime (int input)
{
    int n = 0; /*A variable that will help to determine if the input is prime
                that must be initialized at 0 (explained in better detail 
                below)*/
    
    bool prime; //prime will be true of the number is prime and false if it not
    
    /*Use a for loop to keep dividing the input number by a new integer; the 
     loop counter (which will serve as the divisor of the input number) will 
     be initialized at 1; the counter will be incremented after each iteration,
     and it will cause the loop to terminate only after it surpasses the input
     value*/
    for (unsigned int counter = 1; counter<=input; counter++)
    {
        /*Use an if statement along with a variable (n) to add onto 
         that variable one time for each time a quotient has a remainder
         of 0; if the number is prime, this should only happen twice 
         (when the number is divided by 1 and when it is divided by itself)*/
        
        if (input % counter == 0)
            n++;
    }
    
    /*Use an if statement to set prime as true or false depending on if the
     number is prime or not*/
    
    if (n>2 || input == 0 || input == 1) /*If n>2, or the input divided by the 
                                          counter that incremented from 1 to the
                                          input came out with no remainder more
                                          than twice, it is not prime 
                                          (this means the input can be evenly 
                                          divided by more numbers than just 1
                                          and itself); if the number being 
                                          tested is 0 or 1, it also is not 
                                          prime*/
        prime = false;
    
    else if (n)
        prime = true;
    
    return prime;    
}
//******************************************************************************
//******************************************************************************