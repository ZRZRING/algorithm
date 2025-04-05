#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define N13 1300
#define N23 4000000
using namespace std;
int n,m,mu[N23],flag[N23],prime[N23],cnt;
ll ans_mu[N23],ans_phi[N23],phi[N23];
bool vis_mu[N23],vis_phi[N23];
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
    mu[1]=1;phi[1]=1;
    for (int i=2;i<=N23;i++){
        if (!flag[i]){
            prime[++cnt]=i;phi[i]=i-1;mu[i]=-1;
        }
        for (int j=1;j<=cnt&&i*prime[j]<=N23;j++){
            flag[i*prime[j]]=1;
            if (i%prime[j]==0){
                mu[i*prime[j]]=0;phi[i*prime[j]]=phi[i]*prime[j];break;
            }else{
                mu[i*prime[j]]=-mu[i];phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    for (int i=1;i<=N23;i++){
        phi[i]+=phi[i-1];mu[i]+=mu[i-1];
    }
}
ll cal_phi(int x){
    if (x<=N23)return phi[x];
    int y=n/x;ll res=1ll*x*(x+1)>>1;
    if (vis_phi[y])return ans_phi[y];
    for (int l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        res-=(r-l+1)*cal_phi(x/l);
    }
    vis_phi[y]=1;ans_phi[y]=res;
    return res;
}
ll cal_mu(int x){
    if (x<=N23)return mu[x];
    int y=n/x;ll res=1;
    if (vis_mu[y])return ans_mu[y];
    for (int l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        res-=(r-l+1)*cal_mu(x/l);
    }
    vis_mu[y]=1;ans_mu[y]=res;
    return res;
}
void clear(){
    memset(vis_phi,0,sizeof(vis_phi));
    memset(vis_mu,0,sizeof(vis_mu));
}
signed main(){//file();
    int T=read();init();clear();
    while (T--){
        n=read();
        printf("%lld %lld\n",cal_phi(n),cal_mu(n));
        clear();
    }
    return 0;
}