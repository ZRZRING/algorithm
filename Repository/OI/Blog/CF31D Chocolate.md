>题意：给你一个位数为$2n$的数字$S$，两个初始为$0$的数字$A,B$，每次你可以将$S$中最靠左的一位在$S$中删除掉并接在$A$或者$B$其中一个的后面，要求整个操作结束后，必须$A$与$B$都恰好被接$n$次，最大化$A+B$的值，输出方案

>$n\leq 18$

我们考虑线性做法~~O(n)跑18~~，我们已经在A和B中放好了S的前i个数，其中A放了j个，B放了k个，那么我们对于第i+1个数，它可以放在A或B的末尾，于是我们有了状态转移方程

$$f[i][j][k]=max(f[i-1][j-1][k]+s[i]*10^{n-j}),f[i-1][j][k-1]+s[i]*10^{n-k})$$

放数的时候注意是从最高位开始放


```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=100;
int n,m,dp[N][N],a[N][N],b[N][N],c[N],len;
char go[N][N][N];
char str[N<<1];
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
int power(int a,int x){
    int res=1;
    while (x){
        if (x&1)res*=a;
        a*=a;x>>=1;
    }return res;
}
void write(int now,int x,int y,char ch){
    if (now==0){
        printf("%c",ch);return;
    }
    if (go[now][x][y]=='H')write(now-1,x-1,y,'H');
    else write(now-1,x,y-1,'M');
    if (now!=len)printf("%c",ch);
}
signed main(){
    n=read();len=n<<1;
    scanf("%s",str+1);
    for (int i=1;i<=len;i++){
        c[i]=str[i]-'0';
    }
    for (int i=1;i<=n;i++){
        a[i][i]=a[i-1][i-1]+c[i]*power(10,n-i);go[i][i][0]='H';
        b[i][i]=b[i-1][i-1]+c[i]*power(10,n-i);go[i][0][i]='M';
    }
    for (int i=1;i<=len;i++){
        for (int j=max(i-n,1ll);j<=min(i-1ll,n);j++){
            int k=i-j,ta=c[i]*power(10,n-j),tb=c[i]*power(10,n-k);
            if (a[i-1][j-1]+ta+b[i-1][k]>b[i-1][k-1]+tb+a[i-1][j]){
                a[i][j]=a[i-1][j-1]+ta;
                b[i][k]=b[i-1][k];go[i][j][k]='H';
            }else{
                b[i][k]=b[i-1][k-1]+tb;
                a[i][j]=a[i-1][j];go[i][j][k]='M';
            }
        }
    }
    write(len,n,n,' ');
    return 0;
}
```
