#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

//栈(stack)内存，默认不大在2-10M之间。栈中存放任意类型的变量，但必须是auto类型修饰的，即自动类型的局部变量。
//特点: 随用随开,用完即消。
//局部变量过大，过多 或 递归层数太多 会导致栈溢出。

//重点是堆(heap)内存.堆内存可以存放任意类型的数据，但需要自己申请与释放

int main() {
#if 0
    int a;
    int *p = &a;//指针变量p是存储在栈内存的，p指针也指向栈内存。
    *p = 200;
    printf("*p = %d\n", *p);
    //函数malloc(size_t_Size)申请堆内存空间并返回,若是申请成功则返回非空指针指向申请的空间,失败返回NULL
    int * pm = (int *) malloc(sizeof(int) * 100);//指针变量pm是存储在栈内存的，但是pm指针指向堆内存。
    if (pm == NULL)
        return -1;
    *pm = 100;
    for (int i = 1; i <= 100; i++) {
        pm[i] = i;
        printf("%d\t", *(pm + i));
        if(i%10 == 0)
            printf("\n");
    }
    free(pm);//释放申请的堆内存
#endif
#if 0
    //函数calloc(size_t nmemb,size_t size)申请堆内存空间并返回,所申请的空间自动清零
    //size_t nmemb所需内存单元数量,size_t size内存单元大小。
    //若是申请成功则返回非空指针指向申请的空间,失败返回NULL
    int * array = (int *)calloc(10, sizeof(int));
    for(int j = 0; j<10; j++){
        printf("%d\t", array[j]);//已被初始化为0
    }
#endif
    /*
    char * arr = realloc(NULL,100); //等同于 malloc(100);
    if(NULL == arr)
        return -1;
    char * newArr = realloc(arr, 200);
    if(NULL == newArr){
        printf("realloc error");
        return -1;
    }
    strcpy(newArr, "china is my home");
    printf("%s\n",newArr);
    */
    //变长数组
    int size;
    printf("请输入数组长度:");
    scanf("%d", &size);
    int *pa = (int *) calloc(size, 4);//申请空间
    for (int i = 0; i < size; i++) {
        *(pa + i) = i;
        printf("%d\t", *(pa + i));
    }
    putchar(10);

    int newSize;
    printf("请输入新数组长度:");
    scanf("%d", &newSize);
    pa = (int *) realloc(pa, newSize * 4);//扩展空间
    for (int i = size; i < newSize; i++) {
        *(pa + i) = 100;
    }

    for (int i = 0; i < newSize; i++) {
        printf("%d\t", *(pa + i));
    }
    putchar(10);
    free(pa);//指针pa指向的空间内存被释放，但是pa所指的地址仍然不变
    pa = NULL;//因此要将指针pa置空(NULL)
    system("pause");

    return 0;
}