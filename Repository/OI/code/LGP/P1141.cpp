#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int gox[5]={0,1,-1,0,0};
const int goy[5]={0,0,0,-1,1};
int a[1001][1001],n,m,cnt,p[1001][1001],color[1001][1001],sum[1000100],qx[1000100],qy[1000100];
string str[1001];
void bfs(int sx,int sy){
	int head=0,tail=1,x,y,tmpx,tmpy;
	p[sx][sy]=1;
	qx[tail]=sx;qy[tail]=sy;
	while (head<tail){
		head++;x=qx[head];y=qy[head];
		color[x][y]=cnt;sum[cnt]++;
		//cout<<x<<' '<<y<<endl;
		for (int i=1;i<=4;i++){
			tmpx=x+gox[i];tmpy=y+goy[i];
			if (!p[tmpx][tmpy]&&a[x][y]!=a[tmpx][tmpy]&&tmpx>=1&&tmpx<=n&&tmpy>=1&&tmpy<=n){
				qx[++tail]=tmpx;qy[tail]=tmpy;p[tmpx][tmpy]=1;
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>str[i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			a[i+1][j+1]=str[i][j]-'0';
		}
	}
	for (int x=1;x<=n;x++){
		for (int y=1;y<=n;y++){
			if (!p[x][y]){
				cnt++;bfs(x,y);
			}
		}
	}
	/*for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cout<<color[i][j]<<' ';
		}cout<<endl;
	}*/
	int x,y;
	for (int i=1;i<=m;i++){
		cin>>x>>y;
		cout<<sum[color[x][y]]<<endl;
	}
}
