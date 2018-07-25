#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

//����(Union)��ö��(Enum)
//��c�����У���ͬ�ĳ�Աʹ�ù�ͬ�Ĵ洢��������ݹ������ͳ�Ϊ�����塣
//�������ڶ��塢˵����ʹ����ʽ����ṹ�����ơ����ߵı����ϵĲ�ͬ������ʹ���ڴ�ķ�ʽ�ϡ�

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
    //�ڴ���ռ��С
    //���ڽṹ������,����������ڴ����,��ô�ṹ����ռ�ÿռ�Ĵ�СΪ����Ա��С֮�͡�
    //���ڹ���������,��������ռ�ÿռ�Ĵ�Сȡ��������Ա��ռ�Ĵ�С��
    printf("sizeof(union untest) = %d\n", sizeof(union untest));//4
    printf("sizeof(union structtest) = %d\n", sizeof(struct structtest));//8
    //��Ա����
    printf("&myst.c = %p, &myst.s = %p, &myst.i = %p\n", &myst.c, &myst.s, &myst.i);
    //&myst.c = 00407074, &myst.s = 00407076, &myst.i = 00407078(�ڴ����)

    printf("&myun.c = %p, &myun.s = %p, &myun.i = %p\n", &myun.c, &myun.s, &myun.i);
    //&myun.c = 00407070, &myun.s = 00407070, &myun.i = 00407070(ӵ�й�ͬ����ʼ��ַ)

    myun.i = 0x12345678;
    printf("myun.c = %x\n",myun.c);//78
    printf("myun.s = %x\n",myun.s);//5678
    printf("myun.i = %x\n",myun.i);//12345678

    //��Ч��: ���һ�β����ĳ�Ա���������.
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
    //����Ҫ�Ѳ�ͬ���͵ı�����ŷ���ͬһ���ڴ浥Ԫ���ͬһ���ڴ浥Ԫ�����ݰ��ղ�ͬ��������������Ҫʹ�ù��������ݽṹ��
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
    //ö�����Ͷ�����һ�����ͳ����ļ���
    //ö������һ������,�����е�Ԫ��(ö������)��һЩ���������ͱ���,Ԫ��֮���ö���(,)����
    //��һ��ö�ٳ�Ա��Ĭ��ֵΪ0,����ö�ٳ�Ա��ֵ��ǰһ����Ա�ϼ�1
    //������Ϊ���趨ö�ٳ�Ա��ֵ���Ӷ��Զ���ĳ����Χ�ڵ�����
    enum DAY {
        MON = 1, TUE, WED, THU, FRI, SAT, SUN
    };
    printf("%d %d %d %d %d %d %d\n", MON, TUE, WED, THU, FRI, SAT, SUN);

    enum DAY day = MON;
    printf("day = %d\n",day);
    //�ж�һ���125���ǹ����ջ�����Ϣ��(����һ��365��,��һ������һ)
    unsigned int today;
    printf("pls input today num:");
    scanf("%d",&today);
    today = today % 7;
    enum DAY weekendorholiday = today;//weekendorholiday���з�Χ�ģ�switch case ��䲻�ü�default��

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

    //����bool����(c��������û��bool���͵�)
    typedef enum BOOLEN{
        False,
        True
    } bool;

    bool true = True;
    bool false = False;

    return 0;
}