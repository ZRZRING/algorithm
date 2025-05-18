#include <bits/stdc++.h>
using namespace std;
using i64 = std::int_least64_t;
void solve();
int main() {
  int t = 1;
  std::cin >> t;
  for (int i{}; i != t; ++i) {
    solve();
  }
}
#define int i64
constexpr int mod = 1e9 + 7;
bool chmin(auto &x, auto y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<std::pair<i64, int>>> g(n + 1);
  for (int i{}; i != m; ++i) {
    int u, v, w;
    std::cin >> u >> v >> w;
    g[u].push_back({w, v});
    g[v].push_back({w, u});
  }
  std::vector<int> p(k);
  for (auto &e : p) {
    std::cin >> e;
  }

  std::sort(p.begin(), p.end());

  using T = std::pair<i64, int>;
  std::priority_queue<T, std::vector<T>, std::greater<>> q;
  std::vector<i64> dist(n + 1, 1e18);
  q.push({0, p.front()});
  dist[p.front()] = 0;
  i64 ans{};
  while (!q.empty()) {
    auto [_, u] = q.top();
    q.pop();
    if (std::binary_search(p.begin(), p.end(), u)) {
      // std::cout << "??" << ' ';
      ans += dist[u];
      dist[u] = 0;
    }
    // std::cout << u << '\n';
    for (auto [w, v] : g[u]) {
      // std::cout << "EDGE: " << u << "->" << v << " w: " << w << '\n';
      // std::cout << "dist[u] + w = " << dist[u] + w << '\n';
      if (chmin(dist[v], dist[u] + w)) {
        // std::cout << "CHMIN\n";

        q.push({dist[v], v});
      }
    }
  }

  std::cout << ans << '\n';
}