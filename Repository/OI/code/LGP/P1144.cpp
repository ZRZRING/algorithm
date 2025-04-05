#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#define ll long long
using namespace std;
const ll inf=2147483647;
struct EDGE{
    ll ver,nxt;	
}edge[2000100];
ll head[2000100],p[2000100],ans[2000100];
ll n,m,cnt=0,s,x,y,t,sum[2000100];
priority_queue<pair<ll,ll> >q;
void dijskra(){
    for(int i=1;i<=n;i++)ans[i]=inf;
    memset(p,0,sizeof(p));
    ans[1]=0;sum[1]=1;
    q.push(make_pair(0,1));
    while (!q.empty()){
        int now=q.top().second;q.pop();
        for(int i=head[now];i;i=edge[i].nxt){
            int x=edge[i].ver;
            if(ans[x]>ans[now]+1){
                ans[x]=ans[now]+1;sum[x]=sum[now]%100003;
                q.push(make_pair(-ans[x],x));
            }else{
            	if (ans[x]==ans[now]+1){
            		sum[x]+=sum[now];sum[x]%=100003;
				}
			}
        }
    }
}
void add(int x,int y){
    edge[++cnt].ver=y; 
    edge[cnt].nxt=head[x];
    head[x]=cnt;
}
int main(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>x>>y;
        add(x,y);add(y,x);
    }
    dijskra();
    for (int i=1;i<=n;i++){
    	cout<<sum[i]<<endl;
	}
}
