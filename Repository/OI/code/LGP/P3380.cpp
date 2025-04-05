#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#define lst (now<<1)
#define rst (now<<1|1)
#define lss (son[now][dep][0])
#define rss (son[now][dep][1])
using namespace std;
const int N=50005;
int n,m,a[N],tree[N<<2],rt[N<<2],dep[N<<2],tot[N<<2];
int val[N][20],son[N][20][2],size[N][20],fa[N][20],cnt[N][20];
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
struct SPLAY{
    void ins(int x,int t,int dep){
        if (!rt[x]){
            val[++tot[x]][dep]=t;cnt[tot[x]][dep]++;
            rt[x]=tot[x];splay(tot[x],dep);return;
        }
        int now=rt[x],fat=0;
        while (1){

        }
    }
}sp;
void build(int now,int l,int r,int dep){
    if (l==r){
        tree[now]=a[l];dep[now]=dep;sp.ins(now,a[l],dep);
    }
    int mid=l+r>>1;
    build(lst,l,mid,dep+1);build(rst,mid+1,r,dep+1);
    pushup(now);
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }build(1,1,n,1);
    for (int i=1;i<=m;i++){
        int opt=read(),t=read();
        if (opt==1){
            int x=read(),y=read(),t=read();
        }
        if (opt==2){
            int x=read(),y=read(),t=read();
        }
        if (opt==3){
            int x=read(),t=read();
        }
        if (opt==4){
            int x=read(),y=read(),t=read();
        }
        if (opt==5){
            int x=read(),y=read(),t=read();
        }
    }
    return 0;
}