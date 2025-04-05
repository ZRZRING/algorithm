#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct hh{
	int h,w;
}apple[100000];
int a,b,n,s,w1,ans;
int my_swap(hh a,hh b){
	return a.w<b.w;
}
int main(){
	cin>>n>>s>>a>>b;a+=b; 
	for (int i=1;i<=n;i++){
		cin>>apple[i].h>>apple[i].w;
	}
	sort(apple+1,apple+n+1,my_swap);
	for (int i=1;i<=n;i++){
		if (apple[i].h<=a&&w1+apple[i].w<=s){
			w1+=apple[i].w;ans++;
		}
	}
	cout<<ans;
} 
