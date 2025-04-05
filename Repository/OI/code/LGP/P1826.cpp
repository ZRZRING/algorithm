#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=1e7+5,p=20101009;
int n,m,prime[N],cnt,mu[N];
bool flag[N];
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
    mu[1]=1;int t=min(n,m);
    for (int i=2;i<=t;i++){
        if (!flag[i]){
            mu[i]=-1;prime[++cnt]=i;
        }
        for (int j=1;j<=cnt&&i*prime[j]<=t;j++){
            flag[i*prime[j]]=1;
            if (i%prime[j]==0){
                mu[i*prime[j]]=0;break;
            }mu[i*prime[j]]=-mu[i];
        }
    }
    for (int i=1;i<=t;i++){
        mu[i]=(mu[i-1]+i*i%p*(mu[i]+p)%p)%p;
    }
}
int g(int a,int b){
    return (a*(a+1)/2%p)*(b*(b+1)/2%p)%p;
}
int sum(int x,int y){
    int res=0;
    for (int l=1,r;l<=min(x,y);l=r+1){
        r=min(x/(x/l),y/(y/l));
        res=(res+(mu[r]-mu[l-1]+p)%p*g(x/l,y/l)%p)%p;
    }
    return res;
}
signed main(){
    n=read();m=read();init();
    int ans=0;
    for (int l=1,r;l<=min(n,m);l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans=(ans+(r-l+1)*(l+r)/2%p*sum(n/l,m/l)%p)%p;
    }
    printf("%d",ans);
    return 0;
}