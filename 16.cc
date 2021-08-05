/*
定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
*/

/*
分析：
准备一个指针rhead先为空，head为原链表的头，让指针p = head; head = head->next; 
p->next = rhead; rhead = p;依次循环，直到head==NULL;
NOTE:
    1. 链表为空
    2. 链表只有一个元素
    3. 链表有多个元素
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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

void release_list(struct ListNode** head){
    struct ListNode* p = NULL;
    struct ListNode* q = NULL;

    if(NULL == *head)
        return;

    p = *head;
    while(p){
        *head = p->next;
        free(p);
        p = *head;
    }
}

void print_list(struct ListNode *head){
    if(NULL == head)
        printf("empty\n");

    struct ListNode *node = head;
    while(NULL != node){
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

//TODO: do it with recursively method 
struct ListNode *reverse_list(struct ListNode * head){
    if(NULL == head){
        return NULL;
    }

    struct ListNode *rhead = NULL;
    struct ListNode *p = NULL;

    while(head){
        p = head;
        head = head->next;
        p->next = rhead;
        rhead = p;
    }

    return rhead;
}

int main(){
    struct ListNode *head = NULL;
    struct ListNode *rhead = NULL;
    list_add(&head, 1);
    list_add(&head, 2);
    list_add(&head, 3);
    list_add(&head, 4);
    list_add(&head, 5);
    print_list(head);

    rhead = reverse_list(head);
    print_list(rhead);
    release_list(&rhead);

    rhead = reverse_list(NULL);
    print_list(rhead);
    release_list(&rhead);

    head = NULL;
    list_add(&head, 5);
    print_list(head);
    rhead = reverse_list(head);
    print_list(rhead);
    release_list(&rhead);

    return 0;
}