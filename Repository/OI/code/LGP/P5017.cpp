#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=2139062143,qwq=550,orz=50010;
int n,m,t[orz],s[orz],f[qwq][qwq];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>t[i];
	}
	sort(t+1,t+n+1);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+t[i];
	}
	memset(f,0x7f,sizeof(f));
	t[0]=-inf;
	f[0][0]=0;
	for (int i=0;i<=n;i++){
		int maxx=min(m-1,t[i+1]-t[i]);
		//cout<<maxx<<endl;
		for (int j=0;j<=maxx;j++){
			if (f[i][j]!=inf)
			for (int k=i+1;k<=n;k++){
				int tmp=max(t[i]+j+m-t[k],0);
				//cout<<tmp<<' ';
				f[k][tmp]=min(f[k][tmp],f[i][j]+(tmp+t[k])*(k-i)-(s[k]-s[i]));
			}
			//cout<<endl;
		}
	}
	int ans=inf;
	for (int i=0;i<m;i++){
		ans=min(ans,f[n][i]);
	}
	printf("%d\n",ans);
}
