#include <cstdio>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int cnt = 0, N;
const int maxn = 10005;
int T, id, B, M;
int dp[55][1005];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &B, &M);
        for (int i = 1; i <= B; i++)
            for (int j = 1; j <= M; j++)
                dp[i][j] = INF;
        for (int i = 0; i <= B; i++)
            dp[i][1] = 1, dp[i][0] = 0;
        for (int i = 0; i <= M; i++)
            dp[1][i] = i;
        for (int i = 2; i <= B; i++)
            for (int j = 2; j <= M; j++)
                for (int k = 1; k <= j; k++)
                    dp[i][j] = min(dp[i][j], 1 + max(dp[i - 1][k - 1], dp[i][j - k]));
        cout << dp[B][M] << endl;
    }
    return 0;
}