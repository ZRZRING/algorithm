[Problem - A - Codeforces](https://codeforces.com/contest/1886/problem/A)

[Submission #227347581 - Codeforces](https://codeforces.com/contest/1886/submission/227347581)

小于等于 $6$ 或等于 $9$ 无法分解，其它分类讨论即可。

[Problem - B - Codeforces](https://codeforces.com/contest/1886/problem/B)

[Submission #227359283 - Codeforces](https://codeforces.com/contest/1886/submission/227359283)

一个圆全包，两个圆相交并让每个圆连接一个点，两种情况分开讨论即可。

[Problem - C - Codeforces](https://codeforces.com/contest/1886/problem/C)

[Submission #227392224 - Codeforces](https://codeforces.com/contest/1886/submission/227392224)

每次找出第一个满足 $s_i > s_{i + 1}$ 的字符删掉，可以用单调栈实现，博主写的代码里使用的是打删除标记，并记录每个位置的上一个没有打删除标记的位置，即前驱，维护前驱即可。

[Problem - D - Codeforces](https://codeforces.com/contest/1886/problem/D)

[Submission #227429638 - Codeforces](https://codeforces.com/contest/1886/submission/227429638)

考虑第 $i$ 个数的插入方式，如果为 `<` 或 `>` 即新增一个隔板区间，因为隔板的生成位置确定，所以其不会产生贡献，出现一个 `?` 即往任意隔板区间内插入一个数，而每个 `?` 数都有 $i - 1$ 种位置可供插入，于是每个位置当其为 `?` 会使答案 $\times (i - 1)$，反之无贡献。