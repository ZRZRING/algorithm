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
struct node{
    int x,y,t;
}a[orz];
int head[orz],n,m,cnt,fa[orz],ans;
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
int cmp(node a,node b){
    return a.t<b.t;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=m;i++){
        a[i].x=read(),a[i].y=read(),a[i].t=read();
    }
    sort(a+1,a+m+1,cmp);
    for (int i=1;i<=m;i++){
        int fx=find(a[i].x),fy=find(a[i].y);if (fx==fy)continue;
        fa[fx]=fy;ans=a[i].t;if (++cnt==n-1)break;
    }
    printf("%d %d",n-1,ans);
    return 0;
}