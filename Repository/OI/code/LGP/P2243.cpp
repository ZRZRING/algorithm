#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
struct EDGE{
	int nxt,ver,dis,u;
}edge[500010];
int T,cnt,n,m,u,v,head[500010],ans[500010],p[500010];
char ch;
void add(int u,int v,int dis){
	edge[++cnt].nxt=head[u];
	edge[cnt].u=u;
	edge[cnt].ver=v;
	edge[cnt].dis=dis;
	head[u]=cnt;
}
int main(){
	for (cin>>T;T;T--){
		deque<int>q;q.clear();
		memset(ans,127,sizeof(ans));
		cnt=0;memset(p,0,sizeof(p));
		memset(head,0,sizeof(head));
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>ch;
				if ((i+j)%2==0){//偶格：左上右下 
					u=(i-1)*(m+1)+j;v=i*(m+1)+j+1;
				}else{//奇格：左下右上 
					u=i*(m+1)+j;v=(i-1)*(m+1)+j+1;
				}
				if (((i+j)%2==0&&ch=='\\')||((i+j)%2==1&&ch=='/')){
					add(u,v,0);add(v,u,0);
				}else{
					add(u,v,1);add(v,u,1);
				}
			}
		}
		if ((n+m)%2==1){
			cout<<"NO SOLUTION"<<endl;continue;
		}
		/*for (int i=1;i<=cnt;i++){
			cout<<edge[i].dis<<' '<<edge[i].u<<' '<<edge[i].ver<<endl;
		}*/
		q.push_front(1);ans[1]=0;
		while (!q.empty()){
			int now=q.front();p[now]=1;
			if (now==(n+1)*(m+1)){
				cout<<ans[now]<<endl;break;
			}q.pop_front();
			for (int i=head[now];i;i=edge[i].nxt){
				int x=edge[i].ver;
				if (!p[x]){
					if (edge[i].dis){
						ans[x]=min(ans[x],ans[now]+1),q.push_back(x);
					}else{
						ans[x]=min(ans[now],ans[x]),q.push_front(x);
					}
				}
			}
		}
	}
}
