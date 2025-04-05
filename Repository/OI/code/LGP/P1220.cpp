#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,s,w[1000100],tmp,sum[1000100],f[1001][1001][3];
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
    n=read();s=read();memset(f,0x3f,sizeof(f));
    for (int i=1;i<=n;i++){
        w[i]=read();tmp=read();sum[i]=sum[i-1]+tmp;
    }
    f[s][s][1]=f[s][s][0]=0;
    for (int j=s;j<=n;j++){
        for (int i=j-1;i>=1;i--){
            f[i][j][0]=min(f[i+1][j][0]+(w[i+1]-w[i])*(sum[n]-sum[j]+sum[i]),
                           f[i+1][j][1]+(w[j]-w[i])*(sum[n]-sum[j]+sum[i]));
            f[i][j][1]=min(f[i][j-1][0]+(w[j]-w[i])*(sum[n]-sum[j-1]+sum[i-1]),
                           f[i][j-1][1]+(w[j]-w[j-1])*(sum[n]-sum[j-1]+sum[i-1]));
        }
    }
    cout<<min(f[1][n][0],f[1][n][1]);
}