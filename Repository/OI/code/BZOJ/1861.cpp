// splay
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#define ls son[now][0]
#define rs son[now][1]
using namespace std;
void file(){
	freopen("read.in","r",stdin);
	freopen("write.out","w",stdout);
}
const int N=80010;
inline int read(){
	int sym=0,res=0;char ch=getchar();
	while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
	while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return sym?-res:res;
}
int n,m,a[N],rt,tot=1;
int val[N],fa[N],siz[N],pos[N],son[N][2];
char ch[N];
bool l_r(int x){
	return x==son[fa[x]][1];
}
void pushup(int now){
	siz[now]=siz[ls]+siz[rs]+1;pos[val[now]]=now;
}
void rotate(int x,int &goal){
	int y=fa[x],z=fa[y],kind=l_r(x);
	if (y==goal)goal=x;else son[z][l_r(y)]=x;
	son[y][kind]=son[x][kind^1];fa[son[x][kind^1]]=y;
	son[x][kind^1]=y;fa[y]=x;fa[x]=z;
	pushup(y);pushup(x);
}
void splay(int x,int &goal){
	for (int y=fa[x];x!=goal;y=fa[x]){
		if (y!=goal)rotate(l_r(x)==l_r(y)?y:x,goal);
		rotate(x,goal);
	}
}
void add(int x){
	int now=++tot;
	val[now]=x;pos[x]=now;siz[now]=1;
	fa[now]=now-1;son[fa[now]][1]=now;
	splay(now,rt);
}
int pre(){
	int now=son[rt][0];while (rs)now=rs;return now;
}
int suf(){
	int now=son[rt][1];while (ls)now=ls;return now;
}
void top(int x){
	splay(x,rt);int now=x;
	if (!ls)return;
	if (!rs){
		rs=ls;ls=0;return;
	}
	now=rt;int y=suf();fa[ls]=y;son[y][0]=ls;ls=0;splay(y,rt);
}
void bot(int x){
	splay(x,rt);int now=x;
	if (!rs)return;
	if (!ls){
		ls=rs;rs=0;return;
	}
	now=rt;int y=pre();fa[rs]=y;son[y][1]=rs;rs=0;splay(y,rt);
}
void ins(int x,int k){
	if (k==0)return;splay(x,rt);
	int y=k==1?suf():pre();
	swap(val[x],val[y]);pushup(x);pushup(y);
}
int find(int x){
	int now=rt;
	while (1){
		if (x<=siz[ls])now=ls;
		else{
			x-=siz[ls]+1;
			if (x<=0)return val[now];
			now=rs;
		}
	}
}
int get_ans(int x){
	splay(x,rt);return siz[son[x][0]];
}
int main(){//file();
	n=read();m=read();tot=1;
	rt=1;int x=read();val[1]=x;pos[x]=1;siz[1]=1;
	for (int i=2;i<=n;i++)x=read(),add(x);
	for (int i=1;i<=m;i++){
		scanf("%s",ch);x=read();
		switch (ch[0]){
			case 'T':top(pos[x]);break;
            case 'B':bot(pos[x]);break;
            case 'I':ins(pos[x],read());break;
            case 'Q':printf("%d\n",find(x));break;
            case 'A':printf("%d\n",get_ans(pos[x]));break;
		}
	}
	return 0;
}