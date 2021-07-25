/*
接14题，要求将14题中的函数改的更加通用，求其他形式的数组变换，尽量少的改动函数
*/

/*
分析：
要想改的更加通用，则可以考虑加函数指针，将判断条件通过函数指针传入函数中
*/

#include <stdio.h>

void div_array(int *data, int num, bool (*func)(int)){
    if(NULL == data || 0 == num)
        return;

    int i = 0, j = num - 1, temp = 0;

    while(i != j){
        if(!func(data[i])){
            i++;
            continue;
        }else{
            if(func(data[j])){
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

bool is_even(int data){
    return !(data % 2);
}

int main(){
    int data[5] = {1,2,3,4,5};
    int data1[5] = {1,1,1,1,1};
    int data2[5] = {2,2,2,2,2};
    int data3[5] = {2,2,2,1,1};
    int i = 0;

    div_array(data, 5, is_even);
    for(i=0; i<5; i++){
        printf("%d ", data[i]);
    }
    printf("\n");

    div_array(data1, 5, is_even);
    for(i=0; i<5; i++){
        printf("%d ", data1[i]);
    }
    printf("\n");

    div_array(data2, 5, is_even);
    for(i=0; i<5; i++){
        printf("%d ", data2[i]);
    }
    printf("\n");

    div_array(data3, 5, is_even);
    for(i=0; i<5; i++){
        printf("%d ", data3[i]);
    }
    printf("\n");

    div_array(NULL, 5, is_even);
    return 0;
}