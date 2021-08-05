/*
输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的
*/

/*
分析：
思路不难，因为链表已经排好序，所以比较两个链表的头节点，值比较小的摘下来，链接到新的
链表上，然后将本链表的头节点往后移动一位，继续比较，一直到最长的链表也到达末尾结束

【注意】：
1. 链表排序过程中，可能会出现一个链表还有值未被排序，而另一个链表所有值都被摘除的情况，
出现这种情况时，直接将还有值的链表整个接在排序的链表上即可
2. 其中一条链表为空时的处理
3. 两条链表都为空的处理

NOTE: 一定要注意指针的合理使用
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

void list_add_by_ptr(struct ListNode **head, struct ListNode *member){
    struct ListNode *tmp = NULL;
    if(NULL == *head){
        *head = member;
    }else{
        tmp = *head;
        while(NULL != tmp->next)
            tmp = tmp->next;
        
        tmp->next = member;
    }
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

//use for or while loop
struct ListNode *merge_list(struct ListNode *head1, struct ListNode *head2){ 
    struct ListNode *ret  = NULL;
    struct ListNode *tmp = NULL;
    struct ListNode *tail = NULL;

    if(NULL == head1)
        return head2;
    else if(NULL == head2)
        return head1;

    while(NULL != head1 || NULL != head2){
        if(NULL == head1){
            tail->next = head2;
            return ret;
        }

        if(NULL == head2){
            tail->next = head1;
            return ret;
        }

        if(head1->val < head2->val){
            tmp = head1;
            head1 = head1->next;
        }else{
            tmp = head2;
            head2 = head2->next;
        }

        tmp->next = NULL;
        if(NULL == ret){
            ret = tmp;
        }else{
            tail->next = tmp;
        }

        tail = tmp;
    }

    return ret;
}

//use recusion
struct ListNode *merge_list_recusion(struct ListNode *head1, 
        struct ListNode *head2){
    if(NULL == head1){
        return head2;
    }else if(NULL == head2){
        return head1;
    }

    struct ListNode *mergeed_head = NULL;

    if(head1->val < head2->val){
        mergeed_head = head1;
        mergeed_head->next = merge_list_recusion(head1->next, head2);
    }else{
        mergeed_head = head2;
        mergeed_head->next = merge_list_recusion(head1, head2->next);
    }

    return mergeed_head;
}

int main(){
    struct ListNode *head1 = NULL;
    struct ListNode *head2 = NULL;
    struct ListNode *head3 = NULL;

    list_add(&head1, 1);
    list_add(&head1, 1);
    list_add(&head1, 2);
    list_add(&head1, 2);
    list_add(&head1, 3);
    printf("list 1:\n");
    print_list(head1);

    list_add(&head2, 2);
    list_add(&head2, 3);
    list_add(&head2, 4);
    list_add(&head2, 5);
    list_add(&head2, 6);
    printf("list 2:\n");
    print_list(head2);

    head3 = NULL;
    // head3 = merge_list(NULL, head2);
    head3 = merge_list_recusion(NULL, head2);
    printf("list 3:\n");
    print_list(head3);

    head3 = NULL;
    // head3 = merge_list(NULL, NULL);
    head3 = merge_list_recusion(NULL, NULL);
    printf("list 4:\n");
    print_list(head3);

    // head3 = merge_list(head1, head2);
    head3 = merge_list_recusion(head1, head2);
    printf("list 5:\n");
    print_list(head3);

    return 0;
}