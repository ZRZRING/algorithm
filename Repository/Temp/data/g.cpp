#include<bits/stdc++.h>
using namespace std;
# define N 1005
# define M 60005
int head[N],ver[M],edge[M],deg[M],Next[M],n,m,tot;
int w[N],value[N],W,start,small,big;
bool vis[N];
int DP[N][2005],RD[N][2005];
int T[N],cnt;
void ADD(int x,int y,int z) {
	ver[++tot]=y;
	deg[y]++;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
void topsort() {
	queue<int>Q;
	for(int i=1; i<=n; i++) {
		if(deg[i]==0) {
			Q.push(i);
		}
	}
	while(Q.size()) {
		int x=Q.front();
		Q.pop();
		T[++cnt]=x;
		for(int i=head[x]; ~i; i=Next[i]) {
			int y=ver[i];
			if(--deg[y]==0)Q.push(y);
		}
	}
}
int main() {
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int x,y,z;
//	while(~scanf("%d%d%d",&n,&m,&W)) {
	scanf("%d%d%d",&n,&m,&W);
	start=1;
	for(int i=1; i<=n; i++)
		scanf("%d%d",&w[i],&value[i]);
	memset(head,-1,sizeof(head));
	tot=-1;
	memset(deg,0,sizeof(deg));
	small=0x3f3f3f3f;
	big=0;
	cnt=0;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		ADD(x,y,z);
	}
	topsort();
	//memset(DP,0,sizeof(DP));
	memset(RD,0x3f,sizeof(RD));
	//memset(vis,0,sizeof(vis));
	vis[start]=1;
	DP[start][0]=0;
	RD[start][0]=0;
	for(int i=1; i<=cnt; i++) {
		int x=T[i];
		if(vis[x]==0)continue;
		for(int j=W; j>=w[x]; j--) {
			if(DP[x][j-w[x]]+value[x]>DP[x][j]) {
				DP[x][j]=DP[x][j-w[x]]+value[x];
				RD[x][j]=RD[x][j-w[x]];
			} else  if(DP[x][j-w[x]]+value[x]==DP[x][j]) {
				RD[x][j]=min(RD[x][j],RD[x][j-w[x]]);
			}
		}
		for(int j=head[x]; ~j; j=Next[j]) {
			int y=ver[j];
			vis[y]=1;
			for(int k=W; k>=0; k--) {
				if(DP[x][k]>DP[y][k]) {
					DP[y][k]=DP[x][k];
					RD[y][k]=RD[x][k]+edge[j]*k;
				} else if(DP[x][k]==DP[y][k]) {
					RD[y][k]=min(RD[y][k],RD[x][k]+edge[j]*k);
				}
			}
		}
		if(x==n)
			for(int j=0; j<=W; j++) {
				if(DP[x][j]>big||DP[x][j]==big&&RD[x][j]<small) {
					big=DP[x][j];
					small=RD[x][j];
				}
			}
	}
	printf("%d %d\n",big,small);
	//}
	return 0;
}

/*
in
5 6 10
2 2 
1 3
3 5
4 2
2 3
1 2 1
2 4 5
2 5 3
1 3 4
3 4 2
4 5 2

out
10 20
*/
