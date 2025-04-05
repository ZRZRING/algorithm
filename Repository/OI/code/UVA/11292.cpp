#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
int n,m,enemy[N],hero[N];
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
int main(){//file();
    n=read();m=read();
    while (n!=0||m!=0){
        int now=1,ans=0;
        for (int i=1;i<=n;i++)enemy[i]=read();
        for (int i=1;i<=m;i++)hero[i]=read();
        sort(enemy+1,enemy+n+1);
        sort(hero+1,hero+m+1);
        for (int i=1;i<=m;i++){
            if (hero[i]>=enemy[now]){
                ans+=hero[i];
                if (++now>n)break;
            }
        }
        if (now<=n)printf("Loowater is doomed!\n");
        else printf("%d\n",ans);
        n=read();m=read();
    }
    return 0;
}