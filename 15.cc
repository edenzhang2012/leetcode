/*
输入一个键表，输出该链表中倒数第k个结点.为了符合大多数人的习惯，本题从1开始计数，
即链表的尾结点是倒数第1个结点.例如一个链表有6个结点，从头结点开始它们的值依次是1、2、
3、4、5、6.这个链表的倒数第3个结点是值为4的结点.
*/

/*
分析：
链表为单向链表，所以没法从后往前数，但是我们发现一般有倒数第k个，既是正数第 
n-k+1（k<=n） 个, 这样需要先遍历一遍链表拿到n值，然后再遍历一次链表取得所要的值。
这种常规解法可行，但是需要遍历两遍。
若只想遍历一遍，则需要借助另外一个指针。首先我们观察，假设p1指向的是倒数第3个数
（我们想要的结果），此时，其距离末尾还有2格，若当p1走到第三格时（走过2格），让p2从头
开始走，则当p1走到末尾时，p2正好落在倒数第3个位置上。利用这个规律可以达到我们想要的结果
              p1
|_1_|_2_|_3_|_4_|_5_|_6_|
*/

#include <stdio.h>
#include <assert.h>

/*规定的单链结构体*/
struct ListNode {
    int val;
    struct ListNode *next;
};

void list_add(struct ListNode **head, int data){
    if(NULL == *head){
        *head = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        assert(*head);
        (*head)->val = data;
        (*head)->next = NULL;
        return;
    }

    struct ListNode *node = *head;
    struct ListNode *temp = NULL;
    if(NULL == node->next){
        temp = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        assert(temp);
        temp->next = NULL;
        temp->val = data;
        node->next = temp;
        return;
    }

    while(NULL != node->next){
        node = node->next;
    }

    temp = (struct ListNode *)calloc(1, sizeof(struct ListNode));
    assert(temp);
    temp->next = NULL;
    temp->val = data;
    node->next = temp;
    return;
}

struct ListNode *find_back_point(struct ListNode *head, int k){
    if(NULL == head || 0 == K)
        return NULL;
}

int main(){


    return 0;
}