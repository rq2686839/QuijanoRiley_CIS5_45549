/* 
 * File:   main.cpp
 * Author: Riley Quijano
 * Created on July 17, 2017, 9:31AM
 * Purpose:  Drawing Cards
 */

//System Libraries Here
#include <iostream>     //Input - Output Manipulation Library
#include <cstdlib>      //C Standard Library for rand() Function
#include <ctime>        //C Time Library to Seed the Random Number Generator
#include <string>       //Include String Library for String Functions

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions


//Function Prototypes Here

void nameCrd (unsigned short &, string &, unsigned short &);

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
    
    cout<<name1<<value1<<endl;
    cout<<name2<<value2<<endl;
    cout<<name3<<value3<<endl;
    cout<<name4<<value4<<endl;
    cout<<name5<<value5<<endl;
    cout<<name6<<value6<<endl;
    cout<<name7<<value7<<endl;
    cout<<name8<<value8<<endl;
    cout<<name9<<value9<<endl;
    cout<<name10<<value10<<endl;
    cout<<name11<<value11<<endl;
    cout<<name12<<value12<<endl;
    cout<<name13<<value13<<endl;
    cout<<name14<<value14<<endl;
    cout<<name15<<value15<<endl;
    cout<<name16<<value16<<endl;
    cout<<name17<<value17<<endl;
    cout<<name18<<value18<<endl;
    cout<<name19<<value19<<endl;
    cout<<name20<<value20<<endl;
    cout<<name21<<value21<<endl;
    cout<<name22<<value22<<endl;
    cout<<name23<<value23<<endl;
    cout<<name24<<value24<<endl;
    cout<<name25<<value25<<endl;
    cout<<name26<<value26<<endl;
    cout<<name27<<value27<<endl;
    cout<<name28<<value28<<endl;
    cout<<name29<<value29<<endl;
    cout<<name30<<value30<<endl;
    cout<<name31<<value31<<endl;
    cout<<name32<<value32<<endl;
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