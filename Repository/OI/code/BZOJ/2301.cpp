// 莫反
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=50010;
int T,mu[N],prime[N],cnt,flag[N];
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
    for (int i=1;i<=N;i++)mu[i]+=mu[i-1];
}
int solve(int n,int m){
    int res=0;
    for (int i=1,j;i<=min(n,m);i=j+1){
        j=min(n/(n/i),m/(m/i));
        res+=(mu[j]-mu[i-1])*(n/i)*(m/i);
    }
    return res;
}
int main(){
    T=read();init();
    for (int i=1;i<=T;i++){
        int x=read(),n=read(),y=read(),m=read(),k=read();
        if (i!=T)printf("%d\n",solve(n/k,m/k)-solve(n/k,(y-1)/k)-solve((x-1)/k,m/k)+solve((x-1)/k,(y-1)/k));
        else printf("%d",solve(n/k,m/k)-solve(n/k,(y-1)/k)-solve((x-1)/k,m/k)+solve((x-1)/k,(y-1)/k));
    }
    return 0;
}