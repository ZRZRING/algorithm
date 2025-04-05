s = input()
t = input()
dic = {}
for x in s:
    dic[x] = 1
ans = ['r'] * len(s)
for i in range(len(s)):
    if t[i] == s[i]:
        ans[i] = 'g'
    elif dic.get(t[i], 0):
        ans[i] = 'y'
ans = "".join(ans)
print(ans)
if ans == "g" * len(s):
    print("congratulations")
else:
    print("defeat")