#include <iostream>
#include "sudokuSolver.h"

using namespace std;

int main() {
    
    /*
     int table[D][D]=
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
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 1,2,3, 4,5,0},
        
        {0,0,0, 0,6,7, 8,9,0},
        {0,0,0, 8,0,1, 2,3,4},
        {0,0,0, 2,3,0, 5,0,7},
        
        {0,0,0, 0,7,8, 9,1,2},
        {0,0,0, 9,0,2, 3,0,5},
        {0,0,0, 3,4,5, 6,7,8}
    };
    
    cout<<"ORIGINAL TABLE"<<endl;
    printTable(table);
    if(intuitiveSolve(table))
    {
        cout<<"SUCCESSFUL SIMPLE SOLVE"<<endl;
        printTable(table);
    }
    else
    {
        cout<<"UNSUCCESSFUL SIMPLE SOLVE"<<endl;
        printTable(table);
        if(backTrackSolve(table))
        {
            cout<<"SOLVED"<<endl;
            printTable(table);
        }
        else
        {
            cout<<"UNSOLVABLE"<<endl;
            printTable(table);
        }
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

int blankCounter(int table[D][D])
{
    int blanks=0;
    for(int r=0;r<D;r++)
        for(int c=0;c<D;c++)
            if(table[r][c]==BLANK)
                blanks++;
    return blanks;
}

bool intuitiveSolve(int table[D][D])
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

bool backTrackSolve(int table[D][D])
{
    if(blankCounter(table)==0)
        return true;
    
    int tableCopy[D][D];
    memcpy(tableCopy, table, sizeof(int)*D*D);
    if(intuitiveSolve(tableCopy))
    {
        memcpy(table, tableCopy, sizeof(int)*D*D);
        return true;
    }
    
    for(int r=0;r<D;r++)
    {
        for(int c=0;c<D;c++)
        {
            if(table[r][c]==BLANK)
            {
                for(int n=1;n<=9;n++)
                {
                    if(isValid(table, c, r, n))
                    {
                        table[r][c]=n;
                        if(backTrackSolve(table))
                            return true;
                        table[r][c]=BLANK;
                    }
                }
            }
        }
    }
    return false;
}
