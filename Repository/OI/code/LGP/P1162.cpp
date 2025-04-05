#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1001][1001],n;
int pd(int x,int y){
	int flag=0;
	for (int i=x;i<=n;i++){
		if (a[i][y]==1){
			flag++;break;
		}
	}
	for (int i=x;i>=1;i--){
		if (a[i][y]==1){
			flag++;break;
		}
	}
	for (int i=y;i<=n;i++){
		if (a[x][i]==1){
			flag++;break;
		}
	}
	for (int i=y;i>=1;i--){
		if (a[x][i]==1){
			flag++;break;
		}
	}
	if (flag==4)return 1;
	return 0;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (!a[i][j])if (pd(i,j)){
				cout<<2<<' ';continue;
			}
			cout<<a[i][j]<<' ';
		}cout<<endl;
	}
	
} 
