#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
int len,n,a[100010],minn,maxx;
int main(){
	scanf("%d%d",&len,&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		minn=max(minn,min(len+1-a[i],a[i]));
		maxx=max(maxx,max(len+1-a[i],a[i]));
	}
	printf("%d %d",minn,maxx);
}
