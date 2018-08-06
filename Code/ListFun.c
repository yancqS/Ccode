#include <stdio.h>
#include <stdlib.h>
#include "ListFun.h"

//头插法:在头结点的后面插入节点
Node *createList() {
    //首先创建一个空链表(此时还未存放数据)
    Node *head = (Node *) calloc(1, sizeof(Node));
    head->next = NULL;
    Node *cur;
    int tmp;
    while (1) {
        printf("pls input node data:");
        //输入一个不为0数据
        scanf("%d", &tmp);
        putchar(10);
        if (tmp == 0)//为0则退出
            break;
        //为数据在堆里申请空间
        cur = (Node *) calloc(1, sizeof(Node));
        cur->data = tmp;//存放数据到节点数据域

        cur->next = head->next;//将head所指向节点的指针域的值赋给当前节点的指针域
        //(也就是说原来由head所指向节点的指针域所指针所指向的节点 现在有刚申请的节点的指针域来指向)
        head->next = cur;//将新申请的节点空间的地址赋值给head所指向节点的指针域 构成链表。
        //(也就是说head指针域始终指向新申请的节点地址)
        //原来由head所指向节点的指针域所指向的节点 现在有刚申请的节点的指针域来指向, head所指向节点的指针域始终指向新申请的节点地址。(头插法的核心思想)
    }
    return head;
}

//尾插法:在尾结点的后面插入节点
Node *createListTail() {
    Node *head = (Node *) calloc(1, sizeof(Node));
    head->next = NULL;
    Node *tail = head;
    int data;
    while (1) {
        printf("pls input node data:");
        //输入一个不为0数据
        scanf("%d", &data);
        putchar(10);
        if (data == 0)
            break;
        Node *cur = (Node *) calloc(1, sizeof(Node));
        cur->data = data;
        cur->next = NULL;
        tail->next = cur;
        tail = cur;
    }
    return head;
}

//遍历节点
void traverseList(Node *head) {
    head = head->next;//第一个节点没存放数据
    while (head != NULL) {
        printf("data = %d\n", head->data);
        head = head->next;
    }
}

//求长度
int lenList(Node *head) {
    int len = 0;
    head = head->next;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

//查找
Node *searchList(Node *head, int find) {
    head = head->next;
    while (head != NULL) {
        if (head->data == find)
            break;
        head = head->next;
    }
    return head;
}

//删除
void delNode(Node *head, Node *del) {
    while (head->next != del)
        head = head->next;
    head->next = del->next;
    free(del);
}

//换值排序(冒泡法)
void sortListBubble(Node *head, int len) {
    printf("==========Bubble Sort==========\n");
    for (int i = 0; i < len - 1; i++) {
        Node *cur = head->next;
        for (int j = 0; j < len - 1 - i; j++) {
            if (cur->data > cur->next->data) {
                int tmp = cur->next->data;
                cur->next->data = cur->data;
                cur->data = tmp;
            }
            cur = cur->next;
        }
    }
}

//换值排序(选择法)
void sortListSelect(Node *head, int len) {
    printf("==========Select Sort==========\n");
    Node *cur = head->next;
    for (int i = 0; i < len - 1; i++) {
        Node *curAfter = cur->next;
        for (int j = i + 1; j < len; j++) {
            if (cur->data > curAfter->data) {
                int tmp = curAfter->data;
                curAfter->data = cur->data;
                cur->data = tmp;
            }
            curAfter = curAfter->next;
        }
        cur = cur->next;
    }
}

//换指针排序(冒泡)
void sortByPoint(Node *head, int len) {
    printf("=======Bubble Sort By Point======\n");
    for (int i = 0; i < len - 1; i++) {
        Node *subHead = head;
        Node *pre = subHead->next;
        Node *Aft = pre->next;
        Node *tmp;
        for (int j = 0; j < len - 1 - i; j++) {
            if (pre->data > Aft->data) {
                subHead->next = pre->next;
                pre->next = Aft->next;
                Aft->next = pre;
                //这一步如果以后看不懂: 看夹在讲义15.3.10.2 的一张白纸图解。
                tmp = pre;
                pre = Aft;
                Aft = tmp;
            }
            subHead = subHead->next;
            pre = pre->next;
            Aft = Aft->next;
        }
    }
}

//链表反转
void reverseList(Node *head) {
    Node *p = head->next;
    Node *q;
    head->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}
/*
 * 链表销毁
 * void destroyList(Node *head){
 *      Node *p;
 *      while(head){
 *          p = head->next;
 *          free(p);
 *          head = p;
 *      }
 * }
 * */

