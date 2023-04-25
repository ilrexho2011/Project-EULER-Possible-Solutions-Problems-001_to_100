/*   Su Doku

Problem 96 Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear, but credit must be attributed to Leonhard Euler who invented a similar, and much more difficult, puzzle idea called Latin Squares. The objective of Su Doku puzzles, however, is to replace the blanks (or zeros) in a 9 by 9 grid in such that each row, column, and 3 by 3 box contains each of the digits 1 to 9. Below is an example of a typical starting puzzle grid and its solution grid.

image
image

A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ "guess and test" methods in order to eliminate options (there is much contested opinion over this). The complexity of the search determines the difficulty of the puzzle; the example above is considered easy because it can be solved by straight forward direct deduction.

The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'), contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions (the first puzzle in the file is the example above).

By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution grid; for example, 483 is the 3-digit number found in the top left corner of the solution grid above.

Pergjigje: 24702   */


#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl; 
using std::find;

const int DIM=9;       //!< Dimension of a sudoku square
const int SMALLDIM=3;  //!< Dimension of a small square


/**
 * Prints the current puzzle.
 * @param puzzle The puzzle to print.
 */ 
void printSudoku(const vector<int>& puzzle)
{
    cout << "------------------" << endl;
    for(int i=0;i<DIM;i++)
    {
        for(int j=0;j<DIM;j++)
        {
            cout << puzzle[i*DIM+j];
            if((j+1)%3==0)
            {
                cout << "|";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        if((i+1)%3==0)
        {
            cout << "------------------" << endl;
        }

    }
    cout << endl;
}

/**
 * Makes an educated guess on the next candidates for slot.
 * @param puzzle The puzzle which we are processing
 * @param guess And output parameter which will contain possible values, when this is empty it means no moves are possible.
 * @param row The row of the current position
 * @param col The column of the current position.
 */
inline void makeEducatedGuess(const vector<int>& puzzle, vector<int>& guess, int row, int col)
{
    vector<bool> valid(10,true);

    // Search horizontal
    for(int i=0;i<DIM;i++)
    {
        valid[puzzle[row*DIM+i]]=false;
    }

    // Search vertical
    for(int i=0;i<DIM;i++)
    {
        valid[puzzle[i*DIM+col]]=false;
    }

    // Search within current square
    for(int i=(row/SMALLDIM)*SMALLDIM;i<(1+row/SMALLDIM)*(SMALLDIM);i++)
    {
        for(int j=(col/SMALLDIM)*SMALLDIM;j<(1+col/SMALLDIM)*(SMALLDIM);j++)
        {
            valid[puzzle[i*DIM+j]]=false;
        }
    }

    for(int i=1;i<10;i++)
    {
        if(valid[i])
        {
            guess.push_back(i);
        }
    }

}

/**
 * Recursive function which solves a sudoku puzzle.
 * @param puzzle The puzzle to solve, a location which holds zero shall be searched for, then possible candidates will be searched for and all guess will be passed to a next call of solveSudoku. 
 * @param result Output parameter, will contain the solution.
 * @return false when no solution was found, true when the result parameter contains the solution.
 */
bool solveSudoku(vector<int> puzzle, vector<int>& result)
{
    // Uncomment to show individual steps
    //printSudoku(puzzle);

    // Find the next element to fill in 
    vector<int>::iterator it = find(puzzle.begin(),puzzle.end(),0);
    if(it != puzzle.end())
    {
        int row = (it - puzzle.begin())/DIM;
        int col = (it - puzzle.begin())%DIM;
        vector<int> guess;

        makeEducatedGuess(puzzle,guess,row,col);

        // No moves left ?
        if(guess.size()==0)
        {
            return false;
        }
        
        // Now try all move
        for(vector<int>::iterator it=guess.begin();it != guess.end();it++)
        {
            puzzle[row*DIM+col]=*it;
            if(solveSudoku(puzzle,result))
            {
                return true;
            }            
        }
        return false;
    }
    else
    {
        // Copy the result
        result=vector<int>(puzzle);
        return true;
    }

}


int main(int argc, char **argv)
{
    vector<int> puzzle,result;
    char tmp;
    for(int i=0;i<DIM;i++)
    {
        for(int j=0;j<DIM;j++)
        {
            scanf("%c", &tmp);
            puzzle.push_back(tmp-'0');
        }  
        scanf("\n");
    }
    
    //printSudoku(puzzle);
    if(solveSudoku(puzzle,result))
    {
        printSudoku(result);
        return 0;
    }
    else
    {
        std::cout << "Puzzle cannot be solved" << endl;
        return 1;
    }
}