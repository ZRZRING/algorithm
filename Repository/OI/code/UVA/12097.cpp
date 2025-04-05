#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
const double PI=acos(-1.0);
int n,m;
double s[N];
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
double cal(int x){
    return PI*x*x;
}
bool check(double t){
    int res=0;
    for (int i=1;i<=n;i++)res+=s[i]/t;
    return res>=m+1;
}
int main(){
    int T=read();
    while (T--){
        n=read();m=read();double maxx=0;
        for (int i=1;i<=n;i++)s[i]=cal(read()),maxx=max(maxx,s[i]);
        double l=0,r=maxx;
        while (r-l>1e-5){
            double mid=(l+r)/2;
            if (check(mid))l=mid;else r=mid;
        }printf("%.5lf\n",l);
    }
    return 0;
}