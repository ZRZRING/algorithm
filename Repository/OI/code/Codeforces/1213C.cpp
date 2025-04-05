#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=100010;
int n,m;
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
signed main(){
    int T=read();
    while (T--){
        int n=read(),m=read();
        if (n<m){
            printf("0\n");continue;
        }
        int vis[11]={0},ans=0,cnt=1;
        for (int i=m;i<=n;i+=m,cnt++){
            if (vis[i%10])break;
            ans+=i%10;vis[i%10]=1;
        }cnt--;
        //cout<<ans<<' '<<n<<' '<<m<<' '<<cnt<<endl;
        ans=ans*(n/m/cnt);n=n%(m*cnt);
        for (int i=m;i<=n;i+=m){
            ans+=i%10;
        }printf("%lld\n",ans);
    }
    return 0;
}