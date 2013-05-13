//---------------------------------------------------- 
// Name: Moyo Williams
// E-mail Address: mow5248@psu.edu
// Class: CMPSC 122, Section 102
// Final Project
// Date:04/22/2013
// Hangman Console Game
//----------------------------------------------------



#include <iostream>
#include <fstream>  
#include <string>   
#include <time.h>	
#include <stdlib.h>
#include <windows.h>
#include "HangMan.h"


using namespace std;





//*********************************************
// Put an ASCII Character at point x and y    *
//*********************************************

void HangMan::DrawASCIICharacter(int x, int y, unsigned char ch, WORD CharAttribute)
{
    if (x < 0) return;
    if (y < 0 ) return;
    if (x >= BORDERWIDTH) return;
    if (y >= BORDERHEIGHT) return;

    SCREEN_BUFFER[y*WIDTH + x].Char.AsciiChar = ch;
    SCREEN_BUFFER[y*WIDTH + x].Attributes = CharAttribute;
}


//******************************************
// Draws a border around the screen        *
//******************************************
void HangMan::DrawBorder()
{
    int i;
    
    // Sides
    for (i = 0; i < BORDERHEIGHT; i++)
    {
        DrawASCIICharacter(0, i, 219, WALL_COLOR);
        DrawASCIICharacter(WIDTH - 1, i, 219, WALL_COLOR);
    }

    // Top and Bottom
    for (i = 0; i < WIDTH; i++)
    {
        DrawASCIICharacter(i, 0, 219, WALL_COLOR);
        DrawASCIICharacter(i, BORDERHEIGHT - 1, 219, WALL_COLOR);
    }
}
//***********************************************
// Main Function that runs our game for us      *
//***********************************************

void HangMan::StartGame()
{
        

//********************
// Global Variables  *
//********************

    HANDLE g_hWin;   // Handle to the Standard Output
    HANDLE g_hInput; // Handle to the Standard Input
    COORD BUFFER_SIZE = {BORDERWIDTH, BORDERHEIGHT};
    SMALL_RECT WINDOW_SIZE = {0, 0, BORDERWIDTH-1, BORDERHEIGHT-1};

//******************************************
// Setup the windows console               *
//******************************************

        // get the handles to the standard windows
        g_hWin = GetStdHandle(STD_OUTPUT_HANDLE);
        g_hInput = GetStdHandle(STD_INPUT_HANDLE);

        // Set the title of the window
        SetConsoleTitle(TEXT("Hangman Game"));

        // Set the console window size
        SetConsoleWindowInfo(g_hWin, TRUE, &WINDOW_SIZE);

        // Set the buffer size
        SetConsoleScreenBufferSize(g_hWin, BUFFER_SIZE);
        

        char Continue = 'Y';
        DrawBorder();
        
        //code snippet to change the color for our ASCII art
        HANDLE hCONSOLE;
        hCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute (hCONSOLE, 176);

        //Banner Art
		cout << "\n\n";
        DrawTop(BANNERWIDTH);
		DrawMiddle(BANNERWIDTH);
		cout << " " << SIDE << "                                                                           " << SIDE << endl
			<<" "<<SIDE<<"         Welcome To Hangman!   "<<"                                            "<<SIDE<<endl
			<<" "<<SIDE<<"                 by " <<"                                                       "<<SIDE<<endl
			<<" "<<SIDE<<"            Moyo Williams" <<"                                                  "<<SIDE<<endl
			<<" "<<SIDE<<"  Put on your thinking cap....and don't lose your head!"<<"                    "<<SIDE<<endl;
        cout <<" "<< SIDE<< "                                                                           " << SIDE <<endl;
        DrawMiddle(BANNERWIDTH);
		DrawBottom(BANNERWIDTH);
		cout << "\n\n";	

        LoadFile();
       
        //loop that continues to run the game if the user wants to keep playing
        while (Continue == 'Y')
              {
        
                  RunGame();
                  cout << "\n\n";
                  cout << " Do you want to play again ( Y or N )?" <<endl;
                  cin >> Continue;
                  Continue = toupper(Continue);
        
              }
        
        cout <<"\n"<< " Thanks for playing, good bye!" <<endl;

}

