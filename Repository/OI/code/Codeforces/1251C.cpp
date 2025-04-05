#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
int n,m;
char ch[N];
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
    int T=read();
    while (T--){
        int n=read();
        scanf("%s",ch+1);
        int len=strlen(ch+1);
        for (int i=1;i<=n;i++){
            if (ch[i]){
                
            }
        }
    }
    return 0;
}