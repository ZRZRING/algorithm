#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=200010,p=10007;
struct EDGE{
    int ver,nxt;
}edge[N<<1];
int n,m,cnt,head[N],val[N],ans;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
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
signed main(){//file();
    n=read();int maxx=0;
    for (int i=1;i<=n-1;i++){
        int x=read(),y=read();add(x,y);add(y,x);
    }
    for (int i=1;i<=n;i++){
        val[i]=read();
    }
    for (int u=1;u<=n;u++){
        int tmp=0,tmax=0;
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            maxx=max(maxx,tmax*val[v]);
            tmax=max(tmax,val[v]);
            ans=(ans+2*val[v]*tmp)%p;
            tmp=(tmp+val[v])%p;
        }
    }
    printf("%lld %lld",maxx,ans);
    return 0;
}