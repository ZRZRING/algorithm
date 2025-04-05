#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define tsum(x) tree[x].sum
#define tpow(x) tree[x].pow
#define ls now<<1
#define rs now<<1|1
using namespace std;
const int N=100010;
struct node{
    double pow,sum;
}tree[N<<2];
int n,m;
double tag[N<<2],a[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void pushup(int now){
    tsum(now)=tsum(ls)+tsum(rs);
    tpow(now)=tpow(ls)+tpow(rs);
}
void build(int now,int l,int r){
    if (l==r){
        tsum(now)=a[l];tpow(now)=a[l]*a[l];
        return;
    }int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    pushup(now);
}
void lazy(int now,int l,int r,double t){
    int len=r-l+1;
    tpow(now)+=2.0*tsum(now)*t+len*t*t;
    tsum(now)+=len*t;
    tag[now]+=t;
}
void pushdown(int now,int l,int r,int mid){
    if (!tag[now])return;
    lazy(ls,l,mid,tag[now]);
    lazy(rs,mid+1,r,tag[now]);
    tag[now]=0;
}
void add(int now,int l,int r,int x,int y,double t){
    if (x<=l&&r<=y){
        lazy(now,l,r,t);return;
    }int mid=l+r>>1;pushdown(now,l,r,mid);
    if (mid>=x)add(ls,l,mid,x,y,t);
    if (mid+1<=y)add(rs,mid+1,r,x,y,t);
    pushup(now);
}
double query_pow(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tpow(now);
    }int mid=l+r>>1;pushdown(now,l,r,mid);double res=0;
    if (mid>=x)res+=query_pow(ls,l,mid,x,y);
    if (mid+1<=y)res+=query_pow(rs,mid+1,r,x,y);
    return res;
}
double query_sum(int now,int l,int r,int x,int y){
    if (x<=l&&r<=y){
        return tsum(now);
    }int mid=l+r>>1;pushdown(now,l,r,mid);double res=0;
    if (mid>=x)res+=query_sum(ls,l,mid,x,y);
    if (mid+1<=y)res+=query_sum(rs,mid+1,r,x,y);
    return res;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }build(1,1,n);
    for (int i=1;i<=m;i++){
        int opt=read(),x=read(),y=read();
        if (opt==1){
            double t;scanf("%lf",&t);
            add(1,1,n,x,y,t);
        }if (opt==2){
            double q_sum=query_sum(1,1,n,x,y);int len=y-x+1;
            double sum=q_sum/len;
            printf("%.4lf\n",sum);
        }if (opt==3){
            double q_pow=query_pow(1,1,n,x,y);
            double q_sum=query_sum(1,1,n,x,y);
            int len=y-x+1;
            double sum=q_sum/len,pow=q_pow/len;
            printf("%.4lf\n",pow-sum*sum);
        }
    }
    //printf("%lf %lf\n",query_pow(1,1,n,1,7),query_sum(1,1,n,1,7));
    //printf("%lf %lf",tsum(2),tpow(2));
    return 0;
}