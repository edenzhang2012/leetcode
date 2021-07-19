/*
输入数字n，按顺序打印出从1到最大的n位十进制数。比如，输入3，则打印出1，2，3一直到最大
的3位数999
*/

/*
分析：
1. n的值没有限定，有以下几个问题：
    n能否为负数
    n非常大时，uint64表示不出来(大数问题)
2. 打印
    当数非常大时，uint64表示不出来，需要通过其他方式
*/

/*
方案：
1. 大数使用字符串表示
2. 打印时直接以char的形式打印
*/

#include <iostream>

/*
从1开始对num_str每次递增1，一直到达到最大值时返回true
用字符串模拟加法流程
*/
bool inc_num_to_max(char *num_str){
    bool overflow = false;
    int length = strlen(num_str);
    int i = 0;

    for(i=length-1; i>=0; i--){
        if

        if('9' == num_str[i]){
            if(0 == i){
                overflow = true;
                brek;
            }
            num_str[i] = '0';
            continue;
        }else{
            num_str[i] += 1;
            break;
        }
    }
}

/*
常规解法:
    分两步：
        1. 先将数字使用字符串表示出来
        2. 打印表示出来的数字，注意不打印起始的0
*/
int print_max_number(int n){
    if(0 >= n){
        return 0;
    }

    //申请n+1的空间，初始化未‘0’，最后一位给‘\0’
    char *num_str = new char[n + 1];
    memset(num_str, '0', n);
    num_str[n] = '\0';

    //从1开始打印输出，直到最大值
    while(!inc_num_to_max(num_str)){
        print_num(num_str);
    }

    delete []num_str;
    return 0;
}

int main(){

    return 0;
}