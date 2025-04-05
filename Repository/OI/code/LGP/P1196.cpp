#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,x,y,list[100010],fa[100010],len[100010];
char ch;
int find(int x){
	if (fa[x]==x)return x;
    int fx=find(fa[x]);
    list[x]+=list[fa[x]];
    return fa[x]=fx;
}
int main(){
	cin>>n;
	for (int i=1;i<=30001;i++){
		fa[i]=i;len[i]=1;
	}
    for (int i=1;i<=n;i++){
		cin>>ch>>x>>y;int fx=find(x),fy=find(y);
		if (ch=='M'){
            list[fy]+=len[fx];fa[fy]=fx;len[fx]+=len[fy];len[fy]=0;
        }else{
			if (fx!=fy){
				cout<<-1<<endl;
			}else{
				cout<<abs(list[x]-list[y])-1<<endl;
			}
		}
	}
}
