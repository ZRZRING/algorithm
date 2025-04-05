#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int orz=50010;
int l,r,mid,k,n,m,ans,a[orz],cf[orz],dp[orz];
bool check(int x){
	int ans=0,now=0;
	for (int i=1;i<=n+1;i++){
		if (a[i]-a[now]<x)continue;
		else ans++,now=i;
	}
	//cout<<x<<':'<<ans<<endl;
	return ans-1>=n-m;
}
int main(){
	cin>>k>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];cf[i]=a[i]-a[i-1];
	}
	a[n+1]=k;
	sort(a+1,a+n+1);
	l=1,r=k;
	while (l<r){
		mid=(l+r+1)>>1;
		if (check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
}
