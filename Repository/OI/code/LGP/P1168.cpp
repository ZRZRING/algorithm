#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N=100010;
int n,m;
vector<int>a;
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
int main(){
    n=read();
    for (int i=1,t;i<=n;i++){
        t=read();
        a.insert(upper_bound(a.begin(),a.end(),t),t);
        if (i&1)printf("%d\n",a[i-1>>1]);
    }
    return 0;
}