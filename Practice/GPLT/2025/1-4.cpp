#include <bits/stdc++.h>

int main() {
	int a;
	std::cin >> a;
	int b = 1;
	while (b <= a) {
		b *= 2;
	}
	std::cout << b / 2 << '\n';
}
