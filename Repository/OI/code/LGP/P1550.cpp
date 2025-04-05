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
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
struct EDGE{
    int pre,ver,dis;
}edge[N];
int n,m,fa[N];
bool cmp(EDGE a,EDGE b){
    return a.dis<b.dis;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
    n=read();int cnt=0,tot=0,ans=0;
    for (int i=1;i<=n;i++){
        int x=read();
        edge[++cnt].pre=i;
        edge[cnt].ver=n+1;
        edge[cnt].dis=x;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x=read();
            if (i>j){
                edge[++cnt].pre=i;
                edge[cnt].ver=j;
                edge[cnt].dis=x;
            }
        }
    }
    sort(edge+1,edge+cnt+1,cmp);
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=cnt;i++){
        int u=edge[i].pre,v=edge[i].ver;
        int fx=find(u),fy=find(v);
        if (fx!=fy)fa[fx]=fy,ans+=edge[i].dis,tot++;
        if (tot==n)break;
    }
    printf("%d\n",ans);
    return 0;
}