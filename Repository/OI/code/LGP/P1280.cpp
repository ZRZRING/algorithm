#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
struct W{
	int s,t;
}work[100010];
int n,k,f[100010],p[100010],num=1;
int cmp(W a,W b){
	return a.s>b.s;
}
int main(){
	cin>>k>>n;
	for (int i=1;i<=n;i++){
		cin>>work[i].s>>work[i].t;
		p[work[i].s]++;
	}
	sort(work+1,work+n+1,cmp);
	for (int i=k;i>=1;i--){
		if (!p[i])f[i]=f[i+1]+1;
		else {
			for (int j=1;j<=p[i];j++){
				f[i]=max(f[i+work[num++].t],f[i]);
			}
		}
	}
	cout<<f[1];
}
