#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
int n,m;
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
int main(){
    int T=read();
    while (T--){
        int bing=read()>>1,beef=read(),chi=read(),beef_val=read(),chi_val=read();
        int ans=0;
        if (beef_val>chi_val){
            printf("%d\n",min(bing,beef)*beef_val+max(0,min(chi,bing-beef))*chi_val);
        }else{
            printf("%d\n",min(bing,chi)*chi_val+max(0,min(beef,bing-chi))*beef_val);
        }
    }
    return 0;
}