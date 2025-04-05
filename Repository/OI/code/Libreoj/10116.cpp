#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,tree[100010];
char ch;
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
int lowbit(int x){
    return x&(-x);
}
int sum(int x){
    int ans=0;
    while (x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(int x,int t){
    while (x<=100000){
        tree[x]+=t;
        x+=lowbit(x);
    }
}
int main(){file();
    n=read();m=read();
    for (int i=1;i<=m;i++){
        cin>>ch;
        if (ch=='A'){
            int x=read();
            printf("%d\n",sum(x));
        }
        if (ch=='B'){
            int x=read(),t=read();
            add(x,t);
        }
        if (ch=='C'){
            int x=read(),t=read();
            add(x,-t);
        }
    }
    return 0;
}