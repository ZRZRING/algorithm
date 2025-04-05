#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500,c[5][5]={{0,-1,1,1,-1},
                         {1,0,-1,1,-1},
                         {-1,1,0,-1,1},
                         {-1,-1,1,0,1},
                         {1,1,-1,-1,0}};
int n,m,k1,k2,a[N],b[N],ans1,ans2;
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
    n=read();k1=read();k2=read();
    for (int i=1;i<=k1;i++){
        a[i]=read();
    }
    for (int i=1;i<=k2;i++){
        b[i]=read();
    }
    int j1=0,j2=0;
    for (int i=1;i<=n;i++){
        j1++;j2++;
        if (j1==k1+1)j1=1;
        if (j2==k2+1)j2=1;
        if (c[a[j1]][b[j2]]==1){
            ans1++;
        }
        if (c[a[j1]][b[j2]]==-1){
            ans2++;
        }
    }printf("%d %d",ans1,ans2);
    return 0;
}