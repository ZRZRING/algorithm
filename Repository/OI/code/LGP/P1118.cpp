#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n,sum,cnt,pas[100010],p[100010],ans[100010],g;
void search(int now,int sum){
	if (now==n+1){
		if (sum==g){
			for (int i=1;i<=n;i++)cout<<ans[i]<<' ';exit(0);
		}
	}else{
		if (sum>g)return;
		for (int i=1;i<=n;i++){
			if (!p[i]){
				p[i]=1;ans[now]=i;
				search(now+1,sum+i*pas[now]);
				p[i]=0;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&g);
	pas[0]=0;pas[1]=1;
	for (int i=2;i<=n;i++){
		for (int j=i;j>=1;j--){
			pas[j]+=pas[j-1];
		}
	}
	search(1,0);
}
