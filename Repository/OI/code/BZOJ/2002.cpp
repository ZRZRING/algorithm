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
const int N=200100;
int n,m,siz[N],son[N][2],fa[N],rev[N];
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
void clear(int x){
    son[x][0]=son[x][1]=fa[x]=rev[x]=siz[x]=0;
}
void pushup(int now){
    siz[now]=siz[ls]+siz[rs]+1;
}
bool l_r(int x){
    return x==son[fa[x]][1];
}
bool isroot(int x){
    return x!=son[fa[x]][0]&&x!=son[fa[x]][1];
}
void rotate(int x){
    int y=fa[x],z=fa[y],kind=l_r(x);
    if (!isroot(y))son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
    pushup(y);
}
void splay(int x){
    for (int y=fa[x];!isroot(x);y=fa[x]){
        if (!isroot(y))rotate(l_r(x)==l_r(y)?y:x);
        rotate(x);
    }pushup(x);
}
void access(int x){
    for (int y=0;x;y=x,x=fa[x]){
        splay(x);son[x][1]=y;pushup(x);
    }
}
int main(){//file();
    n=read();
    for (int i=1;i<=n;i++){
        int t=read()+i;siz[i]=1;if (t>n)continue;fa[i]=t;
    }m=read();
    for (int i=1;i<=m;i++){
        int opt=read();
        if (opt==1){
            int x=read()+1;
            access(x);splay(x);printf("%d\n",siz[x]);
        }else{
            int x=read()+1,t=read()+x;
            access(x);splay(x);son[x][0]=fa[son[x][0]]=0;
            if (t>n)continue;fa[x]=t;pushup(x);
        }
    }
    return 0;
}
