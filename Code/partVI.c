#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myStr.h"

//字符串
//常见的常量,出现在代码段
//常见的字符串,出现在数据段,而且是只读数据段
int main() {
    /*
    printf("%d\n", sizeof("hello world"));
    printf("%s\n", "hello");
    //两种情况:char a; char * p = &a; 或者 char name[]; char * p = name;
    char * p = "hello world";
    //字符串存储在数据段,而且是只读数据段。但在main函数内部编译时，把它处理为一个指向数据段中一段字符串的字符指针(char *)
    printf("p = %p, \"hello world\" = %p\n",p,"hello world");//p = 0040506E, "hello world" = 0040506E
    printf("%c\n",p[0]);//h
    printf("%c\n",*(p+1));//e
    printf("%p\n",&p[0]);//0040506E
    printf("===================\n");
    printf("%c\n","hello world"[0]);//h
    printf("%p\n",&"hello world"[0]);//0040506E
     */
    /*
    //字符数组 和 字符串
    char name[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'g', 'k'};
    for (int i = 0; i < 10; i++) {
        *(name + i) = 'm';
        printf("%c", *(name + i));
    }
    putchar(10);
    char *p = "yanchongqing";
    for (int i = 0; *(p + i) != '\0'; i++) {
        //*(p+i) = 'm'; 字符串存储在数据段的只读区,若尝试改变字符串内容会导致崩溃。(常量字符串不可更改)
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
    //经过上面论证，字符数组 和 字符串 在某些方面完全吻合。
    char name[] = "yanchongqing";//"yanchongqing" 和 name 都是 指针。
    //"yanchognqing" 依旧存储在数据段只读区。初始化时又把它拷到字符数组。
    printf("%s\n", name);
    printf("%s\n", "yanchongqing");
    name[1] = 'A';
    //"yanchongqing"[1] = 'A'; 程序崩溃
    printf("%s\n", name);
    printf("%s\n", "yanchongqing");
    printf("%c\n", *(name + 2));//printf("%c\n", name[2]);
    printf("%c\n", *("yanchongqing" + 2));//printf("%c\n", "yanchongqing"[2]);
    */
    /*
    //字符串的输入 和 输出
    printf("%s\n","abcdefg");//遇到字符串结束标记则会停止打印输出
    puts("abcdefgh");//输出后自动换行
    //char name[10];
    char arrS[10];
    //scanf("%s",name);//注意 : 不要越界。在不越界的情况下，scanf会自动在字符串后面追加'\0'。遇到空格会截至输入
    //printf("%s",name);

    gets(arrS);//gets知道遇到回车，才停止输入，空格也可以输入。但不要越界。在不越界的情况下，gets会自动在字符串后面追加'\0'。
    puts(arrS);
     */
    //字符串操作函数
#if 0
    //原生操作之求字符串长度(不包含'\0')
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
    //原生操作之拼接字符串
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
    //库函数strlen
    char name[] = "The Great Wall";
    int len = strlen(name);//strlen函数返回字符串str的长度(即空值结束符'\0'之前字符数目)。
    printf("len = %d\n", len);

    //库函数strcat
    char firstName[] = "jim";
    char lastName[] = "Green";
    char * fullName = strcat(firstName, lastName);//函数将字符串lastName 连接到firstName的末端，并返回指针firstName
    printf("fullName = %s\n", fullName);

    //库函数strcmp
    /*
     * 比较字符串str1 和 str2 的大小。该函数从两字符串的第一个字符开始，如果相等，一次往下比较，直到遇到不同的
     * 字符或者其中一个遇到'\0'。比较的依据是两字符对应的ASCII值的大小。
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

    //登录逻辑
    char user[1024];
    char pass[1024];
    int flag = 0;
    int count = 0;

    while (1) {
        printf("请输入用户名: ");
        gets(user);
        printf("请输入密 码: ");
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
    //库函数strcpy
    char src[] = "I love China";
    char dest[100] = "I am hungry";
    strcpy(dest, src);//将src指向的字符串复制到dest指向的字符串中(dest中要有足够的空间来拷贝内容)。
                      // 拷贝过程中 '\0' 也一起拷贝。
    printf("src = %s\n",src);
    printf("dest = %s\n",dest);
     */
    //myStrlen(strlen函数自实现)
    char str[] = "I love China";
    int len = myStrlen(str);
    printf("len = %d\n", len);

    //myStrcat(strcat函数自实现)
    char dog[] = "dog ";
    char cat[] = "cat";
    myStrcat(dog, cat);
    printf("concat is %s\n", dog);

    //myStrcpy(strcpy函数自实现)
    char src[] = "music is amazing";
    char dest[100] = "bilibili";
    myStrcpy(dest, src);
    printf("dest is %s\n", dest);

    //myStrcmp(strcmp函数自实现)
    char str1[] = "abcd";
    char str2[] = "abc";
    int res = myStrcmp(str1, str2);
    if (res == 0)
        printf("str1 = str2\n");
    else if (res > 0)
        printf("str1 > str2\n");
    else
        printf("str1 < str2\n");


    //多文件编程
    /*
     * myStr.c(一些自定义函数)
     * myStr.h(函数声明)
     * */

    //关于0
    /*
     0          整型的零
     0.0        实型的零
     NULL       指针的零    00000000-FFFFFFFF
     '\0'       ASCII的零(ASCII值为0)
     '0'(48)    字符的零(ASCII值为48) '0'-'9'(48-57) 'A'-'Z'(65-90) 'a'-'z'(97-122)
     * */

    //指针数组,本质是数组
    char *name[] = {"apple", "bear", "peach", "IBM", "Google", "banana"};
    int n = sizeof(name) / sizeof(name[0]);
    printf("排序前: ");
    for (int i = 0; i < n; i++) {
        printf("%s\t", *(name + i));
    }
    putchar(10);
    //冒泡法字符串排序(交换的是指针地址)
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
    printf("排序后: ");
    for (int i = 0; i < n; i++) {
        printf("%s\t", *(name + i));
    }


    return 0;
}

