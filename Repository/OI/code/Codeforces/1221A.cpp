#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=200010;
int n,m,p[N];
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
        n=read();
        for (int i=1;i<=2048;i<<=1)p[i]=0;
        for (int i=1;i<=n;i++){
            int x=read();if (x>2048)continue;p[x]++;
        }
        for (int i=1;i<=1024;i<<=1){
            p[i<<1]+=p[i]>>1;
        }
        if (p[2048])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}