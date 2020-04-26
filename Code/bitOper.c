#include <stdio.h>
#include <stdlib.h>

void binDis(int var);

void circleMove(int *p, int n);

int main() {
    /*int a = 0x55;
    binDis(a);
    int b = 0xF0;
    binDis(b);
    binDis(a & b);//ͬ1λ�뱣�ֲ���,ͬ0λ�����㡣��;: ��ĳЩλ���������£�������λ����.
    binDis(a | b);//ͬ0λ�򱣳ֲ���,ͬ1λ����һ����;: ��ĳЩλ���������£�������λ��һ.

    int c = 1;
    binDis(c);// 0000 0000 0000 0000 0000 0000 0000 0001
    binDis(~c);//1111 1111 1111 1111 1111 1111 1111 1110 (-2)
    binDis(~(1<<31));//int���͵������
    printf("%d",~(1<<31));

    int d = 3;
    int e = 9;
    binDis(d);
    binDis(e);
    binDis(d ^ e);//���: �����߻���ͬ�߹��㣬�����߻�
                  // ��ĳЩλ���ֲ��������£�������λȡ����ͬ0��򱣳ֲ��䣬ͬ1����Ӧλȡ����

    int f = 0xFF;
    binDis(f);
    int g = f<<3;
    binDis(g);//x<<λ��(�Ǹ�����): ʹ�������ĸ�λ���ƣ���λ���㣬��λ���������

    int h = 0xF1;//�з�����������
    binDis(h);
    int i = h>>1;
    binDis(i);//x>>λ��(�Ǹ�����): ʹ�������ĸ�λ���ƣ��Ƴ��ĵ�λ������
              // ��λ: ��*�޷�����*��*�з�����*����������;
              //�з������ĸ�����ȡ������ʹ�õ�ϵͳ--����ĳ�Ϊ ���߼����ơ�����һ�ĳ�Ϊ���������ơ���

    unsigned int j = 1<<31;//�޷�����
    binDis(j);
    printf("%u\n",j);
    j = j>>1;
    binDis(j);

    int k = 1<<31 | 1;//�з������ĸ���
    binDis(k);//1000 0000 0000 0000 0000 0000 0000 0001
    k = k>>1;
    binDis(k);//��1 ���������ơ� 1100 0000 0000 0000 0000 0000 0000 0000
    */

    /*
    //Ӧ��--����Mask
    //����:1.��λ(λ��1) flag |= mask; 2.�ر�λ(λ��0) flag &= ~mask;
    //    3.ת��λ(λ��ת) flag ^= mask; 4.�鿴ĳһλ��ֵ if((flag & mask) == mask)
    int flag = 0x55aa;//0101 0101 1010 1010
    int mask = 1<<7;  //0000 0000 1000 0000
    int mask2 = 1<<6; //0000 0000 0100 0000
    int mask3 = 1<<5; //0000 0000 0010 0000

    printf("��flag�ĵ�7λ��0:\n");
    int zero = flag & ~mask;
    binDis(flag);
    binDis(zero);

    printf("\n\n");

    printf("��flag�ĵ�6λ��1:\n");
    int one = flag | mask2;
    binDis(flag);
    binDis(one);

    printf("\n\n");

    printf("��flag�ĵ�5λȡ��:\n");
    int reverse = flag ^ mask3;
    binDis(flag);
    binDis(reverse);

    printf("\n\n");

    printf("�ж�flag��7λ��0����1:\n");
    if((flag & mask) == mask)
        printf("The seventh bit is 1");
    else
        printf("The seventh bit is 0");
    */

    /*
    //�Ƚض� ����λ
    int masks = 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3;
    int data = 0xaa55;
    int res = (masks & data) >> 3;
    binDis(data);
    binDis(res);
     */

    /*
    //��תһ�����ݵ����nλ(����n = 7)
    int mask = 1<<6 | 1<<5 |1<<4 |1<<3 |1<<2 |1<<1 | 1;
    int flag = 0xa5fd;
    binDis(flag);
    flag ^= mask;
    binDis(flag);
     */
# if 0
    //�ж�һ�����ǲ���2������
    int flag = 1;
    int n;
    printf("pld input Num:");
    scanf("%d", &n);
    while (flag) {
        int j;
        for (j = 0; j < 32; j++) {
            if (n == 1 << j) {
                printf("%d is the %d power of 2\n", n, j);
                flag = 0;
                break;
            }
        }
        if(j == 32){
            printf("%d is not the power of 2\n", n);
            flag = 0;
        }
    }
#endif
    //ѭ����λ
    int p = 1<<31 | 1<<0;
    binDis(p);
    circleMove(&p, 2);
    binDis(p);
    return 0;
}

//��ӡ���ݵĶ�������ʽ
void binDis(int var) {
    int i = 32;
    while (i--) {
        if (var & (1 << i))
            printf("1");
        else
            printf("0");
        if (i % 4 == 0)
            putchar(' ');
    }
    printf("\n");
}

void circleMove(int *pdata, int n) {
    int m;
    m = n > 0 ? n : -n;
    unsigned int mask = 0;
    //��������
    while (m--)
        mask |= (1<<m);
    if(n>0){            //��ѭ��
        //1000 0001     <<3(n=3)0000 1000 ��
        //1000 0001     >>5     1111 1100 �������Ƴ��ĸ�λ�����������ݵĵ�λ
        //                      0000 0111 ��(����)
        //                      0000 0100 ��(�� & ��)���Ƴ��ĸ�λ��ȡ����
        //result = 0000 1100(�� & ��)
        *pdata = (*pdata<<n) | mask & (*pdata >> (sizeof(*pdata)*8 - n));
    } else{             //��ѭ��
        //1000 0001     >>3(n=-3)       1111 0000
        //1000 0001     <<5             0010 0000
        //                              0000 0111
        //                              1110 0000
        //                              0001 1111
        //0011 0000
    }

}