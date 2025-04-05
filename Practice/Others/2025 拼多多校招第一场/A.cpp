#include <bits/stdc++.h>

void solve() {
    int x, y;
    std::cin >> x >> y;
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::map<char, int> gox = {
        {'W', 0},
        {'S', 0},
        {'A', -1},
        {'D', 1}
    };
    std::map<char, int> goy = {
        {'W', 1},
        {'S', -1},
        {'A', 0},
        {'D', 0}
    };
    for (int i = 0; i < n; i++) {
        x += gox[s[i]];
        y += goy[s[i]];
    }
    if (x == 0 && y == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    int T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
}