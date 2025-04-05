#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
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
    int a1=read(),a2=read(),k1=read(),k2=read();n=read();
    if (k1>k2){
        int maxx=n/k2;
        if (maxx>a2){
            maxx=a2;int tmp=(n-a2*k2)/k1;
            if (tmp>a1)maxx=a1+a2;
            else maxx+=tmp;
        }
        n-=a1*(k1-1)+a2*(k2-1);int minn=0;
        if (n>0){
            minn=min(a1+a2,n);
        }
        printf("%d %d",minn,maxx);return 0;
    }else{
        int maxx=n/k1;
        if (maxx>a1){
            maxx=a1;int tmp=(n-a1*k1)/k2;
            if (tmp>a2)maxx=a1+a2;
            else maxx+=tmp;
        }
        n-=a1*(k1-1)+a2*(k2-1);int minn=0;
        if (n>0){
            minn=min(a1+a2,n);
        }
        printf("%d %d",minn,maxx);return 0;
    }
}