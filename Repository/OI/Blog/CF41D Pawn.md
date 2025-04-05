> 你现在处在一个二维棋盘第$n$行的任意位置，棋盘上有一些豆子，你可以每次往左上或者右上走去收集豆子，问你从第$n$行走到第$1$行后，能收集到的豆子数中能被$p+1$整除的最大豆子数是多少，并输出这个方案

显然没有被一个数整除的条件这个题是一个简单题，$f[i][j]$表示从第$n$行走到$(i,j)$所能取到的最大值

但是多了一个条件感觉非常棘手，因为一个方案的结果可能被$p+1$整除的时候不一定是最优解，所以我们加一维$k$表示我们走到$(i,j)$能否取到$k$个豆子


```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=110;
int n,m,a[N][N],f[N][N][1210],go[N][N][1210];
char str[N];
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
void write(int x,int y,int sum,char ch){
    if (x==n){
        printf("%d\n%c",y,ch);return;
    }
    write(x+1,y+go[x][y][sum],sum-a[x][y],go[x][y][sum]==-1?'R':'L');
    if (x!=1)printf("%c",ch);
}
int main(){
    n=read();m=read();int p=read()+1;
    for (int i=1;i<=n;i++){
        scanf("%s",str+1);
        for (int j=1;j<=m;j++){
            a[i][j]=str[j]-'0';
        }
    }
    for (int i=1;i<=m;i++){
        f[n][i][a[n][i]]=1;
    }
    for (int i=n-1;i>=1;i--){
        for (int k=0;k<=1110;k++){
            if (k>=a[i][1])f[i][1][k]=f[i+1][2][k-a[i][1]],go[i][1][k]=1;
            if (k>=a[i][m])f[i][m][k]=f[i+1][m-1][k-a[i][m]],go[i][m][k]=-1;
        }
        for (int j=2;j<m;j++){
            for (int k=0;k<=1110;k++){
                if (k>=a[i][j]){
                    if (f[i+1][j+1][k-a[i][j]])f[i][j][k]=1,go[i][j][k]=1;
                    if (f[i+1][j-1][k-a[i][j]])f[i][j][k]=1,go[i][j][k]=-1;
                }
            }
        }
    }
    for (int k=1110;k>=0;k--){
        if (k%p!=0)continue;
        for (int j=1;j<=m;j++){
            if (f[1][j][k]){
                printf("%d\n",k);write(1,j,k,' ');return 0;
            }
        }
    }printf("-1\n");
    return 0;
}
```
