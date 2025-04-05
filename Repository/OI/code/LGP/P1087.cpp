#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char str[10010],tree[10010];
int n;
void build(int now,int l,int r){
    if (l==r){
        tree[now]=(str[l]=='0'?'B':'I');
        return;
    }
    int mid=(l+r)>>1;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
    tree[now]=(tree[now*2]==tree[now*2+1]?tree[now*2]:'F');
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void write(int now,int l,int r){
    if (l==r){
        cout<<tree[now];return;
    }
    int mid=(l+r)>>1;
    write(now*2,l,mid);
    write(now*2+1,mid+1,r);
    cout<<tree[now];
}
int main(){file();
    cin>>n;
    scanf("%s",str+1);
    build(1,1,1<<n);
    write(1,1,1<<n);
}
