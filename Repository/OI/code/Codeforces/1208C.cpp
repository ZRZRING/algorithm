#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
int n,m,cnt,ans[1010][1010];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
}
int main(){
    n=read();
    for (int i=1;i<=n/2;i++){
        for (int j=1;j<=n/2;j++){
            for (int k=i;k<=n;k+=n/2){
                for (int l=j;l<=n;l+=n/2){
                    ans[k][l]=cnt++;
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            printf("%d ",ans[i][j]);
        }printf("\n");
    }
    return 0;
}