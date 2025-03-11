#include <bits/stdc++.h>

#define endl '\n'

int main() {
	int A, B;
	std::cin >> A >> B;
	if (A == 0) {
		if (B == 0) {
			std::cout << "biii" << endl;
			std::cout << "stop" << endl;
		} else {
			std::cout << "-" << endl;
			std::cout << "stop" << endl;
		}
	}
	if (A == 1) {
		if (B == 0) {
			std::cout << "dudu" << endl;
			std::cout << "move" << endl;
		} else {
			std::cout << "-" << endl;
			std::cout << "move" << endl;
		}
	}
	if (A == 2) {
		if (B == 0) {
			std::cout << "-" << endl;
			std::cout << "stop" << endl;
		} else {
			std::cout << "-" << endl;
			std::cout << "stop" << endl;
		}
	}
}
