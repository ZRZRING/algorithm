#include <bits/stdc++.h>

void solve() {
    std::string s, t;
    std::cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            std::reverse(t.begin(), t.end());
            continue;
        }
        if (s[i] == 'Z') {
            if (i == 0) continue;
            if (s[i - 1] == 'R') {
                std::reverse(t.begin(), t.end());
                continue;
            }
            t.pop_back();
            continue;
        }
        t.push_back(s[i]);
    }
    std::cout << t << '\n';
}

int main() {
    int T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
}