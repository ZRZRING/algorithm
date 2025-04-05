#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,h[1010][1010],num[1000100],s[1000100],ans,a[1010][1010];
int l[1010][1010],r[1010][1010],up[1010][1010],ans_squ,ans_rec;
char tmp;
int read(){
    int res=0,sym=0;char ch=getchar();
    while(ch<'0'||ch>'9'){sym|=ch=='-';ch=getchar();}
    while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){file();
    n=read();m=read();
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=read();
            l[i][j]=r[i][j]=j;
            up[i][j]=1;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=2;j<=m;j++){
            if (a[i][j]!=a[i][j-1]){
                l[i][j]=l[i][j-1];
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=m-1;j>=1;j--){
            if (a[i][j]!=a[i][j+1]){
                r[i][j]=r[i][j+1];
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (i!=1&&a[i][j]!=a[i-1][j]){
                l[i][j]=max(l[i][j],l[i-1][j]);
                r[i][j]=min(r[i][j],r[i-1][j]);
                up[i][j]=up[i-1][j]+1;
            }
            int x=r[i][j]-l[i][j]+1,y=up[i][j];//x长，y高
            ans_squ=max(ans_squ,min(x,y)*min(x,y));
            ans_rec=max(ans_rec,x*y);
        }
    }
    printf("%d\n%d",ans_squ,ans_rec);
}