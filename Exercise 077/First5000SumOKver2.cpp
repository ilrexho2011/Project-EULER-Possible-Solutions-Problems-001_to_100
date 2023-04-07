#include<cstdio>
const int mn=1001;
int f[mn],pr[200],pn;
bool np[mn];

void gjeprim() //gjetja e prime.
{
	for(int i=2;i<mn;i++)
	{
		if(!np[i])pr[pn++]=i;
		for(int j=0;i*pr[j]<mn;j++)
		{
			np[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
}

int main()
{
	gjeprim();
	f[0]=1;
	for(int i=0;i<pn;i++)
		for(int j=pr[i];j<mn;j++)
			f[j]+=f[j-pr[i]];
	for(int i=1;i<mn;i++)
		if(f[i]>5000){printf("%d\n",i);break;}
	return 0;
}
