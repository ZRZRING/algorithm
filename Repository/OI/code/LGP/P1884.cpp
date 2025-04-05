#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls (now<<1)
#define rs (now<<1|1)
#define int long long
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=2000010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
struct TREE{
    int l,r,len,cnt;
}tree[N];
struct node{
    int y,l,r,t;
}pos[N];
int n,m,cnt,rk[N];
void pushup(int l,int r,int now){
    if (tree[now].cnt){
        tree[now].len=rk[r+1]-rk[l];
    }else{
        tree[now].len=tree[ls].len+tree[rs].len;
    }
}
void add(int now,int l,int r,int x,int y,int t){
    if (x<=l&&r<=y){
        tree[now].cnt+=t;pushup(l,r,now);return;
    }int mid=l+r>>1;
    if (mid>=x)add(ls,l,mid,x,y,t);
    if (mid+1<=y)add(rs,mid+1,r,x,y,t);
    pushup(l,r,now);
}
bool cmp(node a,node b){
    return a.y<b.y;
}
signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x1=read(),y2=read(),x2=read(),y1=read();
        pos[(i<<1)-1]=(node){y1,x1,x2,+1};
        rk[(i<<1)-1]=x1;
        pos[i<<1]=(node){y2,x1,x2,-1};
        rk[i<<1]=x2;
    }
    n<<=1;
    sort(rk+1,rk+n+1);
    sort(pos+1,pos+n+1,cmp);
    for (int i=1;i<=n;i++){
        pos[i].l=lower_bound(rk+1,rk+n+1,pos[i].l)-rk;
        pos[i].r=lower_bound(rk+1,rk+n+1,pos[i].r)-rk;
    }
    long long ans=0;
    for (int i=1;i<n;i++){
        add(1,1,n,pos[i].l,pos[i].r-1,pos[i].t);
        ans+=tree[1].len*(pos[i+1].y-pos[i].y);
    }
    printf("%lld",ans);
    return 0;
}