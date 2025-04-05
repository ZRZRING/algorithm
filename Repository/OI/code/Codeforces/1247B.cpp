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
const int N=1000010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,k,d,a[N],vis[N];
int main(){
    int T=read();
    while (T--){
        memset(vis,0,sizeof(vis));
        n=read();k=read();d=read();
        for (int i=1;i<=n;i++){
            a[i]=read();
        }
        int res=0;
        for (int i=1;i<=d;i++){
            if (!vis[a[i]])res++;
            vis[a[i]]++;
        }
        int ans=res;
        for (int i=d+1,j=1;i<=n;i++,j++){
            if (!vis[a[i]])res++;
            vis[a[i]]++;
            vis[a[j]]--;
            if (!vis[a[j]])res--;
            ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}