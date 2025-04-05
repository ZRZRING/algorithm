<!--more--> 

> 找到一个长为$n$序列$b$，对于给定的序列$a$，使得$b$序列的数两两互质并最小化$\sum|a_i - b_i|$

吐槽一句，图片的那个箱子在S4E2出现，但是TS在S3结尾有了翅膀，这幅图根本没有翅膀好吧

从数据范围看出这是一道状压dp，考虑对于一个序列所有数都互质，当且仅当所有数的质因子互不相同，于是我们枚举每一个$b_i$的值，$p_i$表示$i$的质因数集合，$dp[i][j]$表示前$i$个数用$j$集合的质因子得到的最小的$\sum|a_i - b_i|$，容易得到转移方程

$$dp[i][j] = \min_{p[k]\subset j} |a_i - b_i| + dp[i - 1][j - p_k]$$

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010,inf=1e9+7,prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int n,m,a[N],f[101][1<<16],p[N],ans[101][1<<16];
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
void write(int now,int x){
    if(!now)return;
    write(now-1,x^p[ans[now][x]]);
    printf("%d ",ans[now][x]);
}
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    for (int i=1;i<=58;i++){
        for (int j=0;j<16;j++){
            if (i%prime[j]==0){
                p[i]^=(1<<j);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<(1<<16);j++){
            f[i][j]=1e9;
            for (int k=1;k<=58;k++){
                if ((p[k]|j)!=j)continue;
                int now=abs(k-a[i])+f[i-1][j^p[k]];
                if (now<f[i][j])f[i][j]=now,ans[i][j]=k;
            }
        }
    }
    write(n,(1<<16)-1);
    return 0;
}
```