#include <bits/stdc++.h>

using int64 = long long;

#define A3 std::array<int64, 3>

int64 gcd(int64 x, int64 y) {
	return y ? gcd(y, x % y) : x;
}

int64 lcm(int64 x, int64 y) {
	int64 d = gcd(x, y);
	return x / d * y;
}

struct FRAC {
	int64 x, y;

	FRAC() {}

	FRAC(int64 x, int64 y) : x(x), y(y) {}

	friend FRAC operator + (FRAC a, FRAC b) {
		int64 x, y = lcm(a.y, b.y);
		a.x *= y / a.y;
		b.x *= y / b.y;
		x = a.x + b.x;
		int64 d = gcd(x, y);
		x /= d;
		y /= d;
		return FRAC(x, y);
	}

	
	friend FRAC operator * (FRAC a, FRAC b) {
		int64 x = a.x * b.x, y = a.y * b.y, d = gcd(x, y);
		x /= d;
		y /= d;
		return FRAC(x, y);
	}
	
	friend bool operator < (FRAC a, FRAC b) {
		return a.x * b.y < b.x * a.y;
	}

	void print() {
		std::cout << x << ' ' << y << '\n';
	}
};

void solve() {
	int64 n;
	std::cin >> n;
	if (n <= 3) {
		FRAC ans = FRAC(n * (n + 1), 2) * FRAC(1, n);
		ans.print();
		return;
	}
	int64 x = sqrt(2 * n);
	// std::cout << x << '\n';
	auto cal = [&](int64 x) -> FRAC {
		return FRAC(x + 1, 2) + FRAC(n, x);
	};
	int64 t = x;
	if (cal(x + 1) < cal(x)) {
		x++;
	}
	FRAC ans = cal(x) + FRAC(-1, 1);
	ans.print();
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}