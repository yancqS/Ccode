#include <stdio.h>
#include <stdlib.h>
//ָ��
int main() {
    /*
    char a = 1;
    short b = 2;
    int c = 3;
    long long d = 4;
    float e = 1.2;
    double f = 2.3;
    printf("&a = %p\n", &a);// ȡ����ַΪ: 0028FF3F
    printf("&b = %p\n", &b);// ȡ����ַΪ: 0028FF3C
    printf("&c = %p\n", &c);// ȡ����ַΪ: 0028FF38
    printf("&d = %p\n", &d);// ȡ����ַΪ: 0028FF30
    printf("&e = %p\n", &e);// ȡ����ַΪ: 0028FF2C
    printf("&f = %p\n", &f);// ȡ����ַΪ: 0028FF20
    printf("&f = %p\n", &f);// ȡ����ַΪ: 0028FF20
    //ָ���������͵ĵ�ַ����
    printf("===============\n");
    printf("a = %d\n",*(&a));//&a == (char*)0x0028FF3F   &a����ȡ��ַ��ȡ�����ĵ�ַ�������͵ġ�
    printf("b = %d\n",*(&b));//&b == (short*)0x0028FF3C
    printf("c = %d\n",*(&c));//&c == (int*)0x0028FF38
    printf("d = %lld\n",*(&d));//&d == (long long*)0x0028FF30
    printf("e = %.2f\n",*(&e));//&e == (float*)0x0028FF2C
    printf("f = %.2f\n",*(&f));//&f == (double*)0x0028FF20
    printf("===============\n");
    printf("a = %d\n",*((char*)0x0028FF3F));
    printf("b = %d\n",*((short*)0x0028FF3C));
    printf("c = %d\n",*((int*)0x0028FF38));
    printf("d = %lld\n",*((long long*)0x0028FF30));
    printf("e = %.2f\n",*((float*)0x0028FF2C));
    printf("f = %.2f\n",*((double*)0x0028FF20));
    printf("===============\n");
    //���Ͳ�ͬ����С��ͬ����Ϊ4���ֽ�
    //����32λ��ַ���ߣ��κ�һ����ַ����32λ Ҳ����4���ֽڡ�����ȡ������ַ����16���ƣ���Ϊ�����ƾ���32λ(0��1���)
    printf("sizeof(&a) = %d\n", sizeof(&a));//4
    printf("sizeof(&b) = %d\n", sizeof(&b));//4
    printf("sizeof(&c) = %d\n", sizeof(&c));//4
    printf("sizeof(&d) = %d\n", sizeof(&d));//4
    printf("sizeof(&e) = %d\n", sizeof(&e));//4
    printf("sizeof(&f) = %d\n", sizeof(&f));//4
     //ָ������;����˸�ָ���Ѱַ����
    int data = 0x12345678;
    printf("%d\n",data);
    printf("%d\n",*(&data));
    printf("%x\n",*(&data));//12345678
    printf("%x\n",*((char*)&data));//78
    printf("%x\n",*((short*)&data));//5678
    printf("%x\n",*((int*)&data));//12345678
     */
    /*
    int a = 100;
    int *p = &a;//p ָ�����, ���a�ĵ�ַ
    printf("*p = %d\n", *p);
    printf("a = %d\n", a);
    *p = 200;//��ָ�� p ָ����ڴ��ַ��д�����ݡ�
    printf("*p = %d\n", *p);
    printf("a = %d\n", a);
    int b = 300;
    p = &b;//�ְ�b�ĵ�ַ ��ŵ�ָ����� p
    printf("*p = %d\n",*p);
    */
    /*
    int var = 10;
    int *ptr_var;
    ptr_var = &var;
    printf("var ��ֵ��: %d\n", var);//var ��ֵ��: 10
    printf("var ���ڴ��ַ��: %x\n", &var);//var ���ڴ��ַ��: 28ff3c
    printf("ָ�� ptr_var ���ڴ��ַ��: %x\n", &ptr_var);//ָ�� ptr_var ���ڴ��ַ��: 28ff38
    printf("var ��ֵ��: %d\n", *ptr_var);//var ��ֵ��: 10
    printf("var ���ڴ��ַ��: %x\n", ptr_var);//var ���ڴ��ַ��: 28ff3c
    */
    /*ָ������
    char *p = (char *)0x10000;
    printf("%x\n", p);//10000
    printf("%x\n", p+1);//10001
    printf("%x\n", p+5);//10005
    printf("=============\n");
    int *q = (int *)0x20000;
    printf("%x\n",q);//20000
    printf("%x\n",q+1);//20004
    printf("%x\n",q+5);//20014
    printf("=============\n");
    printf("%x\n",++p);//10001
    printf("%x\n",q++);//20000
    printf("%x\n",p);//10001
    printf("%x\n",q);//20004
    */
    /*
    int a = 0x00000;
    int b = 0x00020;
    printf("b - a = %d\n", b-a);//32

    int *pa = (int*)0x00000;
    int *pb = (int*)0x00020;
    printf("pb - pa = %d\n", pb-pa);//8
    */
    /*
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p;
    p = a;
    for (int i = 0; i < 10; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n========================\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", *(a+i));
    }
    printf("\n========================\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", *p++);
    }
    printf("\n========================\n");
    p = a;
    for (int i = 0; i < 10; i++) {
        printf("%d\t", p[i]);
    }
     */

    //int a[3][4] => int[4] a[3]
    int a[3][4] = {{1, 2,  3,  4},
                   {5, 6,  7,  8},
                   {9, 10, 11, 12}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%p\n", &a[i][j]);
        }
    }
    printf("\n========================\n");
    printf("a = %p a+1 = %p a+2 = %p\n", a, a + 1, a + 2);
    //& * �����ǵ�����ȡ��ַ �� ȡ���ݡ�(���� �� ������)
    printf("a = %p &a[0] = %p\n", a, &a[0]);
    printf("a[0] = %p a[0]+1 = %p a[0]+2 = %p\n", a[0], a[0] + 1, a[0] + 2);
    printf("\n========================\n");
    printf("a + 1 = %p (a + 1) + 1 = %p\n", a + 1, (a + 1) + 1);
    printf("a[1]  = %p a[1] + 1    = %p", a[1], a[1] + 1);
    printf("\n========================\n");
    printf("a + 1 = %p *(a + 1) + 1 = %p\n", a + 1, *(a + 1) + 1);
    printf("a[1]  = %p &a[1] + 1    = %p\n", a[1], &a[1] + 1);

    for(int m = 0;m<3;m++){
        for(int n = 0; n<4 ;n++){
            printf("%d\t",*(*(a+m)+n));
        }
        putchar(10);
    }
    /*
     *int a[3][4] => int[4] a[3]
     * a��������Ԫ�صĵ�ַ������a��ֵ��&a[0]��ֵ��ͬ����һ���棬a[0]����Ҳ�ǰ���4������������
     * ��ˣ�a[0]��ֵͬ����Ԫ�ص�ַ&a[0][0]��ͬ���򵥵Ľ�,a[0]��һ��������С����ĵ�ַ,��a��4��������С�����
     * ��ַ����Ϊ������4��������ɵ����鿪ʼ��ͬһ����ַ�����a��a[0]��ֵ����ͬ�ġ�
     *
     * a��ָ�Ķ����С��4��int, ��a[0]��ָ�Ķ����С��1��int, ���, a + 1 �� a[0] + 1 �Ľ���ǲ�ͬ�ġ�
     *
     * ��ά������������,��άΪһά������  *(a+1) <> a[1]
     * һά���������������ã�����Ϊ��ά������  &a[1] <> (a+1)
     * &���� �� *�����û�Ϊ�����ϵ��
     * */
    return 0;
}