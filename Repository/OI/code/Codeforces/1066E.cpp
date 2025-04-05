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
const int N=1000010,p=998244353;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,pow_2[N],a[N],b[N],sum[N],ans;
char ch[N];
int main(){
    n=read();m=read();pow_2[0]=1;sum[0]=1;
    for (int i=1;i<=N-5;i++)pow_2[i]=(pow_2[i-1]<<1)%p;
    scanf("%s",ch+1);for (int i=1;i<=n;i++)a[n-i+1]=ch[i]-'0';
    scanf("%s",ch+1);for (int i=1;i<=m;i++)b[m-i+1]=ch[i]-'0';
    // for (int i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
    // for (int i=1;i<=m;i++)printf("%d ",b[i]);printf("\n");
    for (int i=1;i<=n;i++)a[i]=(a[i-1]+pow_2[i-1]*a[i])%p;
    for (int i=1;i<=m;i++)ans=(ans+a[min(i,n)]*b[i])%p;
    printf("%d",ans);
    return 0;
}