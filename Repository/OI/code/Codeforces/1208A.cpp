#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
int n,a,b;
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
    int t=read();
    while (t--){
        a=read();b=read();n=read();
        if (n%3==0){printf("%d\n",a);continue;}
        if (n%3==1){printf("%d\n",b);continue;}
        printf("%d\n",a^b);
    }
    return 0;
}