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
const int maxn=100010,maxm=1000010;
const ll inf=2147483647;
struct EDGE{
    ll ver,nxt,dis;	
}edge[maxm];
ll head[maxn],p[maxn],ans[maxm];
ll n,m,cnt=0,s,x,y,t,start,ed;
priority_queue<pair<ll,ll> >q;
void dijskra(){
    for(int i=1;i<=n;i++)ans[i]=inf;
    memset(p,0,sizeof(p));
    ans[start]=0;
    q.push(make_pair(0,start));
    while (!q.empty()){
        int now=q.top().second;q.pop();
        if (p[now])continue;p[now]=1;
        for(int i=head[now];i;i=edge[i].nxt){
            int x=edge[i].ver,y=edge[i].dis;
            if(ans[x]>ans[now]+y){
                ans[x]=ans[now]+y;
                q.push(make_pair(-ans[x],x));
            }
        }
    }
}
void add(int x,int y,int t){
    edge[++cnt].ver=y; 
    edge[cnt].dis=t;
    edge[cnt].nxt=head[x];
    head[x]=cnt;
}
int main(){
    cin>>n>>m>>start>>ed;
    for (int i=1;i<=m;i++){
        cin>>x>>y>>t;
        add(x,y,t);
        add(y,x,t);
    }
    dijskra();
    cout<<ans[ed]<<endl;
}
