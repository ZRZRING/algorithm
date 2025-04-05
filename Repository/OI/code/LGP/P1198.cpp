#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int m,p,x,t,f[1000100][30],r;
char ch;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){file();
    scanf("%d%d",&m,&p);
    for (int i=1;i<=m;i++){
        cin>>ch;scanf("%d",&x);
        if (ch=='A'){
            x=(x+t)%p;r++;int tmp=2;f[r][0]=x;
            for(int j=1;r-(1<<j)>=0;j++)f[r][j]=max(f[r][j-1],f[r-(1<<(j-1))][j-1]);
        }else{
            int l=r-x+1,tmp=log(x)/log(2);
            t=max(f[r][tmp],f[l+(1<<tmp)-1][tmp]);
            printf("%d\n",t);
        }
        /*for (int j=1;j<=1000;j++){
            for (int k=0;j+(1<<k)-1<=r;k++){
                if (f[j][k]<=0)break;
                cout<<j<<':'<<k<<'-'<<f[j][k]<<endl;
            }
        }cout<<endl;*/
    }
}