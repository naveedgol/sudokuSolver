#include <iostream>

using namespace std;

#define BLANK 0
#define D 9 //square dimension of table

void printTable(int [D][D]);
bool isRowConflicting(int [D][D], int, int);
bool isColumnConflicting(int [D][D], int, int);
bool isBoxConflicting(int [D][D], int, int, int);
bool solveTable(int [D][D]);
int blankCounter(int [D][D]);
bool isValid(int [D][D], int, int, int);

int main() {
    
    /*
     int table[9][9]=
     {
     {1,2,3, 4,5,6, 7,8,9},
     {4,5,6, 7,8,9, 1,2,3},
     {7,8,9, 1,2,3, 4,5,6},
     
     {2,3,4, 5,6,7, 8,9,1},
     {5,6,7, 8,9,1, 2,3,4},
     {8,9,1, 2,3,4, 5,6,7},
     
     {3,4,5, 6,7,8, 9,1,2},
     {6,7,8, 9,1,2, 3,4,5},
     {9,1,2, 3,4,5, 6,7,8}
     };*/
    
    int table[D][D]=
    {
        {0,2,3, 4,5,6, 0,8,9},
        {4,0,6, 7,8,9, 0,2,3},
        {7,8,0, 1,2,3, 0,5,0},
        
        {2,3,4, 0,6,7, 0,9,0},
        {5,6,7, 8,0,1, 0,3,0},
        {8,9,1, 2,3,0, 0,0,0},
        
        {3,4,5, 6,7,8, 0,0,0},
        {6,7,8, 9,1,2, 0,0,0},
        {9,1,2, 3,4,5, 0,0,0}
    };
    
    cout<<"ORIGINAL TABLE"<<endl;
    printTable(table);
    if(solveTable(table))
    {
        cout<<"SUCCESSFUL SIMPLE SOLVE"<<endl;
        printTable(table);
    }
    else
    {
        cout<<"UNSUCCESSFUL SIMPLE SOLVE"<<endl;
        printTable(table);
    }
    return 0;
}

void printTable(int table[D][D])
{
    cout<<endl;
    for(int r=0;r<D;r++)
    {
        for(int c=0;c<D;c++)
        {
            if(c==3 or c==6)
                cout<<"|";
            cout<<" "<<table[r][c]<<" ";
        }
        cout<<endl;
        if(r==2 or r==5)
            cout<<" -------- --------- --------"<<endl;
    }
    cout<<endl;
}

bool isRowConflicting(int table[D][D], int row, int number)
{
    for(int c=0;c<D;c++)
    {
        if(table[row][c]==number)
            return true;
    }
    return false;
}

bool isColumnConflicting(int table[D][D], int column, int number)
{
    for(int r=0;r<D;r++)
    {
        if(table[r][column]==number)
            return true;
    }
    return false;
}

bool isBoxConflicting(int table[D][D], int column, int row, int number)
{
    int boxRow=(row)/3; //0,1,2 -> 0; 3,4,5 -> 1; 6,7,8 ->2;
    int boxColumn=(column)/3;
    for(int r=boxRow*3;r<boxRow*3+3;r++)
    {
        for(int c=boxColumn*3;c<boxColumn*3+3;c++)
        {
            if(table[r][c]==number)
                return true;
        }
    }
    return false;
}

bool isValid(int table[D][D], int column, int row, int number)
{
    if(isRowConflicting(table, row, number) || isColumnConflicting(table, column, number) || isBoxConflicting(table, column, row, number))
        return false;
    return true;
}

int blankCounter(int table[D][D])
{
    int blanks=0;
    for(int r=0;r<D;r++)
        for(int c=0;c<D;c++)
            if(table[r][c]==BLANK)
                blanks++;
    return blanks;
}

bool solveTable(int table[D][D])
{
    bool ineffectiveCycle=false;
    int blanks=blankCounter(table);
    while(blanks>0)
    {
        if(ineffectiveCycle)
            return false;
        for(int r=0;r<D;r++)
        {
            for(int c=0;c<D;c++)
            {
                if(table[r][c]==0)
                {
                    int possibilities=0;
                    for(int n=1;n<=9;n++)
                    {
                        if(isValid(table,c,r,n))
                        {
                            if(possibilities==0)
                            {
                                table[r][c]=n;
                                possibilities++;
                                blanks--;
                                ineffectiveCycle=false;
                            }
                            else
                            {
                                table[r][c]=BLANK;
                                blanks++;
                                ineffectiveCycle=true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}