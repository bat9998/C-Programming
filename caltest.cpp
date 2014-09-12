#include <iostream> //#Include tells compiler what functionality I'll use
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//creating my own namespace
namespace duration1{
   int length = 4;
}
/*28. Uses its own namespace (use your engr username or some fun name for this),*/
using namespace duration1;

/*17. Demonstrates function overloading,*/

	double calcalc (double h, double t)
	{
		return (h*t);
	}

	int calcalc (int v, int f)
	{
		return (v*f);
	}
	
	//pass by value 
	/*16. Demonstrates the different passing mechanisms (in C++ this means pass by value and pass by reference, 
	 * but you may also choose to show how passing the value of a pointer can allow you to reference the 
	 * memory of values that will live after the function where the pointer is passed by value),*/
	int p=0;
	void numberFunction(int z) {
  	cout << "5 more minutes results in " << z+5+(p*5) << " additional calories lost." << endl;
	p++;
	//using component of namespace duration1
  	if(p<length) {
    	numberFunction(z);
  		}
	
	}
	
	class notvalid{};
/*12. Fulflled by isplha statement below - Demonstrates some form of debugging "tricks" that we have learned throughout the class (print statements, input verification, checks for bad conditions (divide by zero anyone?), asks users for clarification, uses menus to filter user input into an easy to read format (number instead of word or phrase), or any other trick that can help catch, report, or reduce bugs; just be sure to explain why your tricks help reduce bugs)*/
	int getValidEntry(int v, int h)
	{
	{
	
		if (isalpha(v) || isalpha(h))
		cout << "not a valid entry" << endl;
	} 
	throw notvalid(); // Not found
	}

class User{
	protected:
		int activityLevel;
	public:
		void setActivityLevel(int a) {
			activityLevel=a;
		}
};

/*36. Uses inheritance,
37. Uses polymorphism,*/
/*Inheritance and Polymorphism: Because the class developer is derived from the 
class user, here we are showing how it inherits access/use of the attribue "activityLevel"*/

/*24. Defines and uses at least one class to create and use an object,*/
class Developer: public User{
	public:
		void active()
		{	cout << endl;
			cout << "All users resemble a software developer or businessman in terms of activty level." << endl;
		       	cout << endl;	
			cout << "Software developers spend hours gaming online!" << endl; 
			cout << "Acitivy Level: " << activityLevel << "/10" << endl;}

};


class Businessman: public User{
	public:
		void active()
		{	cout << endl;
			cout << "Businessmen only play casual games from time to time." << endl;
			cout << "Acitivy Level: " << activityLevel << "/10" << endl;}

};

int jimmy()
{

	int v=10,f=3,z=0,s=0;
  	double h=20.0,t=1.4;

	cout << "Enter the number of minutes you've been playing battleship." << endl;
	cin >> v;
	h = v;

	/*38. Uses exceptions (does not have to fill the whole huge project with exceptions for all the error handling),--- this is try/catch*/

	try
	{
		int entryIds[] = {v, h}; 
	
		cout << getValidEntry(v, h) << endl; 
	}
	catch(notvalid)
	{
		
		cout << "If you entered an integer value it is valid, " << endl; 
		cout <<	"otherwise your entry is not valid. Please proceed." << endl;
		cout << endl;
		cout << endl;
		
	 
	}


	cout << "You've been playing battleship for " << v << " minutes." << endl;
       	cout << "During that time, you have burned " <<  calcalc (h,t) << " calories if you type slow." << endl;
	s = calcalc (v,f);

	cout << "You have burned " << s << " calories if you type fast." << endl;
	
	cout << endl;
	/*16. Demonstrates the different passing mechanisms (in C++ this means pass by value and pass by reference, but you may also choose to show how passing the value of a pointer can allow you to reference the memory of values that will live after the function where the pointer is passed by value),*/

	/*27. Attempts to use a pointer to an object (This may be new to you, but it is similar to an array or a struct),*/
	numberFunction(s);//pass by value
	cout << endl;
	
	Developer d; //devleoper object created
	Businessman b; //business man object created
	User *user1 = &d; //user1 object created, set equal to address of developer object
	User *user2 = &b;
	user1->setActivityLevel(9);
	user2->setActivityLevel(4);
	d.active();
	b.active();
	
	return 0;
}


