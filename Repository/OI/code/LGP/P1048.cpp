#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,w[100010],c[100010],f[100010];
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&c[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=m;j>=w[i];j--){
			f[j]=max(f[j-w[i]]+c[i],f[j]);
		}
	}
	cout<<f[m];
}
