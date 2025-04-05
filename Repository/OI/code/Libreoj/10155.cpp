#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,d1[1000100],d2[1000100],sum[1000100],ans;
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
void ready(){
    for (int i=1;i<=n;i++){
        for (int j=2;j<=n/i;j++){
            if (i*j>n)break;
            sum[i*j]+=i;
        }
    }
}
int main(){
    n=read();
    ready();
    for (int i=n;i>=1;i--){
        if (i>sum[i]){
            if (d1[i]+1>d1[sum[i]]){
                d2[sum[i]]=d1[sum[i]];
                d1[sum[i]]=d1[i]+1;
            }else{
                if(d1[i]+1>d2[sum[i]]){
                    d2[sum[i]]=d1[i]+1;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (d1[i]+d2[i]>ans)ans=d1[i]+d2[i];
    }
    printf("%d",ans);
    return 0;
}