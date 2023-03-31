//	Coded triangle numbers
/*  The nth term of the sequence of triangle numbers is given by, 
tn = ½n(n+1); so the first ten triangle numbers are:
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to 
its alphabetical position and adding these values we form a word value. 
For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. 
If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), 
a 16K text file containing nearly two-thousand common English words, 
how many are triangle words?  Pergjigja e sakte eshte: 162  */

#include <stdio.h>
#include <stdlib.h>
int tri( int n )
{
    return n*(n+1) / 2;
}

int p42()
{
    ifstream in( "words.txt" );
    string s;
    in >> s;
    in.close();

    int block[200] = {0};
    vector<int> triangle;
    int t = 1;
    for( int i = 2; t < 200; ++i )
    {
        triangle.push_back( t );
        t = tri(i);
    }

    int m = 0;
    int a = 0;
    for( int i = 1; i < s.size(); ++i )
    {
        if( s[i] == '"' )
        {
            i += 2;
            ++(block[a]);
            a = 0;
        }
        else
        {
            a += s[i] - 'A' + 1;
        }
    }

    int sum = 0;
    for( int i = 0; i < triangle.size(); ++i )
    {
        sum += block[ triangle[i] ];
    }
    cout << sum;
}
