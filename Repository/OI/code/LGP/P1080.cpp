#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#define l(i) (a[i].l)
#define r(i) (a[i].r)
#define ans(i) (a[i].ans)
using namespace std;
const int orz=500100;
struct hh{
    int l,r,ans;
}a[orz];
int head[orz],n,m,cnt;
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
/*void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}*/
int cmp(hh a,hh b){
    return a.ans<b.ans;
}
int main(){
    n=read();
    for (int i=0;i<=n;i++){
        l(i)=read();r(i)=read();ans(i)=l(i)*r(i);
    }
    sort(a+1,a+n+1,cmp);
    return 0;
}