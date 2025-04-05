#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010,inf=1e9+7;
struct node{
    int a,b;
    #define a(i) dat[i].a
    #define b(i) dat[i].b
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
int main(){//file();
    n=read();int cnt=0;
    while (n!=0){
        for (int i=1;i<=n;i++){
            a(i)=read();b(i)=read();
        }sort(dat+1,dat+n+1,cmp);
        int sum=0,ans=0;
        for (int i=1;i<=n;i++){
            sum+=a(i);
            ans=max(ans,b(i)+sum);
        }printf("Case %d: %d\n",++cnt,ans);
        n=read();
    }
    return 0;
}