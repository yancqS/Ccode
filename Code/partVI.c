#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myStr.h"

//�ַ���
//�����ĳ���,�����ڴ����
//�������ַ���,���������ݶ�,������ֻ�����ݶ�
int main() {
    /*
    printf("%d\n", sizeof("hello world"));
    printf("%s\n", "hello");
    //�������:char a; char * p = &a; ���� char name[]; char * p = name;
    char * p = "hello world";
    //�ַ����洢�����ݶ�,������ֻ�����ݶΡ�����main�����ڲ�����ʱ����������Ϊһ��ָ�����ݶ���һ���ַ������ַ�ָ��(char *)
    printf("p = %p, \"hello world\" = %p\n",p,"hello world");//p = 0040506E, "hello world" = 0040506E
    printf("%c\n",p[0]);//h
    printf("%c\n",*(p+1));//e
    printf("%p\n",&p[0]);//0040506E
    printf("===================\n");
    printf("%c\n","hello world"[0]);//h
    printf("%p\n",&"hello world"[0]);//0040506E
     */
    /*
    //�ַ����� �� �ַ���
    char name[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'g', 'k'};
    for (int i = 0; i < 10; i++) {
        *(name + i) = 'm';
        printf("%c", *(name + i));
    }
    putchar(10);
    char *p = "yanchongqing";
    for (int i = 0; *(p + i) != '\0'; i++) {
        //*(p+i) = 'm'; �ַ����洢�����ݶε�ֻ����,�����Ըı��ַ������ݻᵼ�±�����(�����ַ������ɸ���)
        printf("%c",*(p+i));
    }
    putchar(10);
    printf("sizeof(name) = %d\n",sizeof(name));//10
    printf("name = %p\n", name);//0x0028FF2A
    printf("name+1 = %p\n", name+1);//0x0028FF2B
    printf("========================\n");
    printf("sizeof(\"yanchongqing\") = %d\n",sizeof("yanchongqing"));//13
    printf("\"yanchongqing\" = %p\n", "yanchongqing");//0x00405064
    printf("\"yanchongqing\"+1 = %p\n", "yanchongqing"+1);//0x00405065
     */
    /*
    //����������֤���ַ����� �� �ַ��� ��ĳЩ������ȫ�Ǻϡ�
    char name[] = "yanchongqing";//"yanchongqing" �� name ���� ָ�롣
    //"yanchognqing" ���ɴ洢�����ݶ�ֻ��������ʼ��ʱ�ְ��������ַ����顣
    printf("%s\n", name);
    printf("%s\n", "yanchongqing");
    name[1] = 'A';
    //"yanchongqing"[1] = 'A'; �������
    printf("%s\n", name);
    printf("%s\n", "yanchongqing");
    printf("%c\n", *(name + 2));//printf("%c\n", name[2]);
    printf("%c\n", *("yanchongqing" + 2));//printf("%c\n", "yanchongqing"[2]);
    */
    /*
    //�ַ��������� �� ���
    printf("%s\n","abcdefg");//�����ַ�������������ֹͣ��ӡ���
    puts("abcdefgh");//������Զ�����
    //char name[10];
    char arrS[10];
    //scanf("%s",name);//ע�� : ��ҪԽ�硣�ڲ�Խ�������£�scanf���Զ����ַ�������׷��'\0'�������ո���������
    //printf("%s",name);

    gets(arrS);//gets֪�������س�����ֹͣ���룬�ո�Ҳ�������롣����ҪԽ�硣�ڲ�Խ�������£�gets���Զ����ַ�������׷��'\0'��
    puts(arrS);
     */
    //�ַ�����������
#if 0
    //ԭ������֮���ַ�������(������'\0')
char name[100] = "yanchongqing";
int count = 0;
char * p = name;
/*for(int i = 0; i<100; i++){
    if(name[i] == '\0')
        break;
    count++;
}*/
while (*p++ != '\0'){
    count++;
}
printf("count = %d\n", count);
    //ԭ������֮ƴ���ַ���
char firstName[10] = "jim";
char lastName[10] = "Green";
char * f;
int n = 0;
for(f = firstName;*f != '\0';f++);
for(char * l = lastName;*l != '\0';){
    *f++ = *l++;
    n++;
}
printf("fullName = %s, n = %d\n",firstName, n);
#endif
#if 0
    //�⺯��strlen
    char name[] = "The Great Wall";
    int len = strlen(name);//strlen���������ַ���str�ĳ���(����ֵ������'\0'֮ǰ�ַ���Ŀ)��
    printf("len = %d\n", len);

    //�⺯��strcat
    char firstName[] = "jim";
    char lastName[] = "Green";
    char * fullName = strcat(firstName, lastName);//�������ַ���lastName ���ӵ�firstName��ĩ�ˣ�������ָ��firstName
    printf("fullName = %s\n", fullName);

    //�⺯��strcmp
    /*
     * �Ƚ��ַ���str1 �� str2 �Ĵ�С���ú��������ַ����ĵ�һ���ַ���ʼ�������ȣ�һ�����±Ƚϣ�ֱ��������ͬ��
     * �ַ���������һ������'\0'���Ƚϵ����������ַ���Ӧ��ASCIIֵ�Ĵ�С��
     * */
    char str1[] = "yAn";
    char str2[] = "yaz";
    int res = strcmp(str1, str2);
    if (res == 0)
        printf("str1 = str2\n");
    else if (res > 0)
        printf("str1 > str2\n");
    else
        printf("str1 < str2\n");

    //��¼�߼�
    char user[1024];
    char pass[1024];
    int flag = 0;
    int count = 0;

    while (1) {
        printf("�������û���: ");
        gets(user);
        printf("�������� ��: ");
        gets(pass);
        if (strcmp(user, "yanchongqing") == 0 && strcmp(pass, "111222") == 0) {
            flag = 1;
            break;
        } else{
            printf("\nInvalid username or password\n");
        }
        count++;
        if (count == 3)
            break;
    }

    if (flag == 1)
        printf("welcome Sir\n");
    else
        printf("system is being hacked\n");
    system("pause");
#endif
    /*
    //�⺯��strcpy
    char src[] = "I love China";
    char dest[100] = "I am hungry";
    strcpy(dest, src);//��srcָ����ַ������Ƶ�destָ����ַ�����(dest��Ҫ���㹻�Ŀռ�����������)��
                      // ���������� '\0' Ҳһ�𿽱���
    printf("src = %s\n",src);
    printf("dest = %s\n",dest);
     */
    //myStrlen(strlen������ʵ��)
    char str[] = "I love China";
    int len = myStrlen(str);
    printf("len = %d\n", len);

    //myStrcat(strcat������ʵ��)
    char dog[] = "dog ";
    char cat[] = "cat";
    myStrcat(dog, cat);
    printf("concat is %s\n", dog);

    //myStrcpy(strcpy������ʵ��)
    char src[] = "music is amazing";
    char dest[100] = "bilibili";
    myStrcpy(dest, src);
    printf("dest is %s\n", dest);

    //myStrcmp(strcmp������ʵ��)
    char str1[] = "abcd";
    char str2[] = "abc";
    int res = myStrcmp(str1, str2);
    if (res == 0)
        printf("str1 = str2\n");
    else if (res > 0)
        printf("str1 > str2\n");
    else
        printf("str1 < str2\n");


    //���ļ����
    /*
     * myStr.c(һЩ�Զ��庯��)
     * myStr.h(��������)
     * */

    //����0
    /*
     0          ���͵���
     0.0        ʵ�͵���
     NULL       ָ�����    00000000-FFFFFFFF
     '\0'       ASCII����(ASCIIֵΪ0)
     '0'(48)    �ַ�����(ASCIIֵΪ48) '0'-'9'(48-57) 'A'-'Z'(65-90) 'a'-'z'(97-122)
     * */

    //ָ������,����������
    char *name[] = {"apple", "bear", "peach", "IBM", "Google", "banana"};
    int n = sizeof(name) / sizeof(name[0]);
    printf("����ǰ: ");
    for (int i = 0; i < n; i++) {
        printf("%s\t", *(name + i));
    }
    putchar(10);
    //ð�ݷ��ַ�������(��������ָ���ַ)
    for (int i = 0; i < n - 1; i++) {
        char *tmp = NULL;
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(*(name + j), *(name + j + 1)) > 0) {
                tmp = *(name + j);
                *(name + j) = *(name + j + 1);
                *(name + j + 1) = tmp;
            }
        }
    }
    printf("�����: ");
    for (int i = 0; i < n; i++) {
        printf("%s\t", *(name + i));
    }


    return 0;
}

