#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct ENEMY{
	int begin,w,end;
}c[1001];
int n,p[1001],ans,T;
int cmp(ENEMY a,ENEMY b){
	return a.w>b.w;
}
int main(){
	cin>>T;
	while (T--){
		memset(p,0,sizeof(p));
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>c[i].begin>>c[i].w>>c[i].end;
		}
		sort(c+1,c+n+1,cmp);
		for (int i=1;i<=n;i++){
			if (p[i])continue;
			ans+=c[i].w;
			for (int j=i+1;j<=n;j++){
				if (p[j])continue;
				if (c[i].end>=c[j].begin&&c[i].begin>=c[j].end){
					p[j]=1;
				}
			}
		}
		cout<<ans;	
	}
}
