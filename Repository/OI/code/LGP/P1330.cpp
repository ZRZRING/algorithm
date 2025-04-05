#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
	int ver,nxt;
}edge[100010];
int cnt,n,m,u,v,color[100010],sum[10],ans,head[100010];
void add(int u,int v){
	edge[++cnt].ver=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
int dfs(int now,int c){
	if (color[now]){
		if (color[now]==c)return true;
		return false;
	}else{
		color[now]=c;sum[c]++;
		int flag=1;
		for (int i=head[now];i;i=edge[i].nxt){
			if (!dfs(edge[i].ver,c==1?2:1))return 0;
		}
		return 1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);add(u,v);add(v,u);
	}
	for (int i=1;i<=n;i++){
		if (color[i])continue;
		sum[1]=sum[2]=0;
		if (!dfs(i,1)){
			printf("Impossible");return 0;
		}
		ans+=min(sum[1],sum[2]);
	}
	printf("%d",ans);
}
