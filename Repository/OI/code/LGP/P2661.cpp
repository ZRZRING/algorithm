#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int fa[200010],dis[200010],ans=1<<30,n,tmp;
int find(int x){
    if(fa[x]!=x){
    	int last=fa[x];
        fa[x]=find(fa[x]);
        dis[x]+=dis[last];
    }
    return fa[x];
}
void add(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
        dis[x]=dis[y]+1;
    }
    else ans=min(ans,dis[x]+dis[y]+1);
    return;
}
int main()
{
	//freopen("2661.in","r",stdin);
	//freopen("my2661.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
    	fa[i]=i;
	}
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        add(i,tmp);
    }
    for (int i=1;i<=n;i++){
    	cout<<dis[i]<<' ';
	}cout<<endl;
    printf("%d",ans);
    return 0;
}
