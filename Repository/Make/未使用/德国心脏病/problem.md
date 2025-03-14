# 题目描述

该游戏规则为：每张牌上都有一个动物或者一定数量的水果，每个人依次翻开自己牌堆顶的牌，将其放到自己面前的场上，如果自己面前的场上有牌，将其覆盖。

之后所有人都可以拍铃，如果一个人拍了铃，此时，如果场上的牌满足拍铃条件时，这个人可以将场上的牌收到自己手里，反之，其他人将自己出的牌收回，该人将自己场上的牌弃掉。

任意时刻，场上某种水果存在正好 $5$ 个，或出现动物牌并满足条件时，即满足拍铃条件，其中动物牌的条件如下。

猴子牌：没有柠檬的情况下满足拍铃条件。

大象牌：没有草莓的情况下满足拍铃条件。

猪牌：任意情况都满足拍铃条件。

现在用字母M表示猴子，E表示大象，P表示猪，L表示柠檬，S表示草莓，A表示苹果，B表示香蕉，现在有 $n$ 个人进行游戏，你已经预知了接下来 $k$ 张要翻开的牌，并且从 $1$ 号开始翻牌，你需要求出翻开这 $k$ 张牌期间，最早是谁可以满足拍铃条件，如果 $k$ 张牌翻完没有人满足拍铃条件，输出 $-1$。

# 输入格式

第一行一个整数 $T$ 表示数据组数。

接下来 $T$ 组数据，每组数据中：

第一行两个整数 $n$，$k$。

接下来 $k$ 行每行一个字母，若该字母表示水果，后面跟着一个整数 $x$，表示水果的数量。

# 输出格式

共 $T$ 行，每行一个整数表示最早满足拍铃条件的人的编号。

# 样例输入 #1

```
3
3 4
A 6
A 5
P
A 5
3 4
A 6
S 5
B 4
A 4
3 1
M
```

# 样例输出 #1

```
3
2
1
```

# 提示说明

|任务|得分|限制|
|:---|:---|:---|
|Subtask $1$|10|$x = 1, n, k\leq 100$|
|Subtask $2$|30|$n, k\leq 100$|
|Subtask $3$|20|$k\leq n$|
|Subtask $4$|15|没有动物牌|
|Subtask $5$|2|没有水果牌|
|Subtask $6$|3|$x = 5$|
|Subtask $7$|20|无特殊限制|

对于 $100\%$ 的数据，$1\leq T\leq 100$，$1\leq x\leq 6$，$1\leq n, k\leq 10^5$。