#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[1000100];
int head[1000100],n,m,cnt,come[1000100],dis[1000100],ans,p[1000100];
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
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void dp(int u){
    int sum=0;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;dp(v);
        if (come[v])sum+=dis[v];
    }
    if (dis[u]>sum){
        come[u]=1;ans=ans+dis[u]-sum;
    }
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        dis[i]=read();
    }int l=1,k;
    while (l!=0){
        l=read();k=read();add(k,l);p[l]=1;
    }
    int root=1;while(p[root])root++;
    dp(root);printf("%d",ans);
    return 0;
}