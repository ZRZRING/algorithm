#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=2000010;
int n,L,a[N],b[N],sum[N],f[N],q[N];
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
    return f[x]+b[x]*b[x];
}
signed main(){
    n=read();L=read();
    for (int i=1;i<=n;i++){
        sum[i]=read()+sum[i-1];
        a[i]=sum[i]+i;b[i]=sum[i]+i+L+1;
    }int head=1,tail=1;b[0]=L+1;
    for (int i=1;i<=n;i++){
        while (head<tail&&cal(q[head+1])-cal(q[head])<=2*a[i]*(b[q[head+1]]-b[q[head]]))head++;
        f[i]=a[i]*a[i]-2*a[i]*b[q[head]]+f[q[head]]+b[q[head]]*b[q[head]];
        while (head<tail&&(cal(q[tail])-cal(q[tail-1]))*(b[i]-b[q[tail]])>=(cal(i)-cal(q[tail]))*(b[q[tail]]-b[q[tail-1]]))tail--;
        q[++tail]=i;
    }
    printf("%lld",f[n]);
    return 0;
}