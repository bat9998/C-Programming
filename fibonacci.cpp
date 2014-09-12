// Recursive Fibonacci Program

#include <iostream>
#include <cmath>

// This function computes and discards many of the Fibonacci numbers 

unsigned long Fib1( int n )
{
  if (n == 0 || n == 1)
    return 1;

  return Fib1( n - 1 ) + Fib1( n - 2 );
}

int main()// start of main function
{
  using namespace std;
  char ans;
  int N;
  do
  {  
    cout << "I will display Fibonacci numbers 0-N." << endl;
    cout << "Enter a limit, please. Be patient if your number is large! " << endl;
    cin >> N; 
    for ( int i = 0; i < N; i++ )// Definition of i
    cout  << Fib1(i) << endl;
    cout  << "Y/y to continue, anything else quits" << endl;
    cin >> ans;
  } while ( 'Y' == ans || 'y' == ans );
}

