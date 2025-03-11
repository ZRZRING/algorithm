[Problem - A - Codeforces](https://codeforces.com/contest/1849/problem/A)

[Submission #215885023 - Codeforces](https://codeforces.com/contest/1849/submission/215885023)

判断一下瓶颈在面包还是奶酪和火腿即可

[Problem - B - Codeforces](https://codeforces.com/contest/1849/problem/B)

[Submission #215895781 - Codeforces](https://codeforces.com/contest/1849/submission/215895781)

所有怪物首先会在出现一个怪物死之前，先被砍到剩余 $a_i \bmod k$ 的生命，对 $a_i \bmod k$ 排序即可

[Problem - C - Codeforces](https://codeforces.com/contest/1849/problem/C)

[Submission #215937836 - Codeforces](https://codeforces.com/contest/1849/submission/215937836)

考虑如果一段区间存在一段前缀 $0$ 或者后缀 $1$，则对该区间排序等价于不存在这些东西，且不存在等价于该区间的更短的区间，于是可以将其作为该区间的最小表示法，之后去重即可，需要注意空区间的处理。

[Problem - D - Codeforces](https://codeforces.com/contest/1849/problem/D)

[Submission #215963034 - Codeforces](https://codeforces.com/contest/1849/submission/215963034)

考虑 dp，记录 $f_{i, 0}$ 表示前 $i$ 个位置已经全部填充的最小代价，$f_{i, 1}$ 表示前 $i$ 个位置已经全部填充，且后一个位置将要被填充的最小代价，然后发现我们可以让一个位置被后面的位置所填充，于是设置一个状态 $f_{i, 2}$ 表示前 $i - 1$ 个位置已经全部填充，第 $i$ 个位置被后续填充的最小代价。具体转移详情见代码。