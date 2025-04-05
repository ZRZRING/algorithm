#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	cin>>a>>b;if(a<b)printf("0"),return 0;
	for (int i=1;i<=a-b;i++){
		ans*=2;ans%=1000000007;
	}n1[0]=1;
	for (int i=1;i<=a;i++){
		n1[i]=n1[i-1]*i;
	}
	ans*=n1[a];ans%=1000000007;
} 
