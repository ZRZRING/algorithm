#include <bits/stdc++.h>

int lowbit(int x) {
    return x & -x;
}

int pc(int x) {
    return __builtin_popcount(x);
}

void solve() {
    int n, l, r;
    std::cin >> n >> l >> r;
    int L = n - r, R = n - l, t = pc(n), x;
    x = L;
    while (pc(x) > pc(n)) {
        x += lowbit(x);
    }
    for (int i = 0; pc(x) < pc(n); i++) {
        x |= 1 << i;
    }
    if (x < L || x > R) {
        std::cout << -1 << '\n';
    } else {
        std::cout << n - x << '\n';
    }
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}