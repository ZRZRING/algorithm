#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int M = 998244353;
vector<vector<int> > tran(36, vector<int>(36, 0));
vector<int> bs(36, 0);
vector<pair<int, int> > opr;
void solve()  // simple dp
{
    vector<int> dp = bs, dp2 = bs;
    dp[0] = 1;
    int n;
    cin >> n;
    for (; n--; dp = dp2, dp2 = bs)
        for (auto [a, b] : opr)
            (dp2[b] += (1ll * dp[a] * tran[a][b] % M)) %= M;
    ll ans = 0;
    for (int b = 0; b < 5; b++)
        (ans += dp[30 + b]) %= M;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int a = 0; a < 6; a++)
        for (int b = 0; b < 5; b++)
            for (int nxt = 1; nxt <= 5 - (b == 4); nxt++) {
                int c = a + (nxt == a + 1), d = ((nxt == b + 1) ? nxt : (nxt == 1));
                tran[a * 6 + b][c * 6 + d]++;
            }
    for (int i = 0; i < 36; i++)
        for (int j = 0; j < 36; j++)
            if (tran[i][j])
                opr.push_back({i, j});
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
/*
        int cnt=0;
        for(int i=0;i<36;i++)
        {
                for(int j=0;j<36;j++)cout<<tran[i][j],cnt+=(tran[i][j]!=0);
                cout<<'\n';
        }
        cout<<"!!!!!!!!!!!!!!!!!!!!!\n";
        cout<<cnt<<"/1296\n";
*/