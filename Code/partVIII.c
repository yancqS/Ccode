#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <time.h>

//结构体:数组成员不需要区分类型，成员大小统一，所以才用首地址加偏移来表示。
//但对于结构体来说，类型大小均不统一，所以采用的成员运算符来进行访问。
//成员名称是区分不同成员的标识。
//每一个构造类型都要解决的问题是类型访问。

//用struct描述构造类型数组
struct Array {
    int a;
    int b;
};//相当于 int a[2]
#if 0
//结构体 类型 的定义. 结构体类型 地位 和 int相同
//有名结构体: 一处定义,多处使用
struct student {
    char name[100];
    int age;
    char sex;
    float score;
};//定义的同时初始化 or 先定义再逐个初始化

//无名结构体: 不引入新的类型
struct {
    char name[100];
    int age;
    char sex;
    float score;
} person;//先定义再逐个初始化
#endif
//别名构造体(常用)
typedef struct staff {
    char name[100];
    int age;
    char sex;
    float score;
} STAFF;//定义的同时初始化 or 先定义再逐个初始化

//结构体类型做参数和返回值
typedef struct complex {
    float real;
    float imag;
} imagNum;

imagNum addComplex(imagNum x, imagNum y) {
    imagNum res;
    res.real = x.real + y.real;
    res.imag = x.imag + y.imag;
    return res;
}

imagNum addComplexPo(imagNum *x, imagNum *y) {
    imagNum res;
    res.real = x->real + y->real;
    res.imag = x->imag + y->imag;
    return res;
}

typedef struct size{
    char sex;//1
    int age;//4
} SIZE;


