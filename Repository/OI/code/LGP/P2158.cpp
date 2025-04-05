#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=50010;
int n,m,flag[N],mu[N],prime[N],cnt;
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
void init(){
    mu[1]=1;flag[1]=1;
    for (int i=2;i<=n;i++){
        if (!flag[i]){
            prime[++cnt]=i;mu[i]=-1;
        }
        for (int j=1;j<=cnt&&i*prime[j]<=n;j++){
            flag[i*prime[j]]=1;
            if (i%prime[j]==0){
                mu[i*prime[j]]=0;break;
            }mu[i*prime[j]]=-mu[i];
        }
    }
    for (int i=1;i<=n;i++){
        mu[i]+=mu[i-1];
    }
}
int main(){
    n=read()-1;int ans=0;
    if (n==0){
        printf("0");return 0;
    }init();
    for (int l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ans+=(mu[r]-mu[l-1])*(n/l)*(n/l);
    }
    printf("%d",ans+2);
    return 0;
}