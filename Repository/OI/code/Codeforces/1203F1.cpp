#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=500010;
struct node{
    int a,b;
}pos[N],neg[N];
int n,m,pos_cnt,neg_cnt;
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
bool cmp1(node a,node b){
    return a.a<b.a;
}
bool cmp2(node a,node b){
    return a.a+a.b>b.a+b.b;
}
int main(){
    n=read();int now=read();
    for (int i=1;i<=n;i++){
        int x=read(),y=read();
        if (y>=0){
            pos[++pos_cnt]=(node){x,y};
        }else{
            neg[++neg_cnt]=(node){x,y};
        }
    }
    sort(pos+1,pos+pos_cnt+1,cmp1);
    sort(neg+1,neg+neg_cnt+1,cmp2);
    for (int i=1;i<=pos_cnt;i++){
        if (now<pos[i].a){
            printf("NO");return 0;
        }else now+=pos[i].b;
    }
    for (int i=1;i<=neg_cnt;i++){
        if (now<neg[i].a){
            printf("NO");return 0;
        }else now+=neg[i].b;
    }
    if (now>=0)printf("YES");
    else printf("NO");
    return 0;
}