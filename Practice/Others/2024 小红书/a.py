def solve():
    s = input().strip()
    n = len(s)
    flag = False
    for length in range(1, n):
        if n % length != 0:
            continue
        t = []
        p = ""
        for i in range(n):
            p += s[i]
            if i % length == length - 1:
                t.append(p)
                p = ""
        
        # Debug print
        # for p in t:
        #     print(p)
        
        S = set(t)
        if len(S) == 1:
            flag = True
            break
        if len(S) == 2:
            t = list(S)
            p1 = p2 = p3 = 0
            for i in range(length):
                if t[0][i] != t[1][i]:
                    if p1 == 0:
                        p1 = i
                    elif p2 == 0:
                        p2 = i
                    else:
                        p3 = 1
            if p3:
                continue
            t[0] = list(t[0])  # Convert string to list for mutation
            t[1] = list(t[1])
            t[0][p1], t[0][p2] = t[0][p2], t[0][p1]
            t[0] = "".join(t[0])
            if t[0][p1] == t[1][p1] and t[0][p2] == t[1][p2]:
                flag = True
        if len(S) == 3:
            t = list(S)
            p1 = p2 = p3 = 0
            for i in range(length):
                if t[0][i] != t[1][i] or t[0][i] != t[2][i]:
                    if p1 == 0:
                        p1 = i
                    elif p2 == 0:
                        p2 = i
                    else:
                        p3 = 1
            if p3:
                continue
            t = [list(x) for x in t]  # Convert strings to lists for mutation
            for i in range(3):
                for j in range(3):
                    t[i][p1], t[j][p2] = t[j][p2], t[i][p1]
                    if all(t[k][p1] == t[k][p2] for k in range(3)):
                        flag = True
                    t[i][p1], t[j][p2] = t[j][p2], t[i][p1]
        if len(S) > 3:
            continue
        if flag:
            break
    if flag:
        print("YES")
    else:
        print("NO")

T = int(input())
for _ in range(T):
    solve()

