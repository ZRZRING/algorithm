#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int orz=1000100;
int n,m,s[orz],w[orz],x[orz],y[orz],cf[orz],sum[orz];
int pd(int now){
	memset(cf,0,sizeof(cf));
	for (int i=1;i<=now;i++){
		cf[x[i]]+=w[i];
		cf[y[i]+1]-=w[i];
	}
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+cf[i];
		if (sum[i]>s[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	for (int i=1;i<=m;i++){
		cin>>w[i]>>x[i]>>y[i];
	}
	if (pd(m)){
		cout<<0;return 0;
	}
	int l=1,r=n;
	while (l<r){
		int mid=(l+r)>>1;
		if (pd(mid))l=mid+1;
		else r=mid;
	}
	printf("-1\n%d",l);
}
