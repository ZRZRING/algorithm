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
int head[orz],n,m,cnt;
int log_2[orz],f_min[orz][20],f_max[orz][20],a[orz];
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
int main(){
    n=read();m=read();log_2[0]=-1;
    for (int i=1;i<=n;i++){
        a[i]=read();f_min[i][0]=f_max[i][0]=a[i];
        log_2[i]=log_2[i>>1]+1;
    }
    for (int j=1;j<=log_2[n];j++){
        for (int i=1;i<=n-(1<<j)+1;i++){
            f_max[i][j]=max(f_max[i][j-1],f_max[i+(1<<j-1)][j-1]);
            f_min[i][j]=min(f_min[i][j-1],f_min[i+(1<<j-1)][j-1]);
        }
    }
    for (int i=1;i<=m;i++){
        int l=read(),r=read(),t=log_2[r-l+1];
        printf("%d\n",max(f_max[l][t],f_max[r-(1<<t)+1][t])-
                      min(f_min[l][t],f_min[r-(1<<t)+1][t]));
    }
    return 0;
}