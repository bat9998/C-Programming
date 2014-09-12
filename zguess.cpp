//Makeup phraseguess game for project 3
//By Zach Singleton
//Date: 3/16/2013
//Advice on phraseguess from Brittany Tamarkin and Wayne Cordey

/*14. Generally uses functional decomposition to reduce how large a single section of 
 * code is or  to make the plan or algorithm obvious for your program,*/

#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Function for storing hidden word and creating an attempted guess string
string CreateWord(string array[]);
string UnderscoreFill(string str);
//This function performs the alpha check
bool IsValid(string);
//Function for checking and updating available letters
string LetterReset(char);
//Function updates and resets words that are guessed
string ResetGuess(char);
//Lowercase function
string LowerTheCase(string);
//Next or new round function
void StartRound();
//Function for getting letter from user entry
void LetterFetch();
//Function for resetting most global variables
void GlobalVarsUpdate();

//Arrays filled with the library of words that will be used in phrase guess
string adjectives[10]= {"hungry", "tall", "luxurious", "outstanding", "quiet", "busty", "incredible",
                   "depressing", "perplexed", "beautiful"};
string nouns[10]= {"computer", "cloud", "jordan", "piano", "mountain", "brick", "ocean", "tiger",
                   "whale", "jabbawockee"};
string verbs[10]= {"walks", "builds", "forgets", "thinks", "professes", "speaks", "types", "jumps",
                   "believes", "designs"};

string hidden_word="a word";
string letters_available="abcdefghijklmnopqrstuvwxyz";
string attempted_guess="";
int guesses= 10;
char letter=' ';

int pguess()
{

 char again = 'y';

 while (again!='n')
 {
   string adjective = CreateWord(adjectives);
   string noun = CreateWord(nouns);
   string verb = CreateWord(verbs);

   //random phrase arrays
   string phrase[3]= {CreateWord(adjectives), CreateWord(nouns), CreateWord(verbs)};
   string underscore_phrase[3] ={UnderscoreFill(adjective), UnderscoreFill(noun), UnderscoreFill(verb)};

   cout << "Welcome to Zach's phrase guessing game!! \n"
        << "The phrase that you will be guessing is as follows:\n";
   cout << underscore_phrase[0] << " " << underscore_phrase[1] << " " << underscore_phrase[2] << endl;

   //looping between words is initiated with this for loop
   for (int i=0; i < 3; i++)
   {
     hidden_word = phrase[i];
     attempted_guess = underscore_phrase[i];
     
     while (attempted_guess!=hidden_word && guesses > 0)
     {
       StartRound();
       ResetGuess(letter);
     }
     //Critiria for winning and losing occurs in the next few blocks of code here
     if (attempted_guess== hidden_word)
     {
       cout << "You got it right!! The hidden word was: "<< "\"" << hidden_word << "\"" << endl;
      
       if (i==0){
         cout << "We have reset your guesses. Let's keep it moving." << endl;
         cout << "The Phrase... \"" << phrase[0] << " " << underscore_phrase[1] << " " << underscore_phrase[2] << "\"" << endl;
       }
       else if (i==1){
         cout << "We have reset your guesses. Let's keep it moving." << endl;
         cout << "The Phrase... \"" << phrase[0] << " " << phrase[1] << " " << underscore_phrase[2] << "\"" << endl;
       }

       GlobalVarsUpdate();
     }
     
     else if (guesses== 0)
     {
       cout << "You're now out of guesses! ";
       cout << "Maybe next time! The correct phrase was: "<< "\""  << phrase[0] << " " << phrase[1] << " " << phrase[2] << "\"" << endl;
       break;
     }
   }

   
   if (guesses!=0)
   {
     cout << "You got it! You're on fire, OMG! The hidden phrase was: "<< "\""  << phrase[0] << " " << phrase[1] << " " << phrase[2] << "\"" << endl;
   }

   cout << "Hit any key to play phrase guess again, or 'n' to quit" << endl;
   cin >> again;
   again = tolower(again);
   GlobalVarsUpdate();

   cin.ignore();
 }


 return 0;
}

//Function for resetting other global variables
void GlobalVarsUpdate()
{
 hidden_word="a word";
 letters_available="abcdefghijklmnopqrstuvwxyz";
 attempted_guess="";
 guesses= 10;
 letter=' ';
}

//Valid word check
string CreateWord(string array[])
{
 srand (time(NULL));
 int random_int = rand() %10;
 string hidden_word = array[random_int];
 return hidden_word;
}

//string underscore fill
string UnderscoreFill(string str)
{
 string underscores= "";
 for (int i=0; i< str.length(); i++)
 {
   underscores.append("_");
 }
 return underscores;
}


//isaplha to validate alpha entry
bool IsValid(string word)
{
 bool valid= true;
 for (int i=0; i < word.length(); i++)
 {

   valid= isalpha(word.at(i));
   if (valid==false)
   {
     return valid;
   }
     
 }
 return valid;
}

//available letter update
string LetterReset(char letter)
{
 if (letters_available.find(letter)==string::npos)
 {
   return letters_available;
 }
 else
 {
   letters_available.erase(letters_available.find(letter),1);
   return letters_available;
 }
}


string ResetGuess(char letter)
{

 for (int i=0; i < hidden_word.length(); i++)
 {
   if (hidden_word.at(i)== letter)
   {

     attempted_guess.replace(i,1,hidden_word.substr(i,1));
   }
  
 }

 return attempted_guess;
}


string LowerTheCase(string str)
{
 for (int i=0; i<str.length(); i++)
 {
   hidden_word[i]= tolower(hidden_word[i]);
 }
 return hidden_word;
}

//indicate number of times letter appears in word
int GetOccurrence(char letter)
{
 int trial=0;
 for (int i=0; i<hidden_word.length(); i++)
 {
   if (hidden_word.at(i) == letter)
   {
     trial++;
   }
 }
 return trial;
}


void LetterFetch()
{
 cout << "Please guess a letter (any letter in the alphabet): ";
 cin >> letter;
 letter= tolower(letter);
 while (isalpha(letter)==false)
 {
   cout << "You made an invalid entry!\n"
        << "Please try again, and choose a different letter: ";
   cin >> letter;
   letter= tolower(letter);
 }
}

//start round or next round for user
void StartRound()
{
 cout << endl;
 cout << "Here's how you're progressing with the current word: " << attempted_guess << endl;
 cout << "Letters available to you: " << LetterReset(letter)<< endl;
 cout << endl;
 cout << "You have "<< guesses << " attempts remaining" << endl;
 LetterFetch();
 while (letters_available.find(letter)==string::npos)
 {
   cout << endl;
   cout << "Shame on you! You already used that letter." << endl;
   LetterFetch();
 }
 cout << string(20, '\n');
 cout << "That letter "<< "\""<< letter << "\"" << " is in the word :" << GetOccurrence(letter) << " times" <<endl;
 if (GetOccurrence(letter)==0)
 {
   guesses--;
 }

}
