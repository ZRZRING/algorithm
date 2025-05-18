#include <bits/stdc++.h>

using int64 = long long;

std::random_device RD;
std::mt19937_64 gen(RD());
int64 roll(int64 l, int64 r) {
	std::uniform_int_distribution<int64> dist(l, r);
	return dist(gen);
}

class Calculate {
private:
	int n;
public:
	Calculate() {

	}

	void lab1() {
		double p = 0.9, ans = 0;
		int n = 1000000;
		for (int i = 1; i <= n; i++) {
			int level = 0, star = 0, round = 0, successive = 0;
			auto levelup = [&]() -> void {
				level++;
				star -= 3;
			};
			auto leveldown = [&]() -> void {
				if (!level) {
					star = 0;
					return;
				}
				level--;
				star += 3;
			};
			while (level <= 5) {
				round++;
				if (roll(1, 100) <= p * 100) {
					star++;
					successive++;
					if (star > 3) levelup();
					// if (successive >= 3) {
					// 	star++;
					// 	if (star > 3) levelup();
					// }
				} else {
					star--;
					successive = 0;
					if (star < 0) leveldown();
				}
			}
			// std::cout << round << '\n';
			ans += round;
		}
		std::cout << std::fixed << std::setprecision(10);
		std::cout << ans / n << '\n';
	}
};

int main() {
	srand(time(0));
	Calculate calculate;
	calculate.lab1();
	return 0;
}