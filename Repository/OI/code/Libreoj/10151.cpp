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
int head[orz],n,m,cnt,a[orz],f[1001][1001],ans[1001][1001],q[1001][2];
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
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();
    }
    for (int len=1;len<=n-1;len++){
        for (int i=1;i+len<=n;i++){
            int j=i+len;
            for (int k=i;k<j;k++){
                if (f[i][j]<f[i][k]+f[k+1][j]+(a[i]+a[j])*a[k]){
                    f[i][j]=f[i][k]+f[k+1][j]+(a[i]+a[j])*a[k];ans[i][j]=k;
                }
            }
        }
    }
    printf("%d\n",f[1][n]);
    int l=1,r=1;
    q[1][0]=1;q[1][1]=n;
	while (l<=r){
		int now=ans[q[l][0]][q[l][1]];printf("%d ",now);
		if (q[l][0]!=now){
			r++;q[r][0]=q[l][0];q[r][1]=now;
		}
		if (q[l][1]!=now+1){
			r++;q[r][0]=now+1;q[r][1]=q[l][1];
		}
		l++;
	}
    return 0;
}