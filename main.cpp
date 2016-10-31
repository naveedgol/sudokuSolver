#include <iostream>

using namespace std;

void printTable(int [9][9]);
bool rowConflict(int [9][9], int, int);
bool columnConflict(int [9][9], int, int);

int main() {
    
    int table[9][9]=
    {
        {0,1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7,8},
        {0,1,2,3,4,5,6,7,8}
    };
    return 0;
}

void printTable(int table[9][9])
{
    for(int r=0;r<9;r++)
    {
        for(int c=0;c<9;c++)
        {
            if(c==3 or c==6)
                cout<<"|";
            cout<<" "<<table[r][c]<<" ";
        }
        cout<<endl;
        if(r==2 or r==5)
            cout<<" -------- --------- --------"<<endl;
    }
}

bool rowConflict(int table[9][9], int row, int number)
{
    for(int c=0;c<9;c++)
    {
        if(table[row][c]==number)
            return false;
    }
    return true;
}

bool columnConflict(int table[9][9], int column, int number)
{
    for(int r=0;r<9;r++)
    {
        if(table[r][column]==number)
            return false;
    }
    return true;
}


