//---------------------------------------------------- 
// Name: Moyo Williams
// E-mail Address: mow5248@psu.edu
// Class: CMPSC 122, Section 102
// Final Project
// Date:04/22/2013
// Hangman Console Game
//----------------------------------------------------

#pragma once
#include <iostream>
#include <fstream>  
#include <string>   
#include <time.h>	
#include <stdlib.h>	
#include <windows.h>



const int  MAX_WORD_SIZE = 15;	// The max size of words
const int  MAX_WORDS = 255;	    // The max number of words
const int WIDTH = 14;           // Width of ASCII border for gallows art
const int BANNERWIDTH = 73;     // Width of banner 
const int BORDERWIDTH = 80;     // Console width
const int BORDERHEIGHT = 50;    // Console height
const WORD WALL_COLOR = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
const unsigned char LEFTCORNER = 201;
const unsigned char RIGHTCORNER = 187;
const unsigned char SIDE = 186;
const unsigned char LINE = 205;
const unsigned char BOTTOMLEFTCORNER = 200;
const unsigned char BOTTOMRIGHTCORNER = 188;


using namespace std;




class HangMan{


public:
    CHAR_INFO SCREEN_BUFFER[BORDERHEIGHT * BORDERWIDTH];
    
    void DrawASCIICharacter(int x, int y, unsigned char ch, WORD CharAttribute);
    void DrawBorder();
    void StartGame();
    void LoadFile();	// Prototypes for our functions
    void RunGame();
    void DrawGallows(int numberOfguesses);
    void DrawTop(int WIDTH);
    void DrawMiddle(int WIDTH);
    void DrawMiddle(int WIDTH, string userInput);
    void DrawBottom(int WIDTH);
    HangMan();
    ~HangMan();
   
        
        


private:
    typedef char String[MAX_WORD_SIZE];	// Make a char type with 15 chars
    String Words[MAX_WORDS - 1];		// This array will hold our words
    int m_numberOfwords;
    
    
};


