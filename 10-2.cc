/*
输入两个整数m和n,计算需要改变m中的二进制的多少位可以得到n
*/

/*
分析：
1. 按照题意，将二进制数m改变为n，即需要统计数m与数n不同的位数有多少
2. 解决方案：先将m与n异或，结果中1的个数即为不同位数的个数
*/