//*******************************************
//Function to load the input text file into *
// our game.                                *
//*******************************************

void HangMan::LoadFile()
{


            char fileLength;		//Used to find lenght of the input file
	        m_numberOfwords = 0;	//Set m_numberOfwords to 0
	        ifstream InputFile;
	        InputFile.open ("words.txt");

	        //Loop to find the lenght of the input file
	        while ((fileLength = InputFile.peek()) != EOF)
	        {
		        // Get the next word and then increment m_numberOfwords
		        InputFile >> Words[m_numberOfwords++];
		
                if( m_numberOfwords > MAX_WORDS - 1)
		            {
			            cout << "Sorry, you have exceeded the maximum number of words" <<endl;
                        cout << "You have a maximum of" << MAX_WORDS << "words" << endl;	
			            m_numberOfwords = MAX_WORDS;
			            break;
		            }

	        }

	        m_numberOfwords;  //number count

	        InputFile.close(); //closes the input file

}

//******************************************
//Function to draw the ASCII art for the   *
//gallows and hangman                      *
//******************************************

 void HangMan::DrawGallows(int numberOfguesses)
 {


     if(numberOfguesses == 6)
	    {
		    
		        //code snippet to change the color for our ASCII art
                HANDLE hCONSOLE;
                hCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
		        SetConsoleTextAttribute (hCONSOLE, 11);
            
            
                // The \\ will translate as '\' because it is a special char
                cout << " \n\n";
                DrawTop(WIDTH);
		        DrawMiddle(WIDTH);
		        cout << " " << SIDE << "                " << SIDE << endl
			         <<" "<<SIDE<<"   +----+    "<<"   "<<SIDE<<endl
			         <<" "<<SIDE<<"   |    |    "<<"   "<<SIDE<<endl
			         <<" "<<SIDE<<"   |    O    "<<"   "<<SIDE<<endl
			         <<" "<<SIDE<<"   |   /|\\  "<<"    "<<SIDE<<endl
			         <<" "<<SIDE<<"   |   / \\  "<<"    "<<SIDE<<endl
			         <<" "<<SIDE<<"   |         "<<"   "<<SIDE<<endl
			         <<" "<<SIDE<<"  ============ "<<" " <<SIDE<<endl;
                cout <<" "<< SIDE<< "                " << SIDE <<endl;
                DrawMiddle(WIDTH);
		        DrawBottom(WIDTH);
                cout << "You died!" << endl;
		        cout << " \n\n";	

	    }
	
 
        else if(numberOfguesses == 5)
	    {
        
            
                //code snippet to change the color for our ASCII art
                HANDLE hCONSOLE;
                hCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
		        SetConsoleTextAttribute (hCONSOLE, 9);

		        cout << " \n\n";
                DrawTop(WIDTH);
		        DrawMiddle(WIDTH);
		        cout << " " << SIDE << "                " << SIDE << endl
			        <<" "<<SIDE<<"   +----+   "<<"    "<<SIDE<<endl
			        <<" "<<SIDE<<"   |    |   "<<"    "<<SIDE<<endl
			        <<" "<<SIDE<<"   |    O   "<<"    "<<SIDE<<endl
			        <<" "<<SIDE<<"   |   /|\\ "<<"     "<<SIDE<<endl
			        <<" "<<SIDE<<"   |     \\ "<<"     "<<SIDE<<endl
			        <<" "<<SIDE<<"   |        "<<"    "<<SIDE<<endl
                    <<" "<<SIDE<<"   |          " <<"  "<<SIDE<<endl
			        <<" "<<SIDE<<"  ============ "<<" " <<SIDE<<endl;
                cout <<" "<< SIDE<< "                " << SIDE <<endl;
                DrawMiddle(WIDTH);
		        DrawBottom(WIDTH);
		        cout << " \n\n";	
	    }
	
    
        else if(numberOfguesses == 4)
	    {
		        //code snippet to change the color for our ASCII art
                HANDLE hCONSOLE;
                hCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
		        SetConsoleTextAttribute (hCONSOLE, 10);
        
                cout << " \n\n";
                DrawTop(WIDTH);
		        DrawMiddle(WIDTH);
		        cout << " " << SIDE << "                " << SIDE << endl
			        <<" "<<SIDE<<"   +----+   "<<"    "<<SIDE<<endl
			        <<" "<<SIDE<<"   |    |   "<<"    "<<SIDE<<endl
			        <<" "<<SIDE<<"   |    O   "<<"    "<<SIDE<<endl
			        <<" "<<SIDE<<"   |   /|\\ "<<"     "<<SIDE<<endl
			        <<" "<<SIDE<<"   |        "<<"    "<<SIDE<<endl
			        <<" "<<SIDE<<"   |        "<<"    "<<SIDE<<endl
                    <<" "<<SIDE<<"   |        "<<"    "<<SIDE<<endl
			        <<" "<<SIDE<<"  ============= "<<""<<SIDE<<endl;
                cout <<" "<< SIDE<< "                " << SIDE <<endl;
                DrawMiddle(WIDTH);
		        DrawBottom(WIDTH);
		        cout << " \n\n";	
	    }
	
    
        else if(numberOfguesses == 3)
	    {
		

            //code snippet to change the color for our ASCII art
            HANDLE hCONSOLE;
            hCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
		    SetConsoleTextAttribute (hCONSOLE, 14);

            cout << " \n\n";
            DrawTop(WIDTH);
		    DrawMiddle(WIDTH);
		    cout << " " << SIDE << "                " << SIDE << endl
			    <<" "<<SIDE<<"   +----+  "<<"     "<<SIDE<<endl
			    <<" "<<SIDE<<"   |    |  "<<"     "<<SIDE<<endl
			    <<" "<<SIDE<<"   |    O  "<<"     "<<SIDE<<endl
			    <<" "<<SIDE<<"   |   /|  "<<"     "<<SIDE<<endl
			    <<" "<<SIDE<<"   |       "<<"     "<<SIDE<<endl
			    <<" "<<SIDE<<"   |       "<<"     "<<SIDE<<endl
                <<" "<<SIDE<<"   |       "<<"     "<<SIDE<<endl
			    <<" "<<SIDE<<"  ============="<<" " <<SIDE<<endl;
            cout <<" "<< SIDE<< "                " << SIDE <<endl;
            DrawMiddle(WIDTH);
		    DrawBottom(WIDTH);
		    cout << " \n\n";	
	
        }


	    else if(numberOfguesses == 2)
	    {

                //code snippet to change the color for our ASCII art
                HANDLE hCONSOLE;
                hCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
		        SetConsoleTextAttribute (hCONSOLE, 13);

		        cout << " \n\n";
                DrawTop(WIDTH);
		        DrawMiddle(WIDTH);
		        cout << " " << SIDE << "                " << SIDE << endl
			     <<" "<<SIDE<<"   +----+  " <<"     "<<SIDE<<endl
			     <<" "<<SIDE<<"   |    |  " <<"     "<<SIDE<<endl
			     <<" "<<SIDE<<"   |    O  " <<"     "<<SIDE<<endl
			     <<" "<<SIDE<<"   |    |  " <<"     "<<SIDE<<endl
			     <<" "<<SIDE<<"   |       " <<"     "<<SIDE<<endl
			     <<" "<<SIDE<<"   |       " <<"     "<<SIDE<<endl
			     <<" "<<SIDE<<"  =============" <<" " <<SIDE<<endl;
                cout <<" "<< SIDE<< "                " << SIDE <<endl;
                DrawMiddle(WIDTH);
		        DrawBottom(WIDTH);
		        cout << " \n\n";	
	
        }
	
    
        else if(numberOfguesses == 1)
	    {
            
                //code snippet to change the color for our ASCII art
                HANDLE hCONSOLE;
                hCONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
		        SetConsoleTextAttribute (hCONSOLE, 12);
		
	    
                cout << " \n\n";
                DrawTop(WIDTH);
		        DrawMiddle(WIDTH);
		        cout << " " << SIDE << "                " << SIDE << endl
		        //cout << SIDE << " " << endl
			         <<" "<<SIDE<<"   +----+  " <<"     "<<SIDE<<endl
			         <<" "<<SIDE<<"   |    |  " <<"     "<<SIDE<<endl
			         <<" "<<SIDE<<"   |       " <<"     "<<SIDE<<endl
			         <<" "<<SIDE<<"   |       " <<"     "<<SIDE<<endl
			         <<" "<<SIDE<<"   |       " <<"     "<<SIDE<<endl
			         <<" "<<SIDE<<"   |       " <<"     "<<SIDE<<endl
			         <<" "<<SIDE<<"  =============" <<" " <<SIDE<<endl; 
		        cout <<" "<< SIDE<< "                " << SIDE <<endl;
                DrawMiddle(WIDTH);
		        DrawBottom(WIDTH);
		        cout << " \n\n";	

        
	    }
 
 
 }


