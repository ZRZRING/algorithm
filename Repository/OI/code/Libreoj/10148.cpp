#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int a[100010],f[1001][1001],n,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];a[i+n]=a[i];
    }
    for (int j=2;j<2*n;j++){
        for (int i=j-1;i>max(j-n,0);i--){
            for (int k=i;k<j;k++){
                f[i][j]=max(f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1],f[i][j]);
            }
            ans=max(ans,f[i][j]);
        }
    }
    printf("%d",ans);
}