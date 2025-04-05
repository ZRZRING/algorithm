#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
struct hh{
    ll x,y,dis;
}edge[1000100];
ll n,m,ans,fa[1000100],tmp,c;
ll cmp(hh a,hh b){
    return a.dis<b.dis;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
    cin>>c>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>tmp;if (i>=j||tmp==0)continue;
            edge[++m].x=i;edge[m].y=j;edge[m].dis=tmp;
        }
    }
    for (int i=1;i<=n;i++){
    	edge[++m].x=0;edge[m].y=i;edge[m].dis=c;
	}
    for (int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(edge+1,edge+m+1,cmp);
    for (int i=1;i<=m;i++){
        int x=find(edge[i].x),y=find(edge[i].y);
        if (x!=y){
            fa[y]=x;ans+=edge[i].dis;
        }
    }
    cout<<ans;
}
