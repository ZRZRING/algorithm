#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=300010,p=998244353;
struct node{
    int a,b;
}c[N];
int n,m,cnt,a[N],b[N],mul[N];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
}
int cmp(node x,node y){
    return x.a==y.a?x.b<y.b:x.a<y.a;
}
signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        a[i]=read();b[i]=read();
        c[i].a=a[i];c[i].b=b[i];
    }sort(a+1,a+n+1);sort(b+1,b+n+1);sort(c+1,c+n+1,cmp);
    mul[0]=1;
    for (int i=1;i<=n;i++){
        mul[i]=mul[i-1]*i%p;
    }
    int ans1=1,ans2=1,ans12=1;
    for (int i=1;i<=n;i++){
        int tmp=1;
        while (a[i]==a[i+1])tmp++,i++;
        ans1=ans1*mul[tmp]%p;
    }
    for (int i=1;i<=n;i++){
        int tmp=1;
        while (b[i]==b[i+1])tmp++,i++;
        ans2=ans2*mul[tmp]%p;
    }
    for (int i=1;i<=n;i++){
        int tmp=1;
        while (c[i].a==c[i+1].a&&c[i].b==c[i+1].b)tmp++,i++;
        ans12=ans12*mul[tmp]%p;
    }
    for (int i=1;i<=n;i++){
        if (c[i].b<c[i-1].b)ans12=0;
    }
    printf("%lld\n",(mul[n]-(ans1+ans2)%p+p+ans12)%p);
    return 0;
}