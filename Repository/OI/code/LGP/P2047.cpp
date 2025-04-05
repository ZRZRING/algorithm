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
int n,m,head[N],cnt;
long long dis[1010][1010],tot[1010][1010];
double ans[N];
int main(){
    n=read();m=read();memset(dis,0x3f,sizeof(dis));
    int inf=dis[0][0];
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),t=read();
        dis[x][y]=dis[y][x]=t;tot[x][y]=tot[y][x]=1;
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dis[i][k]==inf&&dis[k][j]==inf)continue;
                if (dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    tot[i][j]=tot[i][k]*tot[k][j];
                    continue;
                }
                if (dis[i][j]==dis[i][k]+dis[k][j]){
                    tot[i][j]+=tot[i][k]*tot[k][j];
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j)continue;
            for (int k=1;k<=n;k++){
                if (i==k||j==k)continue;
                if (dis[i][k]+dis[k][j]==dis[i][j]){
                    ans[k]+=(1.0*tot[i][k]*tot[k][j])/tot[i][j];
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        printf("%.3lf\n",ans[i]);
    }
    return 0;
}