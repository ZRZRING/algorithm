#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll n,m,lose[100010],win[100010],w[100010],dp[100010],ans,sum;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>lose[i]>>win[i]>>w[i];
		win[i]-=lose[i];
		sum+=lose[i];
	}
	for (int i=0;i<=n;i++){
		dp[i]=sum;
	}
	for (int i=1;i<=n;i++){
		for (int j=m;j>=w[i];j--){
			dp[j]=max(dp[j-w[i]]+win[i],dp[j]);
		}
	}
	cout<<dp[m]*5;
}
