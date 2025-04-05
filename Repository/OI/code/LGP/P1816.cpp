#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int orz=100001;
int a[orz],tree[orz*4];
void build(int now,int l,int r){
    if (l==r){tree[now]=a[l];return;}
    build(now*2,l,(l+r)>>1);
    build(now*2+1,((l+r)>>1)+1,r);
    tree[now]=min(tree[now*2],tree[now*2+1]);
}
int qj(int now,int l,int r,int x,int y){
    if (l>=x&&r<=y)return tree[now];
    int minn=1<<30;
    if ((l+r)>>1>=x)minn=min(minn,qj(now*2,l,(l+r)>>1,x,y));
    if ((l+r)>>1<y)minn=min(minn,qj(now*2+1,((l+r)>>1)+1,r,x,y));
    return minn;
}
int main(){
    int n,m,x,y;
    cin>>m>>n;
    for (int i=1;i<=m;i++){
        cin>>a[i];
    }
    build(1,1,m);
    for (int i=1;i<=n;i++){
        cin>>x>>y;
        cout<<qj(1,1,m,x,y)<<' ';
    }
}
