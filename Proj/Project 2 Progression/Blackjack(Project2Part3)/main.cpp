/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 25, 2017, 8:31 PM
 * Purpose:  Blackjack (Project 2)
 */

//System Libraries Here
#include <iostream>     //Input - Output Manipulation Library
#include <cstdlib>      //C Standard Library for rand() Function
#include <ctime>        //C Time Library to Seed the Random Number Generator
#include <string>       //Include String Library for String Functions
#include <iomanip>      //Input - Output Manipulatin Library to Format Output
#include <fstream>      //Stream for Writing to and Reading from Files
#include <cmath>        //C Math Library for More Math Functions
#include <vector>       //Vector File in Order to Define and Work With Vectors
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

const int MONMAX = 5; 
const int PLAYMAX = 4;

//Function Prototypes Here

void nameCrd (unsigned short &, string &, unsigned short &);
void showAry (float [][MONMAX], short);
void sortAry (unsigned short [], unsigned short[], short);
void showAry (unsigned short [], unsigned short[], short);
int cnvPerc (float, int = 100);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    
    /*Declare a variable for each card in the game; in one game where it is 
     just 1 player against the dealer, it is almost statistically impossible for
     the dealer or player to have more than 8 cards in their hand; given these 
     facts the, 8 cards are declared for the player ad 8 are declared for the 
     dealer; the  player only draws from 1 through 8 and the dealer draws from 
     9 through 16 in this  program, but that does not affect the random nature 
     of the game*/
    unsigned short card1, card2, card3, card4, card5, card6, card7, card8, 
                   card9, card10, card11, card12, card13, card14, card15, 
                   card16;
    
    unsigned short value; /*value is the general value of a particular card
                           and will be used to input the correct value into each
                           of the 16 cards*/
    
    //Declare a variable for the values each of the 16 cards holds
    unsigned short value1, value2, value3, value4, value5, value6, value7,
                   value8, value9, value10, value11, value12, value13, value14,
                   value15, value16;
    
    string face, suit; /*face is where a string that gives the name of the 
                        face of the card will be inputted and suit is where a
                        string that gives the name of the suit of the card
                        will be inputted*/
    
    /*Declare a variable that contains the face and suit names of the card for
     each of the 16 cards*/
    string name1, name2, name3, name4, name5, name6, name7, name8, 
           name9, name10, name11, name12, name13, name14, name15, 
           name16;
    
    float bet, insBet;                 //bet is the amount of the initial bet,
                                       // and insBet is the amount of the insurance
                                       //bet (allowed if dealer's face up card
                                       //is an ace)
    
    unsigned short playTot[MONMAX], dealTot[MONMAX]; 
                                    /*playTot holds the value of all the 
                                     player's cards during each player's set of 
                                     games and dealTot holds the value
                                     of all the dealer's cards during each 
                                     player's set of games*/
    
    float returns; /*returns is money won from any particular bet and gets
                    added to the total money a player has*/
    
    short int gameCnt, playCnt; /*gameCnt is the variable into which the player
                                 inputs the amount of games they would like to 
                                 play; this is used in a for for loop; playCnt
                                 is the variable into which the player inputs 
                                 the amount of players that will be playing;
                                 this also will be used in a for loop*/
    
    float money [PLAYMAX][MONMAX]; /*money is an array that will hold the 
                                    amounts of money each player had at the end
                                    of each round*/
    
    short userIpt; /*userIpt is the variable into which the user will input
                    the game that they want to see the player's and dealer's 
                    final hand values for (at the end of each player's set of 
                    games)*/
    
    vector<float> playBet(MONMAX); 
                            /*PlayBet is a vector that will hold the bets each
                            player made for each game*/
    
    //Open a file to write to
    ofstream saveMny; /*This is what allows the money amounts at the end of 
                       each game to be saved to a file*/
    
    saveMny.open("Moneyamounts.txt"); //This opens the file 
     
    
     //Prompt the user for input 
     
     cout<<"Welcome to Blackjack!! This program works like classic Blackjack";
     cout<<endl<<"in most respects. The rules only differ are that"<<endl;
     cout<<"there are no splits and a designated number of games must"<<endl;
     cout<<"be chosen before playing them out. Also, not all the players"<<endl;
     cout<<"play at the same time in this version. However, rules such"<<endl;
     cout<<"as getting as close to 21 without going over, betting at"<<endl;
     cout<<"the beginning of each game, being able to double only on the"<<endl;
     cout<<"first round, and getting certain returns on your bet based"<<endl;
     cout<<"on your hand with respect to the dealer's still apply."<<endl<<endl;
     
     /*Prompt the user to input the amount of players; it is important to note
      that this simply will be each individual "1v1'ing" the dealer each game;
      to clarify, player1 will play out all of their games against the dealer,
      followed by player2 playing out all of their games against the dealer, 
      etc.*/
     
     cout<<"How many players (max of 4) will be playing against the dealer? ";
     cout<<"Each"<<endl;
     cout<<"player will play out the number of games specified by the user.";
     cout<<endl;
     cin>>playCnt;
     
     //Continuously prompt the user to input so long as their input is invalid
     while (playCnt<0 ||playCnt>4)
     {
         cout<<"This is an invalid input. Input the amount of games in a"<<endl;
         cout<<"row you would like to play, making sure this value is between ";
         cout<<"1 and 4."<<endl;
         cin>>playCnt;
     }
     
     //Prompt the user to input how many games they want each player to play
     cout<<"How many games in a row would each of these"<<endl;
     cout<<"players to play?";
     cout<<" Input this"<<endl;
     cout<<"amount below, making sure it is between 1 and 5."<<endl;
     cin>>gameCnt;
     
     /*Continuously prompt the user to input a number so long as their input is
      invalid*/
     while (gameCnt<1 || gameCnt>5)
     {
         cout<<"This is an invalid input. Input the amount of games in a"<<endl;
         cout<<"row you would like to play, making sure this value is between ";
         cout<<"1 or 5."<<endl;
         cin>>gameCnt;
     }
     
     /*Use a for loop to keep playing out game sets for the number of players
      specified; THERE WILL BE NO INDENTATION FROM THE EHADER OF THE LOOP TO
      ITS BODY, as this would cause some portions of the program to be so
      squished to the right that it would be essentially unreadable*/
     
     for (short int i = 0; i < playCnt; i++)
     {

         //Initialize variables

          money[i][0] = 500.0f; /*money is the amount of money that the player has;  
                           cannot bet more than this; every time a new player
                           starts their series of games, they start with $500*/

        /*Use a for loop to keep shuffling cards and playing the game the amount
         of times specified by the user; THERE WILL BE NO INDENTATION FROM THE 
         HEADER OF THE LOOP TO ITS BODY, as this would cause some portions of the
         program to be so condensed to the right that it would essentially be 
         unreadable*/

        for (short int j = 0; j < gameCnt; j++)
        {    

            /*Find the name and value of card1(with random numbers) by calling a funciton;
             this is within the for loop to simulate shuffling at the start of each
             new game*/

            nameCrd (card1, name1, value1);

            /*Repeat the same exact process for cards2 through 16, except put all 
             function calls in a do {} statement; follow this up with a while that forces
             the calculations to repeat again if the name of  a card is the same as 
             any of the previous ones; this is because in one deck of cards, no card is 
             the same; do this for cards 2 through 16*/
            do{
               nameCrd (card2, name2, value2);
            } 
            while (name2==name1);

            //card3
            do{
               nameCrd (card3, name3, value3);
            } 
            while (name3==name2||name3==name1);

            //card4
            do{
                nameCrd (card4, name4, value4);
            }  
            while (name4==name3||name4==name2||name4==name1);

            //card5
             do{
                   nameCrd (card5, name5, value5);
            } 
            while (name5==name3||name5==name2||name5==name1||name5==name4);

            //card6
             do{
                   nameCrd (card6, name6, value6);
            } 
            while (name6==name3||name6==name2||name6==name1||name6==name4
                    ||name6==name5);

            //card7
            do{
                    nameCrd (card7, name7, value7);
            } 
            while (name7==name3||name7==name2||name7==name1||name7==name4
                    ||name7==name5||name7==name6);

            //card8
            do{
                     nameCrd (card8, name8, value8);
            } 
            while (name8==name3||name8==name2||name8==name1||name8==name4
                    ||name8==name5||name8==name6||name8==name7);

            //card9
            do{
                    nameCrd (card9, name9, value9);
            } 
            while (name9==name3||name9==name2||name9==name1||name9==name4
                    ||name9==name5||name9==name6||name9==name7||name9==name8);

            //card10
            do{
                     nameCrd (card10, name10, value10);
            } 
            while (name10==name3||name10==name2||name10==name1||name10==name4
                    ||name10==name5||name10==name6||name10==name7||name10==name8
                    ||name10==name9);

            //card11
            do{
                    nameCrd (card11, name11, value11);
            } 
            while (name11==name3||name11==name2||name11==name1||name11==name4
                    ||name11==name5||name11==name6||name11==name7||name11==name8
                    ||name11==name9||name11==name10);

            //card12
            do{
                    nameCrd (card12, name12, value12);
            }
             while (name12==name3||name12==name2||name12==name1||name12==name4
                    ||name12==name5||name12==name6||name12==name7||name12==name8
                    ||name12==name9||name12==name10||name12==name11);

            //card13
            do{
                    nameCrd (card13, name13, value13);
            } 
            while (name13==name3||name13==name2||name13==name1||name13==name4
                    ||name13==name5||name13==name6||name13==name7||name13==name8
                    ||name13==name9||name13==name10||name13==name11||name13==name12); 

            //card14
            do{
                     nameCrd (card14, name14, value14);
            } 
            while (name14==name3||name14==name2||name14==name1||name14==name4
                    ||name14==name5||name14==name6||name14==name7||name14==name8
                    ||name14==name9||name14==name10||name14==name11||name14==name12
                    ||name14==name13);

            //card15
            do{
                 nameCrd (card15, name15, value15); 
            } 
            while (name15==name3||name15==name2||name15==name1||name15==name4
                    ||name15==name5||name15==name6||name15==name7||name15==name8
                    ||name15==name9||name15==name10||name15==name11||name15==name12
                    ||name15==name13||name15==name14);

            //card16
            do{
                    nameCrd (card16, name16, value16);
            } 
            while (name16==name3||name16==name2||name16==name1||name16==name4
                    ||name16==name5||name16==name6||name16==name7||name16==name8
                    ||name16==name9||name16==name10||name16==name11||name16==name12
                    ||name16==name13||name16==name14||name16==name15);  

            //Play the game of Blackjack!

            //Set the numerical output format
            cout<<fixed<<setprecision(2)<<showpoint;

            //Start play

            /*If money is less than $1, reset the player's money to $100; if not, set it
             equal to itself; only display this beyond each player's first round*/
            if (money [i][j-1] < 1.00 && j!=0)
            {    
                cout<<"You dropped below $1 so your money was reset to $100."<<endl;
                cout<<endl;
            }    

            /*Ternary operator to set the money at the proper amount; an if statement
             has to be applied to this to make sure this only happens for rounds
             after 1*/
            if (j!=0)
            {    
                money[i][j-1] < 1.00 ? money[i][j] = 100.00 
                                     : money[i][j] = money[i][j-1];
            }

            //Prompt the player to place their bet
            cout<<"Enter the amount you, player "<<i + 1<<", would like to bet"<<endl;
            cout<<"for game "<<j + 1;
            cout<<" below. You currently have $"<<money[i][j]<<'.'<<endl;
            cin>>playBet[j];

            /*Use a while loop to prevent the player from betting a negative number or
             betting higher than how much they currently have*/
            while (playBet[j]<0 || playBet[j]>money[i][j])
            {
                cout<<"This is an invalid bet. Please enter the amount you would"<<endl;
                cout<<"like to bet below."<<endl;
                cin>>playBet[j];
            } 

            money[i][j] -= playBet[j]; /*The money the player has after they place their bet is what 
                                         they had minus their bet*/

            //Deal the cards and display the game with appropriate formatting
            cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ???"<<endl;
            cout<<setw(30)<<"------"<<endl; 
            cout<<setw(20)<<name9<<setw(19)<<"???"<<endl; /*name9 is the dealer's
                                                            first card; the dealer
                                                            starts here for the 
                                                            the simplicity of the 
                                                            program as explained in the
                                                            beginning, but the gameplay
                                                            is not affected*/
            cout<<endl<<endl<<endl;

            //Use an if statement to make an ace equal 1 if the hand total is over 21
            if (value1 + value2 > 21)
            {        
                if(value1 == 11)
                    value1=1;
                else if(value2 == 11)
                    value2=1;
            }
            playTot[j] = value1 + value2; //Player's total is value1 plus value2
            cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = "<<playTot[j]<<endl;
            cout<<setw(30)<<"------"<<endl;
            cout<<setw(20)<<name1<<setw(25)<<name2; /*name1 and name2 are the 
                                                           player's first two cards*/

            cout<<setw(28)<<"**Current Money = $"<<money[i][j]<<endl;/*Display current 
                                                                   money on bottom 
                                                                   right*/
            cout<<endl;

            cout<<"Hit enter when you are ready to progress."<<endl; /*Prompt the player
                                                                        to continue when
                                                                        ready*/

            cin.ignore(); //Use cin.ignore() to allow for cin>> and cin.get()
            cin.get();
            cout<<endl<<endl;

            /*If the dealer's showing card is an ace, and money that the player has left
             is greater than or equal to half of the bet, prompt the player to input if
             they want to place an insurance bet*/

            char choice;
            if ((name9 == "Ace of Spades" || name9 =="Ace of Diamonds" || 
                    name9 == "Ace of Hearts" || name9 == "Ace of Clubs") && 
                    money[i][j] >= (1.0f/2)*playBet[j]) 
            {
                cout<<"Would you like to place an insurance bet? Type 'Y' to place one";
                cout<<" or any other key not to, and hit enter after typing choice.";
                cout<<endl;
                cin>>choice;

                //Use an if/else statement to play out the insurance bet
                if (choice == 'Y')
                {
                    insBet = (1.0f/2)*playBet[j];
                    cout<<"You placed an insurance bet of $"<<insBet<<endl;
                    money[i][j]-=insBet;

                }
                else 
                    insBet = 0.0f; 
            }    


            /*Use if/else if statements to give returns of 3/2 the bet + the OG bet
            if player has 21, returns of only OG bet if both the player and the dealer 
            have 21, and no returns if only the dealer has 21; take insBet 
            into consideration, however, for all of these; redisplay the cards with the 
            dealer's both face up*/

            playTot[j] = value1 + value2; /*Total of player's hand is the value of 
                                            their first card plus the value of their
                                            second*/
            dealTot [j] = value9 + value10; /*Total of dealer's hand is the value of
                                              their first card (card 25) + the value 
                                              of their second card (card 26)*/

            if ((playTot[j] == 21) && (dealTot[j] == 21))      /*If both player 
                                                                and dealer have
                                                                Blackjack*/                                                            
            {
                cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
                cout<<endl;
                cout<<setw(30)<<"------"<<endl;
                cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
                cout<<endl<<endl<<endl;
                cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = "<<playTot[j];
                cout<<endl;
                cout<<setw(30)<<"------"<<endl;
                cout<<setw(20)<<name1<<setw(25)<<name2;
                cout<<setw(28)<<"**Current Money = $"<<money[i][j]<<endl;

                returns = playBet[j] + 3*insBet; /*Player gets back just what they bet and 3 
                                           times insBet if they made one (their insBet 
                                           and 2 times that bet)*/

                money[i][j]+=returns;
                cout<<"PUSH"<<endl;
                cout<<"You now have $"<<money[i][j]<<endl;

                if (insBet > 0.1f) //If the player made an insurance bet
                    cout<<"You won $"<<2*insBet<<" from insurance.";//Insurance pays 2-1
            }

            else if (playTot[j] == 21) //If only player has Blackjack
            {
                cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
                cout<<endl;
                cout<<setw(30)<<"------"<<endl;
                cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
                cout<<endl<<endl<<endl;
                cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = "<<playTot[j];
                cout<<endl;
                cout<<setw(30)<<"------"<<endl;
                cout<<setw(20)<<name1<<setw(25)<<name2;
                cout<<setw(28)<<"**Current Money = $"<<money[i][j]<<endl;

                returns = playBet[j] + (3.0f/2)*playBet[j]; /*Player gets back what they bet and 1/5 
                                               times it*/

                money[i][j]+=returns;
                cout<<"BLACKJACK!!"<<endl;
                cout<<"You won $"<<(3.0f/2)*playBet[j]<<endl;
                cout<<"You now have $"<<money[i][j];
            }

            else if (dealTot[j] == 21) //If only dealer has Blackjack
            {
                cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
                cout<<endl;
                cout<<setw(30)<<"------"<<endl;
                cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
                cout<<endl<<endl<<endl;
                cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = "<<playTot[j];
                cout<<endl;
                cout<<setw(30)<<"------"<<endl;
                cout<<setw(20)<<name1<<setw(25)<<name2;
                cout<<setw(28)<<"**Current Money = $"<<money[i][j]<<endl;

                returns = 3*insBet; /*Player gets back 3x insurance bet if they made one
                                     (the actual insBet + 2x the insBet)*/
                money[i][j]+=returns;
                cout<<"DEALER'S BLACKJACK"<<endl;
                cout<<"You now have $"<<money[i][j]<<endl;

                if (insBet > 0.1f) //If the player made an insurance bet
                    cout<<"You won $"<<2*insBet<<" from insurance."; //Insurance pays 2-1
            }

            else //If no one has 21 to start with, play the game
            {   

                /*Give the player all of their options of play and use a switch statement
                 to let them select one*/

                cout<<"Which would you like to do? Type the letter that is to the ";
                cout<<endl;
                cout<<"left of each choice to make that choice."<<endl;
                cout<<"A. Hit"<<endl;
                cout<<"B. Stand"<<endl;

                /*Only display the "double" option if there is enough money left to put 
                 down an equivalent to the original bet again*/
                if (money[i][j]>=playBet[j])
                    cout<<"C. Double"<<endl;

                cin>>choice;

                /*This makes it to where the player cannot choose double when it
                 is not shown on the menu; double does not display when money < bet, so when
                 money < bet and if choice is C, choice C becomes X to cause another
                 input to be asked for*/
                if (money[i][j] < playBet[j])
                    if (choice == 'C')
                        choice = 'X';

                /*Continuously prompt the player to input a choice so long as their's 
                 is not A, B, or C; do this for the choice for the remaining rounds*/
                while (!(choice == 'A'||choice == 'B'||choice == 'C'))
                {
                    cout<<"This is an invalid choice. Please type the letter to"<<endl;
                    cout<<"the left of the menu to make the corresponding"<<endl;
                    cout<<"choice."<<endl;
                    cout<<" A. Hit"<<endl;
                    cout<<" B. Stand"<<endl;
                    if(money[i][j]>=playBet[j])
                    {    
                        cout<<" C. Double"<<endl;
                    }    
                    cin>>choice;
                    if (money[i][j] < playBet[j])
                    {    
                        if (choice == 'C')
                            choice = 'X';
                    }    
                }    
                switch(choice)
                {
                    case 'A':
                       /*Deal the next card for the player by copying the display 
                        done for the first round and adding the next card; this card's
                        name and value get added to the screen output, and it gets 
                        considered in the ace calculation; repeat this for each hit*/

                        cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ???"<<endl;
                        cout<<setw(30)<<"------"<<endl; 
                        cout<<setw(20)<<name9<<setw(19)<<"???"<<endl;
                        cout<<endl<<endl<<endl;

                        /*This is the ace calculation with 3 cards; if the 3 cards 
                         added together is over 21 and one of the cards is an ace, 
                         its value gets set to 1; if its still over 21, another ace 
                         gets set to 1, and so on*/
                        while ((value1 + value2 + value3 > 21) && (value1 == 11 ||
                                value2 == 11|| value3 == 11))
                        {   
                            if(value1 == 11)
                                value1 = 1;
                            else if(value2 == 11)
                                value2 = 1;
                            else if (value3 == 11)
                                value3 = 1;
                        }
                        playTot[j] = value1 + value2 + value3;
                        cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = "<<playTot[j];
                        cout<<endl;
                        cout<<setw(30)<<"------"<<endl;
                        cout<<setw(20)<<name1<<setw(25)<<name2<<endl;
                        cout<<setw(20)<<name3<<endl;
                        cout<<setw(60)<<"**Current Money = $"<<money[i][j]<<endl;
                        cout<<"Hit enter when you are ready to progress."<<endl; 

                        cin.ignore();  
                        cin.get();
                        cout<<endl<<endl; 

                        /*Use if/else if statements to determine the player's options
                         depending on their hand value*/
                        if (playTot[j] > 21)           //  If the player has more than
                        {                           //  21, they bust and the 
                                                    //  dealer draws cards
                            cout<<"BUST"<<endl;
                            cout<<"Hit enter when";
                            cout<<" you are ready to progress."<<endl;
                            cin.get();
                            choice = 'B'; /*Set choice equal to B so the prompt about 
                                           the dealer drawing will come up; continue
                                           to do this when the player can no longer make
                                           moves*/

                        }

                        else if (playTot[j] == 21)                  //If the player has 21, 
                        {                                        //automatically stand 
                            cout<<"You have 21."<<endl;          //and dealer draws                     
                            cout<<"Hit enter when";
                            cout<<" you are ready to progress."<<endl;
                            cin.get();
                            choice = 'B';
                        }        

                        else 
                               /*If the player has less than 21, continue the game using a
                               switch to let the player make their next choice; this is 
                               how the game will always progress until it is the 
                               dealer's turn*/ 
                        {
                            cout<<"Which would you like to do? Type the letter that is";
                            cout<<endl;
                            cout<<"to the left of each choice to make that choice.";
                            cout<<endl;
                            cout<<"A. Hit"<<endl;
                            cout<<"B. Stand"<<endl;
                            cin>>choice;   
                        } 
                        while (!(choice == 'A'||choice == 'B'))
                        {
                            cout<<"This is an invalid choice. Please type the letter ";
                            cout<<"to"<<endl;
                            cout<<"the left of the menu to make the corresponding";
                            cout<<endl;
                            cout<<"choice."<<endl;
                            cout<<" A. Hit"<<endl;
                            cout<<" B. Stand"<<endl;
                            cin>>choice;
                        }    

                        switch (choice)
                        {
                            case 'A':
                                /*Perform the exact same steps that were done for 
                                 dealing the third card; keep repeating this process
                                 for a total of 7 times, as it is essentially 
                                 statistically impossible to have more than 8 cards
                                 in one hand*/
                                cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ???";
                                cout<<endl;
                                cout<<setw(30)<<"------"<<endl; 
                                cout<<setw(20)<<name9<<setw(19)<<"???"<<endl;
                                cout<<endl<<endl<<endl;

                                /*Do the same ace conversion method except with 4
                                 cards*/
                                while ((value1 + value2 + value3 + value4 > 21) && 
                                       (value1 == 11 || value2 == 11 || value3 == 11
                                        || value4 == 11))
                                {   
                                    if(value1 == 11)
                                        value1 = 1;
                                    else if(value2 == 11)
                                        value2 = 1;
                                    else if (value3 == 11)
                                        value3 = 1;
                                    else if (value4 == 11)
                                        value4 = 1;
                                }
                                playTot[j] = value1 + value2 + value3 + value4;
                                cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = ";
                                cout<<playTot[j]<<endl;
                                cout<<setw(30)<<"------"<<endl;
                                cout<<setw(20)<<name1<<setw(25)<<name2<<endl;
                                cout<<setw(20)<<name3<<setw(25)<<name4<<endl;
                                cout<<setw(60)<<"**Current Money = $"<<money[i][j]<<endl;
                                cout<<"Hit enter when you are ready to progress."<<endl; 

                                cin.ignore();  
                                cin.get();
                                cout<<endl<<endl;

                                 /*Use if/else if statements to determine the player's 
                                 option depending on their hand value*/
                                if (playTot[j] > 21)   //>21 = bust; dealer draws
                                {    
                                    cout<<"BUST"<<endl;
                                    cout<<"Hit enter ";
                                    cout<<"when";
                                    cout<<" you are ready to progress."<<endl;
                                    cin.get();
                                    choice = 'B';
                                }

                                else if (playTot[j] == 21)                 //If player has 
                                                                         //21, 
                                {                                        //stand; 
                                    cout<<"You have 21."<<endl;          //dealer draws                     
                                    cout<<"Hit enter ";
                                    cout<<"when";
                                    cout<<" you are ready to progress."<<endl;
                                    cin.get();
                                    choice = 'B';
                                }        

                                else 
                                      /*If the player has less than 21, continue the game
                                      using a switch; the next rounds when a hit occurs
                                      no longer will contain the commentary above for 
                                      the sake of cleanliness; read the steps above 
                                      to understand what is occurring*/
                                {
                                    cout<<"Which would you like to do? Type the letter";
                                    cout<<" that is";
                                    cout<<endl;
                                    cout<<"to the left of each choice to make that ";
                                    cout<<"choice.";
                                    cout<<endl;
                                    cout<<"A. Hit"<<endl;
                                    cout<<"B. Stand"<<endl;
                                    cin>>choice;    
                                }
                                while (!(choice == 'A'||choice == 'B'))
                                {
                                    cout<<"This is an invalid choice. Please type the ";
                                    cout<<"letter to"<<endl;
                                    cout<<"the left of the menu to make the ";
                                    cout<<"corresponding";
                                    cout<<endl;
                                    cout<<"choice."<<endl;
                                    cout<<" A. Hit"<<endl;
                                    cout<<" B. Stand"<<endl;
                                    cin>>choice;
                                } 
                                switch (choice)
                                {        
                                    case 'A':
                                        cout<<setw(30)<<"DEALER"<<setw(20);
                                        cout<<"hand total = ???";
                                        cout<<endl;
                                        cout<<setw(30)<<"------"<<endl; 
                                        cout<<setw(20)<<name9<<setw(19)<<"???"<<endl;
                                        cout<<endl<<endl<<endl;

                                        while ((value1 + value2 + value3 + value4 +
                                                value5 > 21) && 
                                               (value1 == 11 || value2 == 11 
                                                || value3 == 11 || value4 == 11 
                                                || value5 == 11))
                                        {   
                                            if(value1 == 11)
                                                value1 = 1;
                                            else if(value2 == 11)
                                                value2 = 1;
                                            else if (value3 == 11)
                                                value3 = 1;
                                            else if (value4 == 11)
                                                value4 = 1;
                                            else if (value5 == 11)
                                                value5 = 1;
                                        }
                                        playTot[j] = value1 + value2 + value3 + value4 
                                                + value5;
                                        cout<<setw(30)<<"PLAYER"<<setw(20);
                                        cout<<"hand total = ";
                                        cout<<playTot[j]<<endl;
                                        cout<<setw(30)<<"------"<<endl;
                                        cout<<setw(20)<<name1<<setw(25)<<name2;
                                        cout<<endl;
                                        cout<<setw(20)<<name3<<setw(25)<<name4;
                                        cout<<endl;
                                        cout<<setw(20)<<name5;
                                        cout<<endl;
                                        cout<<setw(60)<<"**Current Money = $";
                                        cout<<money[i][j];
                                        cout<<endl;
                                        cout<<"Hit enter when you are ready to ";
                                        cout<<"progress."<<endl; 

                                        cin.ignore();  
                                        cin.get();
                                        cout<<endl<<endl;


                                        if (playTot[j] > 21)   
                                        {    
                                            cout<<"BUST"<<endl;
                                            cout<<"Hit enter ";
                                            cout<<"when";
                                            cout<<" you are ready to progress."<<endl;
                                            choice = 'B';
                                            cin.get();
                                        }

                                        else if (playTot[j] == 21)                 

                                        {                                        
                                            cout<<"You have 21."<<endl;                              
                                            cout<<"Hit enter ";
                                            cout<<"when";
                                            cout<<" you are ready to progress."<<endl;
                                            choice = 'B';
                                            cin.get();
                                        }        

                                        else  
                                        {
                                            cout<<"Which would you like to do? Type ";
                                            cout<<"the letter";
                                            cout<<" that is";
                                            cout<<endl;
                                            cout<<"to the left of each choice to make ";
                                            cout<<"that ";
                                            cout<<"choice.";
                                            cout<<endl;
                                            cout<<"A. Hit"<<endl;
                                            cout<<"B. Stand"<<endl;
                                            cin>>choice;
                                        }
                                        while (!(choice == 'A'||choice == 'B'))
                                        {
                                            cout<<"This is an invalid choice. Please  ";
                                            cout<<"type the letter to"<<endl;
                                            cout<<"the left of the menu to make the ";
                                            cout<<"corresponding";
                                            cout<<endl;
                                            cout<<"choice."<<endl;
                                            cout<<" A. Hit"<<endl;
                                            cout<<" B. Stand"<<endl;
                                            cin>>choice;
                                        }
                                        switch(choice)
                                        {        
                                            case 'A':
                                            cout<<setw(30)<<"DEALER"<<setw(20);
                                            cout<<"hand total = ???";
                                            cout<<endl;
                                            cout<<setw(30)<<"------"<<endl; 
                                            cout<<setw(20)<<name9<<setw(19)<<"???";
                                            cout<<endl;
                                            cout<<endl<<endl<<endl;

                                            while ((value1 + value2 + value3 + value4 +
                                                    value5 + value6 > 21) && 
                                                   (value1 == 11 || value2 == 11 
                                                    || value3 == 11 || value4 == 11 
                                                    || value5 == 11 || value6 ==11))
                                            {   
                                                if(value1 == 11)
                                                    value1 = 1;
                                                else if(value2 == 11)
                                                    value2 = 1;
                                                else if (value3 == 11)
                                                    value3 = 1;
                                                else if (value4 == 11)
                                                    value4 = 1;
                                                else if (value5 == 11)
                                                    value5 = 1;
                                                else if (value6 == 11)
                                                    value6 = 1;
                                            }
                                            playTot[j] = value1 + value2 + value3 + value4 
                                                    + value5 + value6;
                                            cout<<setw(30)<<"PLAYER"<<setw(20);
                                            cout<<"hand total = ";
                                            cout<<playTot[j]<<endl;
                                            cout<<setw(30)<<"------"<<endl;
                                            cout<<setw(20)<<name1<<setw(25)<<name2;
                                            cout<<endl;
                                            cout<<setw(20)<<name3<<setw(25)<<name4;
                                            cout<<endl;
                                            cout<<setw(20)<<name5<<setw(25)<<name6;
                                            cout<<endl;
                                            cout<<setw(60)<<"**Current Money = $";
                                            cout<<money[i][j];
                                            cout<<endl;
                                            cout<<"Hit enter when you are ready to ";
                                            cout<<"progress."<<endl; 

                                            cin.ignore();  
                                            cin.get();
                                            cout<<endl<<endl;


                                            if (playTot[j] > 21)   
                                            {    
                                                cout<<"BUST"<<endl;
                                                cout<<" Hit enter ";
                                                cout<<"when";
                                                cout<<" you are ready to progress.";
                                                cout<<endl;
                                                choice = 'B';
                                                cin.get();
                                            }

                                            else if (playTot[j] == 21)                 

                                            {                                        
                                                cout<<"You have 21."<<endl; 
                                                cout<<" Hit enter ";
                                                cout<<"when";
                                                cout<<" you are ready to progress.";
                                                cout<<endl;
                                                choice = 'B';
                                                cin.get();
                                            }        

                                            else  
                                            {
                                                cout<<"Which would you like to do? ";
                                                cout<<"Type ";
                                                cout<<"the letter";
                                                cout<<" that is";
                                                cout<<endl;
                                                cout<<"to the left of each choice to ";
                                                cout<<"make ";
                                                cout<<"that ";
                                                cout<<"choice.";
                                                cout<<endl;
                                                cout<<"A. Hit"<<endl;
                                                cout<<"B. Stand"<<endl;
                                                cin>>choice;
                                            }
                                            while (!(choice == 'A'||choice == 'B'))
                                            {
                                                cout<<"This is an invalid choice. ";
                                                cout<<"Please type the letter to"<<endl;
                                                cout<<"the left of the menu to make ";
                                                cout<<"the corresponding";
                                                cout<<endl;
                                                cout<<"choice."<<endl;
                                                cout<<" A. Hit"<<endl;
                                                cout<<" B. Stand"<<endl;
                                                cin>>choice;
                                            }
                                            switch(choice)
                                            {        
                                                case 'A':
                                                cout<<setw(30)<<"DEALER"<<setw(20);
                                                cout<<"hand total = ???";
                                                cout<<endl;
                                                cout<<setw(30)<<"------"<<endl; 
                                                cout<<setw(20)<<name9<<setw(19)<<"???";
                                                cout<<endl;
                                                cout<<endl<<endl<<endl;

                                                while ((value1 + value2 + value3 + 
                                                        value4 + value5 + value6 + 
                                                        value7> 21) && 
                                                       (value1 == 11 || value2 == 11 
                                                        || value3 == 11 || value4 == 11 
                                                        || value5 == 11 || value6 ==11
                                                        || value7 == 11))
                                                {   
                                                    if(value1 == 11)
                                                        value1 = 1;
                                                    else if(value2 == 11)
                                                        value2 = 1;
                                                    else if (value3 == 11)
                                                        value3 = 1;
                                                    else if (value4 == 11)
                                                        value4 = 1;
                                                    else if (value5 == 11)
                                                        value5 = 1;
                                                    else if (value6 == 11)
                                                        value6 = 1;
                                                    else if (value7 == 11)
                                                        value7 = 1;
                                                }
                                                playTot[j] = value1 + value2 + value3 + 
                                                        value4 + value5 + value6 +
                                                        value7;
                                                cout<<setw(30)<<"PLAYER"<<setw(20);
                                                cout<<"hand total = ";
                                                cout<<playTot[j]<<endl;
                                                cout<<setw(30)<<"------"<<endl;
                                                cout<<setw(20)<<name1<<setw(25)<<name2;
                                                cout<<endl;
                                                cout<<setw(20)<<name3<<setw(25)<<name4;
                                                cout<<endl;
                                                cout<<setw(20)<<name5<<setw(25)<<name6;
                                                cout<<endl;
                                                cout<<setw(20)<<name7;
                                                cout<<endl;
                                                cout<<setw(60)<<"**Current Money = $";
                                                cout<<money[i][j];
                                                cout<<endl;
                                                cout<<"Hit enter when you are ready to";
                                                cout<<" progress."<<endl; 

                                                cin.ignore();  
                                                cin.get();
                                                cout<<endl<<endl;


                                                if (playTot[j] > 21)   
                                                {    
                                                    cout<<"BUST"<<endl;
                                                    cout<<" Hit enter ";
                                                    cout<<"when";
                                                    cout<<" you are ready to progress.";
                                                    cout<<endl;
                                                    choice = 'B';
                                                    cin.get();
                                                }

                                                else if (playTot[j] == 21)                 

                                                {                                        
                                                    cout<<"You have 21."<<endl;                              
                                                    cout<<" Hit enter ";
                                                    cout<<"when";
                                                    cout<<" you are ready to progress.";
                                                    cout<<endl;
                                                    choice = 'B';
                                                    cin.get();
                                                }        

                                                else
                                                {
                                                    cout<<"Which would you like to do?";
                                                    cout<<" Type ";
                                                    cout<<"the letter";
                                                    cout<<" that is";
                                                    cout<<endl;
                                                    cout<<"to the left of each choice ";
                                                    cout<<"to ";
                                                    cout<<"make ";
                                                    cout<<"that ";
                                                    cout<<"choice.";
                                                    cout<<endl;
                                                    cout<<"A. Hit"<<endl;
                                                    cout<<"B. Stand"<<endl;
                                                    cin>>choice;
                                                }
                                                 while (!(choice == 'A'||choice == 'B'))
                                                {
                                                    cout<<"This is an invalid choice. ";
                                                    cout<<"Please type the letter to";
                                                    cout<<endl;
                                                    cout<<"the left of the menu to ";
                                                    cout<<"make ";
                                                    cout<<"the corresponding";
                                                    cout<<endl;
                                                    cout<<"choice."<<endl;
                                                    cout<<" A. Hit"<<endl;
                                                    cout<<" B. Stand"<<endl;
                                                    cin>>choice;
                                                }
                                                switch(choice)
                                                {        
                                                    case 'A':
                                                        cout<<setw(30)<<"DEALER";
                                                        cout<<setw(20);
                                                        cout<<"hand total = ???";
                                                        cout<<endl;
                                                        cout<<setw(30)<<"------"<<endl; 
                                                        cout<<setw(20)<<name9;
                                                        cout<<setw(19);
                                                        cout<<"???";
                                                        cout<<endl;
                                                        cout<<endl<<endl<<endl;

                                                        while ((value1 + value2 + 
                                                                value3 + value4 + 
                                                                value5 + value6 + 
                                                                value7 + value8 > 21) && 
                                                               (value1 == 11 
                                                                || value2 == 11 
                                                                || value3 == 11 
                                                                || value4 == 11 
                                                                || value5 == 11 
                                                                || value6 == 11
                                                                || value7 == 11
                                                                || value8 == 11))
                                                        {   
                                                            if(value1 == 11)
                                                                value1 = 1;
                                                            else if(value2 == 11)
                                                                value2 = 1;
                                                            else if (value3 == 11)
                                                                value3 = 1;
                                                            else if (value4 == 11)
                                                                value4 = 1;
                                                            else if (value5 == 11)
                                                                value5 = 1;
                                                            else if (value6 == 11)
                                                                value6 = 1;
                                                            else if (value7 == 11)
                                                                value7 = 1;
                                                            else if (value8 == 11)
                                                                value8 = 1;
                                                        }
                                                        playTot[j] = value1 + value2 + 
                                                                value3 + value4 + 
                                                                value5 + value6 +
                                                                value7 + value8;
                                                        cout<<setw(30)<<"PLAYER";
                                                        cout<<setw(20);
                                                        cout<<"hand total = ";
                                                        cout<<playTot[j]<<endl;
                                                        cout<<setw(30)<<"------"<<endl;
                                                        cout<<setw(20)<<name1<<setw(25);
                                                        cout<<name2;
                                                        cout<<endl;
                                                        cout<<setw(20)<<name3<<setw(25);
                                                        cout<<name4;
                                                        cout<<endl;
                                                        cout<<setw(20)<<name5<<setw(25);
                                                        cout<<name6;
                                                        cout<<endl;
                                                        cout<<setw(20)<<name7;
                                                        cout<<name8;
                                                        cout<<endl;
                                                        cout<<setw(60)<<"**Current ";
                                                        cout<<"Money ";
                                                        cout<<"= $";
                                                        cout<<money[i][j];
                                                        cout<<endl;
                                                        cout<<"Hit enter when you are ";
                                                        cout<<"ready to";
                                                        cout<<" progress."<<endl; 
                                                        cin.ignore();  
                                                        cin.get();
                                                        cout<<endl<<endl;

                                                }

                                            }

                                        }

                                }

                        }
                    case 'B':

                        cout<<"The dealer will now flip their card. ";
                        cout<<"Hit enter to continue."<<endl;
                        if (playTot[j] < 21) //Only use cin.ignore() in this situation
                            cin.ignore(); //When choice 'B' was inputted by the 
                        cin.get();        //player (which is anytime the player's total
                                         //is less than 21)
                    break;

                    default: 
                    {
                        /*Deal the next card for the player by copying the display 
                        done for the first round and adding the next card; this card's
                        name and value get added to the screen output, and it gets 
                        considered in the ace calculation; because this is double,
                        the bet doubles, and the player can no longer draw cards after*/

                        money[i][j]-=playBet[j]; /*The money the player has decreases by the 
                                           bet amount again*/
                        playBet[j]*=2;     //The bet amount increases by 2

                        cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ???"<<endl;
                        cout<<setw(30)<<"------"<<endl; 
                        cout<<setw(20)<<name9<<setw(19)<<"???"<<endl;
                        cout<<endl<<endl<<endl;

                        //Ace calculation with 3 cards
                        while ((value1 + value2 + value3 > 21) && (value1 == 11 ||
                                value2 == 11|| value3 == 11))
                        {   
                            if(value1 == 11)
                                value1 = 1;
                            else if(value2 == 11)
                                value2 = 1;
                            else if (value3 == 11)
                                value3 = 1;
                        }
                        playTot[j] = value1 + value2 + value3;
                        cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = "<<playTot[j];
                        cout<<endl;
                        cout<<setw(30)<<"------"<<endl;
                        cout<<setw(20)<<name1<<setw(25)<<name2<<endl;
                        cout<<setw(20)<<name3<<endl;
                        cout<<setw(60)<<"Your bet is now $"<<playBet[j]<<endl;
                        cout<<setw(60)<<"**Current Money = $"<<money[i][j]<<endl;
                        cout<<"Hit enter when you are ready to progress."<<endl; 

                        cin.ignore();  
                        cin.get();
                        cout<<endl<<endl; 

                        //Use if/else if statements to determine the outcome

                        if (playTot[j] > 21)           //  If the player has more than
                        {                           //  21, they bust and the 
                                                    //  dealer draws cards
                            cout<<"BUST"<<endl;
                            cout<<"Hit enter when";
                            cout<<" you are ready to progress to the dealer"<<endl;
                            cout<<"flipping their card."<<endl;
                            cin.get();

                        }

                        else if (playTot[j] == 21)                //If the player has 21, 
                        {                                        //automatically stand 
                            cout<<"You have 21."<<endl;          //and dealer draws                     
                            cout<<"Hit enter when";
                            cout<<" you are ready to progress to the dealer"<<endl;
                            cout<<" flipping their card."<<endl;
                            cin.get();
                        }        

                        else
                               /*If the player has less than 21, the player automatically
                                stands and the dealer draws because this is a double*/
                        {
                            cout<<"You can no longer draw cards."<<endl;
                            cout<<"Hit enter when you are ready to progress"<<endl;
                            cout<<"to the dealer flipping their card."<<endl;
                            cin.get();
                        }
                    }
                    break;
                }

            //The dealer will now turn over their face down card

            //Use an if statement to make an ace equal 1 if the hand total is over 21
            if (value9 + value10 > 21)
            {        
                if(value9 == 11)
                    value9=1;
                else if(value10 == 11)
                    value10=1;
            }

            dealTot[j] = value9 + value10; //dealTot[j] is the total of the dealer's cards
            cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
            cout<<endl;
            cout<<setw(30)<<"------"<<endl;
            cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
            cout<<endl<<endl<<endl;
            cout<<setw(30)<<"PLAYER"<<endl;
            cout<<setw(30)<<"------"<<endl;
            cout<<"Current Bet: $"<<playBet[j]<<setw(30)<<"Current Money: $";
            cout<<money[i][j]<<endl;
            cout<<endl<<"Hand Total = "<<playTot[j]<<endl<<endl;
            cout<<"Hit enter when you are ready to progress."<<endl;
            cin.get();

            //Determine the next step in the game based on the dealer's total

            if (dealTot[j] >= 17) /*If the dealer's total is 17 or more, they must
                                         stand*/
            {
                cout<<"The dealer must stand. Hit enter when you are ready to"<<endl;
                cout<<"progress."<<endl;
                cin.get();
            }    
            else //If the dealer's total is 16 or less, they must draw again
            {
                cout<<"The dealer must hit. Hit enter when you are ready to"<<endl;
                cout<<"progress."<<endl;
                cin.get();


                /*Repeat this seven times, as it is essentially statistically impossible
                 to ever draw more than this*/

                /*Use a while loop  to make aces equal 1 so long as the hand is over 
                 21*/
                while ((value9 + value10 + value11 > 21) && (value9 == 11 ||
                        value10 == 11|| value11 == 11))
                {   
                    if(value9 == 11)
                        value9 = 1;
                    else if(value10 == 11)
                        value10 = 1;
                    else if (value11 == 11)
                        value11 = 1;
                }    

                dealTot[j] = value9 + value10 + value11; /*dealTot[j] is the total of the 
                                                        dealer's cards*/
                cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
                cout<<endl;
                cout<<setw(30)<<"------"<<endl;
                cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
                cout<<setw(20)<<name11<<endl;
                cout<<endl<<endl;
                cout<<setw(30)<<"PLAYER"<<endl;
                cout<<setw(30)<<"------"<<endl;
                cout<<"Current Bet: $"<<playBet[j]<<setw(30);
                cout<<"Current Money: $";
                cout<<money[i][j]<<endl;
                cout<<endl<<"Hand Total = "<<playTot[j]<<endl<<endl;
                cout<<"Hit enter when you are ready to progress."<<endl;
                cin.get();

                //Determine the next step in the game based on the dealer's total
                if (dealTot[j] > 21)         //If dealer has more than 21, they bust
                {                           

                    cout<<"DEALER'S BUST"<<endl;
                    cout<<"Hit enter when";
                    cout<<" you are ready to progress."<<endl;
                    cin.get();
                }
                else if (dealTot[j] >= 17) /*If the dealer's total is 17 or more, they must
                                             stand*/
                {
                    cout<<"The dealer must stand. Hit enter when you are ready to";
                    cout<<endl;
                    cout<<"progress."<<endl;
                    cin.get();
                }    
                else //If the dealer's total is 16 or less, they must draw again
                {
                    cout<<"The dealer must hit. Hit enter when you are ready to"<<endl;
                    cout<<"progress."<<endl;
                    cin.get();

                    /*Keep repeating the process until the dealer is no longer drawing
                     the next six draws will be exactly what was done before except 
                     taking 1 more card into consideration each time*/

                    while ((value9 + value10 + value11 + value12 > 21) && 
                            (value9 == 11 || value10 == 11|| value11 == 11
                            ||value12 == 11))
                    {   
                        if(value9 == 11)
                            value9 = 1;
                        else if(value10 == 11)
                            value10 = 1;
                        else if (value11 == 11)
                            value11 = 1;
                        else if (value12 == 11)
                            value12 = 1;
                    }    

                    dealTot[j] = value9 + value10 + value11 + value12;

                    cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
                    cout<<endl;
                    cout<<setw(30)<<"------"<<endl;
                    cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
                    cout<<setw(20)<<name11<<setw(25)<<name12<<endl;
                    cout<<endl;
                    cout<<setw(30)<<"PLAYER"<<endl;
                    cout<<setw(30)<<"------"<<endl;
                    cout<<"Current Bet: $"<<playBet[j]<<setw(30);
                    cout<<"Current Money: $";
                    cout<<money[i][j]<<endl;
                    cout<<endl<<"Hand Total = "<<playTot[j]<<endl<<endl;
                    cout<<"Hit enter when you are ready to progress."<<endl;
                    cin.get();

                    if (dealTot[j] > 21)        
                    {                           

                        cout<<"DEALER'S BUST"<<endl;
                        cout<<"Hit enter when";
                        cout<<" you are ready to progress."<<endl;
                        cin.get();
                    }
                    else if (dealTot[j] >= 17) 
                    {    
                        cout<<"The dealer must stand. Hit enter when you are ready to";
                        cout<<endl;
                        cout<<"progress."<<endl;
                        cin.get();
                    }    
                    else
                    {
                        cout<<"The dealer must hit. Hit enter when you are ready to";
                        cout<<endl;
                        cout<<"progress."<<endl;
                        cin.get();

                        //Next draw
                        while ((value9 + value10 + value11 + value12 + value13 > 21) 
                                &&(value9 == 11 || value10 == 11|| value11 == 11
                                   ||value12 == 11 || value13 == 11))
                            {   
                                if(value9 == 11)
                                    value9 = 1;
                                else if(value10 == 11)
                                    value10 = 1;
                                else if (value11 == 11)
                                    value11 = 1;
                                else if (value12 == 11)
                                    value12 = 1;
                                else if (value13 == 11)
                                    value13 = 1;
                            }    

                            dealTot[j] = value9 + value10 + value11 + value12 + value13;

                            cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ";
                            cout<<dealTot[j];
                            cout<<endl;
                            cout<<setw(30)<<"------"<<endl;
                            cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
                            cout<<setw(20)<<name11<<setw(25)<<name12<<endl;
                            cout<<setw(20)<<name13<<endl;
                            cout<<endl;
                            cout<<setw(30)<<"PLAYER"<<endl;
                            cout<<setw(30)<<"------"<<endl;
                            cout<<"Current Bet: $"<<playBet[j]<<setw(30);
                            cout<<"Current Money: $";
                            cout<<money[i][j]<<endl;
                            cout<<endl<<"Hand Total = "<<playTot[j]<<endl<<endl;
                            cout<<"Hit enter when you are ready to progress."<<endl;
                            cin.get();

                            if (dealTot[j] > 21)        
                            {                           

                                cout<<"DEALER'S BUST"<<endl;
                                cout<<"Hit enter when";
                                cout<<" you are ready to progress."<<endl;
                                cin.get();
                            }
                            else if (dealTot[j] >= 17) 
                            {    
                                cout<<"The dealer must stand. Hit enter when you are ";
                                cout<<"ready to";
                                cout<<endl;
                                cout<<"progress."<<endl;
                                cin.get();
                            }    
                            else
                            {
                                cout<<"The dealer must hit. Hit enter when you are ";
                                cout<<"ready to";
                                cout<<endl;
                                cout<<"progress."<<endl;
                                cin.get();

                                //Next draw
                                while ((value9 + value10 + value11 + value12 + value13
                                        + value14> 21) 
                                    &&(value9 == 11 || value10 == 11|| value11 == 11
                                       ||value12 == 11 || value13 == 11 || 
                                        value14 == 11))
                                {   
                                    if(value9 == 11)
                                        value9 = 1;
                                    else if(value10 == 11)
                                        value10 = 1;
                                    else if (value11 == 11)
                                        value11 = 1;
                                    else if (value12 == 11)
                                        value12 = 1;
                                    else if (value13 == 11)
                                        value13 = 1;
                                    else if (value14 == 11)
                                        value14 = 1;
                                }    

                                dealTot[j] = value9 + value10 + value11 + value12
                                          + value13 + value14;

                                cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ";
                                cout<<dealTot[j];
                                cout<<endl;
                                cout<<setw(30)<<"------"<<endl;
                                cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
                                cout<<setw(20)<<name11<<setw(25)<<name12<<endl;
                                cout<<setw(20)<<name13<<setw(25)<<name14<<endl;
                                cout<<endl;
                                cout<<setw(30)<<"PLAYER"<<endl;
                                cout<<setw(30)<<"------"<<endl;
                                cout<<"Current Bet: $"<<playBet[j]<<setw(30);
                                cout<<"Current Money: $";
                                cout<<money[i][j]<<endl;
                                cout<<endl<<"Hand Total = "<<playTot[j]<<endl<<endl;
                                cout<<"Hit enter when you are ready to progress."<<endl;
                                cin.get();

                                if (dealTot[j] > 21)        
                                {                           

                                    cout<<"DEALER'S BUST"<<endl;
                                    cout<<"Hit enter when";
                                    cout<<" you are ready to progress."<<endl;
                                    cin.get();
                                }
                                else if (dealTot[j] >= 17) 
                                {    
                                    cout<<"The dealer must stand. Hit enter when you ";
                                    cout<<"are ready to";
                                    cout<<endl;
                                    cout<<"progress."<<endl;
                                    cin.get();
                                }    
                                else
                                {
                                    cout<<"The dealer must hit. Hit enter when you are";
                                    cout<<" ready to";
                                    cout<<endl;
                                    cout<<"progress."<<endl;
                                    cin.get();

                                    //Next draw 
                                    while ((value9 + value10 + value11 + value12 
                                            + value13 + value14 + value15 > 21) 
                                        &&(value9 == 11 || value10 == 11
                                        || value11 == 11 || value12 == 11 
                                        || value13 == 11 || value14 == 11
                                        || value15 == 11))
                                        {   
                                            if(value9 == 11)
                                                value9 = 1;
                                            else if(value10 == 11)
                                                value10 = 1;
                                            else if (value11 == 11)
                                                value11 = 1;
                                            else if (value12 == 11)
                                                value12 = 1;
                                            else if (value13 == 11)
                                                value13 = 1;
                                            else if (value14 == 11)
                                                value14 = 1;
                                            else if (value15 == 11)
                                                value15 = 1;
                                        }    

                                        dealTot[j] = value9 + value10 + value11 + value12
                                                  + value13 + value14 + value15;

                                        cout<<setw(30)<<"DEALER"<<setw(20);
                                        cout<<"hand total = ";
                                        cout<<dealTot[j];
                                        cout<<endl;
                                        cout<<setw(30)<<"------"<<endl;
                                        cout<<setw(20)<<name9<<setw(25)<<name10<<endl;
                                        cout<<setw(20)<<name11<<setw(25)<<name12<<endl;
                                        cout<<setw(20)<<name13<<setw(25)<<name14<<endl;
                                        cout<<setw(20)<<name15<<endl;
                                        cout<<endl;
                                        cout<<setw(30)<<"PLAYER"<<endl;
                                        cout<<setw(30)<<"------"<<endl;
                                        cout<<"Current Bet: $"<<playBet[j]<<setw(30);
                                        cout<<"Current Money: $";
                                        cout<<money[i][j]<<endl;
                                        cout<<endl<<"Hand Total = "<<playTot[j]<<endl;
                                        cout<<endl;
                                        cout<<"Hit enter when you are ready to ";
                                        cout<<"progress."<<endl;
                                        cin.get();

                                        if (dealTot[j] > 21)        
                                        {                           

                                            cout<<"DEALER'S BUST"<<endl;
                                            cout<<"Hit enter when";
                                            cout<<" you are ready to progress."<<endl;
                                            cin.get();
                                        }
                                        else if (dealTot[j] >= 17) 
                                        {    
                                            cout<<"The dealer must stand. Hit enter ";
                                            cout<<"when you ";
                                            cout<<"are ready to";
                                            cout<<endl;
                                            cout<<"progress."<<endl;
                                            cin.get();
                                        }    
                                        else
                                        {
                                            cout<<"The dealer must hit. Hit enter when";
                                            cout<<" you are";
                                            cout<<" ready to";
                                            cout<<endl;
                                            cout<<"progress."<<endl;
                                            cin.get();

                                            //Last draw
                                            while ((value9 + value10 + value11 
                                                  + value12 + value13 + value14 
                                                  + value15 + value16 > 21) 
                                                  &&(value9 == 11 || value10 == 11
                                                  || value11 == 11 || value12 == 11 
                                                  || value13 == 11 || value14 == 11
                                                  || value15 == 11 || value16 == 11))
                                                {   
                                                    if(value9 == 11)
                                                        value9 = 1;
                                                    else if(value10 == 11)
                                                        value10 = 1;
                                                    else if (value11 == 11)
                                                        value11 = 1;
                                                    else if (value12 == 11)
                                                        value12 = 1;
                                                    else if (value13 == 11)
                                                        value13 = 1;
                                                    else if (value14 == 11)
                                                        value14 = 1;
                                                    else if (value15 == 11)
                                                        value15 = 1;
                                                    else if (value16 == 11)
                                                        value16 = 1;
                                                }    

                                                dealTot[j] = value9 + value10 + value11 
                                                          + value12 + value13 + value14
                                                          + value15 + value16;

                                                cout<<setw(30)<<"DEALER"<<setw(20);
                                                cout<<"hand total = ";
                                                cout<<dealTot[j];
                                                cout<<endl;
                                                cout<<setw(30)<<"------"<<endl;
                                                cout<<setw(20)<<name9<<setw(25);
                                                cout<<name10<<endl;
                                                cout<<setw(20)<<name11<<setw(25);
                                                cout<<name12<<endl;
                                                cout<<setw(20)<<name13<<setw(25);
                                                cout<<name14<<endl;
                                                cout<<setw(20)<<name15<<setw(25);
                                                cout<<name16<<endl;
                                                cout<<endl;
                                                cout<<setw(30)<<"PLAYER"<<endl;
                                                cout<<setw(30)<<"------"<<endl;
                                                cout<<"Current Bet: $"<<playBet[j]<<setw(30);
                                                cout<<"Current Money: $";
                                                cout<<money[i][j]<<endl;
                                                cout<<endl<<"Hand Total = "<<playTot[j];
                                                cout<<endl<<endl;
                                                cout<<"Hit enter when you are ready to";
                                                cout<<" progress."<<endl;
                                                cin.get();
                                        }
                                }
                            }
                    }        
                }
            }

            //Give the payout to the player based on how the game went

            /*All of the returns are twice the bet in every situation the player wins;
             this is because they get back their original bet money and earn an 
             additional amount equal to what they bet*/
            if (dealTot[j] > 21 && playTot[j] <= 21) //If the dealer is over 21 (busts) and 
            {                                  // the player is not, player wins
                returns = playBet[j]*2;
                money[i][j] += returns;
                cout<<endl<<endl;
                cout<<"You won because the dealer busted!"<<endl<<endl;
                cout<<"You won $"<<returns/2<<". You now have $"<<money[i][j];
            }

            else if (playTot[j] > dealTot[j] && ((dealTot[j] < 21) && (playTot[j] <= 21)))
            /*If player's total is higher than dealer's and neither have busted, player
             wins*/
            {   
                returns = playBet[j]*2;
                money[i][j] += returns;
                cout<<endl<<endl;
                cout<<"You won because you had a higher amount!"<<endl<<endl;
                cout<<"You won $"<<returns/2<<". You now have $"<<money[i][j];
            }    

            else if (playTot[j] == dealTot[j] && playTot[j]<=21)
                                                        //If the player total is equal
                                                        //to the dealer total and both
                                                        //are under 21, it is a push
            {
                returns = playBet[j];
                money[i][j] += returns;
                cout<<endl<<endl;
                cout<<"PUSH. You and the dealer had the same amount."<<endl<<endl;
                cout<<"You won $0. You now have $"<<money[i][j];
            }    

            else if (playTot[j] < dealTot[j] && ((dealTot[j] <= 21) &&
                    (playTot[j] < 21)))
            /* If player's total is less than dealer's and neither have busted, player
              loses*/   
            {    
                cout<<endl<<endl;
                cout<<"You lost because the dealer had a higher amount."<<endl<<endl;
                cout<<"You lost $"<<playBet[j]<<". You now have $"<<money[i][j];  
            }
            else if (playTot[j]>21) //If player is ever busted, they lose
            {    
                cout<<endl<<endl;
                cout<<"You lost because you busted."<<endl<<endl;
                cout<<"You lost $"<<playBet[j]<<". You now have $"<<money[i][j];
            }

            } //Closes the { started in line 959


            saveMny<<money[i][j]<<endl; /*This writes the money amount at the end of the
                                          game  to the file;  all these values will be 
                                          used in  calculations at the end of the 
                                          program*/


            cout<<endl<<endl;

            /*Use an if/else statement to explain to the player what to do next based on
             what game  player is on*/
            if (j < gameCnt-1) //If there are more games to be played
            {
                cout<<"Hit enter to continue to game "<<j + 2<<" for player "<<i+1;
                cout<<endl;
                cin.get();
            }  

            else //If there are not more games to be played
            {
                cout<<"You finished your last game. Assuming you do not get"<<endl;
                cout<<"change from the dealer, you walk away with $";
                cout<<static_cast<unsigned int>(money[i][j])<<endl;

                /*Call to a function to display what percentage of the initial value
                 had at the beginning of game 1 the final money is */
                cout<<"This is "<<cnvPerc(money[i][j]);
                cout<<"% of what you started with in ";
                cout<<"game 1."<<endl<<endl;


                /*Fill the rest of the money with -1; this is so the function that 
                displays arrays knows when to not display games*/

                for (short b = gameCnt; b < MONMAX; b++)
                    money[i][b] = -1; 


                /*Call a function that uses bubble sorts to sort the player and dealer
                 end game hand totals; pass in the two arrays that hold these 
                 values and the size as playCnt*/
                sortAry (playTot, dealTot, gameCnt);
                cout<<endl;

                /*Call a function that displays the player and dealer end game hand
                 totals; pass in the the two arrays that hold these values and the
                 size as playCnt*/

                showAry (playTot, dealTot, gameCnt);
                cout<<endl;

                /*Use a binary search to search the player's end-game hand values for
                 21 to display if the player ever got 21 or not*/

                //Use the classic binary search method to search for the value 21

                int first = 0;       //First array element
                int last = playCnt;  //Last array element 
                int middle; //       //Midpoint of search
                bool found = false;  /*If 21 is found, this will be initialized as true
                                      and causae the while loop to stop searching*/

                while (!found && first<=last)
                {
                    middle = (first + last)/2;   //Calculate the midpoint

                    if (playTot[middle] == 21)  
                        found = true;             /*If 21 is found at the midpoint,
                                                  set found to true*/

                    else if (playTot[middle] > 21)
                        last = middle - 1;         /*If the value at the midpoint is 
                                                    higher than 21, the last value 
                                                    in the range that can hold 21
                                                    is set to the value that comes 
                                                    before that midpoint*/

                    else
                        first = middle + 1;        /*If the value at the midpoint is 
                                                    lower than 21, the first value in
                                                    the range that can hold 21 is set
                                                    to the value that comes after the
                                                    midpoint*/   
                }

                //Use an if/else statement to display if the player got 21 or not
                if (found)
                {   
                    cout<<"The player managed to get 21 in at least one of their";
                    cout<<" games."<<endl<<endl;
                }    
                else
                    cout<<"This player never got 21 in any of their games."<<endl<<endl;

                /*Ask the user if they want to see what the player bet during a certain
                 game; use the at function to do this*/

                short whatBet; /*This is where the user will input the game that they
                                wanna see the player's bet for*/

                cout<<"Enter the number of a game for which you wish to revisit"<<endl;
                cout<<"player "<<i + 1<<"'s bet amount. Enter -1 when you"<<endl;
                cout<<"wish to move on."<<endl;
                cin>>whatBet;

               //While the inputted number is not -1
               while (whatBet != -1)
               {
                   while ((whatBet < 1 || whatBet > gameCnt) && whatBet != -1)
                   {
                       cout<<"This is an invalid input. Enter the number of a"<<endl;
                       cout<<"game for which you wish to revisit player "<<i + 1<<"'s";
                       cout<<" bet amount."<<endl;
                       cout<<"Enter -1 when you wish to move on."<<endl;
                       cin>>whatBet;
                   } 
                   
                   if(whatBet == -1)
                   {
                       break;   
                   }
                   
                   cout<<"The bet for game "<<whatBet<<" is $";
                   cout<<playBet.at(whatBet - 1)<<endl;

                   cout<<"Enter another game for which you wish to revisit the"<<endl;
                   cout<<"bet amount, or type -1 to no longer enter games."<<endl;        
                   cin>>whatBet;
               }    

                /*Use an if/else to prompt the user what to do next depending on if 
                 there are more players to play*/
                if (i < playCnt - 1)
                {
                    cout<<"Hit enter to continue to player "<<i + 2<<"'s turn."<<endl;
                    cin.ignore();
                    cin.get();
                }    
                else
                {    
                    cout<<endl;
                    cout<<"All the players have played their games. Hit enter to"<<endl;
                    cout<<"continue."<<endl;
                    cin.ignore();
                    cin.get();
                }

            }    
        } //Closes the { started in line 179  
    } //Closes the { started in line 164  
 
     //Close the file holding the end-game money amounts
     
     saveMny.close();
     
    /*Read the money amounts that were had at the end of each game in from 
     a file and find average and standard deviation*/
     
    ifstream amounts; /*This is what allows money amounts to start being read
                        from the file*/
    
    amounts.open("Moneyamounts.txt"); //This re-opens the file
     
    /*Use a for loop to read in amounts and add them up; a accumulator variable
     must be declared*/
     
    float monyTot = 0.0f; //This will serve as the accumulator
    
    float readMon; /*readMon is the variable that will be used to read in all
                    the money amounts for all the games of every player*/
     
    for(short int k = 1; k <= gameCnt*playCnt; k++) /*Iterate for however many
                                                      games there are*/
    {     
        amounts >> readMon; //Read in the money value for a game
        monyTot += readMon; //continuously add the money amounts
    }
    
    //Find the average of the end game amounts
    
    //Declare average variable
    float avg; 
    
    /*Calculate average, which is the total amounts had at the end of each game
     all added together divided by the number of games*/
    avg = monyTot/(gameCnt*playCnt);
    
    /*Subtract the mean from each amount at the end of the game, square the 
     differences, and add up all the squared differences using a for loop; 
     to re-read the values in from the file, it must be closed and re-opened*/
    
    amounts.close(); //Close file
    
    amounts.open("Moneyamounts.txt"); //Open the file again
    
    float meanDif; /*Declare a variable to hold the difference between each 
                    data point and the average*/
    
    float mDifTot = 0.0f; /*Declare a variable that will serve an an 
                           accumulator of the squared mean differences*/
            
    //For loop to perform calculations
    for(short int x = 1; x <= gameCnt*playCnt; x++) /*Iterate for however many 
                                                     games there are*/
    {
        amounts >> readMon; //Read in money value for a game
        
        meanDif = readMon - avg; //Difference between data point and average
        
        mDifTot += pow(meanDif, 2); /*Square the mean difference using a cmath 
                                     function and add this to the acccumulator*/
    }  
    
    /*Divide mDifTot by the number of money amounts and use cmath function to
     take the square root; this is the standard deviation*/
    float stdDev; //Declare standard deviation variable
    
    stdDev = sqrt(mDifTot/(gameCnt*playCnt));
    
    /*Display the amount of money each player had at the end of each of their
     games by calling to function showAry*/
    
    showAry (money, playCnt);
    
    //Output the highest and lowest end game money amounts for each player 
    
    //Use a for loop to go through each player
    for (short i = 0; i < playCnt; i++)
    {
        /*Set the highest and lowest equal to the first end game money amount
         so the the for loop that re-determines highest and lowest values 
         has a value to compare to*/
        float highest = money[i][0];
        float lowest = money [i][0];
        for (short j = 1; j < gameCnt; j++)
        {
            if (money[i][j] > highest)
                highest = money[i][j]; /*If the money amount of a certain game 
                                        is higher than the previous highest, it
                                        becomes the new highest*/
            
            if (money[i][j] < lowest) 
                lowest = money[i][j];       /*If the money amount
                                             of a certain game 
                                             is lower than the 
                                             previous lowest, it
                                             becomes the new 
                                             lowest*/
              
        } 
        
            /*Output the highest and lowest end game money value for each
            player*/

            cout<<"The lowest money amount for player "<<i + 1<<" is $";
            cout<<lowest<<"."<<endl;
            cout<<"The highest money amount for player "<<i + 1<<" is $";
            cout<<highest<<"."<<endl;
    }    
    
    /*Prompt the player to input if they want their average and standard
     deviation of their money amounts at the end of each game to be displayed*/
    
    cout<<endl; 
    cout<<"Would you like the average money amount had by the players at the";
    cout<<" end of"<<endl;
    cout<<"each game and the standard deviation of these end game money"<<endl;
    cout<<"amounts to be displayed? Type 'Y' and hit enter if you"<<endl;
    cout<<"would, or any other key following by enter if you would not."<<endl;
    
    char choice; //Re-declare choice as a variable for this scope
    cin>>choice;
    
    /*Declare a variable called "display," and set it equal to true if the 
     choice is 'Y'; set it equal to false if not*/
    bool display;
    
    if(choice == 'Y')
        display = true;
    else
        display = false;
    
    /*Use an another if statement with display as the argument to display the 
     statistics or not*/
    
    if(display)
    {
        cout<<"The average money amount had at the end of each game = $";
        cout<<avg;
        cout<<endl;
        cout<<"The standard deviation of the amounts had at the end of ";
        cout<<"each game = $"<<stdDev;
    }
    
    cout<<endl<<endl<<endl;
    cout<<"THANKS FOR PLAYING BLACKJACK!!"<<endl;
    
    //Close the file 
    amounts.close();
    

    
    //Exit
    return 0;
}

