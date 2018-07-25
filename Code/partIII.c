#include <stdio.h>
#include <stdlib.h>
//指针
int main() {
    /*
    char a = 1;
    short b = 2;
    int c = 3;
    long long d = 4;
    float e = 1.2;
    double f = 2.3;
    printf("&a = %p\n", &a);// 取出地址为: 0028FF3F
    printf("&b = %p\n", &b);// 取出地址为: 0028FF3C
    printf("&c = %p\n", &c);// 取出地址为: 0028FF38
    printf("&d = %p\n", &d);// 取出地址为: 0028FF30
    printf("&e = %p\n", &e);// 取出地址为: 0028FF2C
    printf("&f = %p\n", &f);// 取出地址为: 0028FF20
    printf("&f = %p\n", &f);// 取出地址为: 0028FF20
    //指针是有类型的地址常量
    printf("===============\n");
    printf("a = %d\n",*(&a));//&a == (char*)0x0028FF3F   &a进行取地址，取出来的地址是有类型的。
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
    //类型不同，大小相同，均为4个字节
    //对于32位地址总线，任何一个地址都是32位 也就是4个字节。上面取出来地址的是16进制，化为二进制就是32位(0和1组成)
    printf("sizeof(&a) = %d\n", sizeof(&a));//4
    printf("sizeof(&b) = %d\n", sizeof(&b));//4
    printf("sizeof(&c) = %d\n", sizeof(&c));//4
    printf("sizeof(&d) = %d\n", sizeof(&d));//4
    printf("sizeof(&e) = %d\n", sizeof(&e));//4
    printf("sizeof(&f) = %d\n", sizeof(&f));//4
     //指针的类型决定了该指针的寻址能力
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
    int *p = &a;//p 指针变量, 存放a的地址
    printf("*p = %d\n", *p);
    printf("a = %d\n", a);
    *p = 200;//向指针 p 指向的内存地址中写入数据。
    printf("*p = %d\n", *p);
    printf("a = %d\n", a);
    int b = 300;
    p = &b;//又把b的地址 存放到指针变量 p
    printf("*p = %d\n",*p);
    */
    /*
    int var = 10;
    int *ptr_var;
    ptr_var = &var;
    printf("var 的值是: %d\n", var);//var 的值是: 10
    printf("var 的内存地址是: %x\n", &var);//var 的内存地址是: 28ff3c
    printf("指针 ptr_var 的内存地址是: %x\n", &ptr_var);//指针 ptr_var 的内存地址是: 28ff38
    printf("var 的值是: %d\n", *ptr_var);//var 的值是: 10
    printf("var 的内存地址是: %x\n", ptr_var);//var 的内存地址是: 28ff3c
    */
    /*指针运算
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
    //& * 并不是单纯的取地址 和 取内容。(引用 和 解引用)
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
     * a是数组首元素的地址，所以a的值和&a[0]的值相同。另一方面，a[0]本身也是包含4个整数的数组
     * 因此，a[0]的值同其首元素地址&a[0][0]相同。简单的讲,a[0]是一个整数大小对象的地址,而a是4个整数大小对象的
     * 地址。因为整数和4个整数组成的数组开始于同一个地址，因此a和a[0]的值是相同的。
     *
     * a所指的对象大小是4个int, 而a[0]所指的对象大小是1个int, 因此, a + 1 和 a[0] + 1 的结果是不同的。
     *
     * 二维数组名解引用,降维为一维数组名  *(a+1) <> a[1]
     * 一维数组名，对其引用，升级为二维数组名  &a[1] <> (a+1)
     * &引用 和 *解引用互为逆向关系。
     * */
    return 0;
}