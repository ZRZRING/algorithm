#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
struct hh{
	ll x,y,dis;
}edge[1000100];
ll n,m,ans,cnt[1000100],fa[1000100];
ll cmp(hh a,hh b){
	return a.dis<b.dis;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	cin>>n;m=n-1;
	for (int i=1;i<=m;i++){
		cin>>edge[i].x>>edge[i].y>>edge[i].dis;
		ans+=edge[i].dis;
	}
	for (int i=1;i<=n;i++){
		fa[i]=i;cnt[i]=1;
	}
	sort(edge+1,edge+m+1,cmp);
	for (int i=1;i<=m;i++){
		int x=find(edge[i].x),y=find(edge[i].y);
		fa[y]=x;ans+=(cnt[x]*cnt[y]-1)*(edge[i].dis+1);
		cnt[x]+=cnt[y];
	}
	cout<<ans;
}