void nameCrd (unsigned short &card, string &name, unsigned short &crdVal)
{
    /*Redeclare the same variables that were used to assign values to each
     card so they work within the scope of the function*/ 
    
    string face, suit; /*face is where a string that gives the name of the 
                    face of the card will be inputted and suit is where a
                    string that gives the name of the suit of the card
                    will be inputted*/
    
    unsigned short value; /*value is the general value of a particular card
                           and will be used to input the correct value into each
                           of the 16 cards*/
    
    //Initialize variables
    
     card = (rand()%52)+1; //This assigns card a number from 1 to 52
     
        switch (card%13)
        {        
            case 1: 
                face = "Ace of ";
                value = 11;
            break;
        
            case 2:
                face = "2 of ";
                value = 2;
            break;

            case 3:
                face = "3 of ";
                value = 3;
            break;

            case 4:
                face = "4 of ";
                value = 4;
            break;

            case 5:
                face = "5 of ";
                value = 5;
            break;

            case 6:
                face = "6 of ";
                value = 6;
            break;

            case 7:
                face = "7 of ";
                value = 7;
            break;

            case 8:
                face = "8 of ";
                value = 8;
            break;

            case 9:
                face = "9 of ";
                value = 9;
            break;

            case 10:
                face = "10 of ";
                value = 10;
            break;

            case 11:
                face = "Jack of ";
                value = 10;
            break;

            case 12:
                face = "Queen of ";
                value = 10;
            break;

            default:
                face = "King of ";
                value = 10;
        }  

    if (card<=13)
        suit = "Spades";
    else if (card>13 && card<=26)
        suit = "Diamonds";
    else if (card>26 && card<=39)
        suit = "Hearts";
    else
        suit = "Clubs";

    name = face + suit;
    crdVal = value;
}  

