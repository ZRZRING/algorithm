#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m;
int main() {
    int a=read(),b=read();
    if (a==9&&b==1){
        printf("%d %d",a,b*10);
        return 0;
    }
    if (a==b){
        printf("%d %d",a*10,b*10+1);
    }
    if (a<b){
        if (a+1<b){
            printf("%d",-1);
        }else{
            if (a+1==b){
                printf("%d %d",a*10+9,b*10);
            }
        }
    }
    if (a>b){
        printf("%d",-1);
    }
    return 0;
}