#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<int> sc(255), cnt(255);
    for (int i = 'a'; i <= 'z'; i++) {
        std::cin >> sc[i];
    }
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    long long sum = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        std::cout << cnt[i] << " \n"[i == 'z'];
        sum += 1ll * cnt[i] * sc[i];
    }
    std::cout << sum << '\n';
    return 0;
}
