/*
要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）
*/

/*
分析：
1.斐波那契数列，典型的递归应用场景。但是会有较多的重复计算，效率低下
2.循环版
*/

#include <iostream>

//递归实现
int Fibonacci1(int n){
    if(n < 0){
        std::cerr << "invalid params" << std::endl;
        return 0;
    }

    if(0 == n){
        return 0;
    }

    if(1 == n){
        return 1;
    }

    return Fibonacci1(n-2) + Fibonacci1(n-1);
}

//循环实现
int Fibonacci2(int n){
    if(n < 0){
        std::cerr << "invalid params" << std::endl;
        return 0;
    }

    if(0 == n){
        return 0;
    }

    if(1 == n){
        return 1;
    }


    int ppre = 0;
    int pre = 1;
    int right = -1;
    for(int i=2; i<=n; i++){
        right = pre + ppre;
        ppre = pre;
        pre = right;
    }

    return right;
}

int main(){

    uint64_t ret = Fibonacci2(50);
    std::cout << "ret = " << ret << std::endl;
}