int main() {
    struct Array arr;
    arr.a = 10;
    arr.b = 20;
    printf("a = %d, b = %d\n", arr.a, arr.b);

    typedef int INT;
    INT a = 10;
    printf("sizeof(a) = %d, sizeof(INT) = %d\n", sizeof(a), sizeof(INT));

    //凡是基本数据类型，即可定义时初始化，也可以先定义，再赋值(初始化)。
    // int a; a=1; 或者 int a = 1;
    //凡是构造类型，要么在定义时初始化。不能先定义，再以初始化的方式赋值。也可以分别逐个初始化。arr[0] = 0;arr[1] = 1;...
    // int array[10] = {0,1,2,3,4,5,6,7,8,9}。数组是构造类型，结构体也是构造类型。

    //定义的同时初始化
    STAFF sta1 = {"zhangsan", 20, 'o', 78.98};
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", sta1.name, sta1.age, sta1.sex, sta1.score);

    //先定义再逐个初始化
    strcpy(sta1.name, "lisi");
    //sta1.name = "lisi";这样是错误的。首先"lisi"在这是一个地址(指向数据段只读数据段),
    //name是字符数组的数组名。是一个地址常量。代表开辟空间的首地址。
    sta1.age = 40;
    sta1.sex = 'x';
    sta1.score = 45.08;
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", sta1.name, sta1.age, sta1.sex, sta1.score);
#if 0
    //以输入的方式初始化
    printf("请输入姓名:");
    scanf("%s", sta1.name);
    printf("请输入年龄:");
    scanf("%d",&sta1.age);
    getchar();  //%c前吸收一个回车
    printf("请输入性别:");
    scanf("%c",&sta1.sex);
    printf("请输入成绩:");
    scanf("%f",&sta1.score);
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", sta1.name, sta1.age, sta1.sex, sta1.score);
#endif
    //以上访问是 点成员运算符(sta1.xxx) 优先级很高，和()的优先级一样
    //下面介绍指向成员运算符(-> (*).)   优先级很高，和()的优先级一样
    STAFF sta2 = {"yancq", 20, 'o', 78.98};
    STAFF *ps = &sta2;
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", ps->name, ps->age, ps->sex, ps->score);

    strcpy(ps->name, "sungq");
    ps->age = 18;
    ps->sex = 'x';
    ps->score = 98.97;
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", ps->name, ps->age, ps->sex, ps->score);
#if 0
    printf("请输入姓名:");
    scanf("%s", ps->name);
    printf("请输入年龄:");
    scanf("%d", &ps->age);
    getchar();
    printf("请输入性别:");
    scanf("%c", &ps->sex);
    printf("请输入分数:");
    scanf("%f", &ps->score);
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", ps->name, ps->age, ps->sex, ps->score);

    ps = (STAFF *) malloc(sizeof(STAFF));
    printf("请输入姓名:");
    scanf("%s", ps->name);
    printf("请输入年龄:");
    scanf("%d", &ps->age);
    getchar();
    printf("请输入性别:");
    scanf("%c", &ps->sex);
    printf("请输入分数:");
    scanf("%f", &ps->score);
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).score);
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", ps->name, ps->age, ps->sex, ps->score);
#endif
    STAFF cpy = sta2;//同类型赋值
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", cpy.name, cpy.age, cpy.sex, cpy.score);

    typedef struct arr {
        int num[10];
    } ARRAY;

    ARRAY array = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}};
    ARRAY b = array;//实现数组拷贝
    for (int i = 0; i < sizeof(array.num) / sizeof(array.num[0]); i++) {
        printf("%d\t", b.num[i]);
    }
    putchar(10);
    STAFF sta[4] = {{"lulaoye",  20, 'x', 100},
                    {"xika",     30, 'o', 98},
                    {"xiaoxiao", 40, 'x', 78},
                    {"PDD",      33, 'o', 83}};

    for (int i = 0; i < sizeof(sta) / sizeof(sta[0]); i++) {
        printf("name = %s, age = %d, sex = %c, score = %.2f\n", sta[i].name, sta[i].age, sta[i].sex, sta[i].score);
        printf("name = %s, age = %d, sex = %c, score = %.2f\n", (*(sta + i)).name, (*(sta + i)).age, (*(sta + i)).sex,
               (*(sta + i)).score);
    }

    //结构体中嵌套结构体变量
    struct birthday {
        int year;
        int month;
        int day;
    };

    typedef struct student {
        char name[30];
        int age;
        char sex;
        float score;

        struct birthday birth;

    } Stu;

    Stu stus = {"yancq", 23, 'b', 87.9, {1994, 9, 10}};
    printf("%s’s birthday is %d 年 %d 月 %d 日 \n", stus.name, stus.birth.year, stus.birth.month, stus.birth.day);

    imagNum com1 = {1.2, 2.3};
    imagNum com2 = {2.5, 3.1};
    //做参数: struct 类型的变量,既可以传值(同类型的可以赋值),也可以传址(地址是开放的)。推荐传地址。
    imagNum res = addComplex(com1, com2);
    imagNum resP = addComplexPo(&com1, &com2);
    printf("res.real = %.2f, res.imag = %.2f\n", res.real, res.imag);
    printf("resP.real = %.2f, resP.imag = %.2f\n", resP.real, resP.imag);
    //获取当前时间函数的使用(localtime)
    time_t rawTime;
    time(&rawTime);

    struct tm * nowTime = localtime(&rawTime);
    //localtime函数之所以可以返回一个结构体指针,是因为localtime函数内部有一个静态(static)的struct tm 结构空间。
    /*
     *  struct tm {
     *
     * };
     *
     * struct tm * localtime(){
     *      static struct tm xxx;
     *      return &xxx;
     * }
     * */
    int week = nowTime->tm_wday;
    char * day[7];
    switch (week)
    {
        case 0:
            day[0] = "Sunday";
            break;
        case 1:
            day[1] = "Monday";
            break;
        case 2:
            day[2] = "Tuesday";
            break;
        case 3:
            day[3] = "Wednesday";
            break;
        case 4:
            day[4] = "Thursday";
            break;
        case 5:
            day[5] = "Friday";
            break;
        case 6:
            day[6] = "Saturday";
            break;
        default:
            break;
    }
    printf("Now Time is %d 年 %d 月 %d 日 %d 时 %d 分 %d 秒--%s\n", nowTime->tm_year + 1900, nowTime->tm_mon + 1,
           nowTime->tm_mday, nowTime->tm_hour, nowTime->tm_min, nowTime->tm_sec, day[nowTime->tm_wday]);
    //一个成员空间需要多个机器周期去读的现象叫做内存不对齐。内存对齐的本质是牺牲空间，换取时间。
    /*一、对齐原则：
     * 1.结构体内成员按自身按自身长度自对齐。
     * 自身长度，如char=1，short=2，int=4，double=8。所谓自对齐，指的是该成员的起始位置的内存地址必须是它自身长度的整数倍。
     * 如int只能以0,4,8这类的地址开始。
     * 2.结构体的总大小为结构体的有效对齐值的整数倍。
     *
     * 二、结构体的有效对齐值的确定：
     * 1）当未明确指定时，以结构体中最长的成员的长度为其有效值
     * 2）当用#pragma pack(n)指定时，以n和结构体中最长的成员的长度中较小者为其值。
     * 3）当用__attribute__ ((__packed__))指定长度时，强制按照此值为结构体的有效对齐值。
     *
     * https://blog.csdn.net/xiong452980729/article/details/70140050
     *
     * */
    SIZE siz;
    printf("siz = %d\n", sizeof(siz));//8(内存对齐)
    //首成员在低地址,尾成员在高地址。
    printf("&siz = %p\n", &siz);//0x0028FB30
    printf("&siz.sex = %p\n", &siz.sex);//0x0028FB30
    printf("&siz.age = %p\n", &siz.age);//0x0028FB34


    return 0;
}