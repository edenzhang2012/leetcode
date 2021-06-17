/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列
都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数
组中是否含有该整数。
[
  [1,2,8,9],
  [2,4,9,12],
  [4,7,10,13],
  [6,8,11,15]
]
给定 target = 7，返回 true。

给定 target = 3，返回 false。
*/
#include <stdio.h>
#include <stdbool.h>

bool find_in_array(int array[][4], int x, int y, int target){
    if(NULL == array || NULL == *array)
        return false;
    if(0 == x || 0 == y)
        return false;

    int i=0, j=0;
    for(j=y-1; j>=0; j--){
        for(i=0; i<x; i++){
            printf("number %d\n", array[i][j]);
            if(target == array[i][j]){
                return true;
            }else if(target < array[i][j]){
                break;
            }else{
                continue;
            }
        }
    }

    return false;
}

int main(){
    int array[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    int target = 5;

    if(find_in_array(array, 4, 4, target)){
        printf("find it\n");
    }else{
        printf("not found\n");
    }

    return 0;
}