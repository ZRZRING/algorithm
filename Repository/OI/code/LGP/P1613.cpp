#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll n,m,path[101][101][101],dis[1001][1001],x,y;
int main(){
	cin>>n>>m;
	memset(dis,10,sizeof(dis));
	for (int i=1;i<=m;i++){
		cin>>x>>y;dis[x][y]=1;
		path[x][y][0]=1;
	}
	for(int c=1;c<=64;c++){
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
    				if(path[i][k][c-1]&&path[k][j][c-1]){
    					path[i][j][c]=1;
    					dis[i][j]=1;
					}
				}
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	cout<<dis[1][n];
}
