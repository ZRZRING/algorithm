[Problem - B - Codeforces](https://codeforces.com/contest/1200/problem/B)

[Submission #180470934 - Codeforces](https://codeforces.com/contest/1200/submission/180470934)

一个贪心的思想是保证我们在任意时刻我们的背包装的砖的数量尽可能多。

于是我们每次保证从 $i$ 跳到下一个位置 $i+1$ 之前先把 $i$ 位置的砖的数量修改为 $\max\{a[i + 1] - k, 0\}$。