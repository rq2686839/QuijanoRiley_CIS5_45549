/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 10, 2017, 3:54 PM
 * Purpose:  Chapter 5 Homework Menu
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <iomanip>   //Input - Output Manipulation Library
#include <cstdlib>   //C Standard Library for Using rand()
#include <ctime>     //C Time Library for Seeding the Random Number Generator
using namespace std; //Name-space under which system libraries exist

//User Libraries

//Global Constants

//Function Prototypes

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
        cout<<"1. Gaddis, 8th Edition, Chapter 5, Problem 3 (Ocean Levels)";
        cout<<endl;
        cout<<"2. Gaddis, 8th Edition, Chapter 5, Problem 5 (Membership Fees";
        cout<<" Increase)"<<endl;
        cout<<"3. Gaddis, 8th Edition, Chapter 5, Problem 7 (Pennies for Pay)";
        cout<<endl;
        cout<<"4. Gaddis, 8th Edition, Chapter 5, Problem 10 (Average ";
        cout<<"Rainfall)"<<endl;
        cout<<"5. Gaddis, 8th Edition, Chapter 5, Problem 12 (Celsius to ";
        cout<<"Fahrenheit Table)"<<endl;
        cout<<"6. Gaddis, 8th Edition, Chapter 5, Problem 17 (Sales Bar ";
        cout<<"Chart)"<<endl;
        cout<<"7. Gaddis, 8th Edition, Chapter 5, Problem 20 (Random Number ";
        cout<<"Guessing Game)"<<endl;
        cout<<"8. Gaddis, 8th Edition, Chapter 5, Problem 22 (Square ";
        cout<<"Display)"<<endl;
        cout<<"9. Gaddis, 8th Edition, Chapter 5, Problem 23 (Pattern ";
        cout<<"Display)"<<endl;
        cin>>choice;
        
        //Use a switch to display the problem chosen on the menu
        switch(choice)
        {
            case '1':{
                 
                //Declare variables
    
                float riseRat, totRise;  /*riseRat is the rate the ocean's level
                                          is rising per year and totRise is the
                                          total amount the ocean's level has
                                          risen at each year*/

                unsigned short int year; /*year is the whatever year it is and 
                                          will serve as the counter in the 
                                          loop*/

                //Initialize variables

                riseRat = 1.5f; /*The ocean's level is rising 1.5 millimeters
                                  per year*/           

                //Output the information in the data table

                cout<<"The data table below displays the number of millimeters";
                cout<<" the"<<endl;
                cout<<"ocean will have risen each year for the next 25 years";
                cout<<endl;
                cout<<"assuming the ocean's level is currently rising 1.5";
                cout<<endl;
                cout<<"millimeters per year."<<endl<<endl;

                //Display the titles of the data table
                cout<<" AMOUNT OCEAN LEVEL HAS RISEN EACH YEAR (SINCE 2017) ";
                cout<<" FOR 25 YEARS";
                cout<<endl<<endl;
                cout<<" Year        Amount the Ocean Has Risen (mm)"<<endl;
                cout<<" ----        -------------------------------"<<endl;

                /*display the actual information in the data table using a for
                loop; year is initialized at 2018 and will be incremented after 
                every iteration until 2042*/
                for(year=2018; year<=2042; year++)
                {   
                    /*Total amount risen each year is however many years have
                     passed since 2017 X 1.5 millimeters*/
                    totRise = (year-2017)*riseRat;

                    /*Output the year and the total amount the ocean has risen
                     each year with appropriate spacing and numerical output
                     format*/
                    cout<<setw(5)<<year<<setw(24)<<fixed<<setprecision(1);
                    cout<<totRise<<endl;
                }
                cout<<endl;
                break;
            }
            case '2':{
                
                //Declare variables
    
                unsigned short int intChrg, yr; /*intChrg is the initial amount
                                                 the country club charged per
                                                 year for membership and yr
                                                 is the amount of years that
                                                 have passed since the country 
                                                 club charged $2,500 per 
                                                 year and will serve as the 
                                                 counter*/

                float newChrg;                  /*newChrg is the new price of
                                                  membership each year after 
                                                  the 4% increases*/

                //Initialize variables

                intChrg = 2500;                    /*The initial amount the 
                                                    country club charged per
                                                    year for membership is 
                                                    $2,500*/ 

                newChrg = intChrg + (intChrg*0.04f); /*newChrg for the FIRST 
                                                      passed year is the initial
                                                      charge + the initial 
                                                      charge X 4%*/ 

                //Output a data table 

                cout<<"This program will display a projection of rates a ";
                cout<<"country"<<endl;
                cout<<"club is expected to charge for membership in the next ";
                cout<<"six"<<endl;
                cout<<"years based on the knowledge that the club currently";
                cout<<" charges "<<endl;
                cout<<"$2,500 a year for membership and will increase this 4% ";
                cout<<"each"<<endl;
                cout<<"following year."<<endl<<endl;

                //Display the titles for the data table
                cout<<"PROJECTED RATES THE COUNTRY CLUB IS EXPECTED TO"<<endl;
                cout<< "CHARGE FOR MEMBERSHIP IN THE NEXT 6 YEARS"<<endl;
                cout<<" Year      Projected Membership Fee"<<endl;
                cout<<" ----      ------------------------"<<endl;

                /*Output the appropriate information in the data table using a 
                 for loop; initialize the year at 1, increment it after each
                 iteration, and terminate the loop after the year has reached
                 6*/
                for(yr = 1; yr<=6; yr++)
                {
                    cout<<setw(4)<<yr<<setw(15)<<fixed<<setprecision(2);
                    cout<<'$'<<newChrg<<endl;

                    /*The new charge for the following year is the charge of the
                     preceding year + the charge of that preceding year X 4%*/
                    newChrg=newChrg+(newChrg*0.04f); 
                } 
                cout<<endl;
                break;   
            }
            case '3':{
            
                //Declare variables
    
                float dayPay, totPay;     /*dayPay is the salary the person gets
                                            paid each day  and totPay is the
                                            total salary the person gets paid 
                                            at the end of all the days*/

                short int days, totDays;   /*days is the counter for the loop 
                                            and totDays is the inputted number 
                                            of days the person works*/

                //Prompt the reader to input data

                cout<<"This program will calculate how much a person would ";
                cout<<"earn over"<<endl;
                cout<<"a period of time if their salary starts out as one ";
                cout<<"penny on"<<endl;
                cout<<"the first day and doubles each day they work. How ";
                cout<<"many days"<<endl;
                cout<<"they work is determined by the user."<<endl<<endl;

                cout<<"Input the number of days the person works below. Make ";
                cout<<"sure to"<<endl;
                cout<<"enter a number that is 1 or greater."<<endl;
                cin>>totDays;

                /*If the user enters an unacceptable value, continue to tell 
                  them to enter a new value until it is acceptable; do this
                  using a while statement*/
                while (totDays<1)
                {    
                    cout<<"This value is not acceptable. Please enter the ";
                    cout<<"number"<<endl;
                    cout<<"of days the person works below, making sure it is ";
                    cout<<"1 or more."<<endl;
                    cin>>totDays;
                }

                //Initialize variables

                dayPay = 0.01f; /*dayPay on day 1 is $0.01; this must be 
                                 initialized prior to the loop and manipulated 
                                 within the loop*/

                totPay = 0.0f;  /*totPay must be initialized as 0.0f prior to 
                                 the loop because it serves as an accumulator*/

                //Output a data table 

                //Output the titles of the data table
                cout<<" Day          Salary That Day"<<endl;
                cout<<"-----          ---------------"<<endl;

                /*Output the information in the data table using a for loop; 
                 the loop is initialized at 1, is incremented after each 
                 iteration, and runs until the value inputted in "totDays" is 
                 reached*/
                for(days = 1; days<=totDays; days++)
                { 
                    cout<<setw(3)<<days<<setw(18)<<fixed<<setprecision(2);
                    cout<<'$'<<dayPay;
                    cout<<endl;

                    totPay+=dayPay;/*totPay is the is the total of all the daily
                                    payments added together*/

                    dayPay*=2;/*The pay doubles after each day/after each
                                iteration of loop*/
                }  

                //Output the total pay after all of the days
                cout<<endl<<"The total pay after "<<days-1<<" days was $";
                cout<<totPay<<'.';
                cout<<endl;
                break;
            }
            case '4':{
                
                //Declare and initialize variables
    
                short int yrAmnt;                    /*yrAmnt is the period of
                                                       time (in years) to be 
                                                       considered by the
                                                       program; the program will
                                                       calculate how much rain
                                                       falls over this many
                                                       years*/

                unsigned short int mnthTot, yrCount; /*mnthTot is the total
                                                       number of months that 
                                                       there are over the period
                                                       inputted by the user; 
                                                       yrCount is the variable
                                                       that will serve as the
                                                       counter in the outer 
                                                       loop*/

                float mnthRF, totRF, avgRF; /*mnthRF is the amount of rainfall
                                             (in inches) that happens during
                                             each month; this is inputted for
                                             each month by the user; totRf is
                                             the total amount of rainfall 
                                             (in inches) that occurred during 
                                             the entire period inputted
                                             by the user; and avgRF is the
                                             average rainfall per month for the
                                             entire period*/

                totRF = 0.0f;               /*totRF must be initialized at 0.0
                                             because it will later serve as an
                                             accumulator*/

                //Prompt the user to input data

                cout<<"This program will ask for the amount of rainfall that";
                cout<<endl;
                cout<<"occurred during each month of a certain amount of years";
                cout<<endl;
                cout<<"specified by the user. It will then calculate the total";
                cout<<endl;
                cout<<"rainfall over the period of years and display the ";
                cout<<"average"<<endl;
                cout<<"per month."<<endl<<endl;

                cout<<"Input the number of years below. The inputted number of";
                cout<<" years ";
                cout<<"must not be less than 1."<<endl;
                cin>>yrAmnt;

                /*Use a while loop to keep asking for input so long as an
                 unacceptable value is entered*/
                while (yrAmnt<1)
                {
                    cout<<"This is an invalid input. The number of years must ";
                    cout<<"not be less";
                    cout<<" than 1. Please input the number of years below.";
                    cout<<endl;
                    cin>>yrAmnt;
                }    

                //Implement an outer for loop and nested inner for loop

                /*For the outer for loop of this program, the counter will be
                  initialized at one and will be incremented for each iteration 
                  until it reaches the same value as the year amount inputted by
                  the user; it will terminate after it has run for the amount of
                  times specified by the user*/
                for(yrCount = 1; yrCount<=yrAmnt; yrCount++)
                {    
                    /*For the inner for loop of this program, the counter will 
                     be declared as month and will be initialized to 1; the 
                     counter will be incremented after each iteration until it
                     has reached 12*/
                    for(short int month = 1; month<=12; month++)
                    {
                        /*Prompt the user to input the amount of rainfall that
                          occurred each month*/
                        cout<<"Input the amount of rainfall (in inches) that ";
                        cout<<"occurred for ";
                        cout<<"month "<<month<<" of year "<<yrCount<<" below.";
                        cout<<endl;
                        cout<<"This number cannot be negative."<<endl;
                        cin>>mnthRF;

                        /*Use a while loop to keep asking for input so long as 
                         an unacceptable value is entered*/
                        while(mnthRF<0)
                        {
                            cout<<"This is an invalid input. The amount of ";
                            cout<<"rainfall must ";
                            cout<<"not be less than 0. Please input the amount";
                            cout<<" of"<<endl;
                            cout<<"rainfall that occurred for month ";
                            cout<<month<<" of year ";
                            cout<<yrCount<<" below again."<<endl;
                            cin>>mnthRF;
                        }            

                        /*Implement totRF (total rainfall over the entire 
                         period) as an accumulator, adding all of the values for
                         monthly rainfall that are being inputted by the user*/
                        totRF+=mnthRF;
                    }    
                }    

                //Map inputs to outputs or process the data

                mnthTot = yrAmnt*12;    /*The total number of months over the
                                        whole period is the total years over the
                                        whole period x 12*/

                avgRF = totRF/mnthTot;  /*The average rainfall per month for the
                                         entire period is the total rainfall
                                         over the whole period divided by the
                                         number of months over the whole
                                         period*/

                //Output the transformed data

                cout<<"The total number of months that pass over this ";
                cout<<"specified period ";
                cout<<" = "<<mnthTot<<'.'<<endl;
                cout<<"The total inches of rainfall over this specified ";
                cout<<"period = "<<totRF;
                cout<<'.'<<endl;
                cout<<"The average rainfall per month for the entire period";
                cout<<" = "<<avgRF;
                cout<<" inches.";
                cout<<endl<<endl;
                break;
            }
            case '5':{
                
                //Declare variables
    
                unsigned short int cels; /*cels is the temperature in degrees 
                                           Celsius*/
                
                float fahr;              /*fahr is the temperature in degrees
                                           Fahrenheit*/

                //Output a data table 

                cout<<"This program will display a table of the Celsius ";
                cout<<"temperatures 0-20 ";
                cout<<"along with their Fahrenheit equivalents."<<endl<<endl;

                //Output the titles for the data table
                cout<<"TABLE OF CELSIUS TEMPERATURS 0-20 ALONG WITH THEIR ";
                cout<<"FAHRENHEIT EQUIVALENTS"<<endl<<endl;
                cout<<"      Degrees Celsius      Degrees Fahrenheit"<<endl;
                cout<<"      ---------------      ------------------"<<endl;

                /*Use a for loop to output the information contained within the
                 data table; in the for loop, the counter, cels, will be 
                 initialized at 0; cels will be incremented after each iteration
                 and the loop will continue to run until cels surpasses 20*/
                for(cels = 0; cels<=20; cels++)
                {
                    /*degrees Fahrenheit can be calculated by multiplying
                     degrees Celsius by 9/5 and adding 32*/
                     fahr = ((9/5.0f)*cels) + 32; 

                    /*Manipulate the output so it is spaced appropriately and so
                     Fahrenheit temperatures display one decimal*/ 
                    cout<<setw(14)<<cels<<setw(25)<<fixed<<setprecision(1);
                    cout<<fahr<<endl;
                } 
                cout<<endl;
                break;
            }
            case '6':{
                
              //Declare variables 
    
              float sale1, sale2, sale3, sale4, sale5; /*sale1 is the day's
                                                         sales for store 1 to be
                                                         inputted by the user,
                                                         sale2 is the day's 
                                                         sales for store 2 to be 
                                                         inputted by the user,
                                                         sale3 is the day's 
                                                         sales for store 3 to be
                                                         inputted by the user,
                                                         sale4 is the sales for
                                                         store 4 to be inputted
                                                         by the user, and sale5 
                                                         is the day's sales
                                                         for store 5 to be
                                                         inputted by the user*/ 

              //Prompt the user to input values and output data table

              cout<<"This program will ask for today's sales for five stores.";
              cout<<" A"<<endl;
              cout<<"bar graph will then be displayed comparing each store's ";
              cout<<"sales."<<endl;
              cout<<"The bars will be made up of asterisks where 1 asterisk ";
              cout<<"represents $100"<<endl<<endl;
           
              //Prompt the user to input today's sales for store 1
              cout<<"What was today's sales for store 1? Enter the value in ";
              cout<<"dollars "<<endl;
              cout<<"below. Make sure the value is not less than 0."<<endl;
              cin>>sale1;

              /*Use a while loop to keep prompting the reader to input a value
               so long as they continue to enter an invalid one*/
              while (sale1<0)
              {
                  cout<<"This is an invalid value. Please enter the value in ";
                  cout<<"dollars"<<endl;
                  cout<<"again and make sure it is not less than 0."<<endl;
                  cin>>sale1;
              }   

              //Prompt the user to input today's sales for store 2
              cout<<"What was today's sales for store 2? Enter the value in ";
              cout<<"dollars "<<endl;
              cout<<"below. Make sure the value is not less than 0."<<endl;
              cin>>sale2;

              /*Use a while loop to keep prompting the reader to input a value 
               so long as they continue to enter an invalid one*/
              while (sale2<0)
              {
                  cout<<"This is an invalid value. Please enter the value in ";
                  cout<<"dollars"<<endl;
                  cout<<"again and make sure it is not less than 0."<<endl;
                  cin>>sale2;
              }    
              //Prompt the user to input today's sales for store 3
              cout<<"What was today's sales for store 3? Enter the value in ";
              cout<<"dollars "<<endl;
              cout<<"below. Make sure the value is not less than 0."<<endl;
              cin>>sale3;

              /*Use a while loop to keep prompting the reader to input a value
               so long as they continue to enter an invalid one*/
              while (sale3<0)
              {
                  cout<<"This is an invalid value. Please enter the value in ";
                  cout<<"dollars"<<endl;
                  cout<<"again and make sure it is not less than 0."<<endl;
                  cin>>sale3;
              }
              //Prompt the user to input today's sales for store 4
              cout<<"What was today's sales for store 4? Enter the value in ";
              cout<<"dollars "<<endl;
              cout<<"below. Make sure the value is not less than 0."<<endl;
              cin>>sale4;

              /*Use a while loop to keep prompting the reader to input a value
               so long as they continue to enter an invalid one*/
              while (sale4<0)
              {
                  cout<<"This is an invalid value. Please enter the value in ";
                  cout<<"dollars"<<endl;
                  cout<<"again and make sure it is not less than 0."<<endl;
                  cin>>sale4;
              }   
              //Prompt the user to input today's sales for store 5
              cout<<"What was today's sales for store 5? Enter the value in ";
              cout<<"dollars "<<endl;
              cout<<"below. Make sure the value is not less than 0."<<endl;
              cin>>sale5;

              /*Use a while loop to keep prompting the reader to input a value 
               so long as they continue to enter an invalid one*/
              while (sale5<0)
              {
                  cout<<"This is an invalid value. Please enter the value in ";
                  cout<<"dollars"<<endl;
                  cout<<"again and make sure it is not less than 0."<<endl;
                  cin>>sale5;    
              }   
              //Output the title for the data table
              cout<<"SALES BAR CHART FOR THE 5 STORES"<<endl;
              cout<<"       (each * = $100)"<<endl<<endl;

              //Output the title for the first row
              cout<<"Store 1: ";

              /*Use a for loop to output a certain amount of asterisks depending
               on the input for the sales of store 1; in this for loop, the 
               counter will be declared as slCnt1 and initialized to 100, will
               have 100 added to it after each iteration, and will cause the
               loop to terminate when its value exceeds that which was inputted 
               by the user*/
              for(unsigned int slCnt1 = 100 ; slCnt1<=sale1; slCnt1+=100)
              {
                  cout<<'*'; /*Each iteration of the loop prints 1 *, until, by
                              counting by 100s,it reaches the sale input*/

              }   

              //output the title for the second row 
              cout<<endl<<"Store 2: ";

              /*Repeat exactly what was done in terms of the for loop for store
               1 with store 2; this time, declare and initialize the counter as
               slCnt2 and cause the loop to terminate when the counter exceeds
               the value that was inputted for store 2's sales*/
              for(unsigned int slCnt2 = 100 ; slCnt2<=sale2; slCnt2+=100)
                  cout<<'*';

              //Output the title for the third row
              cout<<endl<<"Store 3: ";

              //Repeat the same process using a for loop for store 3
              for(unsigned int slCnt3 = 100 ; slCnt3<=sale3; slCnt3+=100)
                  cout<<'*';

              //Output the title for the fourth row
              cout<<endl<<"Store 4: ";

              //Repeat the same process using a for loop for store 4
              for(unsigned int slCnt4 = 100 ; slCnt4<=sale4; slCnt4+=100)
                  cout<<'*'; 

              //Output the title for the fifth row
              cout<<endl<<"Store 5: ";

              //Repeat the same process using a for loop for store 5
              for(unsigned int slCnt5 = 100 ; slCnt5<=sale5; slCnt5+=100)
                  cout<<'*';
              
              cout<<endl;
              break;
            }
            case '7':{
                
                //Seed the random number generator using system time
    
                srand(static_cast<int>(time(0)));

                //Declare variables

                unsigned short int randNum; /*randNum is the variable that the
                                             generated random number will be put
                                             into*/

                unsigned int guess;         /*guess is the variable into which 
                                             the user will input their guess 
                                             about the value of the random
                                             number*/

                //Initialize variables

                randNum = rand()%1001;      /*The random number will be any 
                                             value from 0 to 1000; not limiting
                                             the range of potential values would
                                             make the game extremely difficult*/ 

               //Prompt the user to input data

                cout<<"This program will play a game with the user! A random ";
                cout<<"whole"<<endl;
                cout<<"number will be generated and the user must guess what ";
                cout<<"it is."<<endl;
                cout<<"Depending on the guess the program will give a hint";
                cout<<endl;
                cout<<"indicating whether the next guess should be higher or ";
                cout<<"lower.";
                cout<<endl<<endl;

                cout<<"Type your guess of the random number below. Keep in ";
                cout<<"mind the random";
                cout<<"number will be a whole number between 0 and 1000."<<endl;
                cin>>guess;

               //Use a while loop to output the appropriate path of code 

                /*The while loop will keep iterating as long as the guess is 
                 wrong*/
                while (guess!=randNum)
                {
                    /*Nest a ternary operator within the while statement that 
                     tells the user to input a higher value if their guess it 
                     too low and a lower value if their guess is too high*/
                    guess > randNum ? cout<<"This guess is too high! Input a "
                                          <<"lower value "
                                          <<"to get closer to the correct "
                                          <<"value."
                                    : cout<<"This guess is too low! Input a "
                                          <<"higher value "
                                          <<"to get closer to the correct "
                                          <<"value.";

                    //Input a new value
                    cout<<endl;
                    cin>>guess;
                }    

                //If the guess is correct, congratulate the user
                cout<<"Congratulations! This is the correct value.";
                cout<<endl<<endl;
                break;
            }
            case '8':{
                
                //Declare all Variables Here
    
                unsigned short int cnterA, cnterB; /*cnterA is the variable that
                                                    will serve as the counter 
                                                    for the outer loop and 
                                                    cnterB is the variable that
                                                    will serve as the counter 
                                                    for the inner loop*/

                short int sqLngth;                 /*sqLngth is the length each
                                                    side of the square will be
                                                    using the character 'X';
                                                    this will be inputted by the
                                                    user*/


                //Prompt the user to input the length of each side of the square

                cout<<"This program will display a square on the screen using ";
                cout<<"the "<<endl;
                cout<<"character 'X.' The size of the square will be ";
                cout<<"determined by"<<endl;
                cout<<"the user inputting what the length of the sides will ";
                cout<<"be."<<endl;
                cout<<endl;

                cout<<"Input an integer from 0 to 15. This value will be the ";
                cout<<"length"<<endl;
                cout<<"of the sides of the square."<<endl;
                cin>>sqLngth;

                /*Use a while statement to prompt the user to input a new value
                 if the so long as the inputted value is unacceptable*/
                while(sqLngth<0 || sqLngth>15)
                {
                    cout<<"This is an invalid input. Input another integer ";
                    cout<<"from 0 to 15.";
                    cout<<endl;
                    cin>>sqLngth;
                }    

                /*Use a for loop nested in another for loop to output the 
                 appropriate code*/

                /*For the outer for loop, the counter is initialized at 1, is 
                 incremented after each iteration, and will terminate the loop 
                 after it exceeds the square length inputted by the user*/
                for(cnterA = 1; cnterA<=sqLngth; cnterA++)
                {
                    /*For the inner loop, the counter is initialized, 
                     incremented, and terminates the loop the same way as the
                     outer loop, but it iterates same amount of times inputted 
                     for sqLngth per each iteration of the outer loop; so, one 
                     iteration of the outer loop is one line of the output, 
                     and each iteration of the inner loop is one 'X' on each
                     line*/
                    for(cnterB = 1; cnterB<=sqLngth; cnterB++)
                        cout<<"X";

                    /*This endl applies to the outer loop and insures there are
                     multiple lines of X's*/            
                    cout<<endl;             
                }
                cout<<endl;
                break;
            }
            case '9':{
                
                 //Declare variables
    
                /*cnterA is the counter for the outer loop of pattern A, cnterB 
                  is the counter for the inner loop of pattern A, cnterC is the 
                  counter for the outer loop of pattern B, and cnterD is the
                  counter for the inner loop of pattern B*/
                unsigned short int cnterA, cnterB, cnterC, cnterD; 

                //Explain the program to the user

                cout<<"This program will display two patterns. The second ";
                cout<<"pattern"<<endl;
                cout<<"will be a sort of upside down version of the first.";
                cout<<endl<<endl;

                //Output the patterns

                //Output the title for pattern A
                cout<<"Pattern A"<<endl;
                cout<<"---------"<<endl;

                /*Output the actual pattern A using a for loop nested in a for
                 loop; the counter of the outer loop will be initialized at 1, 
                 increment after each iteration, and will terminate the loop 
                 after surpassing 10; the counter for the inner loop will be 
                 initialized at 1, increment after each iteration, and will
                 terminate the loop after surpassing whatever counter the outer
                 loop is currently on; so, if outer loop is on counter 2, 
                 inner loop will iterate twice and print 2 consecutive *'s, 
                 etc.*/
                for (cnterA = 1; cnterA<=10; cnterA++)
                {
                    for (cnterB = 1; cnterB<=cnterA; cnterB++)
                        cout<<"+";

                    //End the line after all "+'s" have been outputted for 1 row
                    cout<<endl;
                }

                cout<<endl;

                //Output the title for pattern B
                cout<<"Pattern B"<<endl;
                cout<<"---------"<<endl;

                /*Output the actual pattern B using a for loop nested in a for 
                 loop; the counter of the outer loop will be initialized at 10,
                 decrement after each iteration, and will terminate the loop 
                 after going lower than 1; the counter for the inner loop will
                 be initialized at 1, increment after each iteration, and will 
                 terminate the loop after exceeding whatever counter the outer 
                 loop is currently on; so, during the first iteration of the 
                 outer loop, the inner loop will iterate 10 times, causing 10 
                 consecutive *'s to be printed, during the second iteration of 
                 the outer loop, the inner loop will only do it 9 times, etc.*/

                for (cnterC = 10; cnterC >= 1; cnterC--)
                {
                    for (cnterD = 1; cnterD <= cnterC; cnterD++)
                      cout<<"+";

                    /*End the line after all the "+'s" have been outputted for 1
                     row*/
                    cout<<endl;
                }
                cout<<endl;
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