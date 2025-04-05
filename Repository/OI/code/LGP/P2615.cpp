#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100;
int n,m,cnt,a[N][N];
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
void dfs(int x,int y){
    a[x][y]=++cnt;if (cnt==n*n)return;
    int tx=(x-1?x-1:n),ty=(y+1==n+1?1:y+1);
    if (a[tx][ty])dfs(x==n?1:x+1,y);
    else dfs(tx,ty);
}
int main(){
    n=read();
    dfs(1,(n>>1)+1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}