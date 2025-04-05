#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int qwq=550;
int ans=-(1<<30),a[qwq][qwq],f[qwq][qwq],n,m;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	f[n][(m+1)>>1]=a[n][(m+1)>>1];
	f[n][m>>1]=a[n][m>>1];
	f[n][((m+1)>>1)+1]=a[n][((m+1)>>1)+1];
	for (int i=n-1;i>=1;i--){
		for (int j=max(((m+1)>>1)-(n-i+1),1);j<=min(((m+1)>>1)+(n-i+1),n);j++){
			//cout<<'a';
			f[i][j]=max(f[i+1][max(j-1,1)],max(f[i+1][j],f[i+1][min(j+1,m)]))+a[i][j];
		}
	}//cout<<endl;
	/*for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for (int i=1;i<=m;i++){
		ans=max(ans,f[1][i]);
	}
	cout<<ans;
}
