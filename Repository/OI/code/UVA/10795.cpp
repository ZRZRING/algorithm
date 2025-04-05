#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
int n,m,start[N],last[N];
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
long long f(int *status,int i,int goal){
    if (!i)return 0;
    if (status[i]==goal)return f(status,i-1,goal);
    else return f(status,i-1,6-goal-status[i])+(1ll<<i-1);
}
int main(){//file();
    n=read();int cnt=0;
    while (n){
        for (int i=1;i<=n;i++){
            start[i]=read();
        }
        for (int i=1;i<=n;i++){
            last[i]=read();
        }
        int k=n;long long ans=0;
        while (k&&start[k]==last[k])k--;
        if (k){
            int tmp=6-start[k]-last[k];
            ans=f(start,k-1,tmp)+f(last,k-1,tmp)+1;
        }printf("Case %d: %lld\n",++cnt,ans);
        n=read();
    }
    return 0;
}