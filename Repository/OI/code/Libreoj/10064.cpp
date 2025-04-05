#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
priority_queue<pint,vector<pint>,greater<pint> > q;
const ll inf=(1ll<<31)-1;
struct EDGE{
	ll ver,nxt,dis;
}edge[500010];
struct TREE{
	ll id,dis;
}tree[500010];
ll n,m,dis[500010],head[500010],cnt,x,y,t,mp[10001][10001],ans;
bool vis[500010];
void dij(){
	int now;q.push(make_pair(0,1));
	dis[1]=0;
	while (!q.empty()){
		now=q.top().second;q.pop();
		if (vis[now])continue;vis[now]=1;
		for (int i=head[now];i;i=edge[i].nxt){
			int then=edge[i].ver;
			if (dis[then]>dis[now]+edge[i].dis){
				dis[then]=dis[now]+edge[i].dis;
				q.push(make_pair(dis[then],then));
			}
		}
	}
}
void add(int u,int v,int t){
	edge[++cnt].ver=v;
	edge[cnt].dis=t;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
bool cmp(TREE a,TREE b){
	return a.dis<b.dis;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)dis[i]=inf;
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)mp[i][j]=inf;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&t);
		add(x,y,t);add(y,x,t);
		mp[x][y]=t;
		mp[y][x]=t;
	}
	dij();
	for (int i=1;i<=n;i++){
		tree[i].id=i;tree[i].dis=dis[i];//cout<<dis[i]<<' ';
	}
	sort(tree+1,tree+n+1,cmp);
	ans=1;
	for(int i=2;i<=n;i++){
		cnt=0;
		for(int j=i-1;j>=1;j--){
			int x=tree[i].id;y=tree[j].id;
			if(dis[x]==dis[y]+mp[x][y])cnt++;
		}
		ans=ans*cnt%inf;
	}
	cout<<ans;
}
