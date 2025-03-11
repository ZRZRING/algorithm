[Problem - A - Codeforces](https://codeforces.com/contest/1935/problem/A)

[Submission #249752444 - Codeforces](https://codeforces.com/contest/1935/submission/249752444)

只有头尾有用，根据操作次数的奇偶分类讨论即可。

[Problem - B - Codeforces](https://codeforces.com/contest/1935/problem/B)

[Submission #249767199 - Codeforces](https://codeforces.com/contest/1935/submission/249767199)

分成两段一定最优，若分成两段无法达成，分成更多段肯定达成不了，枚举断点即可，相邻断点转移是 $\mathcal O(1)$ 的。

[Problem - C - Codeforces](https://codeforces.com/contest/1935/problem/C)

[Submission #249785957 - Codeforces](https://codeforces.com/contest/1935/submission/249785957)

- 优先队列

考虑我们选择的数为集合 $S$，我们 $a_i$ 的和固定，为了最小化 $b_i$ 的贡献，肯定是从小到大排序，这样的贡献是 $\max(b_i) - \min(b_i)$，于是对于集合 $S$ 的最优解固定，我们寻找最优的集合 $S$，我们可以按 $b_i$ 排序，这样我们可以对于每个区间 $(l, r)$ 求得一个集合 $S$ 后，我们要求 $(l, r + 1)$ 的最优集合，当我们的贡献超出，我们可以通过多次扔掉集合 $S$ 中 $a_i$ 最大的数来达到条件，我们并不需要考虑这时候边界是否被扔，因为这一定不是我们的最优解，或者这种 $S$ 会在没有扔掉边界的时候再次被计算。

[Problem - D - Codeforces](https://codeforces.com/contest/1935/problem/D)

[Submission #249804575 - Codeforces](https://codeforces.com/contest/1935/submission/249804575)

- 容斥

经典容斥，全部情况减去 $x + y = a_i$ 和 $y - x = a_i$ 的情况，再加上同时满足 $x + y = a_i$ 和 $y - x = a_j$ 的情况，同时满足仅有一种可能，可以通过解方程得到，并且只有当 $a_i$ 和 $a_j$ 奇偶性相同时才有可能存在。

[Problem - E - Codeforces](https://codeforces.com/contest/1935/problem/E)

[Submission #250068572 - Codeforces](https://codeforces.com/contest/1935/submission/250068572)

- 二进制

我们从高位到低位考虑构造答案，如果这一位可以是 $1$ 则我们一定让他成为 $1$。

对于每个二进制数，我们记其左右边界的公共前缀部分为 $w_i$，这一部分是无法改变的，我们把左右边界减去这个数后，最高位一定是 $0$ 和 $1$，这时候我们一定可以给这一位赋值为 $1$，或者把后续所有位置都赋值为 $1$，当我们把这一位赋值为 $1$ 时，后续位置每次碰到右边界为 $1$ 时，都可以做上述选择，这是因为左边界一定严格小于右边界，而上述两个操作代表的数值差为 $1$ 所以一定能达成。于是对于每个询问，我们需要对于每一位判断是否存在可以使用的 $1$，当存在可以使用的右边界的 $1$ 且有其他的可用 $1$ 时，可以将后续全部覆盖为 $1$，这一过程可以用前缀和对每一位单独维护。

[Problem - F - Codeforces](https://codeforces.com/contest/1935/problem/F)

[Submission #250343934 - Codeforces](https://codeforces.com/contest/1935/submission/250343934)

- 欧拉序

删除一个点后，树会分成若干集合，我们把这些集合链接需要的边数是确定的，考虑这些集合的性质，当我们删除的数介于某个集合的上下界之间时，我们一定至少有一种方案使得所有要链接的边的权值为 $1$，反之，方案中一定存在一条权值为 $2$ 的边和若干权值为 $1$ 的边。

我们可以通过类似最小生成树的做法，用一个换根 dp 处理出来每个点分裂的所有集合的上下界 $min, max$，将其与其差为 $1$ 的点所在的集合相连，根据上述性质，我们最后一定会剩下 $(x - 1, x + 1)$ 这条边没有连接。