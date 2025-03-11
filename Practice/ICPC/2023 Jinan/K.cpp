#include <bits/stdc++.h>

using int64 = long long;

#define NO 2
#define YES 1
#define endl '\n'
#define PII std::pair<int64, int64>
#define Fast_IOS std::ios::sync_with_stdio(false), std::cin.tie(0)
#define debug(x) std::cerr << "In Line " << __LINE__ << " the " << #x << " = " << x << '\n';

const int64 mod = 998244353;

template <class T> void MOD(T &x) {x = x % mod;}
template <class T> int64 lg(T x) {return (int)log10(x);}
template <class T> int64 log(T x) {return (int)log2(x);}
template <class T> int64 abs(T x) {return x < 0 ? -x : x;}
template <class T> int64 mysqrt(T x) {return std::floor(sqrtl(x));}

template<typename cmp>
struct DELHEAP {
	int64 sum = 0;

	std::priority_queue<int, std::vector<int>, cmp> q, d;

	int size() {
		return q.size() - d.size();
	}

	bool empty() {
		return size() == 0;
	}

	void push(int x) {
		q.push(x);
		sum += x;
	}

	void erase(int x) {
		d.push(x);
		sum -= x;
	}

	int top() {
		while (!q.empty() && !d.empty() && q.top() == d.top()) {
			q.pop();
			d.pop();
		}
		return q.top();
	}
	
	void pop() {
		erase(q.top());
	}
};

struct SET_MID {
	DELHEAP<std::less<int>> L;
	DELHEAP<std::greater<int>> R;

	void adjust() {
		while (L.size() > R.size()) {
			R.push(L.top());
			L.pop();
		}
		while (R.size() > L.size()) {
			L.push(R.top());
			R.pop();
		}
	}

	void insert(int x) {
		if (L.empty() || x <= L.top()) {
			L.push(x);
		} else {
			R.push(x);
		}
		adjust();
	}

	void erase(int x) {
		if (x <= L.top()) {
			L.erase(x);
		} else {
			R.erase(x);
		}
		adjust();
	}

	int64 sum() {
		// std::cout << L.sum << ' ' << R.sum << endl;
		int64 res = R.sum - L.sum;
		if (L.size() > R.size()) {
			res += L.top();
		}
		return res;
	}
};

int solve() {
	int64 n, k;
	std::cin >> n >> k;
	std::vector<int64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] -= i;
	}
	int ans = 0;
	SET_MID s;
	for (int i = 1, j = 1; i <= n; i++) {
		s.insert(a[i]);
		while (j < i && s.sum() > k) {
			s.erase(a[j]);
			j++;
		}
		ans = std::max(ans, i - j + 1);
	}
	std::cout << ans << endl;
	return 0;
}

int main() {
	Fast_IOS;
	int T = 1;
	std::cin >> T;
	while (T--) {
		int t = solve();
		if (t == 0) continue;
		if (t == YES) std::cout << "YES" << endl;
		if (t == NO) std::cout << "NO" << endl;
	}
	return 0;
}