#include <bits/stdc++.h>

std::vector<long long> ans;

int T = 1;

void init() {
    // std::cin >> T;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::reverse(a.begin(), a.end());
    std::stack<int> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans += i;
        } else {
            ans += i - s.top();
        }
        s.push(i);
    }
    std::cout << ans << '\n';
}

int main() {
    init();
    while (T--) {
        solve();
    }
}