#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//�����������͡����������ʽ������ṹ���
int main() {
    /*���ʹ�С
    printf("sizeof(char) = %d => �ַ�����\n", sizeof(char));//1
    printf("sizeof(short) = %d => ������\n", sizeof(short));//2
    printf("sizeof(int) = %d => ����\n", sizeof(int));//4
    printf("sizeof(long int) = %d => ������\n", sizeof(long int));//4
    printf("sizeof(long long) = %d => long long\n", sizeof(long long));//8
    printf("sizeof(float) = %d => �����ȸ�����\n", sizeof(float));//4
    printf("sizeof(double) = %d => ˫���ȸ�����\n", sizeof(double));//8
    printf("sizeof(long double) = %d => long double\n", sizeof(long double));//12
     */

    /*��˫����λ��
    float fvar = 2.1234567891234;
    double dvar = 2.1234567891234;
    printf("fvar = %.13f\n", fvar);//��֤ǰ7Ϊ���ȣ�����ļ�λ�����仯. fvar = 2.1234567165375
    printf("dvar = %.13f\n", dvar);//����15-16.   dvar = 2.1234567891234
     */

    /*ASCII��
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
    ��һ��ע�ͷ�ʽ(ת���ַ�)
    printf("i like \"football\"\n");
    printf("the rate is %d%%",90);
    printf("aaaaaaaa\rbb\n");
    printf("aaaaaaaa\r\nbb\n");
    printf("aaaaaaaa\tbb\n");
    printf("aaaaa\xd bbbbbb\n"); \xd ʮ������ 13 => \r��Ӧ��ascii��
    printf("aaaaa\11 bbbbbb\n"); \11 �˽��� 9 => \t��Ӧ��ascii��
#endif
    /*
    ��ʽ���
   int var = 1234;
   printf("ʮ����=%d, �˽���=%o, ʮ������=%x\n", var,var,var);
   //ʮ����=1234, �˽���=2322, ʮ������=4d2
   printf("ʮ����=%d, �˽���=%#o, ʮ������=%#x\n", var,var,var);
   //ʮ����=1234, �˽���=02322, ʮ������=0x4d2
   printf("==============\n");
   printf("%10d\n", var);//       1234
   printf("%010d\n", var);//0000001234
   printf("%1d\n", var);//1234
   printf("%-10d\n", var);//1234      (������6�ո�)
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
   printf("%7.2f\n", f);// 123.46(�Ҷ���ո�)
   printf("%07.2f\n", f);//0123.46(�Ҷ���0��)
   printf("%-7.2f\n", f);//123.46
   printf("%e\n", f);//1.234567e+002
   printf("%g\n", f);//123.457
    */
    /*
    ��ʽ����
   int a, b, c;
   scanf("%d%d%d",&a,&b,&c);
   printf("a = %d, b = %d, c = %d\n",a, b, c);
    */
    /*
     * ����ת��: int -> long long -> float -> double(���ȼ�)
    char a; short b; int c;
    long long d; float e; double f;
    printf("sizeof(a) = %d\n", sizeof(a));//sizeof(a) = 1
    printf("sizeof(b) = %d\n", sizeof(b));//sizeof(b) = 2
    printf("sizeof(c) = %d\n", sizeof(c));//sizeof(c) = 4
    printf("sizeof(d) = %d\n", sizeof(d));//sizeof(d) = 8
    printf("sizeof(e) = %d\n", sizeof(e));//sizeof(e) = 4
    printf("sizeof(f) = %d\n", sizeof(f));//sizeof(f) = 8

    printf("sizeof(a+b) = %d\n", sizeof(a+b));//4 ����������char short int ��������һ������ʱ������������int.
    printf("sizeof(a+c) = %d\n", sizeof(a+c));//4
    printf("sizeof(b+c) = %d\n", sizeof(b+c));//4
    printf("sizeof(a+d) = %d\n", sizeof(a+d));//8
    printf("sizeof(d+e) = %d\n", sizeof(d+e));//4 ע�⣺long long(8) + float(4) -> float(4)
    printf("sizeof(d+f) = %d\n", sizeof(d+f));//8
    printf("sizeof(a+f) = %d\n", sizeof(a+f));//8

    c = 3;
    e = 5.6;
    printf("%f\n", c+e);//%d ������ ���Ͳ�ƥ�� int+float -> float
    */
    /*ǿ��ת��
    int a = 3;
    int b = 10;
    float c = b / a; //3.000000
    float d = (float) b / a; //ǿ��ת��==> (float) b 10.0 �ٳ�a ==> 10.0/3 = 3.333333
    printf("c = %f, d = %f\n", c, d);
     */
    /*���������ʽ
    int a = 3, b = 5;
    printf("7/3 = %d, -7/3 = %d, 7/-3 = %d\n", 7/3, -7/3, 7/-3);
    printf("7%%3 = %d, -7%%3 = %d, 7%%-3 = %d\n", 7%3, -7%3, 7%-3);//������/���� -> �����������뱻����һ��
    printf("express a == b value = %d\n", a==b);
    printf("express a != b value = %d\n", a!=b);
    */
    /*
    int a;
    a = 1, 2, 3, 4, 5, 6;//���ű��ʽ�����ȼ���ͣ�����a = 1 ��ֵ���ʽ������ ���ű��ʽ
    printf("a = %d\n", a);//1

    a = (1, 2, 3, 4, 5, 6);//�Ӹ���������������Ķ��ű��ʽ �ڸ�ֵ��a���������ű��ʽ��ֵ�������һ�����ʽ��ֵ��
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
    /*�ж�����
    int year;
    printf("input a year: ");
    scanf("%d", &year);
    if (year % 4 == 0 && year % 100 != 0) {
        printf("��ͨ����");
        system("pause");
    } else if (year % 400 == 0) {
        printf("��������");
        system("pause");
    } else {
        printf("��������");
        system("pause");
    }
     */
    /*����ѡ��if �� switch
    int choice;
    printf("input your choice:\n");
    scanf("%d",&choice);
    switch (choice){
        case 1:
            printf("ţ�ư�һ�Ƚ�\n");
            break;
        case 2:
            printf("�������Ƚ�\n");
            break;
        case 3:
            printf("�Ǻǰ����Ƚ�\n");
            break;
        default:
            printf("���ڲ���\n");
    }
     */
    /*����ѭ��:
     * 1. while(condition){LogicCode}
     * 2. do{LogicCode}while(condition);
     * 3. for(express1; express2; express3){LogicCode}
     */
#if 0
    //��n�Ľ׳�
    int n;
    int res = 1;
    int i;
    printf("input a number:\n");
    scanf("%d", &n);
    if(n == 0 || n == 1){
        printf("%d �Ľ׳�Ϊ: %d", n,1);
    }else{
        for(i = 1;i<=n;i++){
            res *= i;
        }
        printf("%d �Ľ׳�Ϊ: %d", n,res);
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
