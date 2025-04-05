#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,u,v,cnt,head[100010],w[100010],p[100010],come[100010],ans;
struct EDGE{
	int ver,nxt;
}edge[100010];
void add(int u,int v){
	edge[++cnt].ver=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int now){
	int sum=0,tmp;
	for (int i=head[now];i;i=edge[i].nxt){
		tmp=edge[i].ver;dfs(tmp);
		if (come[tmp])sum+=w[tmp];
	}
	if (w[now]>sum){
		come[now]=1;ans+=w[now];ans-=sum;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for (int i=1;i<n;i++){
		cin>>u>>v;add(v,u);p[u]=1;
	}
	for (int i=1;i<=n;i++){
		if (!p[i]){
			dfs(i);cout<<ans;return 0;
		}
	}
}