//Zach Singleton
//1/26/2014
//Project 2: 2-player Word Guessing Game
//Inputs: Player 1's Secret Word, Player 2's guesses
//Outputs: Whether or not Player can guess the word after a fixed numbr of tries
#include <iostream> //#Include tells compiler what functionality I'll use
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;// whenever the computer comes across cout, cin, etc. it will read it as std::cout, std::cin, etc.

int letterFill (char, string, string&); //function definition for strings with referencing

int main ()//function definition and start of block of code
{
string name;//declaration of string
char letter;//declaration of character
char ans;
const int MAX_TRIES=5; //declaration of constant integer
string hiddenword;
string word;
vector<char> v;//creation of vector without any elements
vector<char> b;

do//beginning of loop
{
int num_of_wrong_guesses=0;
//Introduction and secret word selection.

cout << "Welcome to the 2-player word guessing game!" << endl;//game introduction
cout << "\nPlayer 2 please look away from the screen"
<< "\nPlayer 1 please enter any word: " << endl;
cin >> hiddenword;//player 1's entry
bool isAlphabetic = true;//apha check to detect whether proper characters are being used
for (unsigned i = 0; i < hiddenword.size(); ++i)
    if (!isalpha(hiddenword[i]))
    {
        isAlphabetic = false;

	cout << "\nPlayer 1, Your entry was not alphabetic!!" << endl;
	cout << "\nPlease launch the game again and make a fully alphabetic entry." << endl;
        return 0;
    }//forces you to start the game over if you do not use alphabetic characters
word=hiddenword;

// Initialize the secret word with the * character.
string unknown(word.length(),'*');

// welcome the user
cout << "\n\nPlayer 2, it is now your turn to guess the word!";
cout << "\n\nEach letter is represented by a star.";
cout << "\n\nYou should type only one letter in per guess";
cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

// Loop until the guesses are used up
while (num_of_wrong_guesses < MAX_TRIES)
{
cout << "\n\n" << unknown;
if (v.size()>0)//if you have made any entries, this informs the program, and it let's the user know which letters they've entered
{
cout << "\n\nYou have used the following letters: " << endl;
for (int i=0; i < v.size(); i++) 
cout << v[i] << endl;//we display content of the vector to show you what letters you have entered
}
cout << "\n\nGuess a letter: ";
cin >> letter;


// Fill secret word with letter if the guess is correct,
// otherwise increment the number of wrong guesses.
if (letterFill(letter, word, unknown)==0)
{
cout << endl << "Sorry, the entry is not in the word. Try again!" << endl;//lets user know if entry was not in the word
num_of_wrong_guesses++;
v.push_back (letter);//adds player 2's guess to vector v
}
else
{
cout << endl << "You found a letter! Isn't that exciting!" << endl;;//lets user know if entry was in the word
v.push_back (letter);
b.push_back (letter);//adds player 2's guess to vector b if it was found in the word selected by player 1
}

// Tell user how many guesses has left.
cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
cout << " guesses left." << endl;
// Check if user guessed the word.
if (word==unknown)
{
cout << word << endl;
cout << "Yeah! You got it!";
break;
}

}
if(num_of_wrong_guesses == MAX_TRIES)//if user runs out of tries, here we tell them how they performed and ask if they want to play again
{
cout << "\nSorry, you lose. However, you found the following correct letters" << endl;
for (int j=0; j < b.size(); j++) // this line and the next line define j and tell player 1 which characters they selected correctly despite losing
cout << b[j] << endl;
cout << "The word was : " << word << endl;}
cout << "enter Y or y to repeat, " 
         << "any other character ends." << endl;
    cin >> ans;

} while ('Y' == ans || 'y' == ans);
return 0;
}

/* Take a one character guess and the secret word, and fill in the
unfinished guessword. Returns number of characters matched.
Also, returns zero if the character is already guessed. */

int letterFill (char guess, string secretword, string &guessword)
{
int i;
int matches=0;
int len=secretword.length();
for (i = 0; i< len; i++)
{
// Did we already match this letter in a previous guess?
if (guess == guessword[i])
return 0;

// Is the guess in the secret word?
if (guess == secretword[i])
{
guessword[i] = guess;
matches++;
cout << matches++ << endl;
}
}
return matches;
}//end of code

