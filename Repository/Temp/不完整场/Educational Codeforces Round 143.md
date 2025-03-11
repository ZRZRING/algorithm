[Problem - C - Codeforces](https://codeforces.com/contest/1795/problem/C)

[Submission #194240438 - Codeforces](https://codeforces.com/contest/1795/submission/194240438)

~~比赛的时候代码截图给同学然后寄了~~

考虑一个桌子上的茶一定会被某一个区间的人完整的喝光，相当于我们有一个区间加的操作，最后将剩下不满足 $b_i$ 的一个人单独计算贡献

于是我们可以记录前缀和优化查询，然后每次二分查找能喝光的最后一个人，区间加也可以用差分优化，复杂度 $\mathcal{O}(n\log n)$