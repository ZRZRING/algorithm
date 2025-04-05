#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;
const int orz=500100;
int head[orz],n,m,cnt,T,stu[orz],home[orz],mp[1001][1001];
inline int read(){
    int sym(0),res(0);char ch(0);
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){
    T=read();
    while (T--){
        n=read();
        for (int i=1;i<=n;i++){
            stu[i]=read();
        }
        for (int i=1;i<=n;i++){
            home[i]=read();
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                mp[i][j]=read();
                if (stu[i])
            }
        }
    }
    return 0;
}