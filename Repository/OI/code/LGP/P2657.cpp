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
int head[orz],n,m,cnt;
int dp[100][100],a[100],l,r;
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
void init(){
    for (int i=0;i<=9;i++)dp[1][i]=1;
    for (int i=2;i<=15;i++){
        for (int j=0;j<=9;j++){
            for (int k=0;k<=9;k++){
                if (abs(j-k)>=2)dp[i][j]+=dp[i-1][k];
            }
        }
    }
}
int cal(int x){
    int len=0,ans=0;
    while (x){
        a[++len]=x%10;x/=10;
    }
    for (int i=1;i<=len-1;i++){
        for (int j=1;j<=9;j++){
            ans+=dp[i][j];
        }
    }
    for (int i=1;i<=a[len]-1;i++){
        ans+=dp[len][i];
    }
    for (int i=len-1;i>=1;i--){
        for (int j=0;j<=a[i]-1;j++){
            if (abs(a[i+1]-j)>=2){
                ans+=dp[i][j];
            }
        }
        if (abs(a[i]-a[i+1])<2)break;
    }
    return ans;
}
int main(){file();
    l=read();r=read();init();
    printf("%d",cal(r)-cal(l-1));
    return 0;
}