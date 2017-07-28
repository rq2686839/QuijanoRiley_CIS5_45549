/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 25, 2017, 5:55PM
 * Purpose:  Blackjack (Without Splits)
 */

//System Libraries Here
#include <iostream>     //Input - Output Manipulation Library
#include <cstdlib>      //C Standard Library for rand() Function
#include <ctime>        //C Time Library to Seed the Random Number Generator
#include <string>       //Include String Library for String Functions
#include <iomanip>      //Input - Output Manipulatin Library to Format Output
#include <fstream>      //Stream for Writing to and Reading from Files
#include <cmath>        //C Math Library for More Math Functions
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

const float CNVPERC = 100.0f;

const int MONMAX = 5; 
const int PLAYMAX = 4;

//Function Prototypes Here

void nameCrd (unsigned short &, string &, unsigned short &);
void showAry (float [][MONMAX], short);
void sortAry (unsigned short [], unsigned short[], short);
void showAry (unsigned short [], unsigned short[], short);
int diff (float);

//Program Execution Begins Here
int main(int argc, char** argv) {
    
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    
    /*Declare a variable for each card in the game; in one game where it is 
     just 1 player against the dealer, the player can have 24 cards total (this
     can only happen if 3 splits occur and each of 4 hands gets the lowest 
     possible); it is almost statistically impossible for the dealer to have 
     more than 8 cards in their hand; given these facts the, 24 cards are 
     declared for the player ad 8 are declared for the dealer; the 
     player only draws from 1 through 24 and the dealer draws from 25 through
     32 in this  program, but that does not affect the random nature of the
     game*/
    unsigned short card1, card2, card3, card4, card5, card6, card7, card8, 
                   card9, card10, card11, card12, card13, card14, card15, 
                   card16, card17, card18, card19, card20, card21, card22,
                   card23, card24, card25, card26, card27, card28, card29,
                   card30, card31, card32;
    //********************************************************************
    /*SPLITS HAVE NOT YET BEEN IMPLEMENTED WHICH IS WHY CARDS 9-23 ARE NOT
     USED IN THIS PROGRAM*/
    //********************************************************************
    
    unsigned short value; /*value is the general value of a particular card
                           and will be used to input the correct value into each
                           of the 32 cards*/
    
    //Declare a variable for the values each of the 32 cards holds
    unsigned short value1, value2, value3, value4, value5, value6, value7,
                   value8, value9, value10, value11, value12, value13, value14,
                   value15, value16, value17, value18, value19, value20,
                   value21, value22, value23, value24, value25, value26, 
                   value27, value28, value29, value30, value31, value32;
    
    string face, suit; /*face is where a string that gives the name of the 
                        face of the card will be inputted and suit is where a
                        string that gives the name of the suit of the card
                        will be inputted*/
    
    string face1, face2, face3, face4; /*The faces of the first 4 cards must 
                                        be declared specifically because 
                                        these are the only
                                        cards that splits can occur from, so 
                                        their values must be saved throughout
                                        the program*/
    
    /*Declare a variable that contains the face and suit names of the card for
     each of the 32 cards*/
    string name1, name2, name3, name4, name5, name6, name7, name8, 
           name9, name10, name11, name12, name13, name14, name15, 
           name16, name17, name18, name19, name20, name21, name22,
           name23, name24, name25, name26, name27, name28, name29,
           name30, name31, name32;
    
    float bet, insBet, splBet1, splBet2, //bet is the amount of the initial bet,
                     splBet3, splBet4; //insBet is the amount of the insurance
                                       //bet (allowed if dealer's face up card
                                       //is an ace), splBet1 is the bet for
                                       //one hand if a split occurs, splBet2 is 
                                       //the bet for the second hand, splBet3
                                       //is the bet for the third hand if there 
                                       //were 2 splits, and splBet4 is the bet
                                       //for the fourth hand if there were 3 
                                       //splits
    
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
                    games*/
    
    //Open a file to write to
    ofstream saveMny; /*This is what allows the money amounts at the end of 
                       each game to be saved to a file*/
    
    saveMny.open("Moneyamounts.txt"); //This opens the file 
     
    
     //Prompt the user for input 
     
     cout<<"Welcome to Blackjack!!"<<endl<<endl;
     
     /*Prompt the user to input the amount of players; it is important to note
      that this simply will be each individual "1v1'ing" the dealer each game;
      to clarify, player1 will play out all of their games against the dealer,
      followed by player2 playing out all of their games against the dealer, 
      etc.*/
     
     cout<<"How many players (max of 4) will be playing against the dealer? ";
     cout<<"Each"<<endl;
     cout<<"player will play out the number of games they wish to play,"<<endl;
     cout<<"then the next player will play out the number of games they"<<endl;
     cout<<"wish to play."<<endl;
     cin>>playCnt;
     
     //Continuously prompt the user to input so long as their input is invalid
     while (playCnt<0 ||playCnt>4)
     {
         cout<<"This is an invalid input. Input the amount of games in a"<<endl;
         cout<<"row you would like to play, making sure this value is between ";
         cout<<"1 and 4."<<endl;
         cin>>playCnt;
     }
     
     /*Use a for loop to keep playing out game sets for the number of players
      specified; THERE WILL BE NO INDENTATION FROM THE EHADER OF THE LOOP TO
      ITS BODY, as this would cause some portions of the program to be so
      squished to the right that it would be essentially unreadable*/
     
     for (short int i = 0; i < playCnt; i++)
     {
         
         
     //Prompt the user to input how many games the play would like to play 
     cout<<"How many games in a row would player "<<i+1<<" like to play? ";
     cout<<"Input this"<<endl;
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
        
    /*Find the name and value of card1(with random numbers) using a switch;
     this is within the for loop to simulate shuffling at the start of each
     new game*/
             
    card1 = (rand()%52)+1; //This assigns card1 a number from 1 to 52
            
    switch (card1%13)
    {
        case 1: //Value of Ace can be changed to 1 later in the program
            face1 = "Ace of ";
            value = 11;
        break;
        
        case 2:
            face1 = "2 of ";
            value = 2;
        break;
        
        case 3:
            face1 = "3 of ";
            value = 3;
        break;
        
        case 4:
            face1 = "4 of ";
            value = 4;
        break;
        
        case 5:
            face1 = "5 of ";
            value = 5;
        break;
        
        case 6:
            face1 = "6 of ";
            value = 6;
        break;
        
        case 7:
            face1 = "7 of ";
            value = 7;
        break;
        
        case 8:
            face1 = "8 of ";
            value = 8;
        break;
        
        case 9:
            face1 = "9 of ";
            value = 9;
        break;
        
        case 10:
            face1 = "10 of ";
            value = 10;
        break;
        
        case 11:
            face1 = "Jack of ";
            value = 10;
        break;
        
        case 12:
            face1 = "Queen of ";
            value = 10;
        break;
        
        default:
            face1 = "King of ";
            value = 10;
    }
    
    //Find the suit of card1 using if/else if statements
    if (card1<=13)
        suit = "Spades";
    else if (card1>13 && card1<=26)
        suit = "Diamonds";
    else if (card1>26 && card1<=39)
        suit = "Hearts";
    else
        suit = "Clubs";
    
    //Input the name of card1 (name1) and value of card1 (value1)
    name1 = face1 + suit;
    value1 = value;
    
    /*Repeat the same exact process for cards2 through 32, except put all 
     calculations in a do {} statement; follow this up with a while that forces
     the calculations to repeat again if the name of  a card is the same as 
     any of the previous ones; this is because in one deck of cards, no card is 
     the same; do this for cards5 through 32 using a function that does some of 
     it, but not for the first 4 cards because these have their own variables
     for face*/
    
    do{
        card2 = (rand()%52)+1; 

        switch (card2%13)
        {
            case 1: 
                face2 = "Ace of ";
                value = 11;
            break;
        
            case 2:
                face2 = "2 of ";
                value = 2;
            break;

            case 3:
                face2 = "3 of ";
                value = 3;
            break;

            case 4:
                face2 = "4 of ";
                value = 4;
            break;

            case 5:
                face2 = "5 of ";
                value = 5;
            break;

            case 6:
                face2 = "6 of ";
                value = 6;
            break;

            case 7:
                face2 = "7 of ";
                value = 7;
            break;

            case 8:
                face2 = "8 of ";
                value = 8;
            break;

            case 9:
                face2 = "9 of ";
                value = 9;
            break;

            case 10:
                face2 = "10 of ";
                value = 10;
            break;

            case 11:
                face2 = "Jack of ";
                value = 10;
            break;

            case 12:
                face2 = "Queen of ";
                value = 10;
            break;

            default:
                face2 = "King of ";
                value = 10;
        }

        if (card2<=13)
            suit = "Spades";
        else if (card2>13 && card2<=26)
            suit = "Diamonds";
        else if (card2>26 && card2<=39)
            suit = "Hearts";
        else
            suit = "Clubs";

        name2 = face2 + suit;
        value2 = value;
    } 
    while (name2==name1);
    
    //card3
    do{
        card3 = (rand()%52)+1; 

        switch (card3%13)
        {
            case 1: 
                face3 = "Ace of ";
                value = 11;
            break;
        
            case 2:
                face3 = "2 of ";
                value = 2;
            break;

            case 3:
                face3 = "3 of ";
                value = 3;
            break;

            case 4:
                face3 = "4 of ";
                value = 4;
            break;

            case 5:
                face3 = "5 of ";
                value = 5;
            break;

            case 6:
                face3 = "6 of ";
                value = 6;
            break;

            case 7:
                face3 = "7 of ";
                value = 7;
            break;

            case 8:
                face3 = "8 of ";
                value = 8;
            break;

            case 9:
                face3 = "9 of ";
                value = 9;
            break;

            case 10:
                face3 = "10 of ";
                value = 10;
            break;

            case 11:
                face3 = "Jack of ";
                value = 10;
            break;

            case 12:
                face3 = "Queen of ";
                value = 10;
            break;

            default:
                face3 = "King of ";
                value = 10;
        }

        if (card3<=13)
            suit = "Spades";
        else if (card3>13 && card3<=26)
            suit = "Diamonds";
        else if (card3>26 && card3<=39)
            suit = "Hearts";
        else
            suit = "Clubs";

        name3 = face3 + suit;
        value3 = value;
    } 
    while (name3==name2||name3==name1);

    //card4
    do{
        card4 = (rand()%52)+1; 

        switch (card4%13)
        {
            case 1: 
                face4 = "Ace of ";
                value = 11;
            break;
        
            case 2:
                face4 = "2 of ";
                value = 2;
            break;

            case 3:
                face4 = "3 of ";
                value = 3;
            break;

            case 4:
                face4 = "4 of ";
                value = 4;
            break;

            case 5:
                face4 = "5 of ";
                value = 5;
            break;

            case 6:
                face4 = "6 of ";
                value = 6;
            break;

            case 7:
                face4 = "7 of ";
                value = 7;
            break;

            case 8:
                face4 = "8 of ";
                value = 8;
            break;

            case 9:
                face4 = "9 of ";
                value = 9;
            break;

            case 10:
                face4 = "10 of ";
                value = 10;
            break;

            case 11:
                face4 = "Jack of ";
                value = 10;
            break;

            case 12:
                face4 = "Queen of ";
                value = 10;
            break;

            default:
                face4 = "King of ";
                value = 10;
        }

        if (card4<=13)
            suit = "Spades";
        else if (card4>13 && card4<=26)
            suit = "Diamonds";
        else if (card4>26 && card4<=39)
            suit = "Hearts";
        else
            suit = "Clubs";

        name4 = face4 + suit;
        value4 = value;
    }  
    while (name4==name3||name4==name2||name4==name1);
   
    /*Find the names and values of the remaining cards using the same process
     except put the card, name of that card, and value into a function that
     initializes them*/
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
    
    //card17
    do{
            nameCrd (card17, name17, value17);
    } 
    while (name17==name3||name17==name2||name17==name1||name17==name4
            ||name17==name5||name17==name6||name17==name7||name17==name8
            ||name17==name9||name17==name10||name17==name11||name17==name12
            ||name17==name13||name17==name14||name17==name15||name17==name16);

    //card18
    do{
            nameCrd (card18, name18, value18);
    } 
    while (name18==name3||name18==name2||name18==name1||name18==name4
            ||name18==name5||name18==name6||name18==name7||name18==name8
            ||name18==name9||name18==name10||name18==name11||name18==name12
            ||name18==name13||name18==name14||name18==name15||name18==name16
            ||name18==name17);

    //card19
    do{
            nameCrd (card19, name19, value19);
    } 
    while (name19==name3||name19==name2||name19==name1||name19==name4
            ||name19==name5||name19==name6||name19==name7||name19==name8
            ||name19==name9||name19==name10||name19==name11||name19==name12
            ||name19==name13||name19==name14||name19==name15||name19==name16
            ||name19==name17||name19==name18);    

    //card20
    do{
            nameCrd (card20, name20, value20);
    } 
    while (name20==name3||name20==name2||name20==name1||name20==name4
            ||name20==name5||name20==name6||name20==name7||name20==name8
            ||name20==name9||name20==name10||name20==name11||name20==name12
            ||name20==name13||name20==name14||name20==name15||name20==name16
            ||name20==name17||name20==name18||name20==name19); 
   
    //card21
    do{
            nameCrd (card21, name21, value21);
    } 
    while (name21==name3||name21==name2||name21==name1||name21==name4
            ||name21==name5||name21==name6||name21==name7||name21==name8
            ||name21==name9||name21==name10||name21==name11||name21==name12
            ||name21==name13||name21==name14||name21==name15||name21==name16
            ||name21==name17||name21==name18||name21==name19||name21==name20);    

    //card22
    do{
             nameCrd (card22, name22, value22);
    } 
    while (name22==name3||name22==name2||name22==name1||name22==name4
            ||name22==name5||name22==name6||name22==name7||name22==name8
            ||name22==name9||name22==name10||name22==name11||name22==name12
            ||name22==name13||name22==name14||name22==name15||name22==name16
            ||name22==name17||name22==name18||name22==name19||name22==name20
            ||name22==name21);
    
    //card23
    do{
            nameCrd (card23, name23, value23);
    } 
    while (name23==name3||name23==name2||name23==name1||name23==name4
            ||name23==name5||name23==name6||name23==name7||name23==name8
            ||name23==name9||name23==name10||name23==name11||name23==name12
            ||name23==name13||name23==name14||name23==name15||name23==name16
            ||name23==name17||name23==name18||name23==name19||name23==name20
            ||name23==name21||name23==name22); 
    
    //card24
    do{
            nameCrd (card24, name24, value24);
    } 
    while (name24==name3||name24==name2||name24==name1||name24==name4
            ||name24==name5||name24==name6||name24==name7||name24==name8
            ||name24==name9||name24==name10||name24==name11||name24==name12
            ||name24==name13||name24==name14||name24==name15||name24==name16
            ||name24==name17||name24==name18||name24==name19||name24==name20
            ||name24==name21||name24==name22||name24==name23); 
    
    //card25
    do{
            nameCrd (card25, name25, value25);
    } 
    while (name25==name3||name25==name2||name25==name1||name25==name4
            ||name25==name5||name25==name6||name25==name7||name25==name8
            ||name25==name9||name25==name10||name25==name11||name25==name12
            ||name25==name13||name25==name14||name25==name15||name25==name16
            ||name25==name17||name25==name18||name25==name19||name25==name20
            ||name25==name21||name25==name22||name25==name23||name25==name24);      
    
    //card26
    do{
           nameCrd (card26, name26, value26);
    } 
    while (name26==name3||name26==name2||name26==name1||name26==name4
            ||name26==name5||name26==name6||name26==name7||name26==name8
            ||name26==name9||name26==name10||name26==name11||name26==name12
            ||name26==name13||name26==name14||name26==name15||name26==name16
            ||name26==name17||name26==name18||name26==name19||name26==name20
            ||name26==name21||name26==name22||name26==name23||name26==name24
            ||name26==name25);
    
    //card27
    do{
             nameCrd (card27, name27, value27);
    } 
    while (name27==name3||name27==name2||name27==name1||name27==name4
            ||name27==name5||name27==name6||name27==name7||name27==name8
            ||name27==name9||name27==name10||name27==name11||name27==name12
            ||name27==name13||name27==name14||name27==name15||name27==name16
            ||name27==name17||name27==name18||name27==name19||name27==name20
            ||name27==name21||name27==name22||name27==name23||name27==name24
            ||name27==name25||name27==name26);
   
    //card28
    do{
             nameCrd (card28, name28, value28);
    } 
    while (name28==name3||name28==name2||name28==name1||name28==name4
            ||name28==name5||name28==name6||name28==name7||name28==name8
            ||name28==name9||name28==name10||name28==name11||name28==name12
            ||name28==name13||name28==name14||name28==name15||name28==name16
            ||name28==name17||name28==name18||name28==name19||name28==name20
            ||name28==name21||name28==name22||name28==name23||name28==name24
            ||name28==name25||name28==name26||name28==name27); 
    
    //card29
    do{
            nameCrd (card29, name29, value29);
    } 
    while (name29==name3||name29==name2||name29==name1||name29==name4
            ||name29==name5||name29==name6||name29==name7||name29==name8
            ||name29==name9||name29==name10||name29==name11||name29==name12
            ||name29==name13||name29==name14||name29==name15||name29==name16
            ||name29==name17||name29==name18||name29==name19||name29==name20
            ||name29==name21||name29==name22||name29==name23||name29==name24
            ||name29==name25||name29==name26||name29==name27||name29==name28);

    //card30
    do{
           nameCrd (card30, name30, value30);
    } 
    while (name30==name3||name30==name2||name30==name1||name30==name4
            ||name30==name5||name30==name6||name30==name7||name30==name8
            ||name30==name9||name30==name10||name30==name11||name30==name12
            ||name30==name13||name30==name14||name30==name15||name30==name16
            ||name30==name17||name30==name18||name30==name19||name30==name20
            ||name30==name21||name30==name22||name30==name23||name30==name24
            ||name30==name25||name30==name26||name30==name27||name30==name28
            ||name30==name29);    

    //card31
    do{
             nameCrd (card31, name31, value31);
    } 
    while (name31==name3||name31==name2||name31==name1||name31==name4
            ||name31==name5||name31==name6||name31==name7||name31==name8
            ||name31==name9||name31==name10||name31==name11||name31==name12
            ||name31==name13||name31==name14||name31==name15||name31==name16
            ||name31==name17||name31==name18||name31==name19||name31==name20
            ||name31==name21||name31==name22||name31==name23||name31==name24
            ||name31==name25||name31==name26||name31==name27||name31==name28
            ||name31==name29||name31==name30);
    
    //card32
    do{
            nameCrd (card32, name32, value32);
    } 
    while (name32==name3||name32==name2||name32==name1||name32==name4
            ||name32==name5||name32==name6||name32==name7||name32==name8
            ||name32==name9||name32==name10||name32==name11||name32==name12
            ||name32==name13||name32==name14||name32==name15||name32==name16
            ||name32==name17||name32==name18||name32==name19||name32==name20
            ||name32==name21||name32==name22||name32==name23||name32==name24
            ||name32==name25||name32==name26||name32==name27||name32==name28
            ||name32==name29||name32==name30||name32==name31); 
     
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
    cout<<"Enter the amount you, player "<<i + 1<<", would like to bet."<<endl;
    cout<<"below. You currently have $"<<money[i][j]<<'.'<<endl;
    cin>>bet;
    
    /*Use a while loop to prevent the player from betting a negative number or
     betting higher than how much they currently have*/
    while (bet<0 || bet>money[i][j])
    {
        cout<<"This is an invalid bet. Please enter the amount you would"<<endl;
        cout<<"like to bet below."<<endl;
        cin>>bet;
    } 
    
    //Initialize variables that are based on the bet
    
    splBet1 = splBet2 = splBet3 = splBet4 = bet; /*The bet placed on any hand
                                                  created off of a split is the 
                                                  same as the original bet*/
    
    money[i][j] -= bet; /*The money the player has after they place their bet is what 
                   they had minus their bet*/
    
    //Deal the cards and display the game with appropriate formatting
    cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ???"<<endl;
    cout<<setw(30)<<"------"<<endl; 
    cout<<setw(20)<<name25<<setw(19)<<"???"<<endl; /*name25 is the dealer's
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
    if ((name25 == "Ace of Spades" || name25 =="Ace of Diamonds" || 
            name25 == "Ace of Hearts" || name25 == "Ace of Clubs") && 
            money[i][j] >= (1.0f/2)*bet) 
    {
        cout<<"Would you like to place an insurance bet? Type 'Y' to place one";
        cout<<" or any other key not to, and hit enter after typing choice.";
        cout<<endl;
        cin>>choice;
    
        //Use an if/else statement to play out the insurance bet
        if (choice == 'Y')
        {
            insBet = (1.0f/2)*bet;
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
    dealTot [j] = value25 + value26; /*Total of dealer's hand is the value of
                                      their first card (card 25) + the value 
                                      of their second card (card 26)*/

    if ((playTot[j] == 21) && (dealTot[j] == 21))      /*If both player 
                                                        and dealer have
                                                        Blackjack*/                                                            
    {
        cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
        cout<<endl;
        cout<<setw(30)<<"------"<<endl;
        cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
        cout<<endl<<endl<<endl;
        cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = "<<playTot[j];
        cout<<endl;
        cout<<setw(30)<<"------"<<endl;
        cout<<setw(20)<<name1<<setw(25)<<name2;
        cout<<setw(28)<<"**Current Money = $"<<money[i][j]<<endl;
        
        returns = bet + 3*insBet; /*Player gets back just what they bet and 3 
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
        cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
        cout<<endl<<endl<<endl;
        cout<<setw(30)<<"PLAYER"<<setw(20)<<"hand total = "<<playTot[j];
        cout<<endl;
        cout<<setw(30)<<"------"<<endl;
        cout<<setw(20)<<name1<<setw(25)<<name2;
        cout<<setw(28)<<"**Current Money = $"<<money[i][j]<<endl;
        
        returns = bet + (3.0f/2)*bet; /*Player gets back what they bet and 1/5 
                                       times it*/
        
        money[i][j]+=returns;
        cout<<"BLACKJACK!!"<<endl;
        cout<<"You won $"<<(3.0f/2)*bet<<endl;
        cout<<"You now have $"<<money[i][j];
    }
    
    else if (dealTot[j] == 21) //If only dealer has Blackjack
    {
        cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
        cout<<endl;
        cout<<setw(30)<<"------"<<endl;
        cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
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
        if (money[i][j]>=bet)
            cout<<"C. Double"<<endl;

        /*Only display the "split" option  if the cards have the same face and 
         if there is enough money left to make another bet equal to original*/
        if ((face1 == face2) && money[i][j]>=bet)   
            cout<<"D. Split"<<endl;
        
        cin>>choice;
        
        /*This makes it to where the player cannot choose double or split when it
         is not shown on the menu; neither displays when money < bet, so when
         money < bet and if choice is C or D, choice becomes X to cause another
         input to be asked for*/
        if (money[i][j] < bet)
            if (choice == 'C'||choice == 'D')
                choice = 'X';
        
        /*Continuously prompt the player to input a choice so long as their's 
         is not A, B, C, or D; do this for the choice for the remaining rounds*/
        while (!(choice == 'A'||choice == 'B'||choice == 'C'||choice == 'D'))
        {
            cout<<"This is an invalid choice. Please type the letter to"<<endl;
            cout<<"the left of the menu to make the corresponding"<<endl;
            cout<<"choice."<<endl;
            cout<<" A. Hit"<<endl;
            cout<<" B. Stand"<<endl;
            if(money[i][j]>=bet)
            {    
                cout<<" C. Double"<<endl;
                if (face1 == face2)
                    cout<<"D. Split"<<endl;
            }    
            cin>>choice;
            if (money[i][j] < bet)
                if (choice == 'C'||choice == 'D')
                    choice = 'X';
        }    
        switch (choice)
        {
            case 'A':
               /*Deal the next card for the player by copying the display 
                done for the first round and adding the next card; this card's
                name and value get added to the screen output, and it gets 
                considered in the ace calculation; repeat this for each hit*/
                
                cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ???"<<endl;
                cout<<setw(30)<<"------"<<endl; 
                cout<<setw(20)<<name25<<setw(19)<<"???"<<endl;
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
                        cout<<setw(20)<<name25<<setw(19)<<"???"<<endl;
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
                                cout<<setw(20)<<name25<<setw(19)<<"???"<<endl;
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
                                    cout<<setw(20)<<name25<<setw(19)<<"???";
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
                                        cout<<setw(20)<<name25<<setw(19)<<"???";
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
                                                cout<<setw(20)<<name25;
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
                
            case 'C': 
            {
                /*Deal the next card for the player by copying the display 
                done for the first round and adding the next card; this card's
                name and value get added to the screen output, and it gets 
                considered in the ace calculation; because this is double,
                the bet doubles, and the player can no longer draw cards after*/
                
                money[i][j]-=bet; /*The money the player has decreases by the 
                                   bet amount again*/
                bet*=2;     //The bet amount increases by 2
       
                cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ???"<<endl;
                cout<<setw(30)<<"------"<<endl; 
                cout<<setw(20)<<name25<<setw(19)<<"???"<<endl;
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
                cout<<setw(60)<<"Your bet is now $"<<bet<<endl;
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
                
                else if (playTot[j] == 21)                  //If the player has 21, 
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
            
            default:
                cout<<"THE SPLIT IS NOT YET IMPLEMENTED.";
                return 0;
        }
    
    //The dealer will now turn over their face down card
        
    //Use an if statement to make an ace equal 1 if the hand total is over 21
    if (value25 + value26 > 21)
    {        
        if(value25 == 11)
            value25=1;
        else if(value26 == 11)
            value26=1;
    }
        
    dealTot[j] = value25 + value26; //dealTot[j] is the total of the dealer's cards
    cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
    cout<<endl;
    cout<<setw(30)<<"------"<<endl;
    cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
    cout<<endl<<endl<<endl;
    cout<<setw(30)<<"PLAYER"<<endl;
    cout<<setw(30)<<"------"<<endl;
    cout<<"Current Bet: $"<<bet<<setw(30)<<"Current Money: $";
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
        while ((value25 + value26 + value27 > 21) && (value25 == 11 ||
                value26 == 11|| value27 == 11))
        {   
            if(value25 == 11)
                value25 = 1;
            else if(value26 == 11)
                value26 = 1;
            else if (value27 == 11)
                value27 = 1;
        }    

        dealTot[j] = value25 + value26 + value27; /*dealTot[j] is the total of the 
                                                dealer's cards*/
        cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
        cout<<endl;
        cout<<setw(30)<<"------"<<endl;
        cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
        cout<<setw(20)<<name27<<endl;
        cout<<endl<<endl;
        cout<<setw(30)<<"PLAYER"<<endl;
        cout<<setw(30)<<"------"<<endl;
        cout<<"Current Bet: $"<<bet<<setw(30);
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
            
            while ((value25 + value26 + value27 + value28 > 21) && 
                    (value25 == 11 || value26 == 11|| value27 == 11
                    ||value28 == 11))
            {   
                if(value25 == 11)
                    value25 = 1;
                else if(value26 == 11)
                    value26 = 1;
                else if (value27 == 11)
                    value27 = 1;
                else if (value28 == 11)
                    value28 = 1;
            }    

            dealTot[j] = value25 + value26 + value27 + value28;
            
            cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = "<<dealTot[j];
            cout<<endl;
            cout<<setw(30)<<"------"<<endl;
            cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
            cout<<setw(20)<<name27<<setw(25)<<name28<<endl;
            cout<<endl;
            cout<<setw(30)<<"PLAYER"<<endl;
            cout<<setw(30)<<"------"<<endl;
            cout<<"Current Bet: $"<<bet<<setw(30);
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
                while ((value25 + value26 + value27 + value28 + value29 > 21) 
                        &&(value25 == 11 || value26 == 11|| value27 == 11
                           ||value28 == 11 || value29 == 11))
                    {   
                        if(value25 == 11)
                            value25 = 1;
                        else if(value26 == 11)
                            value26 = 1;
                        else if (value27 == 11)
                            value27 = 1;
                        else if (value28 == 11)
                            value28 = 1;
                        else if (value29 == 11)
                            value29 = 1;
                    }    

                    dealTot[j] = value25 + value26 + value27 + value28 + value29;

                    cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ";
                    cout<<dealTot[j];
                    cout<<endl;
                    cout<<setw(30)<<"------"<<endl;
                    cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
                    cout<<setw(20)<<name27<<setw(25)<<name28<<endl;
                    cout<<setw(20)<<name29<<endl;
                    cout<<endl;
                    cout<<setw(30)<<"PLAYER"<<endl;
                    cout<<setw(30)<<"------"<<endl;
                    cout<<"Current Bet: $"<<bet<<setw(30);
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
                        while ((value25 + value26 + value27 + value28 + value29
                                + value30> 21) 
                            &&(value25 == 11 || value26 == 11|| value27 == 11
                               ||value28 == 11 || value29 == 11 || 
                                value30 == 11))
                        {   
                            if(value25 == 11)
                                value25 = 1;
                            else if(value26 == 11)
                                value26 = 1;
                            else if (value27 == 11)
                                value27 = 1;
                            else if (value28 == 11)
                                value28 = 1;
                            else if (value29 == 11)
                                value29 = 1;
                            else if (value30 == 11)
                                value30 = 1;
                        }    

                        dealTot[j] = value25 + value26 + value27 + value28
                                  + value29 + value30;

                        cout<<setw(30)<<"DEALER"<<setw(20)<<"hand total = ";
                        cout<<dealTot[j];
                        cout<<endl;
                        cout<<setw(30)<<"------"<<endl;
                        cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
                        cout<<setw(20)<<name27<<setw(25)<<name28<<endl;
                        cout<<setw(20)<<name29<<setw(25)<<name30<<endl;
                        cout<<endl;
                        cout<<setw(30)<<"PLAYER"<<endl;
                        cout<<setw(30)<<"------"<<endl;
                        cout<<"Current Bet: $"<<bet<<setw(30);
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
                            while ((value25 + value26 + value27 + value28 
                                    + value29 + value30 + value31 > 21) 
                                &&(value25 == 11 || value26 == 11
                                || value27 == 11 || value28 == 11 
                                || value29 == 11 || value30 == 11
                                || value31 == 11))
                                {   
                                    if(value25 == 11)
                                        value25 = 1;
                                    else if(value26 == 11)
                                        value26 = 1;
                                    else if (value27 == 11)
                                        value27 = 1;
                                    else if (value28 == 11)
                                        value28 = 1;
                                    else if (value29 == 11)
                                        value29 = 1;
                                    else if (value30 == 11)
                                        value30 = 1;
                                    else if (value31 == 11)
                                        value31 = 1;
                                }    

                                dealTot[j] = value25 + value26 + value27 + value28
                                          + value29 + value30 + value31;

                                cout<<setw(30)<<"DEALER"<<setw(20);
                                cout<<"hand total = ";
                                cout<<dealTot[j];
                                cout<<endl;
                                cout<<setw(30)<<"------"<<endl;
                                cout<<setw(20)<<name25<<setw(25)<<name26<<endl;
                                cout<<setw(20)<<name27<<setw(25)<<name28<<endl;
                                cout<<setw(20)<<name29<<setw(25)<<name30<<endl;
                                cout<<setw(20)<<name31<<endl;
                                cout<<endl;
                                cout<<setw(30)<<"PLAYER"<<endl;
                                cout<<setw(30)<<"------"<<endl;
                                cout<<"Current Bet: $"<<bet<<setw(30);
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
                                    while ((value25 + value26 + value27 
                                          + value28 + value29 + value30 
                                          + value31 + value32 > 21) 
                                          &&(value25 == 11 || value26 == 11
                                          || value27 == 11 || value28 == 11 
                                          || value29 == 11 || value30 == 11
                                          || value31 == 11 || value32 == 11))
                                        {   
                                            if(value25 == 11)
                                                value25 = 1;
                                            else if(value26 == 11)
                                                value26 = 1;
                                            else if (value27 == 11)
                                                value27 = 1;
                                            else if (value28 == 11)
                                                value28 = 1;
                                            else if (value29 == 11)
                                                value29 = 1;
                                            else if (value30 == 11)
                                                value30 = 1;
                                            else if (value31 == 11)
                                                value31 = 1;
                                            else if (value32 == 11)
                                                value32 = 1;
                                        }    

                                        dealTot[j] = value25 + value26 + value27 
                                                  + value28 + value29 + value30
                                                  + value31 + value32;

                                        cout<<setw(30)<<"DEALER"<<setw(20);
                                        cout<<"hand total = ";
                                        cout<<dealTot[j];
                                        cout<<endl;
                                        cout<<setw(30)<<"------"<<endl;
                                        cout<<setw(20)<<name25<<setw(25);
                                        cout<<name26<<endl;
                                        cout<<setw(20)<<name27<<setw(25);
                                        cout<<name28<<endl;
                                        cout<<setw(20)<<name29<<setw(25);
                                        cout<<name30<<endl;
                                        cout<<setw(20)<<name31<<setw(25);
                                        cout<<name32<<endl;
                                        cout<<endl;
                                        cout<<setw(30)<<"PLAYER"<<endl;
                                        cout<<setw(30)<<"------"<<endl;
                                        cout<<"Current Bet: $"<<bet<<setw(30);
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
        returns = bet*2;
        money[i][j] += returns;
        cout<<endl<<endl;
        cout<<"You won because the dealer busted!"<<endl<<endl;
        cout<<"You won $"<<returns/2<<". You now have $"<<money[i][j];
    }
    
    else if (playTot[j] > dealTot[j] && ((dealTot[j] < 21) && (playTot[j] <= 21)))
    /*If player's total is higher than dealer's and neither have busted, player
     wins*/
    {   
        returns = bet*2;
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
        returns = bet;
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
        cout<<"You lost $"<<bet<<". You now have $"<<money[i][j];  
    }
    else if (playTot[j]>21) //If player is ever busted, they lose
    {    
        cout<<endl<<endl;
        cout<<"You lost because you busted."<<endl<<endl;
        cout<<"You lost $"<<bet<<". You now have $"<<money[i][j];
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
        
        /*Call to a function where you pass in the final array value and return
         the difference this is from  $500*/
        
        int diffr; //Declare a variable to input the function's return value into
        
        diffr = diff (money[i][j]);
        
        /*Use if else to display different message depending on whether the 
         return value is positive or negative*/
        if (diffr >= 0)
        {
            cout<<"This amount is $"<<diffr<<" less than what you started"<<endl;
            cout<<"with in the beginning of your games."<<endl;
        } 
        else 
        {
            cout<<"This amount is $"<<diffr*-1<<" more than what you"<<endl;
            cout<<"started with in the beginning of yours games."<<endl;
        }    
                
                  
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
        
        
        
        /*Use an if/else to prompt the user what to do next depending on if 
         there are more players to play*/
        if (i < playCnt - 1)
        {
            cout<<"Hit enter to continue to player "<<i + 2<<"'s turn."<<endl;
            cin.get();
        }    
        else
        {    
            cout<<endl;
            cout<<"All the players have played their games. Hit enter to"<<endl;
            cout<<"continue."<<endl;
            cin.get();
        }

    }    
    }   
    } //Closes the { started in line 146   
 
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
                           of the 32 cards*/
    
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

/*This function takes the argument of the function call, subtracts if from 500,
 and returns the difference*/
int diff (float fnlMony)
{
    int dfrnce = 500 - static_cast<int>(fnlMony); /*The difference is 500 - the
                                                  final money amount statically
                                                  casted as an int, because it is 
                                                  assumed a Blackjack player
                                                  won't be walking away with
                                                  change*/
    
    return dfrnce;
}