#include <bits/stdc++.h>

int main() {
	int T, S, t;
	
	std::cin >> T >> S >> t;
	
	if (S == 1 && t >= 33 && T > 35) {
		std::cout << "Bu Tie\n";
		std::cout << T << '\n';
		return 0; 	
	}
	
	if (S == 0 && t >= 33 && T > 35) {
		std::cout << "Shi Nei\n";
		std::cout << T << '\n';
		return 0;
	}

    if (S == 1 && (t < 33 || T <= 35)) {
		std::cout << "Bu Re\n";
		std::cout << t << '\n';
		return 0;
    }
	
	std::cout << "Shu Shi\n";
	std::cout << t << '\n';
}
