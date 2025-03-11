#include <bits/stdc++.h>

void solve() {
    std::string s, t;
    std::cin >> s;
    int p = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            if (!t.empty()) {
                p = (p * 10 + s[i] - '0') % t.length();
            } else {
                p = (p * 10 + s[i] - '0');
            }
        } else {
            if (!t.empty()) {
                t = t.substr(p, t.length() - p) + t.substr(0, p - 1);
                p = 0;
            }
            if (s[i] == 'R') {
                std::reverse(t.begin(), t.end());
            } else {
                t.push_back(s[i]);
            }
        }
    }
    std::cout << t << '\n';
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
// 64 位输出请用 printf("%lld")