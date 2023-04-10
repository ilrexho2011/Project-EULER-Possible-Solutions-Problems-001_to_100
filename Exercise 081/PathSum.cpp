/*   Path sum: two ways
 
Problem 81
In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, 
by only moving to the right and down, is indicated in bold red and is equal to 2427.
 
Find the minimal path sum from the top left to the bottom right by only moving right and down 
in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.

Answer:  427337   */

#include <iostream>
#include <fstream>
using std::cout;
using std::ifstream;

const int Mmax = 80;
long M[Mmax][Mmax];

void load_mat(const char* fname)
{
	ifstream ifs(fname);
	for(int i = 0; i < Mmax; i++)
		for(int j = 0; j < Mmax; j++)
			ifs >> M[i][j];
}

long task81(long N)
{
	for(int i = 1; i < N; i++)
	{
		M[i][0]=M[i][0]+M[i-1][0];
		M[0][i]=M[0][i]+M[0][i-1];
	}	
	for(int i=1; i<N; i++)
		for(int j=1; j<N; j++)
			M[i][j]=M[i][j]+ std::min(M[i-1][j],M[i][j-1]);
	
	return M[N-1][N-1];
}

int main()
{
	load_mat("matrix.txt");
	cout << "\ntask 81 answer: " << task81(80);
	return 0;
}