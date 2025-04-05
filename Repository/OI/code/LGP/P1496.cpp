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
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
struct node{
    int l,r;
}dat[N];
int n,m,ans,c[N],cnt,pre[N];
bool cmp(node a,node b){
    return a.l<b.l;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        dat[i].l=read();
        dat[i].r=read();
        c[++cnt]=dat[i].l;
        c[++cnt]=dat[i].r;
    }
    sort(c+1,c+cnt+1);
    cnt=unique(c+1,c+cnt+1)-c-1;
    for (int i=1;i<=n;i++){
        dat[i].l=lower_bound(c+1,c+cnt+1,dat[i].l)-c;
        dat[i].r=lower_bound(c+1,c+cnt+1,dat[i].r)-c;
    }
    for (int i=1;i<=n;i++){
        pre[dat[i].l]++;pre[dat[i].r]--;
    }
    int x=0,ans=0;
    for (int i=1;i<cnt;i++){
        x+=pre[i];
        if (x)ans+=c[i+1]-c[i];
    }
    printf("%d",ans);
    return 0;
}