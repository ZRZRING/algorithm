#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (son[now][0])
#define rs (son[now][1])
using namespace std;
const int N=100100;
int n,m,fa[N],son[N][2],rev[N];
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
bool isroot(int x){
    return x!=son[fa[x]][0]&&x!=son[fa[x]][1];
}
bool l_r(int x){
    return x==son[fa[x]][1];
}
void pushdown(int now){
    if (rev[now]){
        rev[ls]^=1;rev[rs]^=1;swap(ls,rs);rev[now]=0;
    }
}
void update(int x){
    if (!isroot(x))update(fa[x]);
    pushdown(x);
}
void rotate(int x){
    int y=fa[x],z=fa[y],kind=l_r(x);
    if (!isroot(y))son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
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
        splay(x);son[x][1]=y;
    }
}
void makeroot(int x){
    access(x);splay(x);rev[x]^=1;
}
void split(int x,int y){
    makeroot(x);access(y);splay(y);
}
int find(int x){
    access(x);splay(x);while (son[x][0])x=son[x][0];return x;
}
void link(int x,int y){
    makeroot(x);fa[x]=y;
}
void cut(int x,int y){
    split(x,y);fa[x]=son[y][0]=0;
}
int main(){
    n=read();m=read();char opt[10];
    for (int i=1;i<=m;i++){
        scanf("%s",opt);int x=read(),y=read();
        if (opt[0]=='C')if (find(x)!=find(y))link(x,y);
        if (opt[0]=='D')cut(x,y);
        if (opt[0]=='Q'){
            if (find(x)==find(y))printf("Yes\n");else printf("No\n");
        }
    }
    return 0;
}
