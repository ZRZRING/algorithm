import math

def solve():
    n, k = map(int, input().split())
    if k == 1:
        return n
    if k <= 5:
        l, r = 1, 1000000000
        while l < r:
            mid = l + r >> 1
            if mid ** k > n:
                r = mid
            else:
                l = mid + 1
        x = r
        if (abs(n - x ** k) > abs(n - (x - 1) ** k)):
            return x - 1
        else:
            return x
    else:
        for x in range(1, 1000):
            if x ** k > n:
                if (abs(n - x ** k) > abs(n - (x - 1) ** k)):
                    return x - 1
                else:
                    return x
                

T = int(input())
while T:
	T -= 1
	print(solve())