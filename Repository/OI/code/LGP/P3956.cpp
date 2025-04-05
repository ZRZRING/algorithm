#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int gox[5]={0,-1,0,1,0},goy[5]={0,0,-1,0,1};
const int qwq=550;
int ans=1<<30,n,m,x,y,cc,a[qwq][qwq],f[qwq][qwq][3][2];
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>x>>y>>cc;a[x][y]=cc+1;
	}
	/*for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}cout<<endl;
	}*/
	memset(f,0x7f,sizeof(f));
	f[1][1][a[1][1]][1]=0;
	int cont=4;
	while (cont--){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==1&&j==1)continue;
				if (a[i][j]){
					for(int k=1;k<=2;k++){
			            for(int l=0;l<=1;l++){
			            	if(a[i][j]==k){
			                	int tmp=f[i][j][k][1];
			                  	f[i][j][a[i][j]][1]=min(f[i-1][j][k][l],min(f[i][j-1][k][l],min(f[i][j+1][k][l],f[i+1][j][k][l])));
			                	f[i][j][a[i][j]][1]=min(tmp,f[i][j][k][1]);
			              	}else{	
			                  	int tmp=f[i][j][a[i][j]][1];
			                  	f[i][j][a[i][j]][1]=min(f[i-1][j][k][l],min(f[i][j-1][k][l],min(f[i][j+1][k][l],f[i+1][j][k][l])))+1;
			                  	f[i][j][a[i][j]][1]=min(tmp,f[i][j][a[i][j]][1]);
			              	}
						}
					}  
				}else{
				    for(int k=1;k<=2;k++){
				        int tmp=f[i][j][k][0];
				        f[i][j][k][0]=min(f[i-1][j][k][1],min(f[i][j-1][k][1],min(f[i][j+1][k][1],f[i+1][j][k][1])))+2;
				        f[i][j][k][0]=min(tmp,f[i][j][k][0]);
				    }
				}
			}
		}
	}
	/*for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cout<<f[i][j][1][0]<<' ';
		}cout<<endl;
	}*/
	for (int i=1;i<=2;i++){
		for (int j=0;j<=1;j++){
			ans=min(f[n][n][i][j],ans);
		}
	}
	if (ans<1<<30)cout<<ans;
	else cout<<-1;
}
