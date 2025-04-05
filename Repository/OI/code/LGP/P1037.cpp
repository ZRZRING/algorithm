#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll n,m,x,y,vis[1001][1001],num[100010],ans[100010];
string str;
/*1564632
5
1 6
1 9
1 4
4 9
9 6*/
int main(){
	cin>>str>>m;n=str.length();
	for (int i=1;i<=m;i++){
		cin>>x>>y;vis[x][y]=1;
	}
	for (int i=0;i<=9;i++)vis[i][i]=1;
	for (int k=0;k<=9;k++){
		for (int i=0;i<=9;i++){
			for (int j=0;j<=9;j++){
				vis[i][j]=vis[i][j]||(vis[i][k]&&vis[k][j]);
			}
		}
	}
	for (int i=0;i<=9;i++){
		for (int j=0;j<=9;j++){
			if (vis[i][j])num[i]++;
		}
	}
	int x=0;ans[0]=1;ans[1]=1;
	for (int j=0;j<n;j++){
		//cout<<num[str[j]-'0']<<' ';
		x=0;
		for (int i=1;i<=ans[0];i++){
			ans[i]=ans[i]*num[str[j]-'0']+x;
			x=ans[i]/10;
			ans[i]%=10;
		}
		if (x){
			ans[++ans[0]]=x;
		}
	}
	for (int i=ans[0];i>=1;i--){
		cout<<ans[i];
	}
}