//*******************************************
//Function that runs our game and decides   *
//if the user wins or loses                 *
//*******************************************

 void HangMan::RunGame()
{
    
        int Word;			       // This will hold the subscript of our word
	    int Size;			      // This will hold the length of our word
	    int numberOfguesses = 1; // This holds the game numberOfguesses
	    int Subscript = 0;	    // This will hold subscripts
	    char Guess[MAX_WORD_SIZE];	 // this will hold their current word
	    char Copy[MAX_WORD_SIZE];	// This will hold a copy of the word
	    char Letter;		       //This will be their letter guess
	    int Correct = 0;		  // This is a True/False value deciding if they got a good answer
    
        // Seed and create a random number
	    srand((unsigned)time( NULL ));	// use time as a seed
	    Word = rand() % m_numberOfwords;

	    // Make a local copy of the word
	    strcpy_s(Copy, Words[Word]);

	    Size = strlen(Words[Word]);	// Get the word's size

//*****************************************************
// Create a null terminated string to represent       *
//    the word as the player knows it.                *
//*****************************************************
	
	    for(; Subscript < Size; Subscript++)
	    {
		    Guess[Subscript] = '-';
	    }

	    // insert the null charachter
	    Guess[Subscript] = '\0';


        //Loop that runs till the player is hung 
	
        while(numberOfguesses!=6)
	    {
		    DrawGallows(numberOfguesses);	//Draw the gallows
		    cout << Guess << endl;	// Draw Guess

		    cout << "Guess a letter :";
		    cin >> Letter;

		    // We will use only lower case letters
		    Letter = tolower(Letter);
		
		    // Loop through the word
		    for(Subscript = 0; Subscript < Size; Subscript++)
		    {

			    //if the guess is good tell the user and update Guess
			    if(Copy[Subscript] == Letter)
			    {
				    Guess[Subscript] = Letter;
				    Correct = 1;
				    cout << endl << "Good Guess!";

				    // If guess equals the word they won so exit
				    if(strcmp(Words[Word], Guess) == 0)
				    {
					    cout << endl << "Congratulations, you won!";
					    return;
				    }
			    }
		    }

		    // If they didn't get aletter correct chide the user
		    if( Correct == 0)
		    {
			    cout << endl << "Sorry, bad guess!";
			    numberOfguesses++;
		    }

		    Correct = 0;	// reset Correct

	    }

	    DrawGallows( numberOfguesses );	//Draw the gallows at end of game
	    //They lost if they are here so tell them the answer.
	    cout<<"The word was : " << Words[Word] << endl << endl;	

}

//*****************************************************
// Gets the output of the Top or first line in ASCII  *
//*****************************************************

void HangMan::DrawTop(int WIDTH)
{
		
		cout << " " << LEFTCORNER;
		for (int i = 0;  i <= WIDTH+1; i++)
		{
			cout << LINE;
		}
		cout << RIGHTCORNER<< endl;
}


//****************************************************************
//Gets the output for Middle of the text box or the second line  *
//****************************************************************

void HangMan::DrawMiddle(int WIDTH)
{
		cout << " " << SIDE;
	    for (int i = 0;i <= WIDTH+1; i++)
		{ 
			cout << " ";
		}
		cout << SIDE <<endl;
}

//**************************************
//Gets the output of the fourth line   *
//**************************************

void HangMan::DrawBottom(int WIDTH)
{	
	    cout << " " << BOTTOMLEFTCORNER;
		for(int i = 0; i <= WIDTH+1; i++)
		{
			cout << LINE;
		}
		cout << BOTTOMRIGHTCORNER <<endl;
	
}




HangMan::HangMan()
{



}
   
    
HangMan::~HangMan()
{




}


