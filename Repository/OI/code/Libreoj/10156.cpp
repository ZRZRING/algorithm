#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,nxt;
}edge[1000100];
int f[100010][2],cnt,head[1000100],n,p[1000100];
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
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
void dp(int u){
    f[u][0]=0;f[u][1]=1;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;dp(v);
        f[u][0]+=f[v][1];f[u][1]+=min(f[v][1],f[v][0]);
    }  
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read(),size=read();
        for (int i=1;i<=size;i++){
            int tmp=read();p[tmp]=1;add(x,tmp);
        }
    }
    int root=0;while(p[root])root++;dp(root);
    printf("%d",min(f[root][0],f[root][1]));
    return 0;
}