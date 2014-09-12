// DMA of 2D array in C++
#include<iostream>
#include<iomanip>
#include <cstdlib>
#include <ctime>

/*20. Uses at least one multi-dimensional array,
21. Uses at least one dynamically declared array,*/
using namespace std;
int matrix()
{
    int x = 3, y = 3;

    int **ptr = new int *[x];

    for(int i = 0; i<y; i++)
    {
        ptr[i] = new int[y];
    }
    srand(time(0));

    for(int j = 0; j<x; j++)
    {
        for(int k = 0; k<y; k++)
        {
            int a = rand()%10;
            ptr[j][k] = a;
            cout<<ptr[j][k]<<" ";
        }
        cout<<endl;
    }
}

