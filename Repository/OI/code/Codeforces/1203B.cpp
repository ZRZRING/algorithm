#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
int n,m,cnt,a[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
}
int main(){
    int T=read();
    while (T--){
        n=read()<<2;
        for (int i=1;i<=n;i++){
            a[i]=read();
        }
        sort(a+1,a+n+1);int flag=1;
        if (a[1]!=a[2]||a[n]!=a[n-1]){
            printf("NO\n");continue;
        }int S=a[1]*a[n];
        for (int i=3;i<=n>>1;i+=2){
            if (a[i]!=a[i+1]||a[n-i+1]!=a[n-i]){
                printf("NO\n");flag=0;break;
            }
            if (a[i]*a[n-i]!=S){
                printf("NO\n");flag=0;break;
            }
        }if (flag)printf("YES\n");
    }
    return 0;
}