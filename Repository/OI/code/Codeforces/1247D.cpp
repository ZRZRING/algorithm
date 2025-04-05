#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define IT vector<pair<int,int> >::iterator
using namespace std;
const int N=5e5;
int prime[N],cnt[N],p[N],pcnt,n,k,lim[N],w[N];
vector<pair<int,int> >fac[N];
void split(int id,int x)
{
	if(!p[x]){fac[id].push_back(make_pair(x,1));cnt[x]++;return;}	
	int s=1;
	for(int i=1;i<=pcnt&&prime[i]*prime[i]<=x;i++)
	{
		if(x%prime[i]==0)
		{
			int t=0;
			while(x%prime[i]==0)++t,x/=prime[i];
			t%=k;if(!t)continue;for(int j=1;j<=t;j++)s*=prime[i];
			fac[id].push_back(make_pair(prime[i],t));
		}
	}
	if(x!=1)
	{
		fac[id].push_back(make_pair(x,1));
		s*=x;
	}
	cnt[s]++;w[id]=s;
}
void make()
{
	p[1]=1;
	for(int i=2;i<=100000;i++)
	{
		if(!p[i])prime[++pcnt]=i;
		for(int j=1;j<=pcnt&&i*prime[j]<=100000;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=pcnt&&prime[i]<=500;i++)
	{
		lim[prime[i]]=1;int s=prime[i];
		for(;s*prime[i]<=100000;lim[prime[i]]++,s*=prime[i]);
	}
}
int qpower(int a,int b)
{
	int ans=1;for(;b;b>>=1,a*=a)if(b&1)ans*=a;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	make();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",w+i);
		split(i,w[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		long long s=1;
		for(IT j=fac[i].begin();j!=fac[i].end();j++)
		{
			pair<int,int>t=*j;t.second=(k-t.second);
			if(t.second>lim[t.first]){s=1000000000;break;}
			s*=qpower(t.first,t.second);if(s>100000)break;
		}
		if(s<=100000)ans+=cnt[s]-(s==w[i]);
	}
	cout<<ans/2<<endl;
}
