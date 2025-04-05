#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[1000100];
int head[1000100],n,m,cnt;
int a[1000100],p[1000100],dp[2][1<<10][1<<10],ans,sum[1000100];
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
int main(){file();
    n=read();m=read();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char ch;cin>>ch;a[i]<<=1;a[i]+=(ch=='H');
        }
    }
    //for (int i=1;i<=n;i++)cout<<a[i]<<endl;
    for (int i=0;i<=(1<<m);i++){
        p[i]=(i&(i<<1))||(i&(i<<2));//cout<<i<<':'<<p[i]<<endl;
        if (p[i])continue;int tmp=i;
        while (tmp)sum[i]+=(tmp&1),tmp>>=1;//cout<<i<<':'<<sum[i]<<endl;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<(1<<m);j++){
            if (p[j]||j&a[i])continue;
            for (int k=0;k<(1<<m);k++){
                if (p[k]||k&a[i-1])continue;
                if (j&k)continue;
                for (int ek=0;ek<(1<<m);ek++){
                    if (p[ek]||ek&a[i-2])continue;
                    if (j&ek||k&ek)continue;
                    dp[i%2][j][k]=max(dp[i%2][j][k],dp[(i-1)%2][k][ek]+sum[j]);
                }
            }
        }
    }n%=2;
    for (int i=0;i<(1<<m);i++){
        for (int j=0;j<(1<<m);j++){
            ans=max(ans,dp[n][i][j]);
        }
    }
    printf("%d",ans);
    return 0;
}