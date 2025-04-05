#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int T,n,a[100010],b[100010],m;
int cmp(int a,int b){
	return a<b;
}
int pd(int v){
	int p[25001]={0};p[0]=1;
	for (int i=1;i<=m;i++){
		for (int j=b[i];j<=v-1;j++){
			if (p[j-b[i]])p[j]=1;
		}
		if (p[v-b[i]])return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1,cmp);
		m=1;b[1]=a[1];
		for (int i=2;i<=n;i++){
			if (!pd(a[i]))b[++m]=a[i];
		}
		printf("%d\n",m);
	}
}
