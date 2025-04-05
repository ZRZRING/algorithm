#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define inf 2147483647000000
using namespace std;
struct hh{
	int x,y,dis;
}a[1000100];
struct EDGE{
	int ver,nxt,dis;
}edge[1000100];
int n,m,ans,fa[1000100],dep[1000100],bz[100010][20],bmax[100010][20],smax[100010][20],cnt,head[1000100],my_log2[1000100];
int p[1000100],sum;
int cmp(hh a,hh b){
	return a.dis<b.dis;
}
int qmax(int x,int y,int dis){
    int tmp=-inf;
    for (int i=18;i>=0;i--){
        if (dep[bz[x][i]]>=dep[y])
        {
            if (dis!=bmax[x][i])tmp=max(tmp,bmax[x][i]);
            else tmp=max(tmp,smax[x][i]);
            x=bz[x][i];
        }
    }
    return tmp;
}
void add(int u,int v,int dis){
	edge[++cnt].ver=v;
	edge[cnt].dis=dis;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int now,int fath){
	bz[now][0]=fath;
	for (int i=head[now];i;i=edge[i].nxt){
		int v=edge[i].ver;
		if (v==fath)continue;
		dep[v]=dep[now]+1;
		bmax[v][0]=edge[i].dis;
    	smax[v][0]=-inf;
		dfs(v,now);
	}
}
int lca(int x,int y){
	int tmp;
	if (dep[x]<dep[y])swap(x,y);
	for (int i=18;i>=0;i--){
		if (dep[bz[x][i]]>=dep[y]){
			x=bz[x][i];
		}
	}
	if (x==y)return x;
	for (int i=18;i>=0;i--){
		if (bz[x][i]!=bz[y][i]){
			x=bz[x][i];y=bz[y][i];
		}
	}
	return bz[x][0];
} 
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void start(){//Ԥ������������ʹδ�ֵ
	for (int i=1;i<=18;i++){
		for (int j=1;j<=n;j++){
			bz[j][i]=bz[bz[j][i-1]][i-1];//����ͼ������ 
            bmax[j][i]=max(bmax[j][i-1],bmax[bz[j][i-1]][i-1]);//bmax����· 
            smax[j][i]=max(smax[j][i-1],smax[bz[j][i-1]][i-1]);//smax��Ĵγ�· 
            if (bmax[j][i-1]>bmax[bz[j][i-1]][i-1]){//���bmax���bz������ 
                smax[j][i]=max(smax[j][i],bmax[bz[j][i-1]][i-1]);//smax��֮ǰ��bz 
            }else if (bmax[j][i-1]<bmax[bz[j][i-1]][i-1]){//���bmax����֮ǰ��bz 
                smax[j][i]=max(smax[j][i],bmax[j][i-1]);//smax�����ڵ�bz 
            }
		}
	}
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].dis;
	}
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	for (int i=1;i<=m;i++){
		int x=find(a[i].x),y=find(a[i].y);
		if (x!=y){
			fa[x]=y;p[i]=1;sum+=a[i].dis;
			add(a[i].x,a[i].y,a[i].dis);
			add(a[i].y,a[i].x,a[i].dis);
		}
	}
	smax[1][0]=-inf;dep[1]=1;dfs(1,-1);start();
	int ans=inf;
    for(int i=1;i<=m;++i){
        if(!p[i]){
            int u=a[i].x,v=a[i].y,dis=a[i].dis;
            int tmp=lca(u,v),maxu=qmax(u,tmp,dis),maxv=qmax(v,tmp,dis);
            ans=min(ans,sum-max(maxu,maxv)+dis);
        }
    }
	cout<<ans;
}
