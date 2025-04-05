#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=200010;
char s[N],t[N];
int n,m,len,pre[N],suf[N];
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
    scanf("%s%s",s+1,t+1);int j=1;
    n=strlen(s+1);len=strlen(t+1);
    pre[0]=0;suf[len+1]=n+1;
    for (int i=1;i<=n;i++){
        if (t[j]==s[i])pre[j++]=i;
        if (j==len+1)break;
    }j=len;
    for (int i=n;i>=1;i--){
        if (t[j]==s[i])suf[j--]=i;
        if (j==0)break;
    }int ans=0;
    for (int i=0;i<=len;i++){
        ans=max(ans,suf[i+1]-pre[i]-1);
    }printf("%d",ans);
    return 0;
}