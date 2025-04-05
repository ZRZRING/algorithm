#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,w[100010],c[100010],f[100010];
int main(){
	cin>>m>>n;
	for (int i=1;i<=n;i++){
		cin>>w[i];c[i]=w[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=m;j>=w[i];j--){
			f[j]=max(f[j-w[i]]+c[i],f[j]);
		}
	}
	cout<<m-f[m];
}
