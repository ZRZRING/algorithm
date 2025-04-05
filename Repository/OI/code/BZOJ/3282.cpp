// LCT
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (son[now][0])
#define rs (son[now][1])
using namespace std;
const int N=300010;
int n,m,cnt,ans,son[N][2],siz[N],fa[N],rev[N],sum[N],val[N];
inline int read(){
    int sym(0),res(0);char ch(0);
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void clear(int x){
    son[x][0]=son[x][1]=fa[x]=0;
    val[x]=sum[x]=rev[x]=siz[x]=0;
}
void pushup(int now){
    //clear(0);
    siz[now]=siz[ls]+siz[rs]+1;sum[now]=sum[ls]^sum[rs]^val[now];
}
void pushdown(int now){
    if (rev[now]){
        rev[ls]^=1;rev[rs]^=1;swap(ls,rs);rev[now]=0;
    }
}
bool isroot(int x){
    //clear(0);
    return x!=son[fa[x]][0]&&x!=son[fa[x]][1];
}
bool l_r(int x){
    return x==son[fa[x]][1];
}
void rotate(int x){
    int y=fa[x],z=fa[y],kind=l_r(x);
    if (!isroot(y))son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
    pushup(y);pushup(x);pushup(z);
}
void update(int x){
    if (!isroot(x))update(fa[x]);
    pushdown(x);
}
void splay(int x){
    update(x);
    for (int y=fa[x];!isroot(x);y=fa[x]){
        if (!isroot(y))rotate(l_r(x)==l_r(y)?y:x);
        rotate(x);
    }
}
void access(int x){
    for (int y=0;x;y=x,x=fa[x]){
        splay(x);son[x][1]=y;pushup(x);
    }
}
void makeroot(int x){
    access(x);splay(x);rev[x]^=1;
}
int find(int x){
    access(x);splay(x);while (son[x][0])x=son[x][0];
    return x;
}
void split(int x,int y){
    makeroot(x);access(y);splay(y);
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++){
        val[i]=read();
    }
    for (int i=1;i<=m;i++){
        int opt=read(),x=read(),y=read();
        if (opt==0){
            split(x,y);printf("%d\n",sum[y]);
        }
        if (opt==1){
            split(x,y);if (find(x)==find(y))continue;
            makeroot(x);fa[x]=y;
        }
        if (opt==2){
            split(x,y);if (son[y][0]==x&&!son[x][1])fa[x]=son[y][0]=0;
        }
        if (opt==3){
            val[x]=y;pushup(x);
        }
    }
    return 0;
}