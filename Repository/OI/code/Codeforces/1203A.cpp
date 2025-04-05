#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
int n,m,a[N];
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
int main(){
    int T=read();
    for (int t=1;t<=T;t++){
        n=read();int flag=1;a[1]=read();
        for (int i=2;i<=n;i++){
            a[i]=read();
            if (abs(a[i]-a[i-1])!=1&&abs(a[i]-a[i-1])!=n-1)flag=0;
        }
        if (abs(a[n]-a[1])!=n-1&&abs(a[n]-a[1])!=1)flag=0;
        if (flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}