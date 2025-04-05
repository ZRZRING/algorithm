#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=50000;
int n,m,mu[N+5],flag[N+5],prime[N+5],cnt,sum[N+5];
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
void init(){
    mu[1]=1;
    for (int i=2;i<=N;i++){
        if (!flag[i]){
            prime[++cnt]=i;mu[i]=-1;
        }
        for (int j=1;j<=cnt&&i*prime[j]<=N;j++){
            flag[i*prime[j]]=1;
            if (i%prime[j]==0){
                mu[i*prime[j]]=0;break;
            }mu[i*prime[j]]=-mu[i];
        }
    }
    for (int i=1;i<=N;i++){
        mu[i]+=mu[i-1];
    }
    for (int i=1;i<=N;i++){
        for (int l=1,r;l<=i;l=r+1){
            r=i/(i/l);
            sum[i]+=(r-l+1)*(i/l);
        }
    } 
}
signed main(){
    int T=read();init();
    for (int t=1;t<=T;t++){
        n=read();m=read();int ans=0;
        for (int l=1,r;l<=min(n,m);l=r+1){
            r=min(n/(n/l),m/(m/l));
            ans+=(mu[r]-mu[l-1])*sum[n/l]*sum[m/l];
        }
        printf("%lld\n",ans);
    }
    return 0;
}