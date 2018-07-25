#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//基本数据类型、运算符与表达式、程序结构设计
int main() {
    /*类型大小
    printf("sizeof(char) = %d => 字符类型\n", sizeof(char));//1
    printf("sizeof(short) = %d => 短整型\n", sizeof(short));//2
    printf("sizeof(int) = %d => 整型\n", sizeof(int));//4
    printf("sizeof(long int) = %d => 长整型\n", sizeof(long int));//4
    printf("sizeof(long long) = %d => long long\n", sizeof(long long));//8
    printf("sizeof(float) = %d => 单精度浮点型\n", sizeof(float));//4
    printf("sizeof(double) = %d => 双精度浮点型\n", sizeof(double));//8
    printf("sizeof(long double) = %d => long double\n", sizeof(long double));//12
     */

    /*单双精度位数
    float fvar = 2.1234567891234;
    double dvar = 2.1234567891234;
    printf("fvar = %.13f\n", fvar);//保证前7为精度，后面的几位发生变化. fvar = 2.1234567165375
    printf("dvar = %.13f\n", dvar);//精度15-16.   dvar = 2.1234567891234
     */

    /*ASCII表
    unsigned char a;
    for (a=0; a < 128; a++) {
        printf("%c=>%d\t\t", a,a);
        if(a%8 == 0){
            printf("\n");
        }
    }
    return 0;
     */
#if 0
    另一种注释方式(转义字符)
    printf("i like \"football\"\n");
    printf("the rate is %d%%",90);
    printf("aaaaaaaa\rbb\n");
    printf("aaaaaaaa\r\nbb\n");
    printf("aaaaaaaa\tbb\n");
    printf("aaaaa\xd bbbbbb\n"); \xd 十六进制 13 => \r对应的ascii码
    printf("aaaaa\11 bbbbbb\n"); \11 八进制 9 => \t对应的ascii码
#endif
    /*
    格式输出
   int var = 1234;
   printf("十进制=%d, 八进制=%o, 十六进制=%x\n", var,var,var);
   //十进制=1234, 八进制=2322, 十六进制=4d2
   printf("十进制=%d, 八进制=%#o, 十六进制=%#x\n", var,var,var);
   //十进制=1234, 八进制=02322, 十六进制=0x4d2
   printf("==============\n");
   printf("%10d\n", var);//       1234
   printf("%010d\n", var);//0000001234
   printf("%1d\n", var);//1234
   printf("%-10d\n", var);//1234      (后面有6空格)
   printf("==============\n");
   printf("%+d\n", var);//1234
   var = -var;
   printf("%+d\n", var);//-1234
   printf("==============\n");
   var = -1;
   printf("%d\n", var);//-1
   printf("%u\n", var);//4294967295
   printf("==============\n");
   char c = '\x41';
   printf("%c\n", c);//A
   printf("%d\n", c);//65
   printf("%x\n", c);//41
   printf("%#x\n", c);//0x41
   printf("==============\n");
   float f = 123.4567;
   printf("%f\n", f);//123.456703
   printf("%7.2f\n", f);// 123.46(右对齐空格补)
   printf("%07.2f\n", f);//0123.46(右对齐0补)
   printf("%-7.2f\n", f);//123.46
   printf("%e\n", f);//1.234567e+002
   printf("%g\n", f);//123.457
    */
    /*
    格式输入
   int a, b, c;
   scanf("%d%d%d",&a,&b,&c);
   printf("a = %d, b = %d, c = %d\n",a, b, c);
    */
    /*
     * 类型转化: int -> long long -> float -> double(优先级)
    char a; short b; int c;
    long long d; float e; double f;
    printf("sizeof(a) = %d\n", sizeof(a));//sizeof(a) = 1
    printf("sizeof(b) = %d\n", sizeof(b));//sizeof(b) = 2
    printf("sizeof(c) = %d\n", sizeof(c));//sizeof(c) = 4
    printf("sizeof(d) = %d\n", sizeof(d));//sizeof(d) = 8
    printf("sizeof(e) = %d\n", sizeof(e));//sizeof(e) = 4
    printf("sizeof(f) = %d\n", sizeof(f));//sizeof(f) = 8

    printf("sizeof(a+b) = %d\n", sizeof(a+b));//4 整型提升：char short int 等类型在一起运算时，首先提升到int.
    printf("sizeof(a+c) = %d\n", sizeof(a+c));//4
    printf("sizeof(b+c) = %d\n", sizeof(b+c));//4
    printf("sizeof(a+d) = %d\n", sizeof(a+d));//8
    printf("sizeof(d+e) = %d\n", sizeof(d+e));//4 注意：long long(8) + float(4) -> float(4)
    printf("sizeof(d+f) = %d\n", sizeof(d+f));//8
    printf("sizeof(a+f) = %d\n", sizeof(a+f));//8

    c = 3;
    e = 5.6;
    printf("%f\n", c+e);//%d 会乱码 类型不匹配 int+float -> float
    */
    /*强制转化
    int a = 3;
    int b = 10;
    float c = b / a; //3.000000
    float d = (float) b / a; //强制转化==> (float) b 10.0 再除a ==> 10.0/3 = 3.333333
    printf("c = %f, d = %f\n", c, d);
     */
    /*运算符与表达式
    int a = 3, b = 5;
    printf("7/3 = %d, -7/3 = %d, 7/-3 = %d\n", 7/3, -7/3, 7/-3);
    printf("7%%3 = %d, -7%%3 = %d, 7%%-3 = %d\n", 7%3, -7%3, 7%-3);//被除数/除数 -> 余数的正负与被除数一致
    printf("express a == b value = %d\n", a==b);
    printf("express a != b value = %d\n", a!=b);
    */
    /*
    int a;
    a = 1, 2, 3, 4, 5, 6;//逗号表达式的优先级最低，所以a = 1 赋值表达式优先于 逗号表达式
    printf("a = %d\n", a);//1

    a = (1, 2, 3, 4, 5, 6);//加个括号先算完里面的逗号表达式 在赋值给a。整个逗号表达式的值等于最后一个表达式的值。
    printf("a = %d\n", a);//6
     */
    /*
    unsigned char a;
    printf("pls input a char:");
    scanf("%c",&a);
    if(a >= 'a' && a <= 'z'){
        printf("%c in a-z\n", a);
        system("pause");
    }else{
        printf("no no no");
    }
     */
    /*判断闰年
    int year;
    printf("input a year: ");
    scanf("%d", &year);
    if (year % 4 == 0 && year % 100 != 0) {
        printf("普通闰年");
        system("pause");
    } else if (year % 400 == 0) {
        printf("世纪闰年");
        system("pause");
    } else {
        printf("不是闰年");
        system("pause");
    }
     */
    /*两大选择：if 、 switch
    int choice;
    printf("input your choice:\n");
    scanf("%d",&choice);
    switch (choice){
        case 1:
            printf("牛逼啊一等奖\n");
            break;
        case 2:
            printf("不错啊二等奖\n");
            break;
        case 3:
            printf("呵呵啊三等奖\n");
            break;
        default:
            printf("重在参与\n");
    }
     */
    /*三大循环:
     * 1. while(condition){LogicCode}
     * 2. do{LogicCode}while(condition);
     * 3. for(express1; express2; express3){LogicCode}
     */
#if 0
    //求n的阶乘
    int n;
    int res = 1;
    int i;
    printf("input a number:\n");
    scanf("%d", &n);
    if(n == 0 || n == 1){
        printf("%d 的阶乘为: %d", n,1);
    }else{
        for(i = 1;i<=n;i++){
            res *= i;
        }
        printf("%d 的阶乘为: %d", n,res);
    }
#endif

    for(int i =1; i<=9;i++){
        for(int j = 1; j<=i; j++){
            printf("%d*%d=%d\t",j,i,i*j);
        }
        printf("\n");
    }
    system("pause");

    return 0;
}
