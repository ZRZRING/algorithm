> 求$m$面色子扔$n$次的期望最大值

可以得知，最大值在$[1,x]$的情况有$x^n$种，所以对于点数$i$，一共有$i^n-(i-1)^n$种情况最大值为$i$，每种情况贡献为$i$，所有情况的数量为$m^n$，于是答案为

$$
ans=\sum_{i=1}^m\frac{i^n-(i-1)^n}{m^n}\times i=\sum_{i=1}^m(\frac{i}{m})^n\times i-(\frac{i-1}{m})^n\times i
$$

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
double n,m,ans;
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
    m=read();n=read();ans=0;
    for (int i=1;i<=m;i++){
        ans+=i*(pow(i/m,n)-pow((i-1)/m,n));
    }
    printf("%.12lf",ans);
    return 0;
}
```