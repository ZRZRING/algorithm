#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=200010;
int n,h,up[N],down[N],above[N],under[N],f[10010][1010],ans=1e9+7,pre[N];
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
int main(){
    n=read();h=read();int t=read();
    for (int i=1;i<=n;i++){
        up[i]=read();down[i]=read();
    }
    for (int i=1;i<=n;i++){
        under[i]=0;above[i]=h+1;
    }
    for (int i=1;i<=t;i++){
        int x=read();pre[x]=1;under[x]=read();above[x]=read();
    }
    for (int i=1;i<=n;i++){
        pre[i]+=pre[i-1];
    }
    memset(f,0x3f,sizeof(f));
    for (int i=1;i<=h;i++){
        f[0][i]=0;
    }
    for (int i=1;i<=n;i++){
        int flag=1;
        for (int j=up[i]+1;j<=up[i]+h;j++){
            f[i][j]=min(f[i-1][j-up[i]]+1,f[i][j-up[i]]+1);
        }
        for (int j=h+1;j<=up[i]+h;j++){
            f[i][h]=min(f[i][h],f[i][j]);
        }
        for (int j=1;j<=h-down[i];j++){
            f[i][j]=min(f[i][j],f[i-1][j+down[i]]);
        }
        for (int j=0;j<=under[i];j++)f[i][j]=0x3f3f3f3f;
        for (int j=above[i];j<=h;j++)f[i][j]=0x3f3f3f3f;
        for (int j=under[i]+1;j<=above[i]-1;j++){
            if (f[i][j]!=0x3f3f3f3f)flag=0;
        }
        if (flag){printf("0\n%d",pre[i-1]);return 0;}
    }
    for (int i=under[n]+1;i<=above[n]-1;i++){
        ans=min(ans,f[n][i]);printf("%d\n",f[n][i]);
    }printf("1\n%d",ans);
    return 0;
}