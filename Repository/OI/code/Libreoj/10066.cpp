#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct hh{
	int x,y,dis,p;
}edge[1000100];
int n,w[1000100],fa[1000100],ans,tmp,m,p[1000100];
int cmp(hh a,hh b){
	return a.dis<b.dis;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>w[i];fa[i]=i;
		//edge[++m].x=0;edge[m].y=i;edge[m].dis=w[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>tmp;if (i>=j)continue;
			edge[++m].x=i;edge[m].y=j;
			if (w[i]+w[j]<tmp){
				edge[m].dis=w[i]+w[j];edge[m].p=1;
			}else{
				edge[m].dis=tmp;
			}
		}
	}
	sort(edge+1,edge+m+1,cmp);
	for (int i=1;i<=m;i++){
		int x=find(edge[i].x),y=find(edge[i].y);
		if (x!=y){
			fa[x]=y;
			ans+=edge[i].dis;
			if (edge[i].p){
				if (p[edge[i].x])ans-=w[edge[i].x];
				if (p[edge[i].y])ans-=w[edge[i].y];
				p[edge[i].x]=1;p[edge[i].y]=1;
			}
		}
	}
	cout<<ans;
}
