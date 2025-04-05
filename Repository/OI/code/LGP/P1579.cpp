#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,k;
int pd(int a){
	for (int i=2;i<=sqrt(a);i++){
		if (a%i==0)return 0;
	}
	return 1;
}
int main(){
	cin>>n;
	for (int i=2;i<=n-4;i++){
        for (int j=2;j<=n-4;j++){
        	k=n-i-j;
        	if ((pd(i)+pd(j)+pd(k))==3){
        		cout<<i<<' '<<j<<' '<<k;return 0;
        	}
        }
	}
}
