#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n,k,p,c,w,lp,last[100000],sum[100000],ans,cnt[100000];
int main(){
	cin>>n>>k>>p;
	for (int i=1;i<=n;i++){
		cin>>c>>w;
		if (w<=p)lp=i;
		if (lp>=last[c])sum[c]=cnt[c];
		last[c]=i;
		ans+=sum[c];
		cnt[c]++;
	}
	cout<<ans;
}