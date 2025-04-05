#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[100010],pre[100010],suf[100010],ans,res;
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int main(){file();
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);int l=1,r=1;
    for (int i=1;i<=n;i++){
        r++;while (a[r]-a[l]>m)l++;
        pre[i]=r-l+1;
    }l=n;r=n;
    for (int i=n;i>=1;i--){
        l--;while (a[r]-a[l]>m)r--;
        suf[i]=r-l+1;
    }
    for (int i=1;i<=n-1;i++){
        if (pre[i]+suf[i+1]>ans){
            ans=pre[i]+suf[i+1];res=i;
        }
    }
    cout<<res+1;
}