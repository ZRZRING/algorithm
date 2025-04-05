#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,ans=1,cnt,tmp;
int cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>tmp;cnt+=tmp;
		if (cnt>m)ans++,cnt=tmp;
	}
	cout<<ans;
}
