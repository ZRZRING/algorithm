#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define lowbit(x) (x&-x)
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,tree[N];
void add(int x,int t){
    for (int i=x;i<=n;i+=lowbit(i))tree[i]+=t;
}
int query(int x){
    int res=0;
    for (int i=x;i;i-=lowbit(i))res+=tree[i];
    return res;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++)add(i,read());
    for (int i=1;i<=m;i++){
        int opt=read();if (opt==1){int x=read(),t=read();add(x,t);}
        else{int x=read(),y=read();printf("%d\n",query(y)-query(x-1));}
    }
    return 0;
}