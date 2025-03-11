#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=1000000007;
typedef long long ll;
int ksm(ll a,int b,int c=1){
    for(;b;b/=2,a=a*a%mod)
        if(b&1)c=c*a%mod;
    return c;
}
int dp[N][N],n,m,ans,jc[2*N],jc2[2*N];;
char A[N],B[N];
int C(int n,int k){
    return (ll)jc[n]*jc2[k]%mod*jc2[n-k]%mod;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    jc[0]=1;
    for(int i=1;i<2*N;++i)jc[i]=(ll)jc[i-1]*i%mod;
    jc2[2*N-1]=ksm(jc[2*N-1],mod-2);
    for(int i=2*N-1;i;--i)jc2[i-1]=(ll)jc2[i]*i%mod;
    cin>>(A+1)>>(B+1);n=strlen(A+1);m=strlen(B+1);
    for(int i=0;i<=n;++i)dp[i][0]=1;
    for(int j=0;j<=m;++j)dp[0][j]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%mod;
            if(A[i]==B[j])dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            else dp[i][j]=(dp[i][j]+mod)%mod;
        }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << dp[i][j] << " \n"[j == m];
		}
	}
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(A[i]<B[j])ans=(ans+(ll)dp[i-1][j-1]*C(n-i+m-j,n-i))%mod;
    cout<<ans<<'\n';
    return 0;
}