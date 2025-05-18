if __name__ == '__main__':
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    t = 1
    for x in a:
        t *= x
        if t >= 10 ** m:
            t = 1
    print(t)