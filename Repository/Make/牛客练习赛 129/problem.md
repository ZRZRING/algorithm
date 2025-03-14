# A 三位出题人

三位出题人走在路上，他们要给 $m$ 个人分配 $n$ 个题的工作。

第一位出题人认为不应该让所有人同时去参与同一个题的工作。

第二位出题人认为每个题都应该有至少一个人参与。

第三位出题人想知道他们有多少种分配任务的方案。

# B 数数

牛牛穿越到了异世界。
​
在异世界中，牛牛发现这里的人们对奇数和偶数有着独特的定义，在这里，奇数被定义为只有一个质因数的数（相同的质因数不被重复计算），偶数定义为质因数个数大于 $1$ 的数，$1$ 既不是奇数也不是偶数 。牛牛想要知道 $1 ~ n$ 中偶数的个数，聪明的你能帮牛牛解决这个问题吗？

例如：$2 = 2^1$ 是奇数，$8 = 2^3$ 是奇数，$45 = 3^2 \times 5$ 是偶数。

# C 收纳箱

给定 $n$ 个物品，$m$ 个收纳箱，每个收纳箱容量均为 $k$，每个物品体积为 $a_i$。初始指定第一个收纳箱，并选择一个起始位置 $i$，从 $i$ 开始按顺序遍历所有物品，如果当前枚举的物品可以装入目前指定的收纳箱则将其装入，反之则指定下一个收纳箱，直到物品被选完，或者指定下一个收纳箱时不存在下一个收纳箱。问能最多装入多少物品。

# D 和平天使

部落里的怪物生性好斗，具体而言他们生活在一条数轴上，每个点上都有怪物生活，并给出若干关系 $(l_i, r_i)$ 表示位于 $l_i$ 与位于 $r_i$ 之间有矛盾，和平天使决定介入使得所有怪物之间不发生冲突，当和平天使介入数轴的 $j$ 点时，所有满足 $l_i\leq j\leq r_i$ 的矛盾将不会发生冲突，现在你想知道和平天使至少介入多少个点可以避免所有冲突的发生。

# E 网络通路

你是 X 国的总工程师，X 国的 $n$ 个城市之间要架设网络通路，使得每两个国家之间可以通过网络相互到达。为了方便，你希望 X 国架设的网络通路数量最多为 $n - 1$。然而 X 国的网络通路技术并不成熟，传输速度可以被感知出来，对于每条网络通路，其传输数据所需时间为 $d_i$，每两条网络通路之间的衔接时间忽略不计。为了使得城市居民使用网络效率最高，你希望对于每两个城市传输时间的和最小，现在你的任务就是求得这个最小值是多少。

# F 攻防对称

Alice 和 Bob 正在玩一个最近兴起的游戏，名为攻防对称，一人进攻一人防守，进攻方可以进攻 $m$ 次，$m$ 次后如果防守成功则防守方获胜，否则进攻方获胜。

Alice 防守，Bob 进攻。
​
具体规则如下，给定一个长度为 $n$ 的字符串，进攻方 Bob 每次可以进行如下两种操作的一种。

`1 l r` 向 Alice 询问一段字符串的子串 $s_{l, r}$ 是否是对称的，即要求 $s_{l + i} = s_{r - i} (0 \leq i \leq r - l)$。

`2 l r x` 将给定字符串的子串 $s_{l, r}$ 一段的每个字符同时变成它在字典序中后面的第 $x (0 \le x \le 10^9)$ 个字符，并且规定 `z` 在字典序中后面的第一个字符为 `a`。

Alice 很想赢得这个游戏，但是他对于字符串一窍不通，希望得到你的帮助，在每次询问时做出正确的答案。