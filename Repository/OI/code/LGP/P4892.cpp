#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#define int long long
using namespace std;
const int orz=500100,p=19260817;
int n,m,mp[20][20],f[20][1<<20][2],sum[orz];
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
int cal(int x){
    int res=0,cnt=0;
    while (x){
        cnt++;res+=(x&1)*cnt;x>>=1;
    }return res;
}
signed main(){file();
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        if (x!=y)mp[x][y]++,mp[y][x]++;
    }
    f[1][1][0]=1;
    for (int j=0;j<(1<<n);j++){
        for (int u=1;u<=n;u++){
            if (j&(1<<(u-1))){
                for (int v=1;v<=n;v++){
                    if (!mp[u][v])continue;
                    int tmp=(f[u][j][0]*mp[u][v])%p;
                    f[v][j|(1<<(v-1))][v*cal(j)%2]+=tmp;
                    f[v][j|(1<<(v-1))][v*cal(j)%2]%=p;
                    tmp=(f[u][j][1]*mp[u][v])%p;
                    f[v][j|(1<<(v-1))][(v*cal(j)+1)%2]+=tmp;
                    f[v][j|(1<<(v-1))][(v*cal(j)+1)%2]%=p;
                }
            }
        }
    }
    int c=read(),ans=0;
    for (int i=1<<n-1;i<=(1<<n)-1;i++){
        ans+=f[n][i][c];ans%=p;//printf("f[%lld][%lld][%lld]=%lld\n",n,i,c,f[n][i][c]);
    }
    printf("%lld",ans);
    return 0;
}