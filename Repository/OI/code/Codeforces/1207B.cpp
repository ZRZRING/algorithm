#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1001;
int n,m,cnt,a[N][N],p[N][N],b[N][N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){
    n=read();m=read();int cnt1=0,cnt2=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=read();cnt1+=a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
                p[i][j]=1;cnt++;
                b[i][j]=1;b[i+1][j]=1;b[i][j+1]=1;b[i+1][j+1]=1;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cnt2+=b[i][j];
        }
    }
    if (cnt1>cnt2){
        printf("-1");return 0;
    }
    printf("%d\n",cnt);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (p[i][j])printf("%d %d\n",i,j);
        }
    }
    return 0;
}