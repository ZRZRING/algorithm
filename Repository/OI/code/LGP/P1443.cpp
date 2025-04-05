#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int gox[10]={0,-2,-2,-1,-1,1,1,2,2};
const int goy[10]={0,1,-1,2,-2,2,-2,1,-1};
int a[1001][1001],p[1001][1001],n,m,sx,sy,qx[1000100],qy[1000100],qz[1000100];
void bfs(){
	int head=0,tail=1,x,y,tmpx,tmpy;
	p[sx][sy]=1;
	qx[tail]=sx;qy[tail]=sy;
	while (head<tail){
		head++;x=qx[head];y=qy[head];
		a[x][y]=qz[head];
		for (int i=1;i<=8;i++){
			tmpx=x+gox[i];tmpy=y+goy[i];
			if (!p[tmpx][tmpy]&&a[x][y]!=a[tmpx][tmpy]&&tmpx>=1&&tmpx<=n&&tmpy>=1&&tmpy<=m){
				qx[++tail]=tmpx;qy[tail]=tmpy;qz[tail]=qz[head]+1;p[tmpx][tmpy]=1;
			}
		}
	}
}
int main(){
	cin>>n>>m>>sx>>sy;
	memset(a,-1,sizeof(a));
	bfs();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
        	printf("%-5d", a[i][j]);
		}
        printf("\n");
    }
}
