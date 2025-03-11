#include <bits/stdc++.h>

using int64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m + 1);
    int mi = 1e9;
    for (int i = 1; i <= m; i++)
        std::cin >> a[i], mi = std::min(mi, a[i]);
    std::map<std::string, std::vector<int>> mp;
    std::vector<int> r(n + 1);
    std::vector<std::string> s(n + 1);
    std::set<int> st;
    for (int i = 1; i <= n; i++) {
        // int r;
        std::cin >> r[i] >> s[i];
        st.insert(r[i]);
    }
    std::vector<int> c(st.begin(), st.end());
    for (int i = 1; i <= n; i++) {
        r[i] = std::lower_bound(c.begin(), c.end(), r[i]) - c.begin();
        mp[s[i]].push_back(r[i]);
    }
    std::vector<int> diss(c.size() + 10);
    for (auto& [u, v] : mp) {
        sort(v.begin(), v.end(), std::greater<int>());
        for (int i = 0; i < std::min(mi, (int)v.size()); i++) {
            diss[0]++;
            diss[v[i]]--;
        }
        sort(v.begin(), v.end());
    }
    for (int i = 1; i <= c.size(); i++)
        diss[i] += diss[i - 1];
    for (int i = 0; i <= c.size(); i++) {
        std::cout << diss[i] << " \n"[i == c.size()];
    }
    for (int i = 1; i <= n; i++) {
        int pos = std::upper_bound(mp[s[i]].begin(), mp[s[i]].end(), r[i]) - mp[s[i]].begin();
        int siz = mp[s[i]].size() - pos;
		std::cout << pos << ' ' << siz << '\n';
        std::cout << diss[r[i]] - std::min(mi, siz) + std::min(siz + 1, mi) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t = 1;
    while (t--)
        solve();
}