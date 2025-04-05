#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=2000010,inf=1<<30;
int n,d,k,pos[N],c[N],f[N],q[N];
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
bool check(int g){
    int L=max(1ll,d-g),R=d+g,head=1,tail=1,j=0,s=1;
    memset(f,0x8f,sizeof(f));f[0]=0;q[head]=0;
    while (pos[s]<L)s++;if (pos[s]>R)return false;//找到第一个能过去的地方
    j=s;
    for(int i=s;i<=n;i++){
        int last=pos[i]-L;
        while(pos[j]<=last){
            while(head<=tail&&f[j]>f[q[tail]])tail--;
            q[++tail]=j;j++;
        }
        while(head<=tail&&pos[i]-pos[q[head]]>R)head++;
        if (head>tail)continue;
        f[i]=f[q[head]]+c[i];if(f[i]>=k)return true;
    }
    return false;
}
signed main(){
    n=read();d=read();k=read();int sum=0;
	for (int i=1;i<=n;i++){
		pos[i]=read();c[i]=read();sum+=(c[i]>0)*c[i];
	}
    if (sum<k){
        printf("-1");return 0;
    }
	int l=0,r=inf;
	while (l<r){
		int mid=l+r>>1;
		if (check(mid))r=mid;
        else l=mid+1;
	}printf("%d",r);
    return 0;
}