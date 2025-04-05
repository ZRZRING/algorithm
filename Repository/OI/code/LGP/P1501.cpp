#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
#define ls (son[now][0])
#define rs (son[now][1])
using namespace std;
const int N=100010,p=51061;
int n,m,cnt[N],son[N][2],siz[N],sum[N],fa[N],val[N],ans[N],rev[N],add[N],mul[N];
void clear(int x){
    son[x][0]=son[x][1]=fa[x]=0;mul[x]=1;
    val[x]=sum[x]=rev[x]=add[x]=siz[x]=0;
}
bool l_r(int x){
    return son[fa[x]][1]==x;
}
bool isroot(int x){
    clear(0);return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;
}
inline int read(){
    int sym(0),res(0);char ch(0);
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void pushup(int now){
    clear(0);
    siz[now]=(siz[ls]+siz[rs]+1)%p;
    sum[now]=(sum[ls]+sum[rs]+val[now])%p;
}
void pushdown(int now){
    clear(0);
    if (mul[now]!=1){
        int x=mul[now];
        if (ls){
            mul[ls]=mul[ls]*x%p;
            val[ls]=val[ls]*x%p;
            sum[ls]=sum[ls]*x%p;
            add[ls]=add[ls]*x%p;
        }
        if (rs){
            mul[rs]=mul[rs]*x%p;
            val[rs]=val[rs]*x%p;
            sum[rs]=sum[rs]*x%p;
            add[rs]=add[rs]*x%p;
        }
        mul[now]=1;
    }
    if (add[now]){
        int x=add[now];
        if (ls){
            val[ls]=(val[ls]+x)%p;
            add[ls]=(add[ls]+x)%p;
            sum[ls]=(sum[ls]+x*siz[ls]%p)%p;
        }
        if (rs){
            val[rs]=(val[rs]+x)%p;
            add[rs]=(add[rs]+x)%p;
            sum[rs]=(sum[rs]+x*siz[rs]%p)%p;
        }
        add[now]=0;
    }
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
    son[y][kind]=son[x][kind^1];
    if (son[x][kind^1])fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
    pushup(y);pushup(x);pushup(z);
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
    access(x);splay(x);while (son[x][0])x=son[x][0];return x;
	//access(x); update(x); while (!isroot(x)) x = fa[x]; splay(x); return x;
}
void split(int x,int y){
    makeroot(x);access(y);splay(y);
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
signed main(){
    n=read();m=read();
    for (int i=1;i<=n;i++){
        val[i]=1;pushup(i);
    }
    for (int i=1;i<=n-1;i++){
        int x=read(),y=read();
        if (find(x)!=find(y)){
            makeroot(x);fa[x]=y;
        }
    }
    for (int i=1;i<=m;i++){
        char opt;cin>>opt;int x=read(),y=read();
        if (opt=='+'){
            int t=read();split(x,y);
            sum[y]=(sum[y]+siz[y]*t%p)%p;
            val[y]=(val[y]+t)%p;add[y]=(add[y]+t)%p;
        }
        if (opt=='-'){
            split(x,y);
            if (son[y][0]==x&&!son[x][1])son[y][0]=fa[x]=0;
            x=read(),y=read();
            if (find(x)!=find(y))makeroot(x),fa[x]=y;
        }
        if (opt=='*'){
            int t=read();split(x,y);
            sum[y]=sum[y]*t%p;mul[y]=mul[y]*t%p;
            val[y]=val[y]*t%p;
        }
        if (opt=='/'){
            split(x,y);printf("%lld\n",sum[y]);
        }
    }
    return 0;
}