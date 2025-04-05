#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
const int orz=500100;
int n,ans,tot[1000010];
//c[i]表示i作为因子的次数
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
int main(){
    n=read();
    for(int t=1;t<=n;t++){
        int x=read();ans=max(ans,x);
        for(int i=1;i<=sqrt(x);i++){
            if(x%i==0){
                tot[i]++;if(x!=i*i)tot[x/i]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        while(tot[ans]<i)ans--;printf("%d\n",ans);
    }
    return 0;
}