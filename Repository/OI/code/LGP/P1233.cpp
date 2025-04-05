#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
struct DATA{
    int k1,k2;
}data[1000100];
int vis[1000100],n,ans,tmp;
using namespace std;
int read(){
    int res=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return res;
}
int cmp(DATA a,DATA b){
    return a.k1==b.k1?a.k2>b.k2:a.k1>b.k1;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){file();
    n=read();
    for (int i=1;i<=n;i++){
        data[i].k1=read();
        data[i].k2=read();
    }
    sort(data+1,data+n+1,cmp);
    for (int i=1;i<=n;i++){
        if (vis[i])continue;ans++;tmp=data[i].k2;
        for (int j=i+1;j<=n;j++){
            if (data[j].k2<=tmp&&!vis[j]){
                vis[j]=1;tmp=data[j].k2;
            }
        }
    }
    printf("%d",ans);
}