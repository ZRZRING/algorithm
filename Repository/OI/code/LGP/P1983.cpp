#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define rint register int
using namespace std;
struct EDGE{
    int ver,nxt;
}edge[2000100];
int n,rd[2000100],dp[2000100],head[2000100],m,s[2000100],stop[2000100],cnt,ans,pd[1001][1001];
int q[2000100],front,tail;
inline int read(){
    int res=0;char ch=getchar();
    while (!isdigit(ch))ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return res;
}
inline void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
inline void topo(){
    for (rint i=1;i<=n;i++){
        if (!rd[i]){
            q[++tail]=i;dp[i]=0;
        }
    }
    while (front<tail){
        int now=q[++front];dp[now]++;
        for (rint i=head[now];i;i=edge[i].nxt){
            int v=edge[i].ver;dp[v]=max(dp[v],dp[now]);
            rd[v]--;if(!rd[v]){
                q[++tail]=v;
            }
        }
    }
}
int main(){
    //freopen("1983.in","r",stdin);
    //freopen("1983.out","w",stdout);

    n=read();m=read();
    for (rint i=1;i<=m;i++){
        s[i]=read();
        for (rint j=1;j<=s[i];j++){
            stop[j]=read();
        }
        for (rint j=1;j<=s[i];j++){
            for (rint x=1;x<s[i];x++){
                for (rint k=stop[x]+1;k<stop[x+1];k++){
                    if (!pd[k][stop[j]]){
                        pd[k][stop[j]]=1;add(k,stop[j]);rd[stop[j]]++;
                    }
                }
            }
        }
    }
    //for (int i=1;i<=n;i++)cout<<rd[i]<<' ';cout<<endl;
    topo();
    for (rint i=1;i<=n;i++){
        ans=max(ans,dp[i]);//cout<<dp[i]<<' ';
    }//cout<<endl;
    printf("%d",ans);
}