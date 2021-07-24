/*
给定单向链表的头指针和一个结点指针，定义一个函数在o(1)时间删除该结点。
链表结点与函数的定义如下:
struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
}
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);
*/

/*
分析：
O(1)得时间内删除指定单项链表得指定节点，可以这样思考，我们是知道要删得节点得位置的，
但是不知道要删得节点上一个节点得位置（即无法知道上一个节点指向删除节点得指针）。但是
我们可以知道要删除节点的下一个节点，所以可以将下一个节点的内容复制到要删除的节点上，
然后删除下一个节点，就达到目的了。这里需要注意几种特殊情况：
    1. 单项链表中只有一个节点，也是要删除的节点：
        删除该节点，清除链表
    2. 删除的节点是头节点：
        按照定义方式删除即可。头节点没有改变
    3. 删除节点是尾节点：
        由于没有下一个节点了，直接删除本节点，会导致链表中残留一个无效指针，
        会存在问题，所以此时需要遍历列表
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
    ListNode* p = NULL;

    if(NULL == *pListHead || NULL == pToBeDeleted)
        return;

    //delete the only one node
    if(*pListHead == pToBeDeleted && NULL == (*pListHead)->next){
        free(*pListHead);
        *pListHead = NULL;
        return;
    }

    if(NULL == pToBeDeleted->next){
        p = *pListHead;
        while(p){
            if(p->next == pToBeDeleted){
                break;
            }else{
                p = p->next;
            }
        }

        if(NULL == p){
            printf("can not found this node\n");
            return;
        }else{
            p->next = NULL;
            free(pToBeDeleted);
            return;
        }
    }else{
        p = pToBeDeleted->next;
        pToBeDeleted->next = p->next;
        pToBeDeleted->val = p->val;
        free(p);
        return;
    }
}

int main(){
    struct ListNode *head = NULL;

    list_add(&head, 1);
    list_add(&head, 2);
    list_add(&head, 3);
    list_add(&head, 4);

    print_list(head);
    DeleteNode(&head, head);
    print_list(head);
    DeleteNode(&head, head->next);
    print_list(head);
    DeleteNode(&head, head->next);
    print_list(head);
    DeleteNode(&head, head);
    print_list(head);
    release_list(&head);
    return 0;
}