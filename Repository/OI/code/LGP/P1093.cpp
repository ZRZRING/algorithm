#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct hh{
	int C,M,E,num,sum; 
}a[1000];
int n;
int cmp(hh a,hh b)
{
	if(a.sum==b.sum&&a.C!=b.C)return a.C>b.C;
	if(a.sum==b.sum&&a.C==b.C)return a.num<b.num;
	return a.sum>b.sum;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].C>>a[i].M>>a[i].E;
		a[i].sum=a[i].C+a[i].M+a[i].E;
		a[i].num=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=5;i++)
	{
		cout<<a[i].num<<' '<<a[i].sum<<endl;
	}
} 
