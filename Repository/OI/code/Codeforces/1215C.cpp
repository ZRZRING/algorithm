#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=200010;
int n,m,ab[N],ba[N];
char a[N],b[N],p[2];
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
int main(){
    n=read();
    scanf("%s",a+1);scanf("%s",b+1);
    int cnt=0,cnt1=0,cnt2=0;
    for (int i=1;i<=n;i++){
        cnt+=(a[i]=='a')+(b[i]=='a');
        if (a[i]==b[i])continue;
        if (a[i]=='a')ab[++cnt1]=i;
        else ba[++cnt2]=i;
    }
    if (cnt%2==1){
        printf("-1");return 0;
    }
    printf("%d\n",cnt1/2+cnt2/2+cnt1%2+cnt2%2);
    for (int i=1;i<=cnt1-1;i+=2){
        printf("%d %d\n",ab[i],ab[i+1]);
    }
    for (int i=1;i<=cnt2-1;i+=2){
        printf("%d %d\n",ba[i],ba[i+1]);
    }
    if (cnt1%2==1&&cnt2%2==0){
        printf("%d %d\n",ab[cnt1],ab[cnt1]);
        return 0;
    }
    if (cnt1%2==0&&cnt2%2==1){
        printf("%d %d\n",ba[cnt2],ba[cnt2]);
        return 0;
    }
    if (cnt1%2==1&&cnt2%2==1){
        printf("%d %d\n%d %d\n",ab[cnt1],ab[cnt1],ab[cnt1],ba[cnt2]);
        return 0;
    }
    return 0;
}