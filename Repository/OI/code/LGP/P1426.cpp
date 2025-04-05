#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double x,y,l,sum;
int main(){
	cin>>x>>y;
	if (y>14){
		cout<<'y';return 0;
	}
	x-=y;y=x+y+y;
	sum=0,l=7;
	for (;sum<x;){
		l*=0.98;
		sum+=l;
	}
	if (sum+l*0.98>y)cout<<'n';
	else cout<<'y';
}
