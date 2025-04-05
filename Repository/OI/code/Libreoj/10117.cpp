#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x&-x)
using namespace std;
int tree[1000100],x,n,m,tmp,op,l,r;
void add(int x){
	while(x<=n){
		tree[x]^=1;
		x+=lowbit(x);
	}
}
int ask(int x){
	int ans=0;
	while(x){
		ans^=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>tmp;
		if (tmp==2){
			cin>>op;
			cout<<ask(op)<<endl;
		}else{
			cin>>l>>r;
			add(l);add(r+1);
		}
		/*for (int i=1;i<=n;i++){
			cout<<tree[i];
		}cout<<endl;*/
	}
}