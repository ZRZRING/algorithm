#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define a(i) dat[i].a
#define b(i) dat[i].b
#define num(i) dat[i].num
using namespace std;
const int N=500010;
struct node{
    int a,b,num;
}dat[N];
int n,m;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (!isdigit(ch))sym|=(ch=='-'),ch=getchar();
    while (isdigit(ch))res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
bool cmp(node a,node b){
    return a.b>b.b;
}
int main(){
    int T=read();
    while (T--){
        n=read();int q=read();
        for (int i=1;i<=n;i++){
            a(i)=read();b(i)=a(i)-read();num(i)=i;
        }int ans=1e9+7;
        sort(dat+1,dat+n+1,cmp);
        for (int i=1;i<=n;i++)printf("%d %d\n",a(i),b(i));
        for (int i=1;i<=n;i++){
            int r=q-a(i),no=num(i),j=1;
            for (;j<=n;j++){
                if (j==no)continue;
                if (r<=0||b(j)<=0)break;
                r-=b(j);
            }
            if (r<=0)ans=min(ans,j);
        }
        if (ans!=1e9+7)printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}