#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500;
int n,m,d,cnt,ans,a[N][N];
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
    if (x==129)y++,x=0;
    if (y==129)return;
    int res=0;
    for (int i=max(0,x-d);i<=min(128,x+d);i++){
        for (int j=max(0,y-d);j<=min(128,y+d);j++){
            res+=a[i][j];
        }
    }
    if (res==ans)cnt++;
    if (res>ans){
        ans=res;cnt=1;
    }dfs(x+1,y);
}
int main(){
    d=read();n=read();
    for (int i=1;i<=n;i++){
        int x=read(),y=read(),t=read();a[x][y]=t;
    }
    dfs(0,0);
    printf("%d %d\n",cnt,ans);
    return 0;
}