#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#define ll long long
using namespace std;
///////////////////////////////////////////////////
const ll inf=2147483647;
struct EDGE{
	ll ver,nxt,dis;	
}edge[200010];
struct CODE{
	int u,ans,z,pre;
}q[90000010];
ll head[200010],ans[200010];
ll n,m,cnt=0,x,y,t,last_ans;
///////////////////////////////////////////////////
void bfs(){
	for (int i=1;i<=n;i++)ans[i]=inf;
	int q_head=0,q_tail=1;
	ans[1]=0;q[q_tail].u=1;
	while (q_head<q_tail){
		q_head++;int u=q[q_head].u,z=q[q_head].z,last=q[q_head].ans;
		for (int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].ver;
			if (ans[v]>last+edge[i].dis+z){
				ans[v]=last+edge[i].dis+z;
				q[++q_tail]=(CODE){v,ans[v],z+1,q_head};
				if (v==n)last_ans=q_tail;
			}
		}
	}
}
void add(int x,int y,int t){
	edge[++cnt].ver=y; 
	edge[cnt].dis=t;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
void write(int now){
	if (!now)return;
	write(q[now].pre);
	printf("%d ",q[now].u);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&t);
		add(x,y,t);
	}
	bfs();
	printf("%d\n",ans[n]);
	write(last_ans);
}
