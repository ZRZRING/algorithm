[Problem - C - Codeforces](https://codeforces.com/contest/454/problem/C)

[Submission #93546359 - Codeforces](https://codeforces.com/contest/453/submission/93546359)

可以得知，最大值在 $[1,x]$ 的情况有 $x^n$ 种，所以对于点数 $i$，一共有 $i^n-(i-1)^n$ 种情况最大值为$i$，每种情况贡献为 $i$，所有情况的数量为 $m^n$，于是答案为

$$
ans =\sum_{i=1}^m\frac{i^n-(i-1)^n}{m^n}\times i
$$
[Problem - D - Codeforces](https://codeforces.com/contest/454/problem/D)

[Submission #93546345 - Codeforces](https://codeforces.com/contest/453/submission/93546345)

从数据范围看出这是一道状压 dp，考虑对于一个序列所有数都互质，当且仅当所有数的质因子互不相同，于是我们枚举每一个 $b_i$ 的值， $p_i$ 表示 $i$ 的质因数集合，$f_{i, j}$ 表示前 $i$ 个数用 $j$ 集合的质因子得到的最小的 $\sum|a_i-b_i|$，容易得到转移方程

$$
f_{i, j}=\min_{p_k\subset j}\{f_{i-1, j-p_k} + |a_i-b_i|\}
$$

[Problem - E - Codeforces](https://codeforces.com/contest/454/problem/E)

[Submission #89841695 - Codeforces](https://codeforces.com/contest/453/submission/89841695)

我们可以对于给定序列在图上 dfs，经历一次就异或 $1$，目标让序列变为全是 $0$

路径序列长度不超过 $4n$ 也就是经历的边数不超过 $4n-1$

考虑对于每个点都要经历最少的次数来保证长度，很容易想到树形结构，对于每个节点，先异或 $1$，然后进入所有儿子，而这个点有多少儿子就异或几次(从每个儿子回来再进入新的儿子，最后一个儿子回来再回到这个点的父亲)

但如果这个点异或到最后成了 $1$ 的话，我们可以把让它回到父亲节点再下来再回去，这样父亲节点和这个节点就再异或 $1$

最后根节点如果异或成 $1$ 的话，我们就对答案序列减 $3$，也就是我们不让根节点的最后一个儿子回到根节点了，因为根节点没有父节点，这样就少了一次异或 $1$

可以得证，每条边最多经历 $4$ 次，根节点到最后一个儿子的连边最多 $2$ 次