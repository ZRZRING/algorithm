#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll a[1000010],b[1000010],n,ans;
void msort(ll l,ll r){
	if (l==r)return;
	ll mid=(l+r)>>1;
	msort(l,mid);msort(mid+1,r);
	ll i=l,j=mid+1,cnt=l;
	while (i<=mid&&j<=r){
		if (a[i]>a[j]){
			ans+=mid-i+1;b[cnt++]=a[j++];
		}else{
			b[cnt++]=a[i++];
		}
	}
	while (i<=mid)b[cnt++]=a[i++];
	while (j<=r)b[cnt++]=a[j++];
	for (ll i=l;i<=r;i++)a[i]=b[i];
}
int main(){
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	msort(1,n);
	//for (int i=1;i<=n;i++)cout<<a[i]<<' ';
	printf("%lld",ans);
}