/*This function will display the array that holds the end game money amounts 
 for all of the players*/
void showAry (float ary[][MONMAX], short players)
{
    for (short i = 0; i < players; i++)
    {
        cout<<"Player "<< i + 1<<":";
                for(short j = 0; j < MONMAX; j++)
                { 
                    
                    /*Use an if statement to not display if there is no game*/
                    if (ary[i][j] > -1)
                    {    
                        cout<<endl;
                        cout<<"Money at end of Game"<<j + 1<<"- ";
                        cout<<"$"<<ary[i][j];
                    }    
                } 
        cout<<endl<<endl;
    }    
        
}

/*This function will get passed the arrays that hold the player hand totals and
 dealer hand totals at the end of each game and sort them in ascending order
 using bubble sorts*/
void sortAry(unsigned short player[], unsigned short dealer[], short size)
{
    
    //Use the classic bubble sort method for player totals
    
    bool swap;
    int temp1, temp2;
    
    do
    {
        swap = false;
        for (int count = 0; count < size - 1; count++)
        {
            if (player[count] > player [count+1])
            {
                temp1 = player [count];
                player[count] = player[count + 1];
                player[count + 1] = temp1;
                swap = true;
            }    
        }     
    }while (swap);
    
    //Use the classic bubble sort method for dealer totals
    do
    {
        swap = false;
        for (int count = 0; count < size -1; count++)
        {
            if (dealer[count] > dealer[count+1])
            {
                temp2 = dealer[count];
                dealer[count] = dealer[count + 1];
                dealer[count + 1] = temp2;
                swap = true;
            }    
        }     
    }while (swap);
}

/*This function will get passed the arrays that hold the player and dealer
 end game hand totals and display them*/
void showAry (unsigned short player[], unsigned short dealer[], short size)
{
    //Output the titles
    cout<<"PLAYER AND DEALER END-GAME HAND TOTALS IN ASCENDING ORDER"<<endl;
    cout<<endl;
    cout<<"Player                      Dealer"<<endl;
    cout<<"------                      ------"<<endl;
    
    //Use a for loop to output the values
    for (short i = 0; i < size; i++)
    {
        cout<<setw(4)<<player[i]<<"                        "<<setw(4);
        cout<<dealer[i];
        cout<<endl;
    }    
}

/*This function uses a default argument, perc, to calculate what percentage the
 player's final money amount is of what they had at the beginning of game 1;
 it then returns this value as an integer*/
int cnvPerc (float fnlMony, int perc)
{
    float percent; /*percent is declared as the variable into which the
                    percentage of what the final value is of the initial money
                    value in game 1 will be inputted*/
    
    percent = (fnlMony/500)* perc; /*percentage of what the final value of the 
                                    initial value is is the final value 
                                    divided by 500 times 100*/
    
    static_cast<unsigned int>(percent); /*turn percent from a float into an 
                                         integer*/
    
    return percent;
}