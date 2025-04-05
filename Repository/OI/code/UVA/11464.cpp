#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=20,inf=1e9+7;
int n,m,ans=inf,a[N][N],b[N][N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int check(int s){
    memset(b,0,sizeof(b));
    int res=0;
    for (int i=0;i<n;i++){
        if (s&(1<<i)){
            b[1][i+1]=1;
        }else if (a[1][i+1])return inf;
    }
    for (int i=2;i<=n;i++){
        for (int j=1;j<=n;j++){
            int cnt=0;
            if (i>2)cnt+=b[i-2][j];
            if (j>1)cnt+=b[i-1][j-1];
            if (j<n)cnt+=b[i-1][j+1];
            b[i][j]=cnt&1;
            if (a[i][j]==1&&b[i][j]==0)return inf;
        }
    }
    for (int i=1;i<=n;i++){
        int cnt=b[n-1][i]+b[n][i-1]+b[n][i+1];
        if (cnt&1)return inf;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (b[i][j]!=a[i][j])res++;
        }
    }
    return res;
}
int main(){
    int T=read();
    for (int cnt=1;cnt<=T;cnt++){
        n=read();ans=inf;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                a[i][j]=read();
            }
        }
        for (int s=0;s<1<<n;s++){
            ans=min(ans,check(s));
        }
        if (ans==inf)ans=-1;
        printf("Case %d: %d\n",cnt,ans);
    }
    return 0;
}