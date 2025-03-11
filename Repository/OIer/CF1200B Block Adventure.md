> 你处在一个一维坐标系中，每个位置上都有$a_i$块砖，当$|a_i-a_{i+1}|\leq k$时你可以从$i$跳到$i+1$，你可以把你所在位置上的砖装入你背上的一个无限容量的背包，你也可以从背包中取出砖放到当前位置上，初始背包为空，问能否从1走到n

一个贪心的思想是保证我们在任意时刻我们的背包装的砖的数量尽可能多

于是我们每次保证从$i$跳到下一个位置$i+1$之前先把$i$位置的砖的数量修改为$max(a[i+1]-k,0)$

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500100;
int n,m,k,h[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int main(){
    int T=read();
    for (int t=1;t<=T;t++){
        n=read(),m=read(),k=read();
        h[1]=read();int flag=1;
        for (int i=2;i<=n;i++){
            h[i]=read();
            if (h[i]<k)m+=h[i-1];
            else m-=h[i]-(h[i-1]+k);
            if (m<0)flag=0;
        }
        if (flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
```
