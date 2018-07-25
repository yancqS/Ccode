#include <stdio.h>
#include <stdlib.h>

//链表:其价值是内存零碎数据的有效组织

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createList();

Node *createListTail();

void traverseList(Node *head);

int lenList(Node *head);

Node * searchList(Node * head, int find);

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
    printf("=============Static List============\n");
    Node *head = createList();
    traverseList(head);
    int length = lenList(head);
    printf("length = %d\n", length);

    printf("=============Dynamic List============\n");
    //动态链表的创建(尾插法:在尾结点的后面插入节点)
    Node *headTail = createListTail();
    traverseList(headTail);
    int lengthTail = lenList(headTail);
    printf("length = %d\n", lengthTail);

    printf("=============List Search============\n");

    Node * headSearch = createList();
    Node * findIdx = searchList(headSearch,4);
    if(findIdx == NULL)
        printf("NO NUMBER!!!\n");
    else
        printf("findData = %d\n", findIdx->data);

    system("pause");
    return 0;
}

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
    Node *pre = head;
    int data;
    while (1) {
        printf("pls input node data:");
        //输入一个不为0数据
        scanf("%d", &data);
        putchar(10);
        if (data == 0)
            break;
        Node *last = (Node *) calloc(1, sizeof(Node));
        last->data = data;
        last->next = NULL;
        pre->next = last;
        pre = last;
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
Node * searchList(Node * head, int find){
    head = head->next;
    while (head != NULL){
        if(head->data == find)
            break;
        head = head->next;
    }
    return head;
}