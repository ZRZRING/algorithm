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
int head[orz],n,m,cnt,a[orz],maxt,heap[orz];
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
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);int cnt=0;
    for (int i=1;i<=n;i++){
        int flag=1;
        for (int j=1;j<=cnt;j++){
            if (heap[j]<=a[i]){
                heap[j]++;flag=0;break;
            }
        }
        if (flag)heap[++cnt]=1;
    }
    printf("%d",cnt);
    return 0;
}