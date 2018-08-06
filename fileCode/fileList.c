/*
 * 读写文件生成链表
 * 实现功能:
 *      1.初始化现有数据到文件
 *      2.读文件生成链表
 *      3.操作链表-增加 删除
 *      4.写链表到文件
 *建议cmd下运行d:->cd Cppcode->cd cmake-(Tab补全)->fileList.exe->enter
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stuinfo {
    int num;
    char name[30];
    char sex;
    float score;
} STU;

typedef struct listStu {
    STU data;//数据域不再是基本数据类型
    struct listStu *next;

} Node;

//初始化现有数据到文件
void init() {
    STU stu[] = {
            {1001, "Bob",     'x', 100},
            {1002, "Yoranda", 'o', 90},
            {1003, "Ken",     'x', 33}
    };
    FILE *fp = fopen("../fileCode/stuback.data", "w");
    if (NULL == fp)
        exit(-1);
    int n = sizeof(stu) / sizeof(stu[0]);
    fwrite(stu, sizeof(stu[0]), n, fp);
    fclose(fp);
}

//读文件生成链表
Node *creatListFromFile() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    FILE *fp = fopen("../fileCode/stuback.data", "r");
    if (NULL == fp)
        exit(-1);
    Node *cur = (Node *) malloc(sizeof(Node));
    while (fread(&(cur->data), sizeof(STU), 1, fp) > 0) {
        cur->next = head->next;
        head->next = cur;

        cur = (Node *) malloc(sizeof(Node));
    }
    free(cur);
    return head;
}

//打印内容
void displayStudent(Node *head) {
    head = head->next;
    while (head != NULL) {
        printf("%d\t\t%s\t\t%c\t%.2f\n", head->data.num, head->data.name, head->data.sex, head->data.score);
        head = head->next;
    }
}

//操作链表-增加
void insertList(Node *head) {
    Node *cur = (Node *) malloc(sizeof(Node));
    printf("pls input number:");
    scanf("%d", &cur->data.num);
    printf("pls input name:");
    scanf("%s", cur->data.name);
    getchar();
    printf("pls input sex:");
    scanf("%c", &cur->data.sex);
    printf("pls input score:");
    scanf("%f", &cur->data.score);

    cur->next = head->next;
    head->next = cur;
}

//操作链表-删除
void delStudent(Node *head) {
    printf("pls input del name:");
    char name[30];
    scanf("%s", name);
    Node *pfind = head;

    while (pfind != NULL) {
        if (strcmp(pfind->data.name, name) == 0) {
            break;
        }
        pfind = pfind->next;
    }

    if (pfind == NULL)
        printf("find None\n");
    else {
        while (head->next != pfind)
            head = head->next;
        head->next = pfind->next;
        free(pfind);
    }
    return;
}

//写链表到文件
void saveStudent2File(Node *head) {
    FILE *fp = fopen("../fileCode/stuback.data", "w");
    if (NULL == fp)
        exit(-1);
    head = head->next;
    while (head != NULL) {
        fwrite(&(head->data), sizeof(STU), 1, fp);
        head = head->next;
    }
    fclose(fp);
}


int main() {
    //init();
    Node *head = creatListFromFile();
    int choice;
    while (1) {
        system("cls");
        printf("\t----Student Manger System----\n\n");
        printf("num\t\tname\t\tsex\tscore\n\n");
        displayStudent(head);

        printf("\n1->insert\t2->delete\t3->exit\t\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertList(head);
                break;
            case 2:
                delStudent(head);
                break;
            case 3:
                saveStudent2File(head);
                printf("Thanks for using our system-_-");
                return 0;
            default:
                break;
        }
    }
}