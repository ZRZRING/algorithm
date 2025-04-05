#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int c1,c2,c3,a1[101],a2[101],a3[101],ans;
void search(int b1,int b2,int b3,int cnt,int now){
	if (b1==c1+1&&b2==c2+1&&b3==c3+1){
		ans=max(ans,now);return;
	}
	if (b1!=c1+1){
		search(b1+1,b2,b3,cnt+1,now+a1[b1]*cnt);
	}
	if (b2!=c2+1){
		search(b1,b2+1,b3,cnt+1,now+a2[b2]*cnt);
	}
	if (b3!=c3+1){
		search(b1,b2,b3+1,cnt+1,now+a3[b3]*cnt);
	}
}
int main(){
	cin>>c1>>c2>>c3;
	for (int i=c1;i>=1;i--)cin>>a1[i];
	for (int i=c2;i>=1;i--)cin>>a2[i];
	for (int i=c3;i>=1;i--)cin>>a3[i];
	search(1,1,1,1,0);
	cout<<ans;
}
