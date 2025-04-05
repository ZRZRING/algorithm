#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
int n,m,a[N],rcnt[N],lcnt[N];
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
bool check(int t){
    int l=a[1],r=t-a[1];
    lcnt[1]=a[1];rcnt[1]=0;
    for (int i=2;i<=n;i++){
        if (i%2){
            rcnt[i]=min(r-rcnt[i-1],a[i]);
            lcnt[i]=a[i]-rcnt[i];
        }else{
            lcnt[i]=min(l-lcnt[i-1],a[i]);
            rcnt[i]=a[i]-lcnt[i];
        }
    }return lcnt[n]==0;
}
int main(){//file();
    n=read();
    int l=0,r=500000;
    for (int i=1;i<=n;i++){
        a[i]=read();
    }a[n+1]=a[1];
    for (int i=1;i<=n;i++){
        l=max(l,a[i]+a[i+1]);
    }
    if (n==1){
        printf("%d\n",a[1]);return 0;
    }
    if (n%2){
        while (l<r){
            int mid=l+r>>1;
            if (check(mid))r=mid;
            else l=mid+1;
        }
    }printf("%d\n",l);
    return 0;
}