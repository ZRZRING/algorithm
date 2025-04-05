#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[1000100];
int head[1000100],m,cnt;
int c[1001],T,f[100010],d[100010];
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
signed main(){file();
    for (int i=1;i<=4;i++)c[i]=read();
    T=read();f[0]=1;
    for (int i=1;i<=4;i++){
        for (int j=c[i];j<=100010;j++){
            f[j]+=f[j-c[i]];
        }
    }
    while (T--){
        for (int i=1;i<=4;i++)d[i]=read();
        int s=read(),k=0,ans=f[s];
        for (int i=1;i<=15;i++){
            int now=s,k=0,tmp=i;
            for (int j=1;tmp;j++){
                if (tmp&1){
                    k^=1;now-=(d[j]+1)*c[j];
                }
                tmp>>=1;
            }
            if(now>=0)k?ans-=f[now]:ans+=f[now];
        }
        printf("%lld\n",ans);
    }
    return 0;
}