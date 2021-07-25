/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数位于数组的前半部分，所有偶数位予数组的后半部分。
*/

/*
分析：
见到这道题，最常规的解法也是最容易想到的解法就是遍历数组，碰到偶数时，将该数保存，
将该数之后的所有数向前移动一位，将该数放在最后空出来的位置上，当遍历完整个数组时，
就完成了题目要求。但是这样做的时间复杂度为O(n^2)
更为快捷的解法：我们可以定义两个index,一个从前往后，寻找为偶数的位置，找到之后停止，
一个从后往前寻找奇数位置，找到之后与之前的偶数位置，将其值互换。继续向下寻找，直到
两个index相等。这有点儿类似与二分查找，最差的情况下，时间复杂度为O(n)
*/

#include <stdio.h>

void div_array(int *data, int num){
    if(NULL == data || 0 == num)
        return;

    int i = 0, j = num - 1, temp = 0;

    while(i != j){
        if(data[i] % 2 != 0){
            i++;
            continue;
        }else{
            if(data[j] % 2 == 0){
                j--;
                continue;
            }else{
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
                i++;
                j--;
                continue;
            }
        }
    }
}

int main(){
    int data[5] = {1,2,3,4,5};
    int data1[5] = {1,1,1,1,1};
    int data2[5] = {2,2,2,2,2};
    int data3[5] = {2,2,2,1,1};
    int i = 0;

    div_array(data, 5);
    for(i=0; i<5; i++){
        printf("%d ", data[i]);
    }
    printf("\n");

    div_array(data1, 5);
    for(i=0; i<5; i++){
        printf("%d ", data1[i]);
    }
    printf("\n");

    div_array(data2, 5);
    for(i=0; i<5; i++){
        printf("%d ", data2[i]);
    }
    printf("\n");

    div_array(data3, 5);
    for(i=0; i<5; i++){
        printf("%d ", data3[i]);
    }
    printf("\n");

    div_array(NULL, 5);
    return 0;
}