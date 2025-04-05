#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n,tmp,tall,m,l,r,cf[100010],sum[100010];
map<pair<int, int>, bool> pd;
int main(){
	scanf("%d%d%d%d",&n,&tmp,&tall,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		if (l>r)swap(l,r);
		if (pd[make_pair(l,r)])continue;
		pd[make_pair(l,r)]=true;
		cf[l+1]--;cf[r]++;
	}
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+cf[i];
		printf("%d\n",tall+sum[i]);
	}
}
