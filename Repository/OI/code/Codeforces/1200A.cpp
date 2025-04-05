#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100100;
int n,m,cnt;
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
}
int vis[N];
char str[N];
int main(){
    n=read();scanf("%s",str);
    for (int i=0;i<n;i++){
        if (str[i]=='L'){
            for (int j=0;j<=9;j++){
                if (!vis[j]){
                    vis[j]=1;break;
                }
            }
        }else if (str[i]=='R'){
            for (int j=9;j>=0;j--){
                if (!vis[j]){
                    vis[j]=1;break;
                }
            }
        }else{
            vis[str[i]-'0']=0;
        }
    }
    for (int i=0;i<=9;i++){
        printf("%d",vis[i]);
    }
    return 0;
}