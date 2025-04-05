#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int orz=500100,inf=0x7f7f7f7f;
int n,m,k,a[101][10],f[101][101][10];
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
int tmax(int a,int b,int c,int d,int e){
    return max(max(max(max(a,b),c),d),e);
}
int main(){file();
    n=read();m=read();k=read();
    if (m==1){
        for (int i=1;i<=n;i++){
            a[i][1]=read();
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=k;j++){
                f[i][j][0]=max(f[i-1][j][1],f[i-1][j][0]);
                f[i][j][1]=max(f[i-1][j-1][0],f[i-1][j][1])+a[i][1];
            }
        }
        printf("%d",max(f[n][k][0],f[n][k][1]));
    }else{
        memset(f,-0x3f,sizeof(f));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                f[i][j][0]=0;
            }
        }
        for (int i=1;i<=n;i++){
            a[i][1]=read();a[i][2]=read();
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=k;j++){
                f[i][j][0]=tmax(f[i-1][j][0],f[i-1][j][1],f[i-1][j][2],f[i-1][j][3],f[i-1][j][4]);
                f[i][j][1]=tmax(f[i-1][j-1][0],f[i-1][j][1],f[i-1][j-1][2],f[i-1][j-1][3],f[i-1][j][4])
                            +a[i][1];
                f[i][j][2]=tmax(f[i-1][j-1][0],f[i-1][j-1][1],f[i-1][j][2],f[i-1][j-1][3],f[i-1][j][4])
                            +a[i][2];
                f[i][j][3]=tmax(f[i-1][j-1][0],f[i-1][j-1][1],f[i-1][j-1][2],f[i-1][j][3],f[i-1][j-1][4])
                            +a[i][1]+a[i][2];
                f[i][j][4]=tmax(f[i-1][j-1][1],f[i-1][j-1][2],f[i-1][j][4],-inf,-inf)
                            +a[i][1]+a[i][2];
                if (j>=2){
                    f[i][j][4]=max(f[i][j][4],f[i-1][j-2][3]+a[i][1]+a[i][2]);
                    f[i][j][4]=max(f[i][j][4],f[i-1][j-2][0]+a[i][1]+a[i][2]);
                }
            }
        }
        printf("%d",tmax(f[n][k][0],f[n][k][1],f[n][k][2],f[n][k][3],f[n][k][4]));
    }
    return 0;
}