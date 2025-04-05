#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=200010,inf=1<<30;
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
    while (T--){
        n=read();int minn=inf,ans=0;
        for (int i=1;i<=n;i++){
            a[i]=read();
        }
        for (int i=n;i>=1;i--){
            if (a[i]<minn)minn=a[i];
            if (a[i]>minn)ans++;
        }printf("%d\n",ans);
    }
    return 0;
}