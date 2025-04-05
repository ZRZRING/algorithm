#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,t[100010],dis[1001][1001],Q,x,y,now=1,time;
int main(){
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>t[i];
	}
	int tmpx,tmpy,tmp;
	for (int i=1;i<=m;i++){
		cin>>tmpx>>tmpy>>tmp;
		dis[tmpx][tmpy]=tmp;
		dis[tmpy][tmpx]=tmp;
	}
	for (int i=0;i<n;i++)dis[i][i]=0;
	cin>>Q;
	while (Q--){
		cin>>x>>y>>time;
		while (t[now]<=time&&now<n){
			for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][now]+dis[now][j]);
				}
			}now++;
		}
        if(t[x]>time||t[y]>time)cout<<-1<<endl;
        else {
            if(dis[x][y]==0x3f3f3f3f)cout<<-1<<endl;
            else cout<<dis[x][y]<<endl;
        }
	}
}
