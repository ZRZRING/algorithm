#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
int n,m,ans[N],a[N],s[N],top;
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
void dfs(int start,int now,int cnt){
    s[++top]=now;
    if (a[now]==start){
        for (int i=1;i<=top;i++){
            ans[s[i]]=cnt;
        }top=0;return;
    }
    dfs(start,a[now],cnt+1);
}
int main(){
    int T=read();
    while (T--){
        int n=read();memset(ans,0,sizeof(ans));
        for (int i=1;i<=n;i++){
            a[i]=read();
        }
        for (int i=1;i<=n;i++){
            if (!ans[i])dfs(i,i,1);
        }
        for (int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }printf("\n");
    }
    return 0;
}