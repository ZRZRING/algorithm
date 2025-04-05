#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500100;
int n,m,k,h[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int main(){
    int T=read();
    for (int t=1;t<=T;t++){
        n=read(),m=read(),k=read();
        h[1]=read();int flag=1;
        for (int i=2;i<=n;i++){
            h[i]=read();
            if (h[i]<k)m+=h[i-1];
            else m-=h[i]-(h[i-1]+k);
            if (m<0)flag=0;
        }
        if (flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}