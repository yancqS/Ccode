#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

//ջ(stack)�ڴ棬Ĭ�ϲ�����2-10M֮�䡣ջ�д���������͵ı�������������auto�������εģ����Զ����͵ľֲ�������
//�ص�: �����濪,���꼴����
//�ֲ��������󣬹��� �� �ݹ����̫�� �ᵼ��ջ�����

//�ص��Ƕ�(heap)�ڴ�.���ڴ���Դ���������͵����ݣ�����Ҫ�Լ��������ͷ�

int main() {
#if 0
    int a;
    int *p = &a;//ָ�����p�Ǵ洢��ջ�ڴ�ģ�pָ��Ҳָ��ջ�ڴ档
    *p = 200;
    printf("*p = %d\n", *p);
    //����malloc(size_t_Size)������ڴ�ռ䲢����,��������ɹ��򷵻طǿ�ָ��ָ������Ŀռ�,ʧ�ܷ���NULL
    int * pm = (int *) malloc(sizeof(int) * 100);//ָ�����pm�Ǵ洢��ջ�ڴ�ģ�����pmָ��ָ����ڴ档
    if (pm == NULL)
        return -1;
    *pm = 100;
    for (int i = 1; i <= 100; i++) {
        pm[i] = i;
        printf("%d\t", *(pm + i));
        if(i%10 == 0)
            printf("\n");
    }
    free(pm);//�ͷ�����Ķ��ڴ�
#endif
#if 0
    //����calloc(size_t nmemb,size_t size)������ڴ�ռ䲢����,������Ŀռ��Զ�����
    //size_t nmemb�����ڴ浥Ԫ����,size_t size�ڴ浥Ԫ��С��
    //��������ɹ��򷵻طǿ�ָ��ָ������Ŀռ�,ʧ�ܷ���NULL
    int * array = (int *)calloc(10, sizeof(int));
    for(int j = 0; j<10; j++){
        printf("%d\t", array[j]);//�ѱ���ʼ��Ϊ0
    }
#endif
    /*
    char * arr = realloc(NULL,100); //��ͬ�� malloc(100);
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
    //�䳤����
    int size;
    printf("���������鳤��:");
    scanf("%d", &size);
    int *pa = (int *) calloc(size, 4);//����ռ�
    for (int i = 0; i < size; i++) {
        *(pa + i) = i;
        printf("%d\t", *(pa + i));
    }
    putchar(10);

    int newSize;
    printf("�����������鳤��:");
    scanf("%d", &newSize);
    pa = (int *) realloc(pa, newSize * 4);//��չ�ռ�
    for (int i = size; i < newSize; i++) {
        *(pa + i) = 100;
    }

    for (int i = 0; i < newSize; i++) {
        printf("%d\t", *(pa + i));
    }
    putchar(10);
    free(pa);//ָ��paָ��Ŀռ��ڴ汻�ͷţ�����pa��ָ�ĵ�ַ��Ȼ����
    pa = NULL;//���Ҫ��ָ��pa�ÿ�(NULL)
    system("pause");

    return 0;
}