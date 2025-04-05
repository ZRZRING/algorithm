#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int f_gcd(int x,int y){
	return x?f_gcd(y%x,x):y;
}
int gcd,lcm,ans;
int main(){
	cin>>gcd>>lcm;
	for (int i=2;i<=ceil(sqrt(gcd*lcm));i++){
		if (gcd*lcm%i==0&&i%gcd==0){
			int j=gcd*lcm/i;
			if (f_gcd(i,j)==gcd){
				//cout<<i<<' '<<j<<endl;
				ans+=2;if (j==i)ans--;
			}
		}
	}
	cout<<ans;
}
