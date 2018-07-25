#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//函数
//若是定义在前，调用在后，则会正常。如果定义在后，调用在前，需要前向声明。
//returnType functionName([datatype name1][,datatype name2][,datatype name3]...){}
//传值:变量从调用空间，传到被调用空间后，两者在无干系。
//函数定义只能有一个，声明可以有多个。
//声明中的变量名可以省略，但类型不可以 int myMax(int , int );
int myMax(int x, int y);//前向声明

int myMin(int x, int y) {//定义
    return x < y ? x : y;
}

void addInt(int a) {
    a += 1;
}

void addAddre(int *pa) {
    (*pa)++;
}

//利用异或交换两个数
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
    /*库函数的使用
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int randRes = rand();
        printf("randRes = %d\n", randRes%100);//产生0-100的随机数
    }
    double x = 1;
    double squareroot, power;
    while (x <= 10) {
        squareroot = sqrt(x);
        power = pow(x, 3);
        printf("%.0f 的平方根是 %3.2f\t%.0f 的立方为 %3.2f\n", x, squareroot, x, power);
        x++;
    }
     */
    //自定义函数
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
    //二分查找
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
    //选择排序
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
    //冒泡排序
    popSort(arrPop, sizeof(arrPop) / sizeof(arrPop[0]));

    printf("PopSort arrPop:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", arrPop[i]);
    }
    putchar(10);

    //递归调用
    int age = getAge(5);
    printf("第5个孩子的年龄为%d\n", age);

    int count = peach(1);
    printf("猴子第一天摘得桃子数量为:%d\n", count);

    system("pause");
    return 0;

}

int myMax(int x, int y) {
    return x > y ? x : y;
}

//选择排序
void selectSort(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                swap(&p[i], &p[j]);
            }
        }
    }
}

//冒泡排序
void popSort(int *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[j] > p[j + 1]) {
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}
//二分查找
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

//递归
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