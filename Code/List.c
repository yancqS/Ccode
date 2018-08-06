#include <stdio.h>
#include <stdlib.h>
#include "ListFun.h"
//单向链表
//链表:其价值是内存零碎数据的有效组织
int main() {
#if 0
    //静态链表(意义不大)主要原因是数据存储在栈上，栈的存储空间有限，不能动态分配。
    //链表要实现存储的自由，要动态的申请堆里的空间。
    Node a;
    Node b;
    Node c;
    a.data = 10;
    b.data = 20;
    c.data = 30;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    Node * head = &a;
    Node * listP = head;
    while (listP != NULL) {
        printf("data = %d\n", listP->data);
        listP = listP->next;
    }
#endif
    //动态链表的创建(头插法:在头结点的后面插入节点)
    printf("=============Head List============\n");
    Node *head = createList();
    traverseList(head);
    int length = lenList(head);
    printf("length = %d\n", length);

    printf("=============Tail List============\n");
    //动态链表的创建(尾插法:在尾结点的后面插入节点)
    Node *headTail = createListTail();
    traverseList(headTail);
    int lengthTail = lenList(headTail);
    printf("length = %d\n", lengthTail);

    printf("=============List Search============\n");
    Node *headSearch = createList();
    Node *findIdx = searchList(headSearch, 4);
    if (findIdx == NULL)
        printf("NO NUMBER!!!\n");
    else {
        printf("findData = %d\n", findIdx->data);
        traverseList(headSearch);
        //删除某个节点
        delNode(headSearch, findIdx);
        printf("--------------After Delete-------------\n");
        traverseList(headSearch);
    }

    printf("=============List Sort============\n");
    //换值排序(选择法)
    Node *headSortSelect = createList();
    int lenSortSelect = lenList(headSortSelect);
    sortListSelect(headSortSelect, lenSortSelect);
    traverseList(headSortSelect);

    //换值排序(冒泡法)
    Node *headSortBubble = createList();
    int lenSearchBubble = lenList(headSortBubble);
    sortListBubble(headSortBubble, lenSearchBubble);
    traverseList(headSortBubble);

    //换指针排序(冒泡)
    Node *headSortBubbleP = createList();
    int lenSearchBubbleP = lenList(headSortBubbleP);
    sortByPoint(headSortBubbleP, lenSearchBubbleP);
    traverseList(headSortBubbleP);

    //链表反转
    Node *headReverse = createList();
    traverseList(headReverse);
    reverseList(headReverse);
    printf("Reverse:\n");
    traverseList(headReverse);

    system("pause");
    return 0;
}