# 多项式相乘
关键时如何进行散列，即将幂数%表的大小按照余数来进行散列。这样做的好处就是合并同幂项很方便，不用进行排序而导致空间的浪费。注意这种方法比较适合稀疏多项式的乘法，因为散列对空间的要求比较严苛，如果多项式比较紧凑最好用双倍于最大幂数的散列来进行装填。
