#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define p(a,b) make_pair(a,b)
using namespace std;
const int N=200010;
int n,m,cnt;
map <pair<int,int>,bool> mp;
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
int main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read(),y=read();
        if (mp[p(x,i)])cnt--;
        else mp[p(i,x)]=1,cnt++;
        if (mp[p(y,i)])cnt--;
        else mp[p(i,y)]=1,cnt++;
    }
    if (cnt){
        printf("-1");return 0;
    }
    return 0;
}