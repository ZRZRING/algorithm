#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define lg(x) ((int)log10(x))
#define log(x) ((int)log2(x))
#define PII std::pair<int, int64>
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MOD(x) ((x) = ((x) % mod + mod) % mod)
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

struct TREE {
    int n, root = 1, dfn_cnt = 0;

    std::vector<std::vector<PII>> e;

    std::vector<std::vector<int>> fa, min;

    std::vector<int> dep, dfn, vis;

    TREE(int n, int root = 1)
        : n(n), root(root) {
        e.resize(n);
        fa.resize(n);
        dep.resize(n);
        dfn.resize(n);
        min.resize(n);
        vis.resize(n);
        for (int i = 0; i < n; i++) {
            fa[i].resize(21);
        }
        for (int i = 0; i < n; i++) {
            min[i].resize(21);
        }
    }

    void add(int u, int v, int t) {
        e[u].push_back({v, t});
        e[v].push_back({u, t});
    }

    void dfs(int u, int last) {
        dfn[u] = ++dfn_cnt;
        dep[u] = dep[last] + 1;
        for (int i = 1; i <= 20; i++) {
            if (!fa[u][i - 1]) break;
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
            min[u][i] = std::min(min[u][i - 1], min[fa[u][i - 1]][i - 1]);
        }
        for (auto [v, t] : e[u]) {
            if (v == fa[u][0]) continue;
            fa[v][0] = u;
            min[v][0] = t;
            dfs(v, u);
        }
    }

    int lca(int x, int y) {
        if (dep[x] < dep[y]) std::swap(x, y);
        for (int i = dep[x] - dep[y], j = 0; i > 0; i >>= 1, j++) {
            // std::cout << j << endl;
            if (i & 1) x = fa[x][j];
        }
        if (x != y) {
            for (int i = 20; i >= 0; i--) {
                if (fa[x][i] == fa[y][i]) continue;
                x = fa[x][i];
                y = fa[y][i];
            }
            x = fa[x][0];
        }
        return x;
    };

    int get_min(int x, int y) {
        int res = 1e9;
        for (int i = 20; i >= 0; i--) {
            if (dep[fa[x][i]] < dep[y]) continue;
            res = std::min(res, min[x][i]);
            x = fa[x][i];
        }
        return res;
    }

    int64 cal(int u, int last) {
        int64 res = 0;
        for (auto [v, t] : e[u]) {
            if (v == last) continue;
            if (vis[v]) res += t;
            else res += std::min(t, cal(v, u));
        }
        return res;
    }
};

int solve() {
    int n;
    std::cin >> n;
    TREE t1(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, t;
        std::cin >> u >> v >> t;
        t1.add(u, v, t);
    }
    t1.dfs(1, 1);
    int m;
    std::cin >> m;
    std::vector<int> vis(n + 1);
    while (m--) {
        int c;
        std::cin >> c;
        std::vector<int> S(c + 1);
        S[0] = 1;
        for (int i = 1; i <= c; i++) {
            std::cin >> S[i];
            vis[S[i]] = 1;
        }
        std::sort(S.begin(), S.end(), [&](int a, int b) {
            return t1.dfn[a] < t1.dfn[b];
        });
        int t = S.size();
        for (int i = 1; i < t; i++) {
            S.push_back(t1.lca(S[i - 1], S[i]));
        }
        std::sort(S.begin(), S.end(), [&](int a, int b) {
            return t1.dfn[a] < t1.dfn[b];
        });
        c = std::unique(S.begin(), S.end()) - S.begin();
        S.resize(c);
        // for (auto x : S) {
        // 	std::cout << x << ' ';
        // }
        // std::cout << endl;
        std::map<int, int> T;
        TREE t2(S.size(), 0);
        for (int i = 0; i < S.size(); i++) {
            T[S[i]] = i;
            if (vis[S[i]]) t2.vis[i] = 1;
        }
        for (int i = 1; i < S.size(); i++) {
            int u = S[i], v = t1.lca(S[i], S[i - 1]), t = t1.get_min(u, v);
            // std::cout << u << ' ' << v << ' ' << t << endl;
            t2.add(T[u], T[v], t);
            // std::cout << T[u] << ' ' << T[v] << ' ' << t << endl;
        }
        std::cout << t2.cal(0, 0) << endl;
        for (auto x : S) vis[x] = 0;
    }
    return 0;
}

int main() {
    // Fast_IOS;
    int T = 1;
    // std::cin >> T;
    while (T--) {
        int t = solve();
        if (t == 0)
            continue;
        if (t == YES)
            std::cout << "YES" << endl;
        if (t == NO)
            std::cout << "NO" << endl;
    }
    return 0;
}