#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//����
#define M 7
#define N 6

//���ǻ����������ͣ����ɶ���ʱ��ʼ����Ҳ�����ȶ��壬�ٸ�ֵ(��ʼ��)��int a; a=1; ���� int a = 1;
//���ǹ������ͣ�Ҫô�ڶ���ʱ��ʼ���������ȶ��壬���Գ�ʼ���ķ�ʽ��ֵ��int array[10] = {0,1,2,3,4,5,6,7,8,9}
int main() {
    /*�������������ʼ��
    printf("sizeof(int[10]) = %d\n", sizeof(int[10]));
    int array[10] = {01, 11, 21, 31, 41, 51, 61, 71, 81, 91};
    printf("sizeof(array) = %d\n", sizeof(array));
    printf("sizeof(array[0]) = %d\n", sizeof(array[0]));
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n",i,array[i]);
        printf("&array[%d] = %p\n",i,&array[i]);//& ȡ��ַ
    }
     */


    /*���������ֵ
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


    /*����*/
#if 0
    //ѡ������
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
    //ѡ�������Ż����ȶ�������ֻ���±�
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
    //ð�ݷ�����
    int arr[] = {14, 1, 7, 88, 9, 6, 89, 43, 23, 53};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n - 1; i++) { //���ƱȽϼ��β����������
        for (int j = 0; j < n - 1 - i; j++) { //���αȽ����ڵ�����Ԫ��,ʹ�ϴ���Ǹ������
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
    //�۰����:�������ڲ���
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
    //������� ��ʼ�۰����
    int finddata = 88;//Ҫ���ҵ�����
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
     //������ ��ȥ�ء�
    int arr[] = {14, 1, 7, 14, 3, 43, 23, 9, 88, 9, 6, 89, 43, 23, 53};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n - 1; i++) { //���ƱȽϼ��β����������
        for (int j = 0; j < n - 1 - i; j++) { //���αȽ����ڵ�����Ԫ��,ʹ�ϴ���Ǹ������
            int tem;
            if (arr[j] > arr[j + 1]) {
                tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
            }
        }
    }

    int index = 1;//�±�
    int newArr[n];//��Ų��ظ�Ԫ�ص�����
    newArr[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {//�����ǰ������Ԫ�غ�ǰһ��Ԫ�ز����
            newArr[index++] = arr[i];//�浽newArr��
        }
    }
    for (int i = 0; i < index; i++) {
        printf("%d\t", newArr[i]);
    }
    */
    /*
    //��ά����: ����Ҳ��һά���飬ֻ�������������Ա����һ��һά���顣
    int array[3][4] = {{0}};// int[4] array[3],��int[4]����һ���������ͣ�16�ֽڣ�
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
            printf("%p\t", &array[i][j]);//��ַ�������ģ����ڴ��д洢��һά��
        }
        putchar(10);
    }
     */
    /*
    int arr[4][4] = {{1,  2,  3,  4},
                     {5,  6,  7,  8},
                     {9,  10, 11, 12},
                     {13, 14, 15, 16}};
    //��ӡ��ǰ��ά����
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        putchar(10);
    }
    //��ӡ��ǰ��ά�������Խ���
    for (int i = 0; i < 4; i++) {
        int t = i;
        while (t--)
            printf("\t");
        printf("%d\n", arr[i][i]);
    }
    putchar(10);
    //��ӡ��ǰ��ά����ζԽ���
    for (int i = 0; i < 4; i++) {
        int t = 3 - i;
        while (t--)
            printf("\t");
        printf("%d\n", arr[i][3 - i]);
    }
    putchar(10);
    //ת�ö�ά����
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
    //��ӡת�ú��ά����
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        putchar(10);
    }
    */
#if 0
    //���������壬���ж�һ������û��5������������
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
    //�ϲ������Ѿ��������鵽�����������У���ʹ����Ȼ��������
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






