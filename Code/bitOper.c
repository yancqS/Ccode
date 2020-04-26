#include <stdio.h>
#include <stdlib.h>

void binDis(int var);

void circleMove(int *p, int n);

int main() {
    /*int a = 0x55;
    binDis(a);
    int b = 0xF0;
    binDis(b);
    binDis(a & b);//同1位与保持不变,同0位与清零。用途: 在某些位不变的情况下，将其余位置零.
    binDis(a | b);//同0位或保持不变,同1位或置一。用途: 在某些位不变的情况下，将其余位置一.

    int c = 1;
    binDis(c);// 0000 0000 0000 0000 0000 0000 0000 0001
    binDis(~c);//1111 1111 1111 1111 1111 1111 1111 1110 (-2)
    binDis(~(1<<31));//int类型的最大数
    printf("%d",~(1<<31));

    int d = 3;
    int e = 9;
    binDis(d);
    binDis(e);
    binDis(d ^ e);//异或: 相异者或。相同者归零，相异者或。
                  // 在某些位保持不变的情况下，将其余位取反。同0异或保持不变，同1异或对应位取反。

    int f = 0xFF;
    binDis(f);
    int g = f<<3;
    binDis(g);//x<<位数(非负整数): 使操作数的各位左移，低位补零，高位溢出舍弃。

    int h = 0xF1;//有符号数的正数
    binDis(h);
    int i = h>>1;
    binDis(i);//x>>位数(非负整数): 使操作数的各位右移，移出的低位舍弃。
              // 高位: 对*无符号数*和*有符号数*的正数补零;
              //有符号数的负数，取决于所使用的系统--补零的成为 “逻辑右移”，补一的称为“算术右移”。

    unsigned int j = 1<<31;//无符号数
    binDis(j);
    printf("%u\n",j);
    j = j>>1;
    binDis(j);

    int k = 1<<31 | 1;//有符号数的负数
    binDis(k);//1000 0000 0000 0000 0000 0000 0000 0001
    k = k>>1;
    binDis(k);//补1 “算术右移” 1100 0000 0000 0000 0000 0000 0000 0000
    */

    /*
    //应用--掩码Mask
    //功能:1.打开位(位置1) flag |= mask; 2.关闭位(位置0) flag &= ~mask;
    //    3.转置位(位反转) flag ^= mask; 4.查看某一位的值 if((flag & mask) == mask)
    int flag = 0x55aa;//0101 0101 1010 1010
    int mask = 1<<7;  //0000 0000 1000 0000
    int mask2 = 1<<6; //0000 0000 0100 0000
    int mask3 = 1<<5; //0000 0000 0010 0000

    printf("将flag的第7位置0:\n");
    int zero = flag & ~mask;
    binDis(flag);
    binDis(zero);

    printf("\n\n");

    printf("将flag的第6位置1:\n");
    int one = flag | mask2;
    binDis(flag);
    binDis(one);

    printf("\n\n");

    printf("将flag的第5位取反:\n");
    int reverse = flag ^ mask3;
    binDis(flag);
    binDis(reverse);

    printf("\n\n");

    printf("判断flag第7位是0还是1:\n");
    if((flag & mask) == mask)
        printf("The seventh bit is 1");
    else
        printf("The seventh bit is 0");
    */

    /*
    //先截断 在移位
    int masks = 1 << 6 | 1 << 5 | 1 << 4 | 1 << 3;
    int data = 0xaa55;
    int res = (masks & data) >> 3;
    binDis(data);
    binDis(res);
     */

    /*
    //反转一个数据的最后n位(假设n = 7)
    int mask = 1<<6 | 1<<5 |1<<4 |1<<3 |1<<2 |1<<1 | 1;
    int flag = 0xa5fd;
    binDis(flag);
    flag ^= mask;
    binDis(flag);
     */
# if 0
    //判断一个数是不是2的幂数
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
    //循环移位
    int p = 1<<31 | 1<<0;
    binDis(p);
    circleMove(&p, 2);
    binDis(p);
    return 0;
}

//打印数据的二进制形式
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
    //生成掩码
    while (m--)
        mask |= (1<<m);
    if(n>0){            //左循环
        //1000 0001     <<3(n=3)0000 1000 ①
        //1000 0001     >>5     1111 1100 ②这样移除的高位就在现在数据的低位
        //                      0000 0111 ③(掩码)
        //                      0000 0100 ④(② & ③)把移除的高位提取出来
        //result = 0000 1100(① & ④)
        *pdata = (*pdata<<n) | mask & (*pdata >> (sizeof(*pdata)*8 - n));
    } else{             //右循环
        //1000 0001     >>3(n=-3)       1111 0000
        //1000 0001     <<5             0010 0000
        //                              0000 0111
        //                              1110 0000
        //                              0001 1111
        //0011 0000
    }

}