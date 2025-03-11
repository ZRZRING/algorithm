#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

using int64 = long long;
using ll = long long;

int main() {
    int t;
    IOS;
    std::cin >> t;
    while (t--) {
        std::vector<int> a(33);
        for (int i = 1; i <= 32; i++) {
            std::cin >> a[i];
		}
        int num = a[1];
        sort(a.begin(), a.end());
        int pos = 0;
        for (int i = 1; i <= 32; i++) {
            if (a[i] == num) {
                pos = i;
			}
        }
        if (pos >= 32) {
            std::cout << "1\n";
        } else if (pos >= 28) {
            std::cout << "2\n";
        } else if (pos >= 14) {
            std::cout << "4\n";
        } else if (pos >= 7) {
            std::cout << "8\n";
        } else if (pos >= 3) {
            std::cout << "16\n";
        } else {
            std::cout << "32\n";
        }
    }
    return 0;
}