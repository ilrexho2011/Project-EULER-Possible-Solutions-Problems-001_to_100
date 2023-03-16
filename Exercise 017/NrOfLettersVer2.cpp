#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
string getWord(int num)
{
	switch(num)
	{
			case 1 :
				return "One";
			case 2 :
				return "Two";
			case 3 :
				return "Three";
			case 4 :
				return "Four";
			case 5 :
				return "Five";
			case 6 :
				return "Six";
			case 7 :
				return "Seven";
			case 8 :
				return "Eight";
			case 9 :
				return "Nine";
			case 10:
				return "Ten";
			case 11:
				return "Eleven";
			case 12:
				return "Twelve";
			case 13:
				return "Thirteen";
			case 14:
				return "Fourteen";
			case 15:
				return "Fifteen";
			case 16:
				return "Sixteen";
			case 17:
				return "Seventeen";
			case 18:
				return "Eighteen";
			case 19:
				return "Nineteen";
			case 20:
				return "Twenty";
			case 30:
				return "Thirty";
			case 40:
				return "Fourty";
			case 50:
				return "Fifty";
			case 60:
				return "Sixty";
			case 70:
				return "Seventy";
			case 80:
				return "Eighty";
			case 90:
				return "Ninety";
	}
	return "";
}
string getTwoDigitWords(int num)
{
	string word,final_word;
	int d;
	word=getWord(num);
	if(word!="")
	{
		final_word+= " " + word;
	}
	else
	{
		d=num/10;
		d=d*10;
		word=getWord(d);
		final_word=word;
		d=num%10;
		if(d!=0)
		{
			word=getWord(d);
			final_word+= " " + word;
		}
	}
	return final_word;
}
string getThreeDigitWords(int num)
{
	string word,final_word;
	int d;
	d=num/100;
	if(d!=0)
	{
		word=getWord(d);
		if(num%10==0 && num%100==0)
			final_word=word + " Hundred";
		else
		{
			final_word=word + " Hundred and ";
			word=getTwoDigitWords(num%100);
			final_word+=word;
		}
	}
	else
	{
		word=getTwoDigitWords(num);
		final_word+=word;
	}
	return final_word;
}
string getFourDigitWords(int num)
{
	string word,final_word;
	int d;
	d=num/1000;
	if(d!=0)
	{
		word=getWord(d);
		if(num%100==0 && num%1000==0)
			final_word=word + " Thousand";
		else
		{
			final_word=word + " Thousand ";
			word=getThreeDigitWords(num%1000);
			final_word+=word;
		}
	}
	else
	{		
		word=getTwoDigitWords(num);
		final_word+=word;
	}
	return final_word;
}
int main()
{
	int i=0,l=0,j=0;
	string word,final_word,extra;
	for(i=1;i<=1000;i++)
	{
		if(i<=20)
		{			
			word=getWord(i);
			final_word=word;
		}
		else if(i>20 && i<100)
		{
				final_word=getTwoDigitWords(i);
		}
		else if(i>=100 && i<1000)
		{
			final_word=getThreeDigitWords(i);
		}
		else
		{
			final_word=getFourDigitWords(i);	
		}
		extra+=final_word;
		word="";
		word=final_word;
		for(j=0;j<word.length();j++)
		{
			if(word[j]!=' ')
			{
				l++;
				cout<<word[j];
			}
		}
		cout<<endl<<l<<endl;
	}
	//cout<<extra;
	cout<<endl<<"============= Total Length =================="<<endl<<l<<endl;
	return 0;
}
