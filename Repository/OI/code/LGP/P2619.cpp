#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct EDGE{
	int u,v,w,color;
}edge[500001],b[500001];
int n,m,fa[500001],sum,cnt,cont,need,ans;
int cmp(EDGE a,EDGE b){
	if (a.w==b.w)return a.color<b.color;
	return a.w<b.w;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int pd(int x){
	for (int i=1;i<=m;i++){
        b[i].u=edge[i].u;b[i].v=edge[i].v;b[i].color=edge[i].color;
		b[i].w=edge[i].w+x*(!b[i].color);fa[i]=i;
	}
	sort(b+1,b+m+1,cmp);
	sum=0,cnt=0,cont=0;
	for (int i=1;i<=m;i++){
		int x=find(b[i].u),y=find(b[i].v);
		if (x==y)continue;
		sum+=b[i].w;cnt+=!b[i].color;
		fa[y]=x;cont++;if (cont==n-1)break;
	}
	if (cnt>=need)return 1;
	else return 0;
}
int main(){
	cin>>n>>m>>need;
	for (int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w>>edge[i].color;
		edge[i].u++;edge[i].v++;
	}
	int l=-1000,r=1000,mid;
	while (l<r){
		mid=(l+r)>>1;
		if (pd(mid)){
			l=mid+1;ans=sum-mid*need;
		}
		else r=mid;
	}
	cout<<ans;
}
