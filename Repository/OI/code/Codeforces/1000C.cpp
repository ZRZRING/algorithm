#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
struct node{
    int pos,t;
}dat[N];
int n,m,ans[N];
bool cmp(node a,node b){
    return a.pos<b.pos;
}
signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        int l=read(),r=read();
        dat[i]={l,1};dat[i+n]={r+1,-1};
    }
    sort(dat+1,dat+n+n+1,cmp);
    int x=dat[1].t;
    for (int i=2,l=dat[1].pos,r;i<=n<<1;i++,l=r){
        r=dat[i].pos;
        ans[x]+=r-l;
        x+=dat[i].t;
        while (dat[i+1].pos==dat[i].pos){
            i++;x+=dat[i].t;
        }
    }
    for (int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}