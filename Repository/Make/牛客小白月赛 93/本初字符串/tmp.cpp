#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+500;
char st[N];
int cnt[N][26],mx[N],T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",st+1);
		int n=strlen(st+1);
		for(int i=1;i<=n;i++)
		{
			if(n%i)continue;
			for(int j=1;j<=i;j++)
			{
				fill(cnt[j],cnt[j]+26,0);mx[j]=0;
				for(int k=j;k<=n;k+=i)cnt[j][st[k]-97]++;
				for(int k=0;k<26;k++)mx[j]=max(mx[j],cnt[j][k]);
			}
			mx[i+1]=0;
			for(int j=i-1;j>=1;j--)mx[j]+=mx[j+1];
			if(mx[1]<((n+1)>>1))continue;
			int res=(n+1)>>1;
			for(int j=1;j<=i;j++)
			{
				for(int ch=0;ch<26;ch++)
				{
					if(cnt[j][ch]+mx[j+1]>=res){putchar(ch+97);res-=cnt[j][ch];break;}
				}
			}
			break;
		}
		puts("");
	}
}