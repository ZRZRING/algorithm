#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define ls son[now][0]
#define rs son[now][1]
using namespace std;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
const int N=500010,inf=1e9;
inline int read(){
    int sym=0,res=0;char ch=getchar();
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
int n,m,rt,a[N],id[N],tot;
int sum[N],ans[N],pre[N],suf[N],val[N];
int son[N][2],fa[N],tag[N],rev[N],siz[N];
char ch[N];
queue<int>q;
bool l_r(int x){
    return x==son[fa[x]][1];
}
void clear(int x){
    son[x][0]=son[x][1]=fa[x]=tag[x]=rev[x]=sum[x]=ans[x]=siz[x]=0;
}
int max_3(int a,int b,int c){
    return max(a,max(b,c));
}
void pushup(int now){
    if (!now)return;
    sum[now]=sum[ls]+sum[rs]+val[now];
    siz[now]=siz[ls]+siz[rs]+1;
    pre[now]=max(sum[ls]+val[now]+pre[rs],pre[ls]);
    suf[now]=max(sum[rs]+val[now]+suf[ls],suf[rs]);
    ans[now]=max_3(ans[ls],ans[rs],suf[ls]+val[now]+pre[rs]);
}
void lazy_change(int now,int t){
    tag[now]=1;val[now]=t;
    sum[now]=val[now]*siz[now];
    ans[now]=max(sum[now],val[now]);
    suf[now]=pre[now]=max(sum[now],0);
}
void lazy_rev(int now){
    rev[now]^=1;swap(ls,rs);swap(pre[now],suf[now]);
}
void pushdown(int now){
    if (tag[now]){
        if (ls)lazy_change(ls,val[now]);
        if (rs)lazy_change(rs,val[now]);
        rev[now]=tag[now]=0;
    }
    if (rev[now]){
        if (ls)lazy_rev(ls);
        if (rs)lazy_rev(rs);
        rev[now]=0;
    }
}
void build(int last,int l,int r){
    if (l>r)return;
    int mid=l+r>>1,now=id[mid];fa[now]=id[last];
    if (l==r){
        sum[now]=ans[now]=a[l];siz[now]=1;
        pre[now]=suf[now]=max(a[l],0);
    }
    build(mid,l,mid-1);build(mid,mid+1,r);
    val[now]=a[mid];son[fa[now]][mid>last]=now;
    pushup(now);
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
void cut(int now){
    if (ls)cut(ls);if (rs)cut(rs);q.push(now);clear(now);
}
int find(int x){//返回序列第x个数在树上的节点编号
    int now=rt;
    while (1){
        pushdown(now);
        if (x<=siz[ls])now=ls;
        else{
            x-=siz[ls]+1;if (x<=0)return now;now=rs;
        }
    }
}
void ins(int l,int r){
    int len=r-l+1;
    for (int i=1;i<=len;i++)a[i]=read();
    for (int i=1;i<=len;i++){
        if (!q.empty())id[i]=q.front(),q.pop();
        else id[i]=++tot;
    }
    build(0,1,len);int root=id[len+1>>1];
    int x=find(l),y=find(l+1);
    splay(x,rt);splay(y,son[x][1]);
    son[y][0]=root;fa[root]=y;
    pushup(y);pushup(x);
}
int split(int l,int r){
    int x=find(l-1),y=find(r+1);
    splay(x,rt);splay(y,son[x][1]);
    return son[y][0];
}
void del(int l,int r){
    int x=split(l,r),y=fa[x];
    cut(x);son[y][0]=0;
    pushup(y);pushup(fa[y]);
}
void rever(int l,int r){
    int now=split(l,r),y=fa[now];
    lazy_rev(now);pushup(y);pushup(fa[y]);
}
void change(int l,int r,int t){
    int now=split(l,r),y=fa[now];
    lazy_change(now,t);pushup(y);pushup(fa[y]);
}
int query(int l,int r){
    int x=split(l,r);return sum[x];
}
int main(){//file();
    n=read();m=read();rt=n+3>>1;
    ans[0]=a[1]=a[n+2]=-inf;//保证至少选一个数
    for (int i=2;i<=n+1;i++)a[i]=read();
    for (int i=1;i<=n+2;i++)id[i]=i;
    tot=n+2;build(0,1,tot);
    for (int i=1;i<=m;i++){
        scanf("%s",ch);
        if (ch[0]=='M'&&ch[2]=='X'){//max_sum
            printf("%d\n",ans[rt]);continue;
        }
        int l=read()+1,r=l+read()-1;
        if (ch[0]=='I'){//insert
            ins(l,r);
        }
        if (ch[0]=='D'){//delete
            del(l,r);
        }
        if (ch[0]=='R'){//reverse
            rever(l,r);
        }
        if (ch[0]=='G'){//get_sum
            printf("%d\n",query(l,r));
        }
        if (ch[0]=='M'&&ch[2]=='K'){//make_same
            int t=read();change(l,r,t);
        }
    }
    return 0;
}