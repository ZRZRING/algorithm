#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,k,p,color,w,lp,last[100000],sum[100000],ans,cnt[100000];
int main(){
	cin>>n>>k>>p;
	for (int i=1;i<=n;i++){
		cin>>color>>w;if (w<=p)lp=i;
		if (lp>=last[color])sum[color]=cnt[color];
		last[color]=i;ans+=sum[color];cnt[color]++;
	}
	cout<<ans;
}