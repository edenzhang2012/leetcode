/*
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
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

//递归调用
void print_end_to_start_recursion(struct ListNode *head){
    if(NULL == head){
        printf("empty\n");
        return;
    }

    if(NULL == head->next){
        printf("%d\n", head->val);
        return;
    }

    print_end_to_start_recursion(head->next);
    printf("%d\n", head->val);
    return;
}

//非递归方式，想办法将链表反转
void print_end_to_start(struct ListNode *head){
    if(NULL == head){
        printf("empty\n");
        return;
    }

    if(NULL == head->next){
        printf("%d\n", head->val);
        return;
    }


}

void print_list(struct ListNode *head){
    if(NULL == head)
        printf("empty\n");

    struct ListNode *node = head;
    while(NULL != node){
        printf("%d\n", node->val);
        node = node->next;
    }
}

int main(){
    struct ListNode *node = NULL;
    list_add(&node, 67);
    list_add(&node, 0);
    list_add(&node, 24);
    list_add(&node, 58);

    print_list(node);
    print_end_to_start_recursion(node);
}