#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int64, int64>

int64 det(PII p1, PII p2) {
    return p1.first * p2.second - p2.first * p1.second;
}

int64 polyarea(std::vector<PII> s) {
    int n = s.size();
    int64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += det(s[i], s[(i + 1) % n]);
    }
    return ans;
}
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> val(3 * n);
    for (int i = 0; i < n; i++) {
        std::cin >> val[i];
        val[i + n] = val[i];
        val[i + n + n] = val[i];
    }
    std::vector<PII> p(3 * n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].first >> p[i].second;
        p[i + n] = p[i];
        p[i + n + n] = p[i];
    }
    int64 max = 0;
    for (int s = n; s < n + n; s++) {
        std::cout << s + 1 << endl;
        std::vector<std::vector<int>> f(3 * n, std::vector<int>(3 * n));
        std::vector<std::vector<PII>> pre(3 * n, std::vector<PII>(3 * n));
        for (int l = s - 1; l >= 0; l--) {
            // int r = ;
            if (val[l] == val[r]) {
                if (f[l + 1][r - 1] + 1 > f[l][r]) {
                    f[l][r] = f[l + 1][r - 1] + 1;
                    pre[l][r] = {1, -1};
                }
            }
            if (f[l + 1][r] > f[l][r]) {
                f[l][r] = f[l + 1][r];
                pre[l][r] = {1, 0};
            }
            if (f[l][r - 1] > f[l][r]) {
                f[l][r] = f[l][r - 1];
                pre[l][r] = {0, -1};
            }
        }
        int64 res = 2;
        std::vector<PII> P;
        for (int l = n; l < 2 * n; l++) {
            for (int r = l; r < l + n; r++) {
                if (f[l][r] > res) {
                    P.clear();
                    res = f[l][r];
                }
                if (f[l][r] == res) {
                    P.push_back({l, r});
                }
            }
        }
        for (auto [l, r] : P) {
            std::set<int> ans;
            ans.insert(l % n);
            ans.insert(r % n);
            while (pre[l][r].first != 0 || pre[l][r].second != 0) {
                auto [x, y] = pre[l][r];
                if (x == 1 && y == -1) {
                    ans.insert(l % n);
                    ans.insert(r % n);
                }
                l += x;
                r += y;
            }
            std::vector<PII> a;
            for (auto x : ans) {
                a.push_back(p[x]);
                std::cout << x + 1 << ' ';
            }
            std::cout << endl;
            max = std::max(max, polyarea(a));
        }
    }
    std::cout << max << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
}