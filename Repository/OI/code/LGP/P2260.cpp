#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
#define int long long
using namespace std;
const int orz=500100,p=19940417;
int n,m,cnt,ans1,ans2,ans;
inline int read(){
    int sym(0),res(0);char ch(0);
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int exgcd(int a,int b,long long &x,long long &y){
    if(!b){x=1,y=0;return a;}
    int d=exgcd(b,a%b,y,x);y-=a/b*x;
    return d;
}
int inv(int a,int p){
    long long x,y;exgcd(a,p,x,y);
    return (x % p + p ) % p;
}
int sum(int n){
    return n*(n+1)%p*(2*n+1)%p*inv(6,p)%p;
}
signed main(){
    n=read();m=read();int ans_n=0,ans_m=0,inv_2=inv(2,p)%p;
    for (int l=1,r,len,i;l<=n;l=r+1){
        i=n/l,r=n/i,len=(r-l+1)%p;
        ans_n=(ans_n+(i*len%p*(l+r)%p*inv_2%p))%p;
    }
    ans_n=((n*n%p-ans_n)%p+p)%p;
    for (int l=1,r,len,i;l<=m;l=r+1){
        i=m/l,r=m/i,len=r-l+1;
        ans_m=(ans_m+(i*len%p*(l+r)%p*inv_2%p))%p;
    }
    ans_m=((m%p*m%p-ans_m%p)+p)%p;
    ans1=(ans_n%p*ans_m%p)%p;
    ans_n=0,ans_m=0;
    ans2=n*m%p*min(n,m)%p;
    int ans_nm=0;
    for (int l=1,r,len,in,im;l<=min(n,m);l=r+1){
        in=n/l,im=m/l,r=min(n/in,m/im),len=(r-l+1)%p;
        ans_n=(ans_n+(m*in%p*len%p*(l+r)%p*inv_2%p))%p;
        ans_m=(ans_m+(n*im%p*len%p*(l+r)%p*inv_2%p))%p;
        ans_nm=(ans_nm+(im*in%p*(sum(r)-sum(l-1))%p))%p;
    }
    ans2=((ans2-ans_n-ans_m+ans_nm)%p+p)%p;
    ans=(ans1-ans2%p+p)%p;
    printf("%lld",ans);
    return 0;
}