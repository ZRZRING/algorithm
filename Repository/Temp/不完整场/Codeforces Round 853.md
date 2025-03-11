[Problem - D - Codeforces](https://codeforces.com/contest/1789/problem/D)

[Submission #196099535 - Codeforces](https://codeforces.com/contest/1789/submission/196099535)

显然 a 和 b 中仅有一个是 0 就无法达成

我们可以通过 a 的 1 来完成这个任务，由于不能超过 n 次操作，考虑每次操作都能固定一个位置，我们要保证每次操作不会影响我们已经确定好的数

首先尝试对齐 a 和 b 的最左端的 1，然后用这个 1 去更新它的右侧

然后考虑这个 1 的左端，我们可以用当前 a 中最小的 1 去更新，这样它的右侧全是 0，就不会影响我们已经调整好的部分
