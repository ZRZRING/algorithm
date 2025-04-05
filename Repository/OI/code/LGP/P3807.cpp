#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,p,mul[N];
int power(int a,int x){
    int res=1;
    while (x){
        if (x&1)res=res*a%p;
        a=a*a%p;x>>=1;
    }
    return res;
}
int C(int n,int m){
    if (m>n)return 0;
    return mul[n]*power(mul[m],p-2)%p*power(mul[n-m],p-2)%p;
}
int lucas(int n,int m){
    if (!m)return 1;
    return C(n%p,m%p)*lucas(n/p,m/p)%p;
}
signed main(){
    int T=read();
    while (T--){
        n=read();m=read();p=read();mul[0]=1;
        for (int i=1;i<=100010;i++){
            mul[i]=mul[i-1]*i%p;
        }
        printf("%d\n",lucas(n+m,m)%p);
    }
    return 0;
}