> 你有n个项目和一个初始rating，做第i个项目需要你的rating达到$a_i$，做完第i个项目你会获得$b_i$的rating$(-300\leq b_i\leq 300)$，问你最多能做多少项目

首先考虑贪心，b值为正的项目肯定优先选择，能选多少选多少

b值为负的项目，首先a的值可以取为max(a,-b)，然后跑一个01背包就好了

但选择顺序对01背包是没有影响的，而这个题有影响，所以我们对其按a+b排序

这个做法的正确性可以理解为我们对做完一个项目后的结果进行排序，结果好的优先，因为结果是对后续的选择服务的，当前结果越好后续可能选择的越多，于是按这个顺序可以使得01背包一定能取到最优解

注意如果01背包从m跑到1，要从大到小排序，从1跑到m才要从小到大排序


```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=200;
struct node{
    int a,b;
}pos[N],neg[N];
int n,m,pos_cnt,neg_cnt,dp[400000];
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
bool cmp1(node x,node y){
    return x.a<y.a;
}
bool cmp2(node x,node y){
    return x.a+x.b<y.a+y.b;
}
int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++){
        int x=read(),y=read();
        if (y>=0){
            pos[++pos_cnt]=(node){x,y};
        }else{
            neg[++neg_cnt]=(node){max(x,-y),y};
        }
    }
    sort(pos+1,pos+pos_cnt+1,cmp1);
    sort(neg+1,neg+neg_cnt+1,cmp2);
    int ans=0,res=0;
    for (int i=1;i<=pos_cnt;i++){
        if (m<pos[i].a)break;
        else m+=pos[i].b,ans++;
    }
    for (int i=1;i<=neg_cnt;i++){
        for (int j=m;j>=neg[i].a;j--){
            dp[j]=max(dp[j],dp[j+neg[i].b]+1);
            res=max(res,dp[j]);
        }
    }
    printf("%d",ans+res);
    return 0;
}
```