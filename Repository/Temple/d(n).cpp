#include <bits/stdc++.h>

using int64 = long long;

struct FUNCTION {
    int n;

    std::vector<int> vis, c, d, prime;

    FUNCTION(int n) : n(n) {
        vis.resize(n);
        c.resize(n);
        d.resize(n);
        prime.resize(n);
    }

    void init() {
        vis[1] = 1;
        d[1] = 1;
        c[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                prime.push_back(i);
                c[i] = i;
                d[i] = 2;
            }
            for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
                vis[i * prime[j]] = 1;
                if (i % prime[j] == 0) {
                    c[i * prime[j]] = c[i] * prime[j];
                    d[i * prime[j]] = d[i] + d[i / c[i]];
                    break;
                }
                d[i * prime[j]] = d[i] * 2;
                c[i * prime[j]] = prime[j];
            }
        }
    }
};