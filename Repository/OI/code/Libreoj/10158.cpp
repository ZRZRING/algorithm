#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,f[1001][1001],root[1001][1001];
void write(int l,int r){
	if (l>r)return;
	if (l==r){
		printf("%d ",l);return;
	}
	printf("%d ",root[l][r]);
	write(l,root[l][r]-1);
	write(root[l][r]+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&f[i][i]);f[i][i-1]=1;
	}
	for (int i=n;i>=1;i--){
		for (int j=i+1;j<=n;j++){
			for (int k=i;k<=j;k++){
				if (f[i][k-1]*f[k+1][j]+f[k][k]>f[i][j]){
					f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
					root[i][j]=k;
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	write(1,n);
} 
