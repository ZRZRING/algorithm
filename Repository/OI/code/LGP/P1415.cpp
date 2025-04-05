#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
const int orz=500100;
/*struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[orz];*/
int head[orz],n,m,cnt;
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
/*void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}*/
int main(){
    scanf("%s",str);n=strlen(str);
    for (int i=1;i<=n;i++){
        a[i]=str[i-1]-'0';
    }
    for (int i=1;i<=n;i++){
        dp[]
    }
    return 0;
}