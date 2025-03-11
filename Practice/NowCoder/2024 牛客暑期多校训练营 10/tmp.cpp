// std::cout << cnt << ' ' << flag << '\n';
if (flag) {
	int64 ta = a, tb = b, A = 0, B = 0, r2 = qpow(2), t = 1;
	do {
		MOD(t *= r2);
		if (ta < tb) {
			MOD(B += t);
			tb -= ta;
			ta += ta;
		} else {
			MOD(A += t);
			ta -= tb;
			tb += tb;
		}
		// std::cout << ta << ' ' << tb << '\n';
	} while (ta != tb);
	MOD(t *= r2);
	MOD(A += t);
	MOD(B += t);
	std::cout << A << ' ' << B << '\n';
} else {
	int64 ta = a, tb = b, A = 0, B = 0, rn = qpow(qpow(2, cnt) - 1), r2 = qpow(2), t = qpow(2, cnt);
	do {
		MOD(t *= r2);
		if (ta < tb) {
			MOD(B += t * rn % mod);
			tb -= ta;
			ta += ta;
		} else {
			MOD(A += t * rn % mod);
			ta -= tb;
			tb += tb;
		}
		// std::cout << ta << ' ' << tb << '\n';
	} while (ta != a || tb != b);
	std::cout << A << ' ' << B << '\n';
	// std::cout << (A + B) % mod << '\n';
}