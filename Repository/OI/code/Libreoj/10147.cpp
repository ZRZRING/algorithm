#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int inf=1<<30;
int a[100010],n,sum[100010],Fmin[550][550],Fmax[550][550],maxx,minn=inf;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];a[i+n]=a[i];
	}
	//cout<<"sum:";
	for (int i=1;i<=2*n;i++){
		sum[i]=sum[i-1]+a[i];//cout<<sum[i]<<' ';
	}//cout<<endl;
	for (int s=1;s<=n-1;s++){
		for (int j=s+1;j<=s+n-1;j++){
			for (int i=j-1;i>=s;i--){
				Fmin[i][j]=inf;
				for (int k=i;k<j;k++){
					Fmin[i][j]=min(Fmin[i][k]+Fmin[k+1][j]+sum[j]-sum[i-1],Fmin[i][j]);
					Fmax[i][j]=max(Fmax[i][k]+Fmax[k+1][j]+sum[j]-sum[i-1],Fmax[i][j]);
				}
			}
		}
	}
	/*cout<<"MIN:"<<endl;
	for (int i=1;i<=2*n;i++){
		for (int j=1;j<=2*n;j++){
			cout<<Fmin[i][j]<<' ';
		}cout<<endl;
	}
	cout<<"MAX:"<<endl;
	for (int i=1;i<=2*n;i++){
		for (int j=1;j<=2*n;j++){
			cout<<Fmax[i][j]<<' ';
		}cout<<endl;
	}*/
	for (int i=1;i<=n-1;i++){
		maxx=max(maxx,Fmax[i][i+n-1]);
		minn=min(minn,Fmin[i][i+n-1]);
	}
	printf("%d\n%d",minn,maxx);
}