#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
struct AC{
    int vis[2],fail,end;
}ac[N];
int n,m,cnt,vis[N],p[N];
char ch[N];
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
void insert(char *ch){
    int len=strlen(ch),u=0;
    for (int i=0;i<len;i++){
        int v=ch[i]-'0';
        if (!ac[u].vis[v])ac[u].vis[v]=++cnt;
        u=ac[u].vis[v];
    }ac[u].end=1;
}
void build(){
    queue<int>q;
    for (int i=0;i<=1;i++){
        int v=ac[0].vis[i];
        if (v){
            ac[v].fail=0;q.push(v);
        }
    }
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=0;i<=1;i++){
            int v=ac[u].vis[i];
            if (v){
                ac[v].fail=ac[ac[u].fail].vis[i];
                ac[v].end|=ac[ac[v].fail].end;q.push(v);
            }else{
                ac[u].vis[i]=ac[ac[u].fail].vis[i];
            }
        }
    }
}
void dfs(int u){
	if (vis[u]){
        printf("TAK\n");exit(0);
    }if (p[u]||ac[u].end)return;
	vis[u]=1;p[u]=1;
	dfs(ac[u].vis[0]);dfs(ac[u].vis[1]);
	vis[u]=0;
}
int main(){file();
    n=read();
    for (int i=1;i<=n;i++){
        scanf("%s",ch);insert(ch);
    }build();dfs(0);
    printf("NIE\n");
    return 0;
}