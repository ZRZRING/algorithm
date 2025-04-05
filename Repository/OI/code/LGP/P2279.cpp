#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int dis[1000100],dep[1000100],n,fa[1000100],num[1000100],ans;
//dis数组维护“离i最近的消防站到i的距离”
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
int cmp(int a,int b){
    return dep[a]>dep[b];
}
int main(){
    n=read();dep[1]=1;num[1]=1;memset(dis,127,sizeof(dis));
    for (int i=2;i<=n;i++){
        fa[i]=read();dep[i]=dep[fa[i]]+1;num[i]=i;
    }
    sort(num+1,num+n+1,cmp);
    for (int i=1;i<=n;i++){
        int now=num[i],fat=fa[now],grf=fa[fa[now]];
        dis[now]=min(dis[now],min(dis[fat]+1,dis[grf]+2));
        if (dis[now]>2){
            dis[grf]=0;ans++;
            dis[fa[grf]]=min(dis[fa[grf]],1);dis[fa[fa[grf]]]=min(dis[fa[fa[grf]]],2);
        }
    }
    printf("%d",ans);
}