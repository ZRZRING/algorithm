#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct MAP{
	int u,v,w;
}edge[500001];
int n,m,fa[500001],ans,cnt;
int q_swap(MAP a,MAP b){
	return a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for (int i=1;i<=n;i++)fa[i]=i;
	sort(edge+1,edge+m+1,q_swap);
	for (int i=1;i<=m;i++){
		int eu=find(edge[i].u),ev=find(edge[i].v);
		if (eu==ev)continue;
		ans=max(ans,edge[i].w);
		fa[ev]=eu;
		if (++cnt==n-1)break;
	}
	if (cnt!=n-1)cout<<-1;
	else cout<<ans;
}
