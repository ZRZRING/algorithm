#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int gox[5]={0,1,-1,0,0};
const int goy[5]={0,0,0,-1,1};
int a[1001][1001],n,m,f[1001][1001],ans;
int dfs(int x,int y){
	if (f[x][y])return f[x][y];
	int tmp=0;
	for (int i=1;i<=4;i++){
		int tx=x+gox[i],ty=y+goy[i];
		if (tx>=1&&tx<=n&&ty>=1&&ty<=n&&a[x][y]>a[tx][ty]){
			tmp=max(tmp,dfs(tx,ty)+1);
		}
	}
	f[x][y]=max(f[x][y],tmp);
	return f[x][y];
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			ans=max(ans,dfs(i,j));
		}
	}
	cout<<ans+1;
}
