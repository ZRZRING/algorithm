#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct hh{
	int l,r;
}t[1000100];
int n,ans;
int cmp(hh a,hh b){
	return a.r<b.r;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t[i].l>>t[i].r;
	}
	sort(t+1,t+n+1,cmp);
	/*for (int i=1;i<=n;i++){
		cout<<t[i].l<<' '<<t[i].r<<endl;
	}*/
	int i=1,j;
	while (i<=n){
		j=i+1;
		while (t[i].r>t[j].l&&j<=n)j++;
		ans++;i=j;
	}
	cout<<ans;
}
