#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define num(i) dat[i].num
#define pos(i) dat[i].pos
#define d(i) dat[i].d
using namespace std;
const int N=500010;
struct node{
    int num,pos;
    char d;
}dat[N];
int n,m,order[N];
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
    return a.pos<b.pos;
}
int main(){//file();
    int T=read();
    for (int cnt=1;cnt<=T;cnt++){
        int len=read(),t=read();n=read();
        char x[1];
        for (int i=1;i<=n;i++){
            num(i)=i;pos(i)=read();scanf("%s",x);d(i)=x[0];
        }
        sort(dat+1,dat+n+1,cmp);
        for (int i=1;i<=n;i++){
            order[num(i)]=i;
            if (d(i)=='L')pos(i)-=t;else pos(i)+=t;
        }
        sort(dat+1,dat+n+1,cmp);
        printf("Case #%d:\n",cnt);
        for (int j=1;j<=n;j++){
            int i=order[j];
            if (pos(i)==pos(i-1)||pos(i)==pos(i+1)){
                printf("%d Turning\n",pos(i));continue;
            }
            if (pos(i)<0||pos(i)>len){
                printf("Fell off\n");continue;
            }
            printf("%d %c\n",pos(i),d(i));
        }printf("\n");
    }
    return 0;
}