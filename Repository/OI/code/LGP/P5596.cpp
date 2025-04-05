#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=500010;
int n,m;
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
signed main(){
    int a=read(),b=read();
    if (a*a==b<<2){
        printf("inf");return 0;
    }
    if(a==1&&b==0){
        printf("1");return 0;
    }
    int sq=sqrt(b),a2=a>>1,ans=0;
    if (sq>=a2){
        for (int i=a2+1;i<=sq;i++){
            if ((b-i*i)%((i<<1)-a)==0)ans++;
        }
    }else{
        for (int i=sq;i<=(a2<<1==a?a2-1:a2);i++){
            if ((b-i*i)%((i<<1)-a)==0)ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}