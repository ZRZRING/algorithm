#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,dis[1000][1000],a,b;
int main(){
	cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            dis[i][j]=dis[j][i]=1e9;
    int tmp;
	for (int i=1;i<=n;i++)
    {
        cin>>tmp;
        if(i+tmp<=n)dis[i][i+tmp]=1;
        if(i-tmp>=1)dis[i][i-tmp]=1;
    }
	for (int k=1;k<=n;k++){
		for (int j=1;j<=n;j++){
			for (int i=1;i<=n;i++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	if(dis[a][b]<10000)cout<<dis[a][b];
	else cout<<-1;
} 
