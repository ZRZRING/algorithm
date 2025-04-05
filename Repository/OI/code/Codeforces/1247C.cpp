#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define lowbit(x) (x&-x)
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,p,res;
int main(){
	n=read();p=read();
	while(1){
		res++;n-=p;
		if(n<=0){
			printf("-1");return 0;
		}
		int m=n,t=0;
		while (m){
			m-=lowbit(m);t++;
		}
		if (t>res||res>n)continue;
	    printf("%d",res);
		return 0;
	}	
}
