#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#define int long long
using namespace std;
int x,y;
const int orz=500100;
/*struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];*/
int head[orz],n,m,cnt,a,p,ans,M;
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
/*void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}*/
int exgcd(int a,int b,int &x,int &y){
    if (!b){x=1;y=0;return a;}
    int d=exgcd(b,a%b,y,x);y-=(a/b*x);
    return d;
}
int mul(int x,int y,int p){
    int res=0;x=(x%p+p)%p;y=(y%p+p)%p;
    while (y){
        if (y&1)res=(res+x)%p;
        x=(x<<1)%p;y>>=1;
    }
    return res;
}
signed main(){
    n=read();M=read();ans=read();
    for (int i=2;i<=n;i++){
        p=read();a=read();
        int b=(a-ans%p+p)%p,d=exgcd(M,p,x,y);
        if (b%d){
            printf("-1");return 0;
        }b/=d;p/=d;
        x=mul(x,b,p);ans+=M*x;
        M*=p;ans=(ans%M+M)%M;
    }
    printf("%lld",ans);
    return 0;
}