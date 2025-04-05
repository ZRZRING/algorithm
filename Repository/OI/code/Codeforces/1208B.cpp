#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=2010;
int n,m,a[N],b[N],vis[N],vis2[N];
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
signed main(){
    n=read();int flag=1,ans1=0,ans2=0;
    //-------------------
    for (int i=1;i<=n;i++){
        a[i]=read();b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int size=unique(b+1,b+n+1)-b;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(b+1,b+size+1,a[i])-b+1;
    }
    //-------------------
    int r=n;
    while (!vis2[a[r]]&&r>=1)vis2[a[r--]]=1;
    int ans=r;memset(vis2,0,sizeof(vis2));
    for (int l=1;l<=n;l++){
        if (vis[a[l]])break;vis[a[l]]=1;r=n;
        while (!vis[a[r]]&&!vis2[a[r]]&&r>=1)vis2[a[r--]]=1;
        ans=min(ans,r-l);memset(vis2,0,sizeof(vis2));
    }
    printf("%I64d\n",ans);return 0;
}