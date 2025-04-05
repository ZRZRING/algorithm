#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (son[now][0])
#define rs (son[now][1])
using namespace std;
const int N=1000010,inf=1e9,p=1000000;
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
void clear(int x){
    son[x][0]=son[x][1]=fa[x]=val[x]=cnt[x]=0;
}
bool l_r(int x){
    return x==son[fa[x]][1];
}
void rotate(int x,int &goal){
    int y=fa[x],z=fa[y],kind=l_r(x);
    if (y==goal)goal=x;else son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
}
void splay(int x,int &goal){
    for (int y=fa[x];x!=goal;y=fa[x]){
        if (y!=goal)rotate(l_r(x)==l_r(y)?y:x,goal);
        rotate(x,goal);
    }
}
void ins(int x){
    if (!rt){
        rt=++tot;val[rt]=x;cnt[rt]=1;return;
    }
    int now=rt,fat=0;
    while (1){
        if (val[now]==x){
            cnt[now]++;splay(now,rt);return;
        }
        fat=now;now=son[now][x>val[now]];
        if (!now){
            now=++tot;cnt[now]=1;val[now]=x;
            son[fat][x>val[fat]]=now;fa[now]=fat;
            splay(now,rt);return;
        }
    }
}
int pre(){
    if (cnt[rt]>1)return val[rt];
    int now=son[rt][0];while (rs)now=rs;return now;
}
int suf(){
    if (cnt[rt]>1)return val[rt];
    int now=son[rt][1];while (ls)now=ls;return now;
}
void get_rank(int x){
    int now=rt;
    while (1){
        if (x<val[now])now=ls;
        else{
            if (x==val[now]){
                splay(now,rt);return;
            }
            now=rs;
        }
    }
}
void del(int x){
    get_rank(x);
    if (cnt[rt]>1){
        cnt[rt]--;return;
    }
    int now=rt;
    if (!ls&&!rs){
        clear(now);rt=0;return;
    }
    if (ls&&rs){
        int y=pre();splay(y,rt);
        son[y][1]=rs;fa[rs]=y;
        clear(now);return;
    }
    if (ls){
        rt=ls;fa[rt]=0;clear(now);return;
    }
    if (rs){
        rt=rs;fa[rt]=0;clear(now);return;
    }
}
int main(){
    n=read();int tag,flag=0;ins(inf);ins(-inf);
    for (int i=1;i<=n;i++){
        int opt=read(),t=read();
        if (!flag)tag=opt;
        if (opt==tag)ins(t),flag++;
        else{
            ins(t);int x=val[pre()],y=val[suf()];del(t);
            if (t-x<=y-t){
                ans=(ans+t-x)%p;del(x);
            }else{
                ans=(ans+y-t)%p;del(y);
            }flag--;
        }
    }
    printf("%d",ans);
    return 0;
}