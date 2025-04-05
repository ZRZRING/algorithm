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
const int N=500010,p=1e9+7;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,cnt,a[N+5],fib[N+5];
char ch[N+5];
int main(){
    scanf("%s",ch+1);n=strlen(ch+1);
    for (int i=1;i<=n;i++){
        if (ch[i]=='m'||ch[i]=='w'){
            printf("0");return 0;
        }
        if (ch[i]=='u'){
            cnt++;while (ch[i]=='u')a[cnt]++,i++;i--;
        }
        if (ch[i]=='n'){
            cnt++;while (ch[i]=='n')a[cnt]++,i++;i--;
        }
    }
    fib[1]=1;fib[2]=2;long long ans=1;
    for (int i=3;i<=N;i++)fib[i]=(fib[i-1]+fib[i-2])%p;
    for (int i=1;i<=cnt;i++)ans=ans*fib[a[i]]%p;
    printf("%lld",ans);
    return 0;
}