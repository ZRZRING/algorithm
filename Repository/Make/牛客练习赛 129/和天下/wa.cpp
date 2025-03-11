#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
const int N = 200100;
ll a[N];
int pre[N];
int Rank[N];
void init(int n) {
    for (int i = 0; i <= n; ++i) {
        pre[i] = i;
        Rank[i] = 1;
    }
}
int find(int now) {
    if (pre[now] == now)
        return now;
    else
        return pre[now] = find(pre[now]);
}
bool equal(int x, int y) {
    return find(x) == find(y);
}
bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    else {
        pre[y] = x;
        Rank[x] += Rank[y];
        return true;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k;
    int t, n, i, j, w, ans;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 1; i <= n; ++i)
            cin >> a[i];
        if (k == 0) {
            cout << n << '\n';
            continue;
        }
        sort(a + 1, a + n + 1);
        init(n);
        vector<int> b[64];
        for (i = 1; i <= n; ++i)
            for (j = 0; j < 62; ++j)
                if ((a[i] >> j) & 1)
                    b[j].emplace_back(i);
        w = __lg(k);
        for (j = 0; j < 62; ++j)
            for (i = 1; i < b[j].size(); ++i)
                if ((a[b[j][i - 1]] & a[b[j][i]]) >= k)
                    merge(b[j][i - 1], b[j][i]);
        vector<int> f1 = b[w];
        while (!f1.empty() && w >= 0) {
            vector<int> f2, f3;
            for (i = 1; i < f1.size(); ++i)
                if ((a[f1[i - 1]] & a[f1[i]]) >= k)
                    merge(f1[i - 1], f1[i]);
            //             int new_ans=0;
            //             for(i=1;i<=n;++i)
            //                 if(find(i)==i)
            //                     new_ans=max(new_ans,Rank[i]);
            //             cout<<new_ans<<'\n';
            for (i = 0; i < f1.size(); ++i) {
                if ((a[f1[i]] >> w) & 1)
                    f2.emplace_back(f1[i]);
                else
                    f3.emplace_back(f1[i]);
            }
            if ((k >> w) & 1)
                f1 = f2;
            else {
                for (i = 1; i < f2.size(); ++i)
                    merge(f2[i - 1], f2[i]);
                f1 = f3;
            }
            --w;
        }
        ans = 0;
        for (i = 1; i <= n; ++i)
            if (find(i) == i)
                ans = max(ans, Rank[i]);
        cout << ans << '\n';
    }
    return 0;
}