#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int my_swap(hh a,hh b){
	return a.w<b.w; 
}
int findfa(int a){
	
}
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>x>>y>>l;
		a[i].x=x;
		a[i].y=y;
		a[i].w=l;
	}
	sort(a+1,a+m+1,my_swap);
	for (int i=1;i<=m;i++){
		if (pd()){
			cout<<ans;return 0;
		}else{
			ans+=a[i].w;
			fa[a[i].x]=findfa(a[i].x);
		}
	}
}
