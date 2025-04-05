#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (son[now][0])
#define rs (son[now][1])
using namespace std;
const int N=1000010;
int n,m,son[N][2],siz[N],val[N],fa[N],delta,cnt[N],tot,rt;
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
int l_r(int x){
    return x==son[fa[x]][1];
}
void clear(int x){
    son[x][0]=son[x][1]=fa[x]=val[x]=cnt[x]=siz[x]=0;
}
void pushup(int now){
    siz[now]=siz[ls]+siz[rs]+cnt[now];
}
void rotate(int x){
    int y=fa[x],z=fa[y],kind=l_r(x);
    if (y==rt)rt=x;else son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
    pushup(y);pushup(x);pushup(z);
}
void splay(int x){
    for (int y=fa[x];x!=rt;y=fa[x]){
        if (y!=rt)rotate(l_r(x)==l_r(y)?y:x);
        rotate(x);
    }
}
void insert(int x){
    if (!rt){
        cnt[++tot]++;val[tot]=x;rt=tot;pushup(rt);return;
    }int now=rt,fat=0;
    while (1){
        if (val[now]==x){
            cnt[now]++;pushup(now);pushup(fat);splay(now);return;
        }fat=now;now=son[now][x>val[now]];
        if (!now){
            cnt[++tot]++;val[tot]=x;fa[tot]=fat;
            son[fat][x>val[fat]]=tot;
            pushup(tot);pushup(fat);splay(tot);
            return;
        }
    }
}
int find(int x){
    int now=rt;
    while (1){
        if (rs&&x<=siz[rs])now=rs;
        else{
            x-=siz[rs]+cnt[now];
            if (x<=0)return val[now];
            now=ls;
        }
    }
}
void get_rank(int x){
    int now=rt;
    while (1){
        if (x<val[now])now=ls;
        else{
            if (x==val[now]){
                splay(now);return;
            }now=rs;
        }
    }
}
int pre(){
    int now=son[rt][0];while (rs)now=rs;return now;
}
void del(int x){
    get_rank(x);
    if (cnt[rt]>1){
        cnt[rt]--;pushup(rt);return;
    }int now=rt;
    if (!ls&&!rs){
        clear(rt);rt=0;return;
    }if (ls&&rs){
        int y=pre(),last=rt;splay(y);
        fa[rs]=y;son[y][1]=rs;
        clear(last);pushup(rt);return;
    }if (ls){
        int last=rt;rt=ls;fa[rt]=0;
        clear(last);return;
    }if (rs){
        int last=rt;rt=rs;fa[rt]=0;
        clear(last);return;
    }
}
void debug(){
    printf("---\n");
    for (int now=1;now<=tot;now++){
        printf("%d:ls-%d rs-%d val-%d size-%d\n",now,ls,rs,val[now],siz[now]);
    }
}
int main(){file();
    n=read();m=read();char ch[10];int ans=0;
    for (int i=1;i<=n;i++){
        scanf("%s",ch);int k=read();
        if (ch[0]=='I'){
            if (k>=m)insert(k-delta);
        }if (ch[0]=='A'){
            delta+=k;
        }if (ch[0]=='S'){
            delta-=k;insert(m-delta);
            ans+=siz[son[rt][0]];son[rt][0]=0;
            pushup(rt);del(m-delta);
        }if (ch[0]=='F'){
            if (k>siz[rt])printf("-1\n");
            else printf("%d\n",find(k)+delta);
        }
    }printf("%d",ans);
    return 0;
}