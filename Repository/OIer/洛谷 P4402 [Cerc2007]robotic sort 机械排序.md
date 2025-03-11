[文艺平衡树](https://www.luogu.com.cn/problem/P3391)的[题解](/note/code/luogu/3391)

蒟蒻学习Splay第二天，这个题可以说和文艺平衡树几乎一样了，但是我硬生生调了一个上午

这个题和那个题的区别在于，你需要首先对于数据进行一些处理，比较简单，一个结构体记录读入的数据$val$和$id$，按$val$排序后，每次交换的就是$i$到$id$了


```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#define ls (son[now][0])
#define rs (son[now][1])
using namespace std;
const int N=500100,inf=1e9;
struct node{
    int id,val;
}a[N];
int n,m,cnt[N],rt,son[N][2],fa[N],size[N],tag[N];
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
int cmp(node a,node b){
    return a.val==b.val?a.id<b.id:a.val<b.val;
}
void pushup(int now){
    size[now]=size[ls]+size[rs]+1;
}
int build(int l,int r,int fat){
    if (l>r)return 0;
    int now=l+r>>1;fa[now]=fat;size[now]=1;
    son[now][0]=build(l,now-1,now);
    son[now][1]=build(now+1,r,now);
    pushup(now);return now;
}
bool l_r(int x){
    return x==son[fa[x]][1];
}
void pushdown(int now){
    if (!tag[now])return;
    swap(ls,rs);tag[ls]^=1;tag[rs]^=1;
    tag[now]=0;
}
void rotate(int x,int &goal){
    int y=fa[x],z=fa[y],kind=l_r(x);
    pushdown(y);pushdown(x);
    if (y==goal)goal=x;else son[z][l_r(y)]=x;
    son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
    son[x][kind^1]=y;fa[y]=x;fa[x]=z;
    pushup(y);pushup(x);
}
void splay(int x,int &goal){
    for (int y=fa[x];x!=goal;y=fa[x]){
        pushdown(fa[y]);pushdown(y);pushdown(x);
        //我们发现，主程序里那个splay之前没有find操作，也就是没有任何pushdown，所以这里要pushdown
        if (y!=goal)rotate(l_r(x)==l_r(y)?y:x,goal);
        rotate(x,goal);
    }
}
int find(int x){
    int now=rt;
    while (1){
        pushdown(now);
        if (ls&&x<=size[ls])now=ls;
        else{
            x-=size[ls]+1;if (x<=0)return now;now=rs;
        }
    }
}
void rever(int l,int r){
    int x=find(l-1),y=find(r+1);
    splay(x,rt);splay(y,son[x][1]);
    //这里的splay在find后面，已经pushdown完了
    tag[son[y][0]]^=1;
}
int main(){
    n=read();
    for (int i=2;i<=n+1;i++){
        a[i].val=read();a[i].id=i;
    }a[1].id=1;a[n+2].id=n+2;
    sort(a+2,a+n+2,cmp);rt=build(1,n+2,0);
    for (int i=2;i<=n;i++){
        splay(a[i].id,rt);
        printf("%d ",size[son[rt][0]]);
        rever(i,size[son[rt][0]]+1);
    }
    printf("%d",n);
    return 0;
}
```
