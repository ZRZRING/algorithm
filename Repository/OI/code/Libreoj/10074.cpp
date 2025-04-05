#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <deque>
#define mp(n,m) (make_pair(n,m))
using namespace std;
struct EDGE{
	int nxt,ver,dis;
}edge[100010];
int cnt,n,m,k,dis[100010],head[100010],p[100010],x,y,t,max_dis,q[100010];
void add(int u,int v,int dis){
	edge[++cnt].ver=v;
	edge[cnt].dis=dis;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
int pd(int tmp){
	memset(p,0,sizeof(p));memset(dis,127,sizeof(dis));
	int qhead=0,tail=1;q[tail]=1;p[1]=1;dis[1]=0;
	while (qhead<tail){
		qhead++;int now=q[qhead];
		for (int i=head[now];i;i=edge[i].nxt){
			if (dis[edge[i].ver]>dis[now]+(edge[i].dis>tmp)){
				dis[edge[i].ver]=dis[now]+(edge[i].dis>tmp);
				if (!p[edge[i].ver]){
					q[++tail]=edge[i].ver;p[edge[i].ver]=1;
				}
			}
		}
		p[now]=0;
	}
	/*cout<<tmp<<endl;
	for (int i=1;i<=n;i++)cout<<dis[i]<<' ';
	printf("\nqwq\n");*/
	return dis[n]<=k;
}
int main(){
	cin>>n>>m>>k;
	if (m<n-1){
		cout<<-1;return 0;
	}
	for (int i=1;i<=m;i++){
		cin>>x>>y>>t;
		max_dis=max(max_dis,t);
		add(x,y,t);add(y,x,t);
	}
	int l=0,r=max_dis;
	while (l<r){
		int mid=(l+r)>>1;
		if (!pd(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<r;
}
