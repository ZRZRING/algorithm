记 $x$ 子树内最长链中 $x$ 在原树上的儿子为 $x$ 的重儿子

对于每个询问 $x,y$ 有两种情况，设 $x$ 的深度小于 $y$：

- $lca(x,y)\not = x$，答案就是 $x$ 和 $y$ 之间的距离，加上 $x$ 子树内的最长链和 $y$ 子树内的最长链的长度

- $lca(x,y) = x$，我们判断一下 $y$ 是否在 $x$ 子树内的最长链上，如果是的话需要在 $x$ 除去重儿子的子树内的最长链，否则找到 $x$ 子树外的最长链即可