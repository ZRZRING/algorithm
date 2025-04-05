// splay
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define lowbit(x) (x&-x)
#define ls son[now][0]
#define rs son[now][1]
#define lss now<<1
#define rss now<<1|1
#define inf 1e9+7
using namespace std;
void file(){
    freopen("1.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=2000010;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,cf[N],rt,ans_sort=inf,tree[N],ans=inf,a[N],b[N];
int val[N],siz[N],son[N][2],cnt=1,fa[N];
char ch[N];
bool l_r(int x){
    return x==son[fa[x]][1];
}
void update(int now){
    tree[now]=min(tree[lss],tree[rss]);
}
void pushup(int now){
    siz[now]=siz[ls]+siz[rs]+1;
}
void rotate(int x,int &goal){
    int y=fa[x],z=fa[y],kind=l_r(x);
    if (y==goal)goal=x;else son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
    pushup(y);pushup(x);
}
void splay(int x,int &goal){
    for (int y=fa[x];x!=goal;y=fa[x]){
        if (y!=goal)rotate(l_r(x)==l_r(y)?y:x,goal);
        rotate(x,goal);
    }
}
int pre(){
    if (!son[rt][0])return -inf;
    int now=son[rt][0];while (rs)now=rs;return val[now];
}
int suf(){
    if (!son[rt][1])return inf;
    int now=son[rt][1];while (ls)now=ls;return val[now];
}
void ins(int x){
    int now=rt,fat=0;
    while (1){
        if (x==val[now]){
            ans_sort=0;return;
        }
        fat=now;now=son[now][x>val[now]];
        if (!now){
            now=++cnt;siz[now]=1;fa[now]=fat;
            son[fat][x>val[fat]]=now;val[now]=x;
            pushup(fat);splay(now,rt);
            ans_sort=min(ans_sort,min(x-pre(),suf()-x));
            return;
        }
    }
}
void build(int now,int l,int r){
    if (l==r){
        tree[now]=cf[l];return;
    }
    int mid=l+r>>1;
    build(lss,l,mid);
    build(rss,mid+1,r);
    update(now);
}
void change(int now,int l,int r,int x,int t){
    if (l==x&&r==x){
        tree[now]=t;return;
    }
    int mid=l+r>>1;
    if (mid>=x)change(lss,l,mid,x,t);
    else change(rss,mid+1,r,x,t);
    update(now);
}
int main(){//file();
    n=read();m=read();
    a[1]=read();rt=1;val[1]=a[1];siz[1]=1;
    for (int i=2;i<=n;i++){
        b[i]=a[i]=read();if (ans_sort)ins(a[i]);
    }
    for (int i=1;i<n;i++)cf[i]=abs(a[i]-a[i+1]);
    build(1,1,n-1);
    for (int i=1;i<=m;i++){
        scanf("%s",ch);
        if (ch[4]=='R'){
            int x=read(),t=read();
            if (ans_sort)ins(t);ans=min(ans,abs(t-a[x]));
            if (x!=n)change(1,1,n-1,x,abs(t-b[x+1]));a[x]=t;
        }
        if (ch[4]=='G'){
            printf("%d\n",min(tree[1],ans));
        }
        if (ch[4]=='S'){
            printf("%d\n",ans_sort);
        }
    }
    return 0;
}