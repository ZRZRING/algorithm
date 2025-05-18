[Problem - A - Codeforces](https://codeforces.com/contest/1853/problem/A)

[Submission #215194024 - Codeforces](https://codeforces.com/contest/1853/submission/215194024)

数列本身无序输出 $0$ 即可，有序输出最大极差的贡献

[Problem - B - Codeforces](https://codeforces.com/contest/1853/problem/B)

[Submission #215204810 - Codeforces](https://codeforces.com/contest/1853/submission/215204810)

暴力枚举前一项，计算出后 $k$ 项是否满足单调

斐波那契数列的增长是指数的，当末项为 $x$ 时，合法斐波那契数列的项数是 $\log x$ 级别的，于是可以 $\mathcal{O}(n\log n)$ 复杂度通过此题

[Problem - C - Codeforces](https://codeforces.com/contest/1853/problem/C)

[Submission #215362656 - Codeforces](https://codeforces.com/contest/1853/submission/215362656)

我们将问题模型转化，删除数字对应为在合适的位置插入 $0$，用 $0$ 替换 $a_i$ 位置的数，这样我们在 $k$ 轮以后，最小的没删除的元素对应即为 $1$ 所在的位置。

这样我们每次在 $1$ 前插入的数的数量是单调的，每轮插入计算一下该轮插入多少个 $0$ 即可，复杂度 $\mathcal O(k + n)$

[Problem - D - Codeforces](https://codeforces.com/contest/1853/problem/D)

[Submission #215369960 - Codeforces](https://codeforces.com/contest/1853/submission/215369960)

考虑 $b$ 数组的含义，把 $b$ 数组排序，显然对应的 $a$ 数组一定存在对应的单调的解的序列。

那么 $a$ 数组中所有数，应当都可以和一段后缀的数相加为正。

(图寄了不知道去哪了)

那么上述过程可以看作，存在一个分割，分割右侧的每个数，形成一个该位置的数的后缀长度，给该区间加 $1$，恰好使得分割左侧的所有位置的结果，等于该处的 $b$ 的值，则是有解的，例如上图，存在于第二个和第三个位置间的分割，该 $b$ 数组有解。

也就是说，靠左的需要靠右的提供后缀，靠右的提供等于它自身的后缀，那么我们可以模拟一个类似于双端队列的过程，每次观察是最后一个位置等于当前区间长度，还是第一个位置已经满足了所需的值，满足其中一个即可进行操作并删除，如果两者同时满足，则出现了冲突，即无解。

同理，此过程中，可以同时构造出答案序列，这里不多赘述

