/*   Anagramic squares
 
Problem 98
By replacing each of the letters in the word CARE with 1, 2, 9, and 6 respectively, we form a square number: 1296 = 362. What is remarkable is that, by using the same digital substitutions, the anagram, RACE, also forms a square number: 9216 = 962. We shall call CARE (and RACE) a square anagram word pair and specify further that leading zeroes are not permitted, neither may a different letter have the same digital value as another letter.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, find all the square anagram word pairs (a palindromic word is NOT considered to be an anagram of itself).

What is the largest square number formed by any member of such a pair?

NOTE: All anagrams formed must be contained in the given text file.


Pergjigje:  18769   */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "words.h"

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define EACH(A,p) for(typeof(A.begin()) p=A.begin();p!=A.end();p++)
#define ALL(A) A.begin(), A.end()

typedef vector<string> VS;

#define sz size()
#define pb push_back

string toStr(int n) { ostringstream o; o << n; return o.str();}
int toInt(string s) { istringstream in(s); int n; in >> n; return n;}

bool anag(string a, string b)
{
	sort(ALL(a)); sort(ALL(b));
	return (a==b);
}

set<int> S;

VS getL(string T)
{
	VS R;
	EACH(S,s)
	{
		string N = toStr(*s);
		map<char,char> M, iM;
		if(N.sz != T.sz) continue;
		int f = 1;
		FOR(i,0,N.sz)
			if(M.find(N[i]) == M.end())
			{
				if(iM.find(T[i]) == iM.end())
				{ M[N[i]] = T[i]; iM[T[i]] = N[i];}
				else if(iM[T[i]] != N[i]) { f = 0; break;}
			}
			else if(M[N[i]] != T[i]) { f = 0; break;}
		if(f) R.pb(N);
	}
	return R;
}

int main()
{
	int k;
	for(k=0;word[k]!="x";k++) ;
	FOR(i,1,35000) S.insert(i*i);
	int ma = 0;
	FOR(i,0,k)
		FOR(j,i+1,k) if(anag(word[i],word[j]))
		{
			cout << word[i] << " " << word[j] << endl;
			VS L = getL(word[i]);
			FOR(p,0,L.sz)
			{
				map<char,char> M;
				FOR(q,0,word[i].sz) M[word[i][q]] = L[p][q];
				string N = L[p];
				FOR(q,0,word[j].sz) N[q] = M[word[j][q]];
				if(N[0] == '0') continue;
				cout << L[p] << " " << N;
				int n = toInt(N);
				if(S.find(n) != S.end())
				{
					cout << " good";
					ma >?= max(toInt(L[p]),n);
				}
				cout << endl;
			}
		}
	cout << ma << endl;
	return 0;
}