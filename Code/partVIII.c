#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <time.h>

//�ṹ��:�����Ա����Ҫ�������ͣ���Ա��Сͳһ�����Բ����׵�ַ��ƫ������ʾ��
//�����ڽṹ����˵�����ʹ�С����ͳһ�����Բ��õĳ�Ա����������з��ʡ�
//��Ա���������ֲ�ͬ��Ա�ı�ʶ��
//ÿһ���������Ͷ�Ҫ��������������ͷ��ʡ�

//��struct����������������
struct Array {
    int a;
    int b;
};//�൱�� int a[2]
#if 0
//�ṹ�� ���� �Ķ���. �ṹ������ ��λ �� int��ͬ
//�����ṹ��: һ������,�ദʹ��
struct student {
    char name[100];
    int age;
    char sex;
    float score;
};//�����ͬʱ��ʼ�� or �ȶ����������ʼ��

//�����ṹ��: �������µ�����
struct {
    char name[100];
    int age;
    char sex;
    float score;
} person;//�ȶ����������ʼ��
#endif
//����������(����)
typedef struct staff {
    char name[100];
    int age;
    char sex;
    float score;
} STAFF;//�����ͬʱ��ʼ�� or �ȶ����������ʼ��

//�ṹ�������������ͷ���ֵ
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

    //���ǻ����������ͣ����ɶ���ʱ��ʼ����Ҳ�����ȶ��壬�ٸ�ֵ(��ʼ��)��
    // int a; a=1; ���� int a = 1;
    //���ǹ������ͣ�Ҫô�ڶ���ʱ��ʼ���������ȶ��壬���Գ�ʼ���ķ�ʽ��ֵ��Ҳ���Էֱ������ʼ����arr[0] = 0;arr[1] = 1;...
    // int array[10] = {0,1,2,3,4,5,6,7,8,9}�������ǹ������ͣ��ṹ��Ҳ�ǹ������͡�

    //�����ͬʱ��ʼ��
    STAFF sta1 = {"zhangsan", 20, 'o', 78.98};
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", sta1.name, sta1.age, sta1.sex, sta1.score);

    //�ȶ����������ʼ��
    strcpy(sta1.name, "lisi");
    //sta1.name = "lisi";�����Ǵ���ġ�����"lisi"������һ����ַ(ָ�����ݶ�ֻ�����ݶ�),
    //name���ַ����������������һ����ַ�����������ٿռ���׵�ַ��
    sta1.age = 40;
    sta1.sex = 'x';
    sta1.score = 45.08;
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", sta1.name, sta1.age, sta1.sex, sta1.score);
#if 0
    //������ķ�ʽ��ʼ��
    printf("����������:");
    scanf("%s", sta1.name);
    printf("����������:");
    scanf("%d",&sta1.age);
    getchar();  //%cǰ����һ���س�
    printf("�������Ա�:");
    scanf("%c",&sta1.sex);
    printf("������ɼ�:");
    scanf("%f",&sta1.score);
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", sta1.name, sta1.age, sta1.sex, sta1.score);
#endif
    //���Ϸ����� ���Ա�����(sta1.xxx) ���ȼ��ܸߣ���()�����ȼ�һ��
    //�������ָ���Ա�����(-> (*).)   ���ȼ��ܸߣ���()�����ȼ�һ��
    STAFF sta2 = {"yancq", 20, 'o', 78.98};
    STAFF *ps = &sta2;
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", ps->name, ps->age, ps->sex, ps->score);

    strcpy(ps->name, "sungq");
    ps->age = 18;
    ps->sex = 'x';
    ps->score = 98.97;
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", ps->name, ps->age, ps->sex, ps->score);
#if 0
    printf("����������:");
    scanf("%s", ps->name);
    printf("����������:");
    scanf("%d", &ps->age);
    getchar();
    printf("�������Ա�:");
    scanf("%c", &ps->sex);
    printf("���������:");
    scanf("%f", &ps->score);
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", ps->name, ps->age, ps->sex, ps->score);

    ps = (STAFF *) malloc(sizeof(STAFF));
    printf("����������:");
    scanf("%s", ps->name);
    printf("����������:");
    scanf("%d", &ps->age);
    getchar();
    printf("�������Ա�:");
    scanf("%c", &ps->sex);
    printf("���������:");
    scanf("%f", &ps->score);
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).score);
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", ps->name, ps->age, ps->sex, ps->score);
#endif
    STAFF cpy = sta2;//ͬ���͸�ֵ
    printf("name = %s, age = %d, sex = %c, score = %.2f\n", cpy.name, cpy.age, cpy.sex, cpy.score);

    typedef struct arr {
        int num[10];
    } ARRAY;

    ARRAY array = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}};
    ARRAY b = array;//ʵ�����鿽��
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

    //�ṹ����Ƕ�׽ṹ�����
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
    printf("%s��s birthday is %d �� %d �� %d �� \n", stus.name, stus.birth.year, stus.birth.month, stus.birth.day);

    imagNum com1 = {1.2, 2.3};
    imagNum com2 = {2.5, 3.1};
    //������: struct ���͵ı���,�ȿ��Դ�ֵ(ͬ���͵Ŀ��Ը�ֵ),Ҳ���Դ�ַ(��ַ�ǿ��ŵ�)���Ƽ�����ַ��
    imagNum res = addComplex(com1, com2);
    imagNum resP = addComplexPo(&com1, &com2);
    printf("res.real = %.2f, res.imag = %.2f\n", res.real, res.imag);
    printf("resP.real = %.2f, resP.imag = %.2f\n", resP.real, resP.imag);
    //��ȡ��ǰʱ�亯����ʹ��(localtime)
    time_t rawTime;
    time(&rawTime);

    struct tm * nowTime = localtime(&rawTime);
    //localtime����֮���Կ��Է���һ���ṹ��ָ��,����Ϊlocaltime�����ڲ���һ����̬(static)��struct tm �ṹ�ռ䡣
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
    printf("Now Time is %d �� %d �� %d �� %d ʱ %d �� %d ��--%s\n", nowTime->tm_year + 1900, nowTime->tm_mon + 1,
           nowTime->tm_mday, nowTime->tm_hour, nowTime->tm_min, nowTime->tm_sec, day[nowTime->tm_wday]);
    //һ����Ա�ռ���Ҫ�����������ȥ������������ڴ治���롣�ڴ����ı����������ռ䣬��ȡʱ�䡣
    /*һ������ԭ��
     * 1.�ṹ���ڳ�Ա�������������Զ��롣
     * �����ȣ���char=1��short=2��int=4��double=8����ν�Զ��룬ָ���Ǹó�Ա����ʼλ�õ��ڴ��ַ�������������ȵ���������
     * ��intֻ����0,4,8����ĵ�ַ��ʼ��
     * 2.�ṹ����ܴ�СΪ�ṹ�����Ч����ֵ����������
     *
     * �����ṹ�����Ч����ֵ��ȷ����
     * 1����δ��ȷָ��ʱ���Խṹ������ĳ�Ա�ĳ���Ϊ����Чֵ
     * 2������#pragma pack(n)ָ��ʱ����n�ͽṹ������ĳ�Ա�ĳ����н�С��Ϊ��ֵ��
     * 3������__attribute__ ((__packed__))ָ������ʱ��ǿ�ư��մ�ֵΪ�ṹ�����Ч����ֵ��
     *
     * https://blog.csdn.net/xiong452980729/article/details/70140050
     *
     * */
    SIZE siz;
    printf("siz = %d\n", sizeof(siz));//8(�ڴ����)
    //�׳�Ա�ڵ͵�ַ,β��Ա�ڸߵ�ַ��
    printf("&siz = %p\n", &siz);//0x0028FB30
    printf("&siz.sex = %p\n", &siz.sex);//0x0028FB30
    printf("&siz.age = %p\n", &siz.age);//0x0028FB34


    return 0;
}