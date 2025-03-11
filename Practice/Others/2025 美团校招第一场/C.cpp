#include <bits/stdc++.h>

using A2 = std::array<int, 2>;

struct NODE {
    bool B, U, G, BU, UG, BUG;
    bool UB, GU, GUB;
    NODE() {
        B = U = G = BU = UG = BUG = 0;
        UB = GU = GUB = 0;
    }
    NODE(char c) {
        B = (c == 'B');
        U = (c == 'U');
        G = (c == 'G');
    }
    friend NODE operator + (const NODE a, const NODE b) {
        NODE c;
        c.B = (a.B || b.B);
        c.U = (a.U || b.U);
        c.G = (a.G || b.G);
        c.BU = (a.BU || b.BU || a.B && b.U);
        c.UG = (a.UG || b.UG || a.U && b.G);
        c.BUG = (a.BUG || b.BUG || a.B && b.UG || a.BU && b.G);
        c.UB = (a.UB || b.UB || a.U && b.B);
        c.GU = (a.GU || b.GU || a.G && b.U);
        c.GUB = (a.GUB || b.GUB || a.G && b.UB || a.GU && b.B);
        return c;
    }
};

NODE rev(NODE &a) {
    std::swap(a.BU, a.UB);
    std::swap(a.UG, a.GU);
    std::swap(a.BUG, a.GUB);
    return a;
}

void print(NODE a) {
    std::cout << a.B << ' ';
    std::cout << a.U << ' ';
    std::cout << a.G << ' ';
    std::cout << a.BU << ' ';
    std::cout << a.UG << ' ';
    std::cout << a.BUG << ' ';
    std::cout << '\n';
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector fa(n + 1, std::vector<int>(20));
    std::vector d(n + 1, std::vector<NODE>(20));
    std::vector<int> dep(n + 1);
    std::vector e(n + 1, std::vector<int>());
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        e[x].push_back(i);
        fa[i][0] = x;
        dep[i] = dep[x] + 1;
    }
    std::string S;
    std::cin >> S;
    S = " " + S;
    for (int i = 1; i <= n; i++) {
        d[i][0] = NODE(S[i]);
        for (int j = 1; j < 20; j++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            d[i][j] = d[i][j - 1] + d[fa[i][j - 1]][j - 1];
        }
    }
    auto line = [&](int x, int y) -> NODE {
        NODE s, t;
        for (int i = 19; i >= 0; i--) {
            if (dep[fa[x][i]] >= dep[y]) {
                x = fa[x][i];
                s = s + d[x][i];
            }
        }
        for (int i = 19; i >= 0; i--) {
            if (dep[fa[y][i]] >= dep[x]) {
                y = fa[y][i];
                t = rev(d[y][i]) + t;
            }
        }
        if (x == y) {
            return s + t;
        }
        for (int i = 19; i >= 0; i--) {
            if (fa[x][i] != fa[y][i]) {
                x = fa[x][i];
                s = s + d[x][i];
                y = fa[y][i];
                t = rev(d[y][i]) + t;
            }
        }
        return s + NODE(S[x]) + t;
    };
    // auto lineStr = [&](int x, int y) -> std::string {
    //     std::string s, t;
    //     while (dep[x] > dep[y]) {
    //         s = s + S[x];
    //         x = fa[x];
    //     }
    //     while (dep[x] < dep[y]) {
    //         t = S[y] + t;
    //         y = fa[y];
    //     }
    //     if (x == y) {
    //         return s + t;
    //     }
    //     while (x != y) {
    //         s = s + S[x];
    //         x = fa[x];
    //         t = S[y] + t;
    //         y = fa[y];
    //     }
    //     return s + S[x] + t;
    // };
    for (int i = 1; i <= q; i++) {
        int x, y;
        std::cin >> x >> y;
        NODE t = line(x, y);
        // std::cout << lineStr(x, y) << '\n';
        // print(t);
        std::cout << (t.BUG ? "NO" : "YES") << '\n';
    }
}

int main() {
    int T = 1;
    // std::cin >> T;
    while (T--) {
        solve();
    }
}
// 64 位输出请用 printf("%lld")