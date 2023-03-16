#include<sstream>
#include<iostream>
#include<strstream>
using namespace std;
string numbers[10]={"","one","two","three","four","five","six","seven","eight","nine"};
string eleventonineteen[10]={"","eleven","tweleve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string tennum[10]={"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

class number
{
public:
	int strlen;
	int value;
void subtract();
private:
void print(int hundred ,int ten,int value);

};
void number::subtract()
{
	int hundreds,tens;
	for (  hundreds=0;value>=100;++hundreds,value-=100);
	for (  tens=0;value>=10;++tens,value-=10);
	print(hundreds,tens,value);
}
void number::print(int hundred ,int ten,int value)
{
	string str;
	if (hundred>0)
		str+=numbers[hundred]+"hundred";
	
	if (hundred>0&&(ten>0||value>0))
	str+="and";
	if(ten==1&&value>0)
		str+=eleventonineteen[value];
	else if (ten>0)
		{
			str+=tennum[ten];
	if (value>0)
		str+=numbers[value];
	}
	else if (value>0)
		str+=numbers[value];
	cout<<str<<" "<<str.length()<<endl;
	strlen=str.length();
}
int main()
{number num;
	int input,sum=0;
	for (  input=1;input<1000;input++)
	{
	num.value=input;
	num.subtract();
	input+=1;
	sum+=num.strlen;
	}
	cout<<sum;
	getchar();
	return 0;
}
