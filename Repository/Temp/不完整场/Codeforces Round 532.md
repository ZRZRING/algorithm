[Problem - E - Codeforces](https://codeforces.com/contest/1100/problem/E)

[Submission #93546676 - Codeforces](https://codeforces.com/contest/1100/submission/93546676)

写了两天了，这个题需要完全理解如何实现的和为什么这么实现，这样真的可以得到进步qwq

如果我们知道最终的答案为 $x$，对于大于 $x$ 的答案，我们就多了一些可反转的边的选择（但我们可以不选），必然也是可以得到我们想要的结果的，显然这个满足二分的条件单调性

我们求出答案 $x$ 以后，对于边权大于 $x$ 的边跑一个拓扑求出所有点 $u$ 的拓扑序 $\mathrm{dfn_u}$，然后对于边权小于等于 $x$ 的边，设这条边为 $(u,v)$，如果 $\mathrm{dfn}_v < \mathrm{dfn}_u$，则这条边就要反转