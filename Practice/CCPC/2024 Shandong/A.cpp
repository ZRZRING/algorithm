#include <bits/stdc++.h>

struct DATA {
    std::string s;
    int x, y;
};

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector a(n, std::string());
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<DATA> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k * m; j += k) {
            d.push_back((DATA){"", i + 1, j / k + 1});
            for (int p = j; p < j + k; p++) {
                d.back().s.push_back(a[i][p]);
            }
        }
    }
    std::sort(d.begin(), d.end(), [&](DATA a, DATA b) {
        return a.s < b.s;
    });
    // for (auto [s, x, y] : d) {
    //     std::cout << s << ' ' << x << ' ' << y << '\n';
    // }
    if (d[0].s == d[1].s) {
        std::cout << d.back().x << ' ' << d.back().y << '\n'; 
    } else {
        std::cout << d[0].x << ' ' << d[0].y << '\n';
    }
}