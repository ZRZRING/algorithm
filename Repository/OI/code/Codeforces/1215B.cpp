#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
#define ls now<<1
#define rs now<<1|1
using namespace std;
const int N=200010;
int n,m,z,f,dpz[N],dpf[N];
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
    n=read();
    for (int i=1;i<=n;i++){
        int zz=z,ff=f,x=read();
        if (x>0){
            z=zz+1;f=ff;
        }else{
            z=ff;f=zz+1;
        }
        dpz[i]=dpz[i-1]+z;dpf[i]=dpf[i-1]+f;
    }
    cout<<dpf[n]<<' '<<dpz[n];
    return 0;
}