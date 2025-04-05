#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,a[100010],ans,minn=1<<30;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]>a[i-1])ans+=a[i]-a[i-1];
	}
	printf("%d",ans);
}
