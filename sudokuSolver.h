#ifndef sudokuSolver_h
#define sudokuSolver_h

#define D 9 //square dimension of table
#define BLANK 0

bool isRowConflicting(int [D][D], int, int);
bool isColumnConflicting(int [D][D], int, int);
bool isBoxConflicting(int [D][D], int, int, int);
bool isValid(int [D][D], int, int, int);
void printTable(int [D][D]);
bool intuitiveSolve(int [D][D]);
int blankCounter(int [D][D]);
bool backTrackSolve(int [D][D]);

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

#endif
