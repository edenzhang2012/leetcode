/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数
组的一个旋转，输出旋转数组的最小元素。例如数组{3，4，5，1，2}是递增数组{1，2，3，4，5}
的一个旋转，其最小元素为1
*/

/*
思路：
1. 可以使用最简单的暴力破解的思路，遍历一下数组找出最大值，时间复杂度O(n)
2. 观察数组，很明显的可以看到数组是有规律的，可以看成是两个递增数组组合在一起，最小元素
藏在中间的某一个位置，这种情况可以尝试使用二分法
NOTE: 几种特殊情况需要注意
    1. 数组只旋转了0个元素，即数组还是递增数组
    2. 数组为空
    3. 二分法查找时，start，middle，end指向的值都相同，此时无法判断最小值位于哪个位置，
    需要使用顺序查找
*/

#include <iostream>

int min_in_order(int *data, int start, int end){
    int ret = data[start];
    for(int i=start; i<=end; i++){
        if(data[i] < ret)
            ret = data[i];
    }
    return ret;
}

int find_min(int *data, int len){
    if(NULL == data || len <= 0){
        std::cout << "invalied params" << std::endl;
        return -1;
    }

    int start = 0;
    int end = len-1;
    int middle = (start + end)/2;

    //有可能只旋转了0个元素，即旋转后的数组还是递增数组，此时直接返回第一个元素即是最
    //小元素
    if(data[start] < data[end]){
        return data[start];
    }

    while(end != start + 1){
        //当前中后三个值都相等时，我们没法判定最小值所在的位置，此时只能顺序查找
        if(data[start] == data[middle] && data[middle] == data[end]){
            return min_in_order(data, start, end);
        }

        if(data[start] <= data[middle]){
            start = middle;
        }

        if(data[end] >= data[middle]){
            end = middle;
        }

        middle = (start + end)/2;
    }

    return data[end];
}

int main(){
    int data1[] = {3,4,5,1,2};
    int min1 = find_min(data1, sizeof(data1)/sizeof(int));
    std::cout << "min number " << min1 << std::endl;

    int data2[] = {1,2,3,4,5};
    int min2 = find_min(data2, sizeof(data2)/sizeof(int));
    std::cout << "min number " << min2 << std::endl;

    int data3[] = {1,0,1,1,1};
    int min3 = find_min(data3, sizeof(data3)/sizeof(int));
    std::cout << "min number " << min3 << std::endl;

    int min4 = find_min(NULL, 0);
    std::cout << "min number " << min4 << std::endl;

    int data5[] = {1};
    int min5 = find_min(data5, sizeof(data5)/sizeof(int));
    std::cout << "min number " << min5 << std::endl;
}