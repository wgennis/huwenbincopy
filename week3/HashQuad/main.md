# 开放地址散列表声明
平方探测在开放地址散列表中的应用排除了一次元素的聚集使得查找和插入的实现变简单了；双散列则是用了第二个散列函数hash2（X），对此函数的应用要谨慎一些。总而言之，这种散列表实现的精髓在于对元素冲突的解决。
