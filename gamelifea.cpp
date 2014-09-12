#include <iostream>
#include <cstdlib>
#include <ctime>
#define W 80 //Define vertical height
#define H 20 //Define horizontal width

using namespace std;

void print(bool table[H][W]) //Prints out a table
{

  for (int i = 0; i < H; i++)
  {
      for (int j = 0; j < W; j++)
      {
          if (table[i][j]) cout << " ";
          else cout <<"+";
      }
      cout << endl;
  }
}

void wipe(bool table[H][W]) //Kills each cell in the table
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         table[i][j] = 0;
     }
 }
}

void calculate(bool tableY[H][W], bool tableZ[H][W])//count number of closefriends and apply rules
{
  unsigned int closefriends;
  for (int i = 0; i < H; i++)
  {
      for (int j = 0; j < W; j++)
      {
          closefriends = 0;
            //Begin counting number of closefriends:
          //top left
           if (j != 0 && i != 0)
               if (tableY[i-1][j-1] == 1) closefriends += 1;
          //top
           if (i != 0)
               if (tableY[i-1][j] == 1) closefriends += 1;
          //top right
           if (j != W - 1 && i != 0)
               if (tableY[i-1][j+1] == 1) closefriends += 1;
          //left
           if (j != 0)
               if (tableY[i][j-1] == 1) closefriends += 1;
          //right
           if (j != W-1)
               if (tableY[i][j+1] == 1) closefriends += 1;
          //bottom left
           if (j != 0 && i != H - 1)
               if (tableY[i+1][j-1] == 1) closefriends += 1;
          //bottom
           if (i != H - 1)
               if (tableY[i+1][j] == 1) closefriends += 1;
          //bottom right
           if (j != W-1 && i != H - 1)
               if (tableY[i+1][j+1] == 1) closefriends += 1;

            //Apply rules to the cell:
          if (tableY[i][j] == 1 && closefriends < 2)
           tableZ[i][j] = 0;
       else if (tableY[i][j] == 1 && closefriends > 3)
           tableZ[i][j] = 0;
       else if (tableY[i][j] == 1 && (closefriends == 2 || closefriends == 3))
           tableZ[i][j] = 1;
       else if (tableY[i][j] == 0 && closefriends == 3)
           tableZ[i][j] = 1;

   	}
   }
  for (int i = 0; i < H; i++)
 	{
    for (int j = 0; j < W; j++)
    {
      tableY[i][j] = tableZ[i][j];
    }
  }
}

//Play the Game of Life Funciton
void playGOL()
{
bool grid[H][W], grid2[H][W];
bool validinput = false;
char ans, response;
int i, n, choosepatt, j;
int a, b, maxa=80, mina=0, maxb=20, minb=0;

	do
	{
newpattern:


   wipe(grid);
   wipe(grid2);

    cout << "Please select your Game of Life Pattern" << endl;//displays game selection options to user
    cout << "Enter 1 to use Acorn Pattern" << endl;
    cout << "Enter 2 to use Random Pattern" << endl;
    cout << "Enter 3 to use Anya Pattern" << endl;
   
    cin >> choosepatt;//game selection entry
    cin.ignore();

   if (choosepatt == 1 || choosepatt == 2 || choosepatt == 3)//if statement serves as the input validation
    {
	validinput = true;
	
    //switch statement used to call functions for game selection
    switch ( choosepatt ) {
        case 1:
	cout << endl << endl;
            goto acorn;//goto game 1
    }
    switch ( choosepatt ) {
        case 2:
	cout << endl << endl;
           goto random;//goto game 2
    }

    switch ( choosepatt ) {
        case 3:
	cout << endl << endl;
           goto anya;//goto game 3
    }

    // acorn pattern
   acorn:
   {
   grid[14][62]=true;
   grid[14][63]=true;
   grid[14][66]=true;
   grid[14][67]=true;
   grid[14][68]=true;
   grid[12][63]=true;
   grid[13][65]=true;
   print(grid);

   goto generations;
   }
   
   // random pattern
   random:
   {
   srand(time(0));
   for (j = 0; j < 200; j++)
   {	   
   a = (rand( ) % H);
   b = (rand( ) % W);
   
   grid[a][b]=true;
   }
   print(grid);
   goto generations;
   }
   // anya pattern
    anya:
   {
   grid[17][48]=true;
   grid[16][49]=true;
   grid[15][50]=true;
   grid[14][51]=true;
   grid[14][52]=true;
   grid[14][53]=true;
   grid[14][54]=true;
   print(grid);

   goto generations;
   }
   }
   else
	{
	cout << endl;
	cout << "your entry is not accepted. enter a valid integer." << endl;
	cout <<endl;
	cout <<endl;
	}
   }while (!validinput);

//Additional Generations Loop

generations:

do
{

cout << "Enter the number of generations of life you want to create." << endl;
cin >> n;

	for(i=0;i<=n-1;i++)
	{
   	calculate(grid, grid2);
   	print(grid2);
	cout << endl;
	}
	cout << "Here are the next " << n << " generations of life." << endl;

	cout << endl;
	cout << "enter y to create more generations of life. "
        << "any other character exits." << endl;
   	cin >> ans;
	

} while ('Y' == ans || 'y' == ans);

 cout << "enter n to select a new pattern. any other character ends." << endl;
    cin >> response;
    if (response == 'n' || response == 'N')
    {
            goto newpattern;//change pattern
    	}
}

//Main function
int main()
{

   	char showrules;
   	char ans;

	cout << endl;

	//Game of Life Menu
	cout << left << "Welcome to Zach's Game of Life, Love and Laughter." << endl << endl;
    	cout << "We assume you know the Rules of Life, so let's get it on!" << endl;
	cout << endl;

	//Option to read the game rules or play w/o them
	cout << "But... in case you want to read the boring rules, enter r. \nIf not, any other entry continues the game." << endl;
    	cin >> showrules;
	cout << endl;
	cout << endl;

    if ('r' == showrules || 'R' == showrules)
    {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << "  The Rules of Life  " << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Any live cell with fewer than two live neighbors dies, as if by loneliness." << endl;
        cout << "2. Any live cell with more than three live neighbors dies, as if by \novercrowding." << endl;
        cout << "3. Any live cell with two or three live neighbors lives, unchanged." << endl;
        cout << "4. Any dead cell with exactly three live neighbors comes to life." << endl << endl;

        cout << endl;

   	cout << "enter C or c to continue game "<< endl; //move on from rules and goto play;
        cin >> ans;
	cout << endl;

    	if('C' == ans || 'c' == ans)
    	{
    	playGOL();//Call to playGOL if you read the rules
	return 0;
   	}
   }

   else
   {

	playGOL();//Call to playGOL if you didn't read the rules
	return 0;

   }

return 0;
}

