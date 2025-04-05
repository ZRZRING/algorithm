#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int N=10010;
int n,b,cnt,a[N];
char type[N],name[N];
struct node{
    int cost,val;
};
map<string,int>id;
vector<node>comp[N];
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
int ID(string s){
    if (!id.count(s))id[s]=++cnt;
    return id[s];
}
bool check(int t){
    int sum=0;
    for (int i=1;i<=cnt;i++){
        int minn=b+1;
        vector<node>::iterator it;
        for (it=comp[i].begin();it!=comp[i].end();it++){
            node x=(*it);
			if (x.val>=t){
                minn=min(minn,x.cost);
            }
        }if (minn==b+1)return 0;
        sum+=minn;if (sum>b)return 0;
    }
    return 1;
}
int main(){//file();
    int T=read();
    while (T--){
        n=read();b=read();
        for (int i=1;i<=n;i++){
            comp[i].clear();
        }id.clear();cnt=0;
        int l=0,r=0;
        for (int i=1;i<=n;i++){
            scanf("%s%s",type,name);
            int cost=read(),val=read();r=max(r,val);
            comp[ID(type)].push_back((node){cost,val});
        }
        while (l<r){
            int mid=l+r+1>>1;
            if (check(mid))l=mid;
            else r=mid-1;
        }printf("%d\n",l);
    }
    return 0;
}