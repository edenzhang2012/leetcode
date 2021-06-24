/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0。不得使用库函数，同时不需要考虑大数问题，也不用考虑小数点
后面0的位数。
*/

/*
分析：
功能不难，主要是边界条件
1. base为0时，exponent不为0，结果为0.0
2. base为0，exponent为0，数学上无意义，可以直接返0
3. exponent为0，base不为0，结果为1.0
4. 当exponent为负数时，取绝对值，按照正数算，之后取倒数
再考虑效率：
当exponent为偶数时，a^n = a^(n/2)*a^(n/2)
当exponent为奇数时，a^n = a*(a^(n-1)/2)*(a^(n-1)/2)
上式已经有点儿斐波那契数列的影子了，可以使用递归处理

注意：
1. 浮点数由于精度原因不能直接比较，若两个浮点数差值在某个范围内，则认为两个浮点数相等
*/

#include <iostream>
#include <iomanip>
#include <stdio.h>

//浮点数比较，精度0.0000001
bool float_equal(double a, double b){
    if(a-b < 0.0000001 && a-b > -0.0000001)
        return true;
    else
        return false;
}

double float_power_unsigned(double base, unsigned int exponent){
    if(exponent == 1)
        return base;
    
    double ret = float_power_unsigned(base, exponent >> 1);
    ret *= ret;
    if(exponent & 0x01)
        ret *= base;

    return ret;
}

double float_power(double base, int exponent){
    double ret = 0.0;
    if(float_equal(base, 0.0))
        return 0.0;
    
    if(exponent == 0)
        return 1.0;
    
    if(exponent < 0){
        ret = float_power_unsigned(base, -exponent);
        ret = 1.0 / ret;
    }else{
        ret = float_power_unsigned(base, exponent);
    }

    return ret;
}

int main(){
    double ret = 0.0;
    ret = float_power(23.4, 4);
    // std::cout << "ret = " << std::setprecision(4) << ret << std::endl;
    printf("ret = %lf\n", ret);

    ret = float_power(0.0, 4);
    // std::cout << "ret = " << std::setprecision(4) << ret << std::endl;
    printf("ret = %lf\n", ret);

    ret = float_power(0.0, 0);
    // std::cout << "ret = " << std::setprecision(4) << ret << std::endl;
    printf("ret = %lf\n", ret);

    ret = float_power(23.5, 0);
    // std::cout << "ret = " << std::setprecision(4) << ret << std::endl;
    printf("ret = %lf\n", ret);
    return 0;
}