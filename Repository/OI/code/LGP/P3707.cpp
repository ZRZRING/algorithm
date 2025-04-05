#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;
const int orz=500100;
const double eps=1e-9;
struct TREE{
    double x,y,xy,x2;
}tree[orz];
long long n,m,cnt,dx[orz],dy[orz],sum[orz],power_sum[orz];
double tx[orz],ty[orz],tcx[orz],tcy[orz];
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
void pushup(int now){
    TREE *k=tree+now,*ls=tree+(now<<1),*rs=tree+(now<<1|1);
    k->x=ls->x+rs->x;k->y=ls->y+rs->y;
    k->xy=ls->xy+rs->xy;k->x2=ls->x2+rs->x2;
}
void build(int now,int l,int r){
    if (l==r){
        tree[now]=(TREE){dx[l],dy[l],dx[l]*dy[l],dx[l]*dx[l]};return;
    }
    int mid=l+r>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushup(now);
}
void lazy(int now,int l,int r,double S,double T){
    TREE *k=tree+now;int len=r-l+1;
    tx[now]+=S;ty[now]+=T;
    k->xy+=len*S*T+S*k->y+T*k->x;
    k->x2+=len*S*S+2*S*k->x;
    k->x+=len*S;k->y+=len*T;
}
void lazy2(int now,int l,int r,double S,double T){
    TREE *k=tree+now;int len=r-l+1;
    tcx[now]=S;tcy[now]=T;tx[now]=ty[now]=0;
    long long tsum=sum[r]-sum[l-1],tpower=power_sum[r]-power_sum[l-1];
    k->xy=len*S*T+(S+T)*tsum+tpower;
    k->x2=len*S*S+2*S*tsum+tpower;
    k->x=len*S+tsum;k->y=len*T+tsum;
}
bool sgn(double x){return (x>eps)-(x<-eps);}
void pushdown(int now,int l,int r){
    int mid=l+r>>1;
    if(sgn(tcx[now])||sgn(tcy[now])){
        lazy2(now<<1,l,mid,tcx[now],tcy[now]);
        lazy2(now<<1|1,mid+1,r,tcx[now],tcy[now]);
        tcx[now]=tcy[now]=0;
    }
    if(sgn(tx[now])||sgn(ty[now])){
        lazy(now<<1,l,mid,tx[now],ty[now]);
        lazy(now<<1|1,mid+1,r,tx[now],ty[now]);
        tx[now]=0;ty[now]=0;
    }
}
void change(int now,int l,int r,int x,int y,double S,double T){
    if (x<=l&&r<=y){
        lazy(now,l,r,S,T);return;
    }
    int mid=l+r>>1;
    pushdown(now,l,r);
    if (mid>=x)change(now<<1,l,mid,x,y,S,T);
    if (mid+1<=y)change(now<<1|1,mid+1,r,x,y,S,T);
    pushup(now);
}
void change2(int now,int l,int r,int x,int y,double S,double T){
    if (x<=l&&r<=y){
        lazy2(now,l,r,S,T);return;
    }
    int mid=l+r>>1;
    pushdown(now,l,r);
    if (mid>=x)change2(now<<1,l,mid,x,y,S,T);
    if (mid+1<=y)change2(now<<1|1,mid+1,r,x,y,S,T);
    pushup(now);
}
TREE ask(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tree[now];
    }
    int mid=l+r>>1;TREE res={0,0,0,0};
    pushdown(now,l,r);
    if (mid>=x){
        TREE tmp=ask(now<<1,l,mid,x,y);
        res.x+=tmp.x;
        res.y+=tmp.y;
        res.xy+=tmp.xy;
        res.x2+=tmp.x2;
    }
    if (mid+1<=y){
        TREE tmp=ask(now<<1|1,mid+1,r,x,y);
        res.x+=tmp.x;
        res.y+=tmp.y;
        res.xy+=tmp.xy;
        res.x2+=tmp.x2;
    }
    return res;
}
double cal(int l,int r){
    double len=(r-l+1)*1.0;TREE a=ask(1,1,n,l,r);
    double x=a.x,y=a.y,xy=a.xy,x2=a.x2;
    return (xy-x/len*y)/(x2-x*x/len);
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)dx[i]=read(),sum[i]=sum[i-1]+i;
    for(int i=1;i<=n;i++)dy[i]=read(),power_sum[i]=power_sum[i-1]+1ll*i*i;
    build(1,1,n);
    for (int i=1;i<=m;i++){
        int tmp=read();
        if (tmp==1){
            double x=read(),y=read();
            printf("%.10lf\n",cal(x,y));
        }
        if (tmp==2){
            int x=read(),y=read();double s=read(),t=read();
            change(1,1,n,x,y,s,t);
        }
        if (tmp==3){
            int x=read(),y=read();double s=read(),t=read();
            change2(1,1,n,x,y,s,t);
        }
    }
    return 0;
}