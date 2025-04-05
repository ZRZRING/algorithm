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
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,cnt,color[N][2];
int main(){
    int T=read();
    while (T--){
        n=read();memset(color,0,sizeof(color));
        for (int i=1;i<=n-1;i++){
            for (int j=i+1;j<=n;j++){
                int t=read();
                color[i][t]++;color[j][t]++;
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++){
            ans+=color[i][0]*color[i][1];
        }
        printf("%d\n",n*(n-1)*(n-2)/6-ans/2);
    }
    return 0;
}