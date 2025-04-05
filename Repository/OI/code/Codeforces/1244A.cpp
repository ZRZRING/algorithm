#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
int n,m;
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
    int T=read();
    while (T--){
        int lena=read(),lenb=read(),a=read(),b=read(),k=read();
        int ares=(lena+a-1)/a,bres=(lenb+b-1)/b;
        if (ares+bres<=k)ares=k-bres;
        else {printf("-1\n");continue;}
        printf("%d %d\n",ares,bres);
    }
    return 0;
}