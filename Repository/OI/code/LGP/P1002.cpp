#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int gox[10]={0,-2,-2,-1,-1,1,1,2,2};
const int goy[10]={0,1,-1,2,-2,2,-2,1,-1};
long long n,m,hx,hy,p[1001][1001],dp[1001][1001];
int main(){
    cin>>n>>m>>hx>>hy;n++;m++;hx++;hy++;p[hx][hy]=1;
    for (int i=1;i<=8;i++){
        if (hx+gox[i]<0||hy+goy[i]<0)continue;
        p[hx+gox[i]][hy+goy[i]]=1;
    }
    dp[1][1]=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            //cout<<p[i][j]<<' ';
            if (i==1&&j==1)continue;
            if (p[i][j])dp[i][j]=0;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            //cout<<dp[i][j]<<' ';
        }//cout<<endl;
    }
    cout<<dp[n][m];
}