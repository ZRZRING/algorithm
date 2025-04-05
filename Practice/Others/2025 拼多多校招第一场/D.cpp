#include <bits/stdc++.h>

std::vector<long long> ans;

int T = 1;

void init() {
    std::cin >> T;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> a(m);
    for (auto &x : a) {
        std::cin >> x;
        x--;
    }
    std::sort(a.begin(), a.end());
    std::sort(t.begin(), t.end());
    for (int i = 0, j = 0; i < m; i++) {
        if (i != 0 && a[i] == a[i - 1]) {
            continue;
        }
        s[a[i]] = t[j];
        j++;
    }
    std::cout << s << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
}