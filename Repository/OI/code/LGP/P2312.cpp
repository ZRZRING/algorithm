#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
void file(){
    freopen("2312_2.in","r",stdin);
    freopen("2312_2.ans","w",stdout);
}
const int N=500010,p=998244353;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=((res<<3)%p+(res<<1)%p+(ch^48))%p,ch=getchar();
    return sym?-res:res;
}
int n,m,a[N],cnt,ans[N];
bool check(int x){
    int res=a[n];
    for (int i=n-1;i>=0;i--){
        res=(res*x%p+a[i])%p;
    }
    return !res;
}
signed main(){//file();
    n=read();m=read();
    for (int i=0;i<=n;i++){
        a[i]=read();
    }
    for (int i=0;i<=m;i++){
        if (check(i)){
            ans[++cnt]=i;
        }
    }
    printf("%lld\n",cnt);
    for (int i=1;i<=cnt;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}