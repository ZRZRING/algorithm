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