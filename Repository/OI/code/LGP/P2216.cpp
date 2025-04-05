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
int a,b,l1,l2,r1,r2,q1[orz],q2[orz],c[orz],cmax[1001][1001],cmin[1001][1001];
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
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
int main(){file();
    a=read();b=read();n=read();
    for (int i=1;i<=a;i++){
        int l1=l2=1,r1=r2=0;
        for (int j=1;j<=b;j++){
            c[j]=read();
            while (l1<=r1&&j-q1[l1]>=n)l1++;
            while (l2<=r2&&j-q2[l2]>=n)l2++;
            while (l1<=r1&&c[j]>=c[q1[r1]])r1--;
            while (l2<=r2&&c[j]<=c[q2[r2]])r2--;
            q1[++r1]=j;q2[++r2]=j;
            cmax[i][j]=c[q1[l1]];cmin[i][j]=c[q2[l2]];
        }
    }
    int ans=1<<30;
    for (int j=n;j<=b;j++){
        int l1=l2=1,r1=r2=0;
        for (int i=1;i<=a;i++){
            while (l1<=r1&&i-q1[l1]>=n)l1++;
            while (l2<=r2&&i-q2[l2]>=n)l2++;
            while (l1<=r1&&cmax[i][j]>=cmax[q1[r1]][j])r1--;
            while (l2<=r2&&cmin[i][j]<=cmin[q2[r2]][j])r2--;
            q1[++r1]=i;q2[++r2]=i;
            if (i>=n)ans=min(ans,cmax[q1[l1]][j]-cmin[q2[l2]][j]);
        }
    }
    printf("%d",ans);
    return 0;
}
