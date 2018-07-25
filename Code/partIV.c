#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//����
//���Ƕ�����ǰ�������ں������������������ں󣬵�����ǰ����Ҫǰ��������
//returnType functionName([datatype name1][,datatype name2][,datatype name3]...){}
//��ֵ:�����ӵ��ÿռ䣬���������ÿռ���������޸�ϵ��
//��������ֻ����һ�������������ж����
//�����еı���������ʡ�ԣ������Ͳ����� int myMax(int , int );
int myMax(int x, int y);//ǰ������

int myMin(int x, int y) {//����
    return x < y ? x : y;
}

void addInt(int a) {
    a += 1;
}

void addAddre(int *pa) {
    (*pa)++;
}

//������򽻻�������
void swap(int *px, int *py) {
    *px ^= *py;
    *py ^= *px;
    *px ^= *py;
}

void selectSort(int *p, int n);

void popSort(int *p, int n);

int binarySearch(int * p, int low, int high, int find);

int getAge(int x);

int peach(int day);

int main() {
    /*�⺯����ʹ��
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int randRes = rand();
        printf("randRes = %d\n", randRes%100);//����0-100�������
    }
    double x = 1;
    double squareroot, power;
    while (x <= 10) {
        squareroot = sqrt(x);
        power = pow(x, 3);
        printf("%.0f ��ƽ������ %3.2f\t%.0f ������Ϊ %3.2f\n", x, squareroot, x, power);
        x++;
    }
     */
    //�Զ��庯��
#if 0
    int a = 3;
    int b = 5;
    int max = myMax(a, b);
    int min = myMin(a, b);
    printf("max = %d\n", max);
    printf("min = %d\n", min);

    addInt(a);
    printf("a = %d\n", a);

    addAddre(&a);
    printf("a = %d\n", a);

    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
#endif

    int arr[10] = {99, 33, 66, 22, 100, 300, 600, 350, 1, 2};
    int arrBin[10] = {34, 76, 25, 2, 10, 340, 690, 53, 12, 25};
    int arrPop[10] = {90, 30, 60, 20, 100, 300, 600, 350, 1, 2};
    int findDate = 340;


    printf("arrBin:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", arrBin[i]);
    }
    putchar(10);
    //���ֲ���
    int index = binarySearch(arrBin, 0, sizeof(arrBin) / sizeof(arrBin[0])-1, findDate);
    printf("arrBin Sort:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", arrBin[i]);
    }
    putchar(10);
    printf("%d in arr[%d]\n", findDate, index);
    printf("-------------------------------------------------------------------\n");

    printf("arr:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    putchar(10);
    //ѡ������
    selectSort(arr, sizeof(arr) / sizeof(arr[0]));

    printf("selecrSort arr:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    putchar(10);
    printf("-------------------------------------------------------------------\n");
    printf("arrPop:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", arrPop[i]);
    }
    putchar(10);
    //ð������
    popSort(arrPop, sizeof(arrPop) / sizeof(arrPop[0]));

    printf("PopSort arrPop:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", arrPop[i]);
    }
    putchar(10);

    //�ݹ����
    int age = getAge(5);
    printf("��5�����ӵ�����Ϊ%d\n", age);

    int count = peach(1);
    printf("���ӵ�һ��ժ����������Ϊ:%d\n", count);

    system("pause");
    return 0;

}

int myMax(int x, int y) {
    return x > y ? x : y;
}

//ѡ������
void selectSort(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                swap(&p[i], &p[j]);
            }
        }
    }
}

//ð������
void popSort(int *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[j] > p[j + 1]) {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}
//���ֲ���
int binarySearch(int * p, int low, int high, int find){
    popSort(p, high+1);
    while (high > low){
        int mid = (low + high)/2;
        if(p[mid] == find){
            return mid;
        }
        if(p[mid] > find){
            high = mid -1;
        } else{
            low = mid + 1;
        }
    }
}

//�ݹ�
int getAge(int x) {
    if (x == 1)
        return 10;
    else
        return getAge(x - 1) + 2;
}

int peach(int day) {
    if (day == 10)
        return 1;
    else
        return (peach(++day) + 1) * 2;
}