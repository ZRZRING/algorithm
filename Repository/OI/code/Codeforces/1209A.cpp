#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=105;
int n,m,vis[N],ans,a[N];
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
    n=read();if (n==1){
        printf("1");return 0;
    }
    for (int i=1;i<=n;i++){
        a[i]=read();
    }sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        if (vis[i])continue;ans++;
        for (int j=i+1;j<=n;j++){
            if (a[j]%a[i]==0)vis[j]=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}