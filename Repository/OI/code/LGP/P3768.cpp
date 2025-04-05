#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=5000010;
int prime[N],cnt,phi[N];
int n,p,inv_4,inv_6,ans[N];
bool flag[N],vis[N];
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
int inv(int a,int x){
	int res=1;
	while (x){
		if (x&1)res=res*a%p;
		a=a*a%p;x>>=1;
	}
	return res;
}
void init(){
    inv_4=inv(4,p-2);inv_6=inv(6,p-2);
    phi[1]=1;
    for (register int i=2;i<=N;i++){
        if (!flag[i]){
            phi[i]=i-1;prime[++cnt]=i;
        }
        for (int j=1;j<=cnt&&i*prime[j]<=N;j++){
            flag[i*prime[j]]=1;
            if (i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j]%p;break;
            }phi[i*prime[j]]=phi[i]*(prime[j]-1)%p;
        }
    }
    for (register int i=1;i<=N;i++){
        phi[i]=phi[i]*i%p*i%p;
        phi[i]=(phi[i]+phi[i-1])%p;
    }
}
int s2(int x){
    return x%p*(x+1)%p*(2*x%p+1)%p*inv_6%p;
}
int s3(int x){
    return x%p*x%p*(x+1)%p*(x+1)%p*inv_4%p;
}
int cal(int x){
    if (x<=N)return phi[x];
    int y=n/x;
    if (vis[y])return ans[y];
    ans[y]=s3(x);
    for (int l=2,r;l<=x;l=r+1){
        r=x/(x/l);
        ans[y]=(ans[y]-(s2(r)-s2(l-1))*cal(x/l)%p+p)%p;
    }vis[y]=1;return ans[y];
}
signed main(){
    p=read();init();n=read();int ans=0;
    for (int l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        ans=(ans+((cal(r)-cal(l-1))+p)%p*s3(n/l)%p)%p;
    }
    printf("%lld",ans);
    return 0;
}