#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[1000010],f[100010][20],t,l,r;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i][0]=a[i];
	}
	t=log(n)/log(2);
	for (int j=1;j<=t;j++){
		for (int i=1;i<=n-(1<<j)+1;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		t=log(r-l+1)/log(2);
		printf("%d\n",max(f[l][t],f[r-(1<<t)+1][t]));
	}
}
