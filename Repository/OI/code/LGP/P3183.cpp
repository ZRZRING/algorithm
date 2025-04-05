#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
	int ver,nxt;
}edge[200010];
int ans,cnt,n,m,x,y,rd[200010],cd[200010],head[200010],c[200010];
void add(int u,int v){
	edge[++cnt].ver=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
int search(int now){
	if (c[now])return c[now];
	if (!head[now])return 1;
	for (int i=head[now];i;i=edge[i].nxt){
		c[now]+=search(edge[i].ver);
	}return c[now];
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>x>>y;add(x,y);rd[y]++;cd[x]++;
	}
	for (int i=1;i<=n;i++){
		if (!rd[i]&&cd[i]){
			ans+=search(i);
		}
	}
	cout<<ans;
}
