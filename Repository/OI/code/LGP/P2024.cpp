#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fa[500010],n,m,ans,tmp,x,y;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline int read(){
   int sum=0,sym=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')sym=-1;ch=getchar();}
   while(ch>='0'&&ch<='9')sum=sum*10+ch-'0',ch=getchar();
   return sum*sym;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=3*n;i++){
		fa[i]=i;
	}
	for (int i=1;i<=m;i++){
		tmp=read();x=read();y=read();
		if (x>n||y>n){
			ans++;continue;
		}else{
			if (tmp==1){
				if (find(x)==find(y+n)||find(y)==find(x+n))ans++;
				else{
					fa[find(x)]=find(y);
					fa[find(x+n)]=find(y+n);
					fa[find(x+n+n)]=find(y+n+n);
				}
			}else{
				if (find(x)==find(y)||find(x)==find(y+n))ans++;
				else{
					fa[find(x+n)]=find(y);
					fa[find(x+n+n)]=find(y+n);
					fa[find(x)]=find(y+n+n); 
				}
			}
		}
	}
	cout<<ans;
}
