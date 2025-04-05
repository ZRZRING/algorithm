#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
long long n,k,a[1000000],sum,ans;
bool pd(int a){
	if (a==2)return true;
	for (int i=2;i<=ceil(sqrt(a));i++){
		if (a%i==0)return false;
	}
	return true;
}
void ss(int l,int g){
	if (l==k+1){
		if (pd(sum))ans++;
	}else
	for (int i=g+1;i<=n;i++){
		sum+=a[i];
		ss(l+1,i);
		sum-=a[i];
	}
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	ss(1,0); 
	cout<<ans;
}
