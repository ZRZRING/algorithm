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
int main(){
    n=read();
    m=read();
    for (int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=1;j++){
            line[i][j]=line[i][j+1]+(a[i][j]=='R');
        }
    }
    for (int j=1;j<=m;j++){
        for (int i=n;i>=1;i--){
            col[i][j]=col[i+1][j]+(a[i][j]=='R');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if ()
        }
    }
    return 0;
}