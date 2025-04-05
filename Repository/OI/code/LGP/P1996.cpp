#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,nxt[100010],last[100010];
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
void write(int x){
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int main(){file();
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        nxt[i]=i+1;last[i]=i-1;
    }
    int p=0;nxt[0]=1;nxt[n]=1;last[1]=n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            p=nxt[p];
        }
        cout<<p<<' ';int tmp=last[p];nxt[last[p]]=nxt[p];last[nxt[p]]=tmp;
    }
}