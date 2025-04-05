#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
int n,m,a[N];
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
int main(){
    int T=read();
    while (T--){
        n=read();int ans=1;
        for (int i=1;i<=n;i++){
            a[i]=read();
        }
        sort(a+1,a+n+1);
        for (int i=1;i<n;i++){
            if (a[i]+1==a[i+1])ans=2;
            a[i]=0;
        }a[n]=0;
        printf("%d\n",ans);
    }
    return 0;
}