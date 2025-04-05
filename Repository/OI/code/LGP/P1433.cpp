#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int n,p[1001];
double x[20],y[20],dis[1001][1001],ans=1234123412.0;
void dfs(int now,int last,double length){
	if (now==n){
		ans=min(ans,length);
	}else{
		if (length>=ans)return;
		for (int i=1;i<=n;i++){
			if (!p[i]){
				p[i]=1;
				dfs(now+1,i,length+dis[last][i]);
				p[i]=0;
			}
		}
	}
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	}
	dfs(0,0,0.0);
	printf("%.2f",ans);
}
