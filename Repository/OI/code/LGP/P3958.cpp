#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
const int orz=100010;
ll fa[orz],T,n,h,r,scnt,fcnt,x[orz],y[orz],z[orz],sky[orz],flor[orz];
double dis(long long x,long long y,long long z,long long x1,long long y1,long long z1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
}
ll find(ll now){
	if (fa[now]==now)return now;
	return fa[now]=find(fa[now]);
}
int main(){
	freopen("read.in","r",stdin);
	freopen("write.out","w",stdout);
	
	cin>>T;
	for (int t=1;t<=T;t++){
		cin>>n>>h>>r;
		fcnt=0;scnt=0;
        for (int i=1;i<=n;i++){
        	fa[i]=i;
        }
		/*if (n==1){
			cin>>x[1]>>y[1]>>z[1];
			if (z[1]<=r&&z[1]>=h-r)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
			continue;
		}*/
		for (int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if (z[i]+r>=h){
				sky[++scnt]=i;
			}
            if (z[i]-r<=0){
            	flor[++fcnt]=i;
			}
			for (int j=1;j<=i;j++){
                if (dis(x[i],y[i],z[i],x[j],y[j],z[j])<=2*r){
                    int tmp1=find(i);
                    int tmp2=find(j);
                    if (tmp1!=tmp2){
                    	fa[tmp1]=tmp2;
					}
                }
            }
		}
		int flag=1;
		for (int i=1;i<=fcnt;i++){
			for (int j=1;j<=scnt;j++){
				if (find(flor[i])==find(sky[j])&&flag){
					cout<<"Yes"<<endl;flag=0;
				}
			}
		}
		if (flag)cout<<"No"<<endl;
	}
}
