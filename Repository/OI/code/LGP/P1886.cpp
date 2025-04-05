#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=2000010;
int n,k,a[N],q[N],p[N];
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
int main(){
	n=read();k=read();
	for (int i=1;i<=n;i++)a[i]=read();
	int head=1,tail=0;
	for (int i=1;i<=n;i++){//最小 
		while (p[head]<=i-k&&head<=tail)head++;
		while (q[tail]>=a[i]&&head<=tail)tail--;
		q[++tail]=a[i];p[tail]=i;
		if (i>=k)printf("%d ",q[head]); 
	}printf("\n");
	head=1,tail=0;
	for (int i=1;i<=n;i++)q[i]=0,p[i]=0;
	for (int i=1;i<=n;i++){//最大 
		while (q[tail]<=a[i]&&head<=tail)tail--;
		while (p[head]<=i-k)head++;
		q[++tail]=a[i];p[tail]=i;
		if (i>=k)printf("%d ",q[head]); 
	}
    return 0;
}