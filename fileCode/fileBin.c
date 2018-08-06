#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int num;
    char name[30];
    char sex;
    float math;
    float english;
    float chinese;
} STU;
#define OPENERROR(fp) if(fp == NULL){printf("open error\n");return -1;}

//一次读写一块字符(二进制操作)
//前面所学的所有文件接口函数，要么以'\0',表示输入结束,要么以'\n',EOF表示读取结束。
//'\0','\n'等都是文本文件结束的重要标识,而二进制文件,则往往以块的形式,写入或者写出。
/*
 * int fwrite(void *buffer, int num_bytes, int count, FILE *fp);
 * int fread(void *buffer, int num_bytes, int count, FILE *fp);
 *
 * void *buffer--指向要输入/输出数据存储区的首地址的指针
 * int num_bytes--每个要读/写的字段的字节数
 * int count--要读/写的字段的个数
 * FILE *fp--要读/写的文件指针
 *
 * 返回值: 成功，返回读/写的字段数。出错或者文件结束,返回0.
 * */
int main() {
    /*//fputs("abc\0defg",stdout);
    FILE *fpw = fopen("../fileCode/mainBin.txt", "wb");
    if (NULL == fpw) {
        return -1;
    }
    char p[1024] = "china \n is \0 great!";//二进制读写不关心文本格式
    fwrite(p, 1, strlen(p) + 8, fpw);
    fclose(fpw);

    FILE *fpr = fopen("../fileCode/mainBin.txt", "rb");
    char q[1024];
    int len = fread(q, 1, 1024, fpr);
    printf("len = %d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%x\t", *(q + i));
    }
    fclose(fpr);*/
    //返回值的陷阱
    //fread(起始地址,每个字段的最小单元字节,读取字段个数，文件句柄)
    FILE *fp = fopen("../fileCode/bintest.txt", "rb");
    if (NULL == fp)
        return -1;
    char buffer[1024];
    /*for (int i = 0; i < 100; i++) {
        int n = fread(buffer, 1, 1, fp);
        printf("n = %d index = %d\n", n, i);
        if (n == 0)
            break;
    }*/
    int n;
    while ((n = fread(buffer, 1, 3, fp)) > 0) {
        printf("n = %d\n", n);
        for (int i = 0; i < n; i++) {
            printf("%c\t", buffer[i]);
        }
        putchar(10);
    }
    //二进制读写才是我的本质
    printf("=============================\n");
    int a[10] = {0xff, '\0', 10, 0x0d, '\n', 6, 8, 33, 77, 99};
    FILE *fpwb = fopen("../fileCode/binFile.txt", "wb+");
    if (NULL == fpwb)
        return -1;
    fwrite(a, 4, sizeof(a) / sizeof(a[0]), fpwb);
    rewind(fpwb);
    int buf[10];
    int len = sizeof(buf) / sizeof(buf[0]);
    fread(buf, 4, len, fpwb);
    for (int i = 0; i < len; i++) {
        printf("%x\n", buf[i]);
    }
    printf("=============================\n");
    //读写结构体是长项
    FILE *fps = fopen("../fileCode/stu.data", "wb+");
    OPENERROR(fps);

    STU stu[] = {
            {1001, "Bob",     'x', 100, 30, 20},
            {1002, "Yoranda", 'o', 90,  80, 90},
            {1003, "Ken",     'x', 33,  89, 56}
    };

    int stulen = sizeof(stu) / sizeof(stu[0]);
    for (int i = 0; i < stulen; i++) {
        fwrite(stu, sizeof(stu[0]), stulen, fps);
    }

    rewind(fps);

    STU stuback;
    for (int i = 0; i < stulen; i++) {
        fread(&stuback, sizeof(stu[0]), 1, fps);
        printf("num = %d,name = %s, sex = %c,math = %.2f,english = %.2f,chinese = %.2f\n", stuback.num, stuback.name,
               stuback.sex, stuback.math, stuback.english, stuback.chinese);
    }
    fclose(fps);

    return 0;
}