#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (son[now][0])
#define rs (son[now][1])
using namespace std;
const int N=100010;
int n,cnt[N],ans,son[N][2],fa[N],rt,val[N],tot;
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
bool l_r(int x){
    return x==son[fa[x]][1];
}
void rotate(int x){
    int y=fa[x],z=fa[y],kind=l_r(x);
    if (y==rt)rt=x;else son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
}
void splay(int x){
    for (int y=fa[x];x!=rt;y=fa[x]){
        if (y!=rt)rotate(l_r(x)==l_r(y)?y:x);
        rotate(x);
    }
}
void ins(int t){
    if (!rt){
        val[++tot]=t;cnt[tot]++;rt=tot;
    }else{
        int now=rt,fat=0;
        while (1){
            if (val[now]==t){
                cnt[now]++;splay(now);return;
            }
            fat=now;now=son[now][t>val[now]];
            if (!now){
                now=++tot;val[now]=t;cnt[now]++;fa[now]=fat;
                son[fat][t>val[fat]]=now;splay(now);
                return;
            }
        }
    }
}
int pre(){
    int now=son[rt][0];while (rs)now=rs;return now;
}
int suf(){
    int now=son[rt][1];while (ls)now=ls;return now;
}
int main(){file();
    n=read();ins(ans=read());
    for (int i=1;i<n;i++){
        int t=read();ins(t);if (cnt[rt]>1)continue;
        int x=pre(),y=suf();
        printf("%d %d %d\n",t,val[x],val[y]);
        if (y==0){
            ans+=t-val[x];printf("ans:%d\n",t-val[x]);
        }else if (x==0){
            ans+=val[y]-t;printf("ans:%d\n",val[y]-t);
        }else{
            ans+=min(t-val[x],val[y]-t);printf("ans:%d\n",val[y]-t);
        }
    }
    printf("%d",ans);
    return 0;
}

/*
//Treap
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
const int inf=1<<30;
using namespace std;
const int orz=500100;
int lc[orz],rc[orz],val[orz],dis[orz];
int head[orz],n,m,cnt,root,ans;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int read(){
    int res=0,sym=0;char ch=getchar();
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int pre(int t){
    int x=root,res=-inf;
    while (x){
        if (t>=dis[x])res=dis[x],x=rc[x];
        else x=lc[x];
    }
    return res;
}
int suf(int t){
    int x=root,res=inf;
    while (x){
        if (t<=dis[x])res=dis[x],x=lc[x];
        else x=rc[x];
    }
    return res;
}
void left_up(int &x){
    int y=lc[x];lc[x]=rc[y];rc[y]=x;x=y;
}
void right_up(int &x){
    int y=rc[x];rc[x]=lc[y];lc[y]=x;x=y;
}
void insert(int &x,int t){
    if (!x){
        dis[x=++cnt]=t;val[x]=rand();
        return;
    }
    if (t<dis[x]){//如果当前点权比该位置点权小
        insert(lc[x],t);//去左边
        if (val[lc[x]]<val[x])left_up(x);//如果左儿子价值小，左儿子上位
    }else{
        insert(rc[x],t);
        if (val[rc[x]]<val[x])right_up(x);
    }
}
int main(){//file();
    n=read();insert(root,ans=read());
    for (int i=1;i<=n-1;i++){
        int t=read();
        ans+=min(suf(t)-t,t-pre(t));
        insert(root,t);
    }
    printf("%d",ans);
}
*/