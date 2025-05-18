[Problem - D - Codeforces](https://codeforces.com/contest/1793/problem/D)

[Submission #196130486 - Codeforces](https://codeforces.com/contest/1793/submission/196130486)

记 $MEX(a_l, a_{l + 1}, \cdots, a_r) = MEX(b_l, b_{l + 1}, \cdots, b_r) = M$，考虑枚举 $M$，计算符合条件的 $[l, r]$ 的数量，那么我们就必须使得两个排列都包含 $[1, M - 1]$ 的所有数，且不能包含 $M$，我们可以找到这样一个极小的区间满足上述条件，若 $M$ 在这个区间的外面，那么我们可以直接得出这个区间可以扩展到多大，这样 $l$ 和 $r$ 都可以在一个区间内任意取值，并使得两个区间均不包含 $M$，由于包含 $[1, M - 1]$ 的极小区间满足线性关系，于是这个过程可以用线性的复杂度处理
