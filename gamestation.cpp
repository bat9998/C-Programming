//Zach Singleton
//2/9/2014
//Project 4: Game Station
//Inputs: Game Selection (and prior game inputs)
//Outputs: Launch of the selected game (and prior game outputs)
#include <iostream> //#Include tells compiler what functionality I'll use
#include <fstream>
#include <stdlib.h>
//The following cpp files must be saved in the same folder with this file for these programs to run when called
#include "twoguess.cpp"
#include "wordguessfinal.cpp"
#include "phraseguessfinal.cpp"

using namespace std;// whenever the computer comes across cout, cin, etc. it will read it as std::cout, std::cin, etc.

int main() //function definition and start of block of code
{
  char ans;//character definition
do
{
    int choosegame;//integer definition

    cout << "This is a program to select which programs to run" << endl;//displays game selection options to user
    cout << "Enter 1 to play Number Guess" << endl;
    cout << "Enter 2 to play Word Guess" << endl;
    cout << "Enter 3 to play Phrase Guess" << endl;
   
    cin >> choosegame;//game selection entry
    cin.ignore();

    if (choosegame == 1 || choosegame == 2 || choosegame == 3)//if-else serves as the input validation
    {
	
    //switch statement used to call functions for game selection
    switch ( choosegame ) {
        case 1:
	cout << endl << endl;
            playGame();//function for game 1
    }
    switch ( choosegame ) {
        case 2:
	cout << endl << endl;
            playGameTwo();//function for game 2
    }

    switch ( choosegame ) {
        case 3:
	cout << endl << endl;
            playGameThree();//function for game 3
    }
    }
    else
    {
    cout << endl << endl << "Your game selection was not valid!!" << endl;
	cout <<	"Please launch the game again, and enter number 1, 2 or 3.";
	continue;
    }
    cout << endl << endl << endl << "Enter S to select a different game, "//play different game or quit options 
         << "any other character ends." << endl;
    cin >> ans;

} while ('S' == ans || 's' == ans);
    return 0;//end of program
}
