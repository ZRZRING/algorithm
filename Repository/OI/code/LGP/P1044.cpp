#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
long long n,f[100010];
int main(){
	cin>>n;
	f[1]=1;
	for (int i=2;i<=n;i++){
		for (int j=1;j<=i-1;j++){
			f[i]+=f[j]*f[i-j];
		}
		f[i]+=f[i-1];
	}
	cout<<f[n];
}
