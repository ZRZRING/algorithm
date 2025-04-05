#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct EDGE{
	int nxt,ver,dis;
}edge[100010];
int n,m,head[100010],x[100010],y[100010],t[100010],dis[100010],ans,cnt,p[100010];
void add(int u,int v,int dis){
	edge[++cnt].ver=v;edge[cnt].nxt=head[u];edge[cnt].dis=dis;head[u]=cnt;
}
void dij(){
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,1));dis[1]=0;
	while(!q.empty()){
		int now=q.top().second;q.pop();
		if (p[now])continue;p[now]=1;
		for (int i=head[now];i;i=edge[i].nxt){
			int x=edge[i].ver;
			if (dis[x]>dis[now]+edge[i].dis){
				dis[x]=dis[now]+edge[i].dis;
				q.push(make_pair(-dis[x],x));
			}
		}
	}
}
int main(){
	cin>>n>>m;memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>t[i];add(x[i],y[i],t[i]);
	}
	dij();
	for (int i=1;i<=n;i++){
		ans+=dis[i];
	}
	cnt=0;memset(dis,0x3f,sizeof(dis));memset(p,0,sizeof(p));memset(head,0,sizeof(head));
	for (int i=1;i<=m;i++){
		add(y[i],x[i],t[i]);
	}
	dij();
	for (int i=1;i<=n;i++){
		ans+=dis[i];
	}
	cout<<ans;
}
