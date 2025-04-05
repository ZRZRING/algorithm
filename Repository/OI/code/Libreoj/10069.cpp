#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=31011;
struct EDGE{
	int x,y,dis;
}edge[1001];
struct DATA{
	int l,r,cnt;
}data[1001];
int fa[1001],n,m,cnt,tot,sum,ans;
int cmp(EDGE a,EDGE b){
	return a.dis<b.dis;
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
void dfs(int c,int now,int cont){
	if (now==data[c].r+1){
		if (cont==data[c].cnt){
			sum++;
		}return;
	}else{
		int x=find(edge[now].x),y=find(edge[now].y);
		if (x!=y){
			fa[x]=y;
			dfs(c,now+1,cont+1);
			fa[x]=x;fa[y]=y;
		}
		dfs(c,now+1,cont);
	}
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=1;i<=m;i++){
		cin>>edge[i].x>>edge[i].y>>edge[i].dis;
	}
	sort(edge+1,edge+m+1,cmp);
	for (int i=1;i<=m;i++){
		if (edge[i].dis!=edge[i-1].dis){
			data[cnt].r=i-1;data[++cnt].l=i;
		}
		int x=find(edge[i].x),y=find(edge[i].y);
		if (x!=y){
			fa[x]=y;data[cnt].cnt++;tot++;
		}
	}data[cnt].r=m;//cout<<cnt<<endl;
	/*for (int i=1;i<=cnt;i++){
		cout<<data[i].cnt<<' '<<data[i].l<<' '<<data[i].r<<endl;
	}*/
	if (tot<n-1){
		printf("0");return 0;
	} 
	ans=1;
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=1;i<=cnt;i++){
		sum=0;
		dfs(i,data[i].l,0);
		ans=ans*sum%inf;
		for (int j=data[i].l;j<=data[i].r;j++){
			int x=find(edge[j].x),y=find(edge[j].y);
			if (x!=y){
				fa[x]=y;
			}
		}
	}
	cout<<ans;
}
