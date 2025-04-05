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
char str[1001];
queue<int>q;
/*struct node{
    int l,r,lnum,rnum,id,x,t;
}q[orz];*/
int head[orz],n,m,cnt,a[orz],vis[orz],fa[orz],d[orz];
int mp[1001][1001],s;char ans[orz];
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
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int u){
    for (int v=20;v<=200;v++){
        if(mp[u][v])mp[u][v]=mp[v][u]=0,dfs(v);
    }
    ans[n--]=u;
}
int main(){
    n=read();int s=0;
    for (int i=20;i<=200;i++)fa[i]=i;
    for (int i=1;i<=n;i++){
        scanf("%s",str);
        mp[str[0]][str[1]]=mp[str[1]][str[0]]=1;
        int fx=find(str[0]),fy=find(str[1]);
        if (fx!=fy)fa[fx]=fy;d[str[0]]++;d[str[1]]++;
    }
    int tot=0;
    for (int i=20;i<=200;i++)if(fa[i]==i&&d[i])tot++;
    if (tot!=1){printf("No Solution");return 0;}
    for (int i=20;i<=200;i++){
        if (d[i]&1){
            cnt++;if(!s)s=i;
        }
    }
    if (cnt&&cnt!=2){
        puts("No Solution");return 0;
    }
    if (!s){
        for(int i=20;i<=200;i++){
            if(d[i]){
                s=i;break;
            }
        }
    }
    dfs(s);puts(ans);
    return 0;
}