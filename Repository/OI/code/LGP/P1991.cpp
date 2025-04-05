#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double dis(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
struct hh{
	int x,y;double dis;
}edge[1000100];
int n,k,m,px[1000100],py[1000100],fa[1000100],cnt;double ans[1000100];
int cmp(hh a,hh b){
	return a.dis<b.dis;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	cin>>k>>n;
	if (k>=n){
		printf("0.00");return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>px[i]>>py[i];fa[i]=i;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			edge[++m]=(hh){i,j,dis(px[i],py[i],px[j],py[j])};
		}
	}
	sort(edge+1,edge+m+1,cmp);
	for (int i=1;i<=m;i++){
		int x=find(edge[i].x),y=find(edge[i].y);
		if (x!=y){
			fa[x]=y;
			ans[++cnt]=edge[i].dis;
		}
	}
	printf("%.2lf",ans[cnt-k+1]);
}
