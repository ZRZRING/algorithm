#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m;
struct node{
    int l,r,id;
}dat[N];
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        dat[i].l=read();dat[i].r=read();dat[i].id=read();
    }
    sort(dat+1,dat+n+1,cmp);
    for (int i=1;i<=n;i++){

    }
    return 0;
}