#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
#define reg register
using namespace std;
const int orz=500100,N=100005;
bitset<orz+5> pos,neg;
/*struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];*/
struct node{
    int l,r,lnum,rnum,id,x,t;
}q[orz];
int head[orz],n,m,cnt[orz],ans[orz],a[orz],l=1,r;
inline void add(int x){
    neg[N-a[x]]=(++cnt[a[x]]!=0);pos[a[x]]=(cnt[a[x]]!=0);
}
inline void del(int x){
    neg[N-a[x]]=(--cnt[a[x]]!=0);pos[a[x]]=(cnt[a[x]]!=0);
}
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
/*void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}*/
inline int cmp(node a,node b){
    return a.lnum==b.lnum ? (a.lnum%2 ? a.r<b.r : a.r>b.r) :a.l<b.l;
}
int main(){//file();
    pos[0]=0;pos[N]=0;neg[0]=0;neg[N]=0;
    n=read();m=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    int size=n/sqrt(2*m/3);
    for (reg int i=1;i<=m;i++){
        q[i].t=read();q[i].l=read();q[i].r=read();q[i].x=read();
        q[i].lnum=q[i].l/size;q[i].rnum=q[i].r/size;
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    for (reg int i=1;i<=m;i++){
        while (l>q[i].l)add(--l);
        while (r<q[i].r)add(++r);
        while (l<q[i].l)del(l++);
        while (r>q[i].r)del(r--);
        if (q[i].t==1){
            if ((pos&(pos<<q[i].x)).any())ans[q[i].id]=1;
        }
        if (q[i].t==2){
            if ((neg>>(N-q[i].x)&pos).any())ans[q[i].id]=1;
        }
        if(q[i].t==3){
            for (int j=1;j*j<=q[i].x;j++){
                if (q[i].x%j==0){
                    if (pos[j]&&pos[q[i].x/j]){
                        ans[q[i].id]=1;break;
                    }
                }
            }
        }
    }
    for (reg int i=1;i<=m;i++){
        if (ans[i])printf("hana\n");
        else printf("bi\n");
    }
    return 0;
}
