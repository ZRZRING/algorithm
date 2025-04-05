#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
	int ver,dis,nxt;
}edge[500010];
int n,m,s,x,y,w,dis[500010],q[500010],p[500010],head[500010],cnt;
void add(int u,int v,int w){
	edge[++cnt].ver=v;
	edge[cnt].dis=w;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void SPFA(){
	int qhead=0,tail=1;q[tail]=s;p[s]=1;dis[s]=0;
	while (qhead<tail){
		qhead++;int now=q[qhead];
		for (int i=head[now];i;i=edge[i].nxt){
			if (dis[edge[i].ver]>dis[now]+edge[i].dis){
				dis[edge[i].ver]=dis[now]+edge[i].dis;
				if (!p[edge[i].ver]){
					q[++tail]=edge[i].ver;p[edge[i].ver]=1;
				}
			}
		}
		p[now]=0;
	}
}
int main(){
	cin>>n>>m;s=n+1;//起点为n+1，保证前缀和递增
	for (int i=1;i<=m;i++){
		cin>>x>>y>>w;add(y,x-1,-w);
		//dis[y]>=w+dis[x-1]
		//dis[x-1]<=-w+dis[y]
		//为啥要乘-1？因为要换号，保证是小于等于号
	}
	for(int i=1;i<=n;i++){
        add(s,i,0);//起点往所有点连一条0边
		add(i-1,i,1);//每个数只选一次
    	add(i,i-1,0);//保证前缀和
    }
	for (int i=1;i<=3*n+m;i++){
		dis[i]=2147483647;
	}
	SPFA();
	int minn=2147483647;
	for (int i=0;i<=n;i++){
		minn=min(minn,dis[i]);
	}
	cout<<dis[n]-minn;
}