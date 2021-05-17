/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_blank(char *src){
    printf("before replace: %s\n", src);
    if(NULL == src){
        printf("src string is NULL\n");
        return;
    }
    int src_len = strlen(src) + 1;
    int i=0, nr_blank=0;
    for(i=0; i<src_len; i++){
        if(' ' == src[i])
            nr_blank++;
    }
    int dest_len = src_len + 2 * nr_blank;

    char *p1 = &src[src_len - 1];
    char *p2 = &src[dest_len - 1];
    while(p1 != p2){
        if(' ' == *p1){
            *p2 = '0';
            p2--;
            *p2 = '2';
            p2--;
            *p2 = '%';
            p2--;
            p1--;
        }else{
            *p2 = *p1;
            p2--;
            p1--;
        }
    }

    printf("after replace: %s\n", src);
}

int main(){
    char data1[100] = "We Are Happy.";
    char *data2 = NULL;
    char data3[100] = "";
    char data4[100] = " ";
    char data5[100] = " we ";
    char data6[100] = "w      e";

    replace_blank(data1);
    replace_blank(data2);
    replace_blank(data3);
    replace_blank(data4);
    replace_blank(data5);
    replace_blank(data6);

    return 0;
}