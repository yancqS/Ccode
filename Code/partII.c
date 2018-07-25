#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//数组
#define M 7
#define N 6

//凡是基本数据类型，即可定义时初始化，也可以先定义，再赋值(初始化)。int a; a=1; 或者 int a = 1;
//凡是构造类型，要么在定义时初始化。不能先定义，再以初始化的方式赋值。int array[10] = {0,1,2,3,4,5,6,7,8,9}
int main() {
    /*数组的声明、初始化
    printf("sizeof(int[10]) = %d\n", sizeof(int[10]));
    int array[10] = {01, 11, 21, 31, 41, 51, 61, 71, 81, 91};
    printf("sizeof(array) = %d\n", sizeof(array));
    printf("sizeof(array[0]) = %d\n", sizeof(array[0]));
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n",i,array[i]);
        printf("&array[%d] = %p\n",i,&array[i]);//& 取地址
    }
     */


    /*求数组的最值
    int arr[10] = {11,3,56,7,97,43,74,23,74,78};
    int min = arr[0];
    int max = arr[0];
    for(int i = 0; i<10; i++){
        if(arr[i] < min)
            min = arr[i];

        if(arr[i] > max)
            max = arr[i];
    }
    printf("min = %d, max = %d\n", min, max);
     */


    /*排序*/
#if 0
    //选择法排序
    int arr[10] = {14, 1, 7, 88, 9, 6, 89, 43, 23, 53};
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            int tmp;
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
#endif


#if 0
    //选择法排序优化，比而不换，只记下标
    int arr[] = {14, 2, 7, 88, 9, 6, 89, 43, 23, 53};
    int n = sizeof(arr) / sizeof(int);

    for(int i = 0; i < n-1; i++){
        int tmp,idx = i;
        for(int j = i+1; j < n;j++){
            if(arr[idx] > arr[j]){
                idx = j;
            }
        }
        if(idx != i){
            tmp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = tmp;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
#endif


#if 0
    //冒泡法排序
    int arr[] = {14, 1, 7, 88, 9, 6, 89, 43, 23, 53};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n - 1; i++) { //控制比较几次才能完成排序
        for (int j = 0; j < n - 1 - i; j++) { //依次比较相邻的两个元素,使较大的那个向后移
            int tem;
            if(arr[j] > arr[j+1]){
                tem = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tem;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
#endif


#if 0
    //折半查找:先排序，在查找
    int arr[10] = {14, 1, 7, 88, 9, 6, 89, 43, 23, 53};
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            int tmp;
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    //排序结束 开始折半查找
    int finddata = 88;//要查找的数据
    int idx = -1;
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (finddata == arr[mid]) {
            idx = mid;
            break;
        }
        if (finddata > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (idx == -1) {
        printf("find none in arr");
    } else {
        printf("find %d in arr[%d]", finddata, idx);
    }
#endif


    /*
     //先排序 再去重。
    int arr[] = {14, 1, 7, 14, 3, 43, 23, 9, 88, 9, 6, 89, 43, 23, 53};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n - 1; i++) { //控制比较几次才能完成排序
        for (int j = 0; j < n - 1 - i; j++) { //依次比较相邻的两个元素,使较大的那个向后移
            int tem;
            if (arr[j] > arr[j + 1]) {
                tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
            }
        }
    }

    int index = 1;//下标
    int newArr[n];//存放不重复元素的数组
    newArr[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {//如果当前遍历的元素和前一个元素不相等
            newArr[index++] = arr[i];//存到newArr中
        }
    }
    for (int i = 0; i < index; i++) {
        printf("%d\t", newArr[i]);
    }
    */
    /*
    //二维数组: 本质也是一维数组，只不过，其数组成员又是一个一维数组。
    int array[3][4] = {{0}};// int[4] array[3],把int[4]当作一种数据类型（16字节）
    printf("sizeof(array[0]) = %d, sizeof(int[4]) = %d\n", sizeof(array[0]), sizeof(int[4]));
    printf("sizeof(array) = %d\n", sizeof(array));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", array[i][j]);
        }
        putchar(10);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%p\t", &array[i][j]);//地址是连续的，在内存中存储是一维的
        }
        putchar(10);
    }
     */
    /*
    int arr[4][4] = {{1,  2,  3,  4},
                     {5,  6,  7,  8},
                     {9,  10, 11, 12},
                     {13, 14, 15, 16}};
    //打印当前二维数组
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        putchar(10);
    }
    //打印当前二维数组主对角线
    for (int i = 0; i < 4; i++) {
        int t = i;
        while (t--)
            printf("\t");
        printf("%d\n", arr[i][i]);
    }
    putchar(10);
    //打印当前二维数组次对角线
    for (int i = 0; i < 4; i++) {
        int t = 3 - i;
        while (t--)
            printf("\t");
        printf("%d\n", arr[i][3 - i]);
    }
    putchar(10);
    //转置二维数组
    for (int i = 0; i < 4; i++) {
        int tmp;
        for (int j = 0; j < 4; j++) {
            if(i > j){
                tmp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = tmp;
            }
        }
    }
    //打印转置后二维数组
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        putchar(10);
    }
    */
#if 0
    //生成五子棋，并判断一行中有没有5个连续的棋子
    int chess[10][10] = {0};
    srand(time(NULL));
    int i, j;
    int count = 0;
    while (1) {
        i = rand() % 10;
        j = rand() % 10;

        if (chess[i][j] == 0) {
            chess[i][j] = 1;
            count++;
            if (count == 50)
                break;
        }
    }
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            printf("%d\t", chess[x][y]);
        }
        putchar(10);
    }

    for (int x = 0; x < 10; x++) {
        int idx = 0;
        int winid = 0;
        int flag = 0;
        for (int y = 0; y < 10; y++) {
            if(chess[x][y] == 1){
                flag = 1;
                winid++;
                idx++;
                if(winid >= 5)
                    break;
            } else{
                flag = 0;
                winid = 0;
            }
        }
        if(idx >= 5)
            printf("good chess in %d line\n", x);
        if(flag == 1 && winid >= 5)
            printf("\nnice chess in %d line\n\n",x);
    }
#endif
    //合并两个已经有序数组到第三个数组中，并使其依然保持有序
    int a[M] = {1, 3, 5, 6, 9,10,30};
    int b[N] = {2, 4, 7,8,11,24};
    int c[M + N];
    int ai = 0, bj = 0, ck = 0;
    while (ai < M && bj < N) {
        if (a[ai] < b[bj])
            c[ck++] = a[ai++];
        else
            c[ck++] = b[bj++];
    }

    if (ai == M) {
        while (bj < N) {
            c[ck++] = b[bj++];
        }
    }

    if (bj == N) {
        while (ai < M) {
            c[ck++] = a[ai++];
        }
    }

    for (int index = 0; index < M + N; index++) {
        printf("%d\t", c[index]);
    }

    return 0;
}






