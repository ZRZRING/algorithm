#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
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
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int cal(int a){
    int res=0;
    for (int i=1;i<=sqrt(a);i++){
        if (a%i==0){
            res++;if (i*i!=a)res++;
        }
    }return res;
}
signed main(){
    int n=read(),a=read(),b;
    for (int i=2;i<=n;i++){
        b=read();if (a<b)swap(a,b);a=gcd(a,b);
    }printf("%d",cal(a));
    return 0;
}