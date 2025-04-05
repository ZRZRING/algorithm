#include <iostream>
#include <cmath>
#include <cstdio>
#define ll long long
using namespace std;
ll n,m,x,y,k,ans,a[500001],b[500001];
ll lowbit(ll a){
	return a&-a;
}
void add(int l,int r,int k){
	x=l;
	while (x<=n){
		b[x]+=k;x+=lowbit(x);
	}
	x=r+1;
	while (x<=n){
		b[x]-=k;x+=lowbit(x);
	}
}
ll sum(int x){
	ans=0;
	while (x>0){
		ans+=b[x];x-=lowbit(x);
	}
	return ans;
}
int main(){
	cin>>n>>m;
	//cout<<"a:";
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll tmp;
	for (int i=1;i<=m;i++){
		cin>>tmp;
		if (tmp==1){
			cin>>x>>y>>k;add(x,y,k);
		}
		if (tmp==2){
			cin>>x;cout<<a[x]+sum(x)<<endl;
		}
	}
}