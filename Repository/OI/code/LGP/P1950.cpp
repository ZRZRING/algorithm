#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll n,m,h[1001][1001],num[100010],s[100010],ans;
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
            cin>>tmp;
            if (tmp=='.'){
                h[i][j]=h[i-1][j]+1;
            }else{
                h[i][j]=0;
            }
        }
    }
    /*for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<h[i][j]<<' ';
        }cout<<endl;
    }*/
    for (int i=1;i<=n;i++){
        int l[1001]={0},r[1001]={0},top=0;
        for (int j=m;j>=1;j--){
            while (top&&h[i][j]<=h[i][s[top]]){
                l[s[top]]=j;top--;
            }s[++top]=j;
        }top=0;
        for (int j=1;j<=m;j++){
            while (top&&h[i][j]<h[i][s[top]]){
                //这里没有=，上面有=，应该是相等的区间从一边只计算一次，呈三角状
                //所以只要有一边有=，另一边没有即可
                r[s[top]]=j;top--;
            }s[++top]=j;
        }while (top)r[s[top--]]=m+1;
        //for (int j=1;j<=m;j++)cout<<l[j]<<' ';cout<<endl;
        //for (int j=1;j<=m;j++)cout<<r[j]<<' ';cout<<endl;cout<<endl;
        for (int j=1;j<=m;j++){
            ans+=(j-l[j])*(r[j]-j)*h[i][j];
        }
    }cout<<ans;
}