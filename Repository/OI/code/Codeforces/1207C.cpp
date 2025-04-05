#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=200010;
int n,m;
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
signed main(){
    int T=read();char ch[N];
    while (T--){
        n=read();int a=read(),b=read();
        int ans=(n+1)*b+n*a,l=1,r=n,s[N]={0},cnt=0,tmp=1;
        scanf("%s",ch+1);
        while (ch[l]=='0')l++;while (ch[r]=='0')r--;
        if (l>r){printf("%lld\n",ans);continue;}
        ans+=a<<1;
        for (int i=l;i<=r;i++){
            tmp=1;while (ch[i]==ch[i+1])tmp++,i++;
            if (++cnt&1){
                ans+=b*(tmp+1);
            }else{
                ans+=min(b*(tmp-1),a<<1);
            }
        }printf("%lld\n",ans);
    }
    return 0;
}