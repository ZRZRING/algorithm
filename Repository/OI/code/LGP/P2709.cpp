#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
const int orz=500100;
/*struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];*/
struct node{
    int l,r,lnum,rnum,id;
}q[orz];
int head[orz],n,m,cnt[orz],l,r,ans[orz],tmp,a[orz],k;
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
void add(int x){
    tmp+=(cnt[a[x]]<<1)+1;cnt[a[x]]++;
}
void del(int x){
    tmp-=(cnt[a[x]]<<1)-1;cnt[a[x]]--;
}
int cmp(node a,node b){
    return a.lnum==b.lnum ? (a.lnum%2 ? a.r<b.r : a.r>b.r) : a.l<b.l;
}
int main(){
    n=read();m=read();k=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    int size=n/sqrt(2*m/3);
    for (int i=1;i<=m;i++){
        q[i].l=read();q[i].r=read();
        q[i].lnum=q[i].l/size;
        q[i].rnum=q[i].r/size;
        q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    for (int i=1;i<=m;i++){
        while (l>q[i].l)add(--l);
        while (l<q[i].l)del(l++);
        while (r<q[i].r)add(++r);
        while (r>q[i].r)del(r--);
        ans[q[i].id]=tmp;
    }
    for (int i=1;i<=m;i++){
        printf("%d\n",ans[i]-1);
    }
    return 0;
}
