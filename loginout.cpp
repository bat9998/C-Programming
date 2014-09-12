
#include <iostream>
#include <string>
#include <vector>

using namespace::std;

/*24. Defines and uses at least one class to create and use an object,*/

class playerLog//use of class

/*18. Uses at least one string variable (std::string or c-style string),*/
{
 private:
 vector<string> players;
 public:
 string skill;

 /*32. Defines classes covering the use of a default constructor, a copy constructor, and a 
destructor (you have to make these to prove that you understand them!),*/
 playerLog();//default constructor
 //lookup name and return index of name
 int find(string playername){
 for (int i= 0; i< players.size(); i++){
 if (players.at(i) == playername ){
 return i;
 }
 }
 //return -1 if record not found
 return -1;
 }
 /*32. Defines classes covering the use of a default constructor, a copy constructor, and a 
destructor (you have to make these to prove that you understand them!),*/
 playerLog( const playerLog &obj);//copy constructor

 //show names in the system
 void show(){
 cout << "\"";
 for (int i = 0; i< players.size(); i++){
 cout << players.at(i);
 if (i< players.size()-1){
 cout << ", ";
 }
 }
 cout << "\"" << endl;
 }
 //add name to guest log
 void add(string playername){
 players.push_back(playername);
 }
//remove name from guest log
 bool remove(string playername){
 if (find(playername)==-1){
 return false;
 }
 else {
 players.erase(players.begin()+find(playername));
 }
 }


};

/*32. Defines classes covering the use of a default constructor, a copy constructor, and a 
destructor (you have to make these to prove that you understand them!),*/
playerLog::playerLog()
{

}


int signin() {

 playerLog playerLog1; //Declaration of object of class playerLog

 string level;
 
 playerLog1.skill = level; //Use of object of class playerLog part 1

 //create new guest log
 playerLog player_log = playerLog();

 string input = " ";

 while (input!= "c"){
 cout << "enter 'l' to Login to Battleship\n";
 cout << "      " << "'s' to show current player\n";
 cout << "      " << "'r' to logout player\n";
 cout << "       " << "or 'c' to continue to Battleship\n";
 getline(cin, level);//Use of object of class playerLog part 2
 input = level;
 //if input is s
 if (input =="s"){
 cout << "players: ";
 player_log.show();
 }
 //if input is l
 else if(input =="l"){
 string playername;
 while (playername!= "b")
 {
 cout << "Enter the name you want to Login, or select 'b' to go back to menu\n";
 cout << "name:";
 getline(cin, playername);
 if (playername != "b"){
 player_log.add(playername);
 }
 }
 }
 //if input is r
 else if (input =="r"){
 string playername;
 while (playername!= "b")
 {
 cout << "Enter the name you want to Logout, or select 'b' to back to menu\n";
 cout << "name:";
 getline(cin, playername);
 if (playername != "b"){
 //checks to see if name is in the guest log
 if (player_log.find(playername)==-1){
 cout << "that name is not logged in to Battleship.\n";
 }
 else {
 player_log.remove(playername);
 }
 }
 }
 }
 else {
 if (input!= "c"){
 cout << "Your entry was invalid. Try again.\n";
 }
 }
 }

 return 0;
}
