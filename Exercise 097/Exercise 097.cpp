/*   Large non-Mersenne prime

Problem 97
The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 26972593−1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p−1, have been found which contain more digits.

However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×27830457+1.

Find the last ten digits of this prime number.


Pergjigje:  8739992577   */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
string s="1";
int p=0;
int num;
	for(int i=0;i<7830457;i++)
	{
		p=0;
		for(int j=0;j<s.size();j++)
		{
			num=((int(s[j]-'0')*2)+p)%10;
			p=((int(s[j]-'0')*2)+p)/10;
			if(num==0)
				s[j]='0';
			if(num==1)
				s[j]='1';
			if(num==2)
				s[j]='2';
			if(num==3)
				s[j]='3';
			if(num==4)
				s[j]='4';
			if(num==5)
				s[j]='5';
			if(num==6)
				s[j]='6';
			if(num==7)
				s[j]='7';
			if(num==8)
				s[j]='8';
			if(num==9)
				s[j]='9';
		}
		if(s.size()==10)
			continue;
		while(p)
		{
			num=p%10;
			p/=10;
			if(s.size()==10)
			continue;
			if(num==0)
				s+='0';
			if(num==1)
				s+='1';
			if(num==2)
				s+='2';
			if(num==3)
				s+='3';
			if(num==4)
				s+='4';
			if(num==5)
				s+='5';
			if(num==6)
				s+='6';
			if(num==7)
				s+='7';
			if(num==8)
				s+='8';
			if(num==9)
				s+='9';
		}
	}



p=0;

	for(int j=0;j<s.size();j++)
		{
			num=((int(s[j]-'0')*28433)+p)%10;
				p=((int(s[j]-'0')*28433)+p)/10;
			if(num==0)
				s[j]='0';
			if(num==1)
				s[j]='1';
			if(num==2)
				s[j]='2';
			if(num==3)
				s[j]='3';
			if(num==4)
				s[j]='4';
			if(num==5)
				s[j]='5';
			if(num==6)
				s[j]='6';
			if(num==7)
				s[j]='7';
			if(num==8)
				s[j]='8';
			if(num==9)
				s[j]='9';
		}


reverse(s.begin(),s.end());
printf("%s \n",s.c_str());
return 0;

}