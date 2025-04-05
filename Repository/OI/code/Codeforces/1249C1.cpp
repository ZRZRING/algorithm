#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long 
using namespace std;
const int N=37;
int mul[50],a[50];
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
signed main(){
    mul[0]=1;
    for (int i=1;i<=N;i++){
        mul[i]=mul[i-1]*3;
    }
    int T=read();
    while (T--){
        int flag=0,pos=-1,n=read(),cnt=-1,tn=n;
        memset(a,0,sizeof(a));
        while (tn){
            a[++cnt]=tn%3;tn/=3;
            if (a[cnt]==2)pos=cnt;
        }
        if (~pos){
            while (a[pos])pos++;a[pos]=1;
            for (int i=0;i<pos;i++)a[i]=0;
        }
        int ans=0;
        for (int i=0;i<=N;i++){
            ans+=a[i]*mul[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}