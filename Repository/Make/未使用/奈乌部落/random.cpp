#include <bits/stdc++.h>
#define sz(a) ((int) (a).size())
#define lg(a) ((int) log10(a))
#define log(a) ((int) log2(a))
#define ULL unsigned long long
#define LL long long
#define mem(a) memset(a, 0, sizeof(a))
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pll pair<LL, LL>
#define hash map<int, int>

#define debug(x...) \
    do { \
        std::cout << "[" << #x << "] -> "; \
        err(x); \
    } while (0)
 
void err() {
    std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
    std::cout << arg << ' ';
    err(args...);
}

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
	cin >> T;
	while (T--) {
		int n, ans = (int) 2e9;
		cin >> n;
		int h[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> h[i];
		}
		for (int j = 1; j <= 1000; j++) {
			random_shuffle(h + 1, h + 1 + n);
			std::vector<int> now(n + 1);
			for (int i = 1; i <= n; i++) {
				now[i] = h[i];
			}
			int l = 1, r = n;
			while (r - l + 1 >= 2) {
				int x = now[l];
				int y = now[r];
				now[l] -= y;
				now[r] -= x;
				if (now[l] <= 0) {
					l++;
				}
				if (now[r] <= 0) {
					r--;
				}
			}
			ans = std::min(ans, *std::max_element(now.begin() + 1, now.end()));
		}
		cout << ans << "\n";
	}
    return 0;
}