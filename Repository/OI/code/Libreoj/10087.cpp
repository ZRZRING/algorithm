#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
	int ver,dis,nxt;
}edge[500010];
int n,m,s,x,y,w,dis[500010],q[500010],p[500010],head[500010],cnt,l,r;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
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
int main(){file();
	cin>>m;
	for (int i=1;i<=m;i++){
		cin>>x>>y>>w;add(y,x-1,-w);r=max(r,y);l=min(l,x-1);
		//dis[y]>=w+dis[x-1]
		//dis[x-1]<=-w+dis[y]
	}
    s=r+1;//起点为n+1，保证前缀和递增
	for(int i=l;i<=r;i++){
        add(s,i,0);//起点往所有点连一条0边
		add(i-1,i,1);//每个数只选一次
    	add(i,i-1,0);//保证前缀和
    }
	for (int i=1;i<=3*r+m;i++){
		dis[i]=2147483647;
	}
	SPFA();
	int minn=2147483647;
	for (int i=0;i<=r;i++){
		minn=min(minn,dis[i]);
	}
	cout<<dis[r]-minn;
    return 0;
}