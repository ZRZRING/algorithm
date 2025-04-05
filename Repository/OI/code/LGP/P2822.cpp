#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int c[2001][2001],ans[2001][2001],m,n,k,T;
void build(){//c[i][j]表示j个数里选i个 
	c[0][0]=c[1][0]=c[0][1]=c[1][1]=1;
	for (int i=2;i<=2000;i++){
		c[i][0]=1;
		for (int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
			ans[i][j]=ans[i][j-1]+ans[i-1][j]-ans[i-1][j-1];
			if (!c[i][j])ans[i][j]++;
		}
		ans[i][i+1]=ans[i][i];
	}
}
int main(){
	scanf("%d%d",&T,&k);
	build();
	while (T--){
		scanf("%d%d",&n,&m);
		if (m>n)m=n;
		printf("%d\n",ans[n][m]);
	}
}
