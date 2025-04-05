#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,a[N],b[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int T=read();
    while (T--){
        n=read();for (int i=1;i<=n;i++)a[i]=read();
        sort(a+1,a+n+1,cmp);if (a[n]>=n){printf("%d\n",n);continue;}
        for (int i=1;i<=n;i++)if (a[i]<i)printf("%d\n",i-1);break;
    }
    return 0;
}