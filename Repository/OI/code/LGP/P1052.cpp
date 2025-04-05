#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int m,l,r,dp[1000100],n,w[1000100],last,cf[1000100],p[1000100],ans;
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
    m=read();l=read();r=read();n=read();
    if (r>m){
        printf("0");return 0;
    }
    memset(dp,0x3f,sizeof(dp));
    for (int i=1;i<=n;i++)w[i]=read();
    sort(w+1,w+n+1);w[0]=0;
    if (l==r){
        int res=0;
        for (int i=1;i<=n;i++)res+=(w[i]%l==0);
        printf("%d",res);return 0;
    }
    cf[n+1]=min(m-w[n],100);m=0;
    for(int i=1;i<=n;i++){
        cf[i]=min(w[i]-w[i-1],100);
        m+=cf[i];p[m]=1;
    }
    m+=cf[n+1];dp[0]=0;
    for (int i=1;i<=m+10;i++){
        for (int j=i-r;j<=i-l;j++){
            if(j<0)continue;
            dp[i]=min(dp[i],dp[j]+p[j]);
        }
    }ans=1<<30;
    for (int i=m;i<=m+10;i++){
        ans=min(ans,dp[i]);
    }
    printf("%d",ans);
}