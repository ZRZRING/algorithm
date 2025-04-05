#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int orz=500100;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];
int head[orz],n,m,cnt,f[1001][1001];
char str[1001];
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
    scanf("%s",str+1);n=strlen(str+1);
    for (int i=1;i<=n;i++){
        f[i][i]=1;
    }
    for (int len=1;len<n;len++){
        for (int i=1;i+len<=n;i++){
            int j=i+len;
            if (str[i]=='('&&str[j]==')'||str[i]=='['&&str[j]==']'){
                f[i][j]=f[i+1][j-1];
            }else{
                f[i][j]=1<<30;
            }
            for (int k=i;k<=j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
        }
    }
    printf("%d",f[1][n]);
    return 0;
}