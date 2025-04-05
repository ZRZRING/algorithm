#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char ch[300];
int n,b=233,h=99979,p=1e7+1,nxt[100000],tot,adj[100000],stk[100000],top,num[100000];
void insert(int x)
{
	int key=x%h;
	for (int i=adj[key];i;i=nxt[i])
		if (num[i]==x)return;
	if (!adj[key])stk[++top]=key;
	nxt[++tot]=adj[key];
	adj[key]=tot;
	num[tot]=x;
}
int query(int x)
{
	int key=x%h;
	for (int i=adj[key];i;i=nxt[i])
		if (x==num[i])return 1;
		else return 0;
}
int main()
{
	cin>>n;
	while (n--)
	{
		gets(ch);
		int len=strlen(ch),sum=0;
		if (ch[0]=='a')
		{
			for (int i=4;i<len;i++)
				sum=(sum*b+ch[i])%p;
			insert(sum);
		}
		else
		{
			for (int i=5;i<len;i++)
				sum=(sum*b+ch[i])%p;
			if (query(sum))cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
	return 0;
}
