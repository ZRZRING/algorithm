#include <bits/stdc++.h>

using int64 = long long;
using A2 = std::array<int64, 2>;

#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

const int64 mod = 998244353;

class WORK {
public:
	int N;

	WORK() {}

	void solve() {
		int n,m;
		std::cin>>n>>m;
		std::vector<int> a(n+1),b(m+1);
		for(int i=1;i<=n;i++)
			std::cin>>a[i];
		for(int i=1;i<=m;i++)
			std::cin>>b[i];
		int64 ans = 0;
		for(int i=2;i<=n;i++)
			ans +=abs(a[i]-a[i-1]);
		for(int i=2;i<=m;i++)
			ans +=abs(b[i]-b[i-1]);
		std::cout<<ans<<"\n";
	}
};

int main() {
	Fast_IOS;
	WORK work;
	int T = 1;
	// std::cin >> T;
	while (T--) {
		work.solve();
	}
	return 0;
}