[Educational Codeforces Round 170 (Rated for Div. 2)](https://codeforces.com/contest/2025)

# E [Card Game](https://codeforces.com/contest/2025/problem/E)

如果没有花色只有数字，我们可以用类似于李白喝酒的 DP 解决，$f_{i, j}$ 表示考虑前 $i$ 大的数字分配给 A 和 B，A 在去掉用于打出比 B 大的牌之后，还剩 $j$ 张牌没使用，枚举下一张牌分配给 A 和 B，可以容易得到
$$
f_{i, j} = f_{i - 1, j - 1} + f_{i - 1, j + 1}
$$
实际上后续过程中 $i$ 并没有用，我们只会用 $f_{n, j}$，那么后文重新定义 $f_i$ 表示一共 $m$ 张牌，A 在去掉用于打出比 B 大的牌之后，还剩 $j$ 张牌没使用。

我们再考虑花色，因为 1 号花色比较特殊，我们考虑类似于上述 DP，除了 1 号花色外，B 可以比 A 大上几张牌，这几张牌再让 A 用 1 号花色去压制，所以我们可以得到 $g_{i, j}$ 表示有 $i$ 种花色（不包括 1 号花色）B 比 A 大 $j$ 张牌的方案数，枚举之前的花色和该花色 B 比 A 分别大几张牌即可。
$$
g_{i, j} = \sum_{j_1 + j_2 = j} g_{i - 1, j_1} \times f_{j_2}
$$


当然 $g_{i, j}$ 我们也不需要 $i$，那重新定义 $g_{i}$ 表示 $n - 1$ 种花色（不包括 1 号花色）B 比 A 大 $i$ 张牌的方案数，而上述 $f_i$ 可以恰好理解为 1 号花色的状态（A 多出 $i$ 张 1 号花色牌用于打 B 其它的牌），统计最终答案将 $i$ 对应一下即可。

https://codeforces.com/contest/2025/submission/286004418