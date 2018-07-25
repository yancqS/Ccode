#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

//共用(Union)与枚举(Enum)
//在c语言中，不同的成员使用共同的存储区域的数据构造类型称为共用体。
//共用体在定义、说明和使用形式上与结构体类似。两者的本质上的不同仅在于使用内存的方式上。

union untest {
    char c;
    short s;
    int i;
} myun;
struct structtest {
    char c;
    short s;
    int i;
} myst;

union mix {
    char name[100];
    int age;
};

typedef struct tands {
    char name[30];
    int num;
    char sex;
    char job;
    union {
        int grade;
        char position[50];
    } grpo;
} STA;


int main() {
#if 0
    //内存所占大小
    //对于结构体来讲,如果不考虑内存对齐,那么结构体所占用空间的大小为各成员大小之和。
    //对于共用体来讲,共用体所占用空间的大小取决于最大成员所占的大小。
    printf("sizeof(union untest) = %d\n", sizeof(union untest));//4
    printf("sizeof(union structtest) = %d\n", sizeof(struct structtest));//8
    //成员访问
    printf("&myst.c = %p, &myst.s = %p, &myst.i = %p\n", &myst.c, &myst.s, &myst.i);
    //&myst.c = 00407074, &myst.s = 00407076, &myst.i = 00407078(内存对齐)

    printf("&myun.c = %p, &myun.s = %p, &myun.i = %p\n", &myun.c, &myun.s, &myun.i);
    //&myun.c = 00407070, &myun.s = 00407070, &myun.i = 00407070(拥有共同的起始地址)

    myun.i = 0x12345678;
    printf("myun.c = %x\n",myun.c);//78
    printf("myun.s = %x\n",myun.s);//5678
    printf("myun.i = %x\n",myun.i);//12345678

    //有效性: 最后一次操作的成员是有意义的.
    union mix m;
    strcpy(m.name,"China");
    printf("name = %s\n",m.name);
    printf("age = %d\n",m.age);
    printf("=========================\n");
    m.age = 100;
    printf("name = %s\n",m.name);
    printf("age = %d\n",m.age);
#endif
#if 0
    //当需要把不同类型的变量存放发到同一段内存单元或对同一段内存单元的数据按照不同类型来处理则需要使用共用体数据结构。
    STA sta;
    printf("pls input your name:");
    scanf("%s", sta.name);
    printf("pls input your number:");
    scanf("%d", &sta.num);
    getchar();
    printf("pls input your sex:");
    scanf("%c", &sta.sex);
    getchar();
    printf("pls input your job:");
    scanf("%c", &sta.job);

    if (sta.job == 't') {
        printf("pls input your position:");
        scanf("%s", sta.grpo.position);
        printf("welcome Teacher: name = %s, num = %d, sex = %c, position = %s\n", sta.name, sta.num, sta.sex,
               sta.grpo.position);
    } else {
        printf("pls input your grade:");
        scanf("%d", &sta.grpo.grade);
        printf("welcome Student: name = %s, num = %d, sex = %c, grade = %d\n", sta.name, sta.num, sta.sex,
               sta.grpo.grade);
    }
#endif
    //枚举类型定义了一组整型常量的集合
    //枚举型是一个集合,集合中的元素(枚举类型)是一些命名的整型变量,元素之间用逗号(,)隔开
    //第一个枚举成员的默认值为0,后续枚举成员的值在前一个成员上加1
    //可以人为的设定枚举成员的值，从而自定义某个范围内的整数
    enum DAY {
        MON = 1, TUE, WED, THU, FRI, SAT, SUN
    };
    printf("%d %d %d %d %d %d %d\n", MON, TUE, WED, THU, FRI, SAT, SUN);

    enum DAY day = MON;
    printf("day = %d\n",day);
    //判断一年第125天是工作日还是休息日(假设一年365天,第一天星期一)
    unsigned int today;
    printf("pls input today num:");
    scanf("%d",&today);
    today = today % 7;
    enum DAY weekendorholiday = today;//weekendorholiday是有范围的，switch case 语句不用加default。

    switch (weekendorholiday){
        case MON:
        case TUE:
        case WED:
        case THU:
        case FRI:
            printf("today is workDay\n");
            break;
        case SAT:
        case SUN:
            printf("today is holiday\n");
            break;
    }

    //增加bool类型(c语言中是没有bool类型的)
    typedef enum BOOLEN{
        False,
        True
    } bool;

    bool true = True;
    bool false = False;

    return 0;
}