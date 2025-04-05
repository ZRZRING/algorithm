#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1000100;
int n,m,cnt,phi[N],p[N],flg[N];
long long ans[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void init(){
    phi[1]=1;
    for (int i=2;i<=N;i++){
        if (!flg[i]){
            p[++cnt]=i;phi[i]=i-1;
        }
        for (int j=1;j<=cnt&&i*p[j]<=N;j++){
            flg[i*p[j]]=1;
            if (i%p[j]==0){
                phi[i*p[j]]=phi[i]*p[j];break;
            }
            phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
    for (int i=1;i<=N;i++){
        for (int j=1;i*j<=N;j++){
            ans[i*j]+=1LL*j*phi[j]>>1;
        }
    }
    for (int i=1;i<=N;i++){
        ans[i]=1LL*ans[i]*i+i;
    }
}
int main(){
    int T=read();init();
    for (int i=1;i<=T;i++){
        n=read();printf("%lld\n",ans[n]);
    }
    return 0;
}