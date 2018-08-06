typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createList();

Node *createListTail();

void traverseList(Node *head);

int lenList(Node *head);

Node *searchList(Node *head, int find);

void delNode(Node *head, Node *del);

void sortListBubble(Node *head, int len);

void sortListSelect(Node *head, int len);

void sortByPoint(Node *head, int len);

void reverseList(Node * head);

#ifndef CPPCODE_LISTFUN_H
#define CPPCODE_LISTFUN_H

#endif //CPPCODE_LISTFUN_H
