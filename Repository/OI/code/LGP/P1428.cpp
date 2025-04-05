#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define lowbit(x) x&-x
using namespace std;
const int N=100010;
int n,m,tree[N],a[N];
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
void add(int x){
    for (int i=x;i<=N;i+=lowbit(i))tree[i]++;
}
int query(int x){
    int res=0;
    for (int i=x;i;i-=lowbit(i))res+=tree[i];
    return res;
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read()+1;
    }
    for (int i=1;i<=n;i++){
        add(a[i]);printf("%d ",query(a[i]-1));
    }
    return 0;
}