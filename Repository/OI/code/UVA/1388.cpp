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
    while (scanf("%d%d",&n,&m)){
        double ans=0.0;m+=n;
        for (int i=1;i<n;i++){
            double pos=(double)i/n*m;
            ans+=fabs(pos-floor(pos+0.5))/m;
        }printf("%.4lf\n",ans*10000);
    }
    return 0;
}