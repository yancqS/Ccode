#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * void rewind(FILE *stream) 将文件指针重新指向一个流的开头
 * long ftell(FILE *stream) 得到流式文件的当前读写位置,其返回值是当前读写位置偏离文件头部的字节数
 * int fseek(FILE * stream, long offset, int origin) 偏移文件指针
 *
 *          #define SEEK_CUR 1
 *          #define SEEK_END 2
 *          #define SEEK_SET 0
 * */
int main() {
    /*
    FILE *fp = fopen("../fileCode/filePoffset.txt", "w");
    if (NULL == fp) {
        return -1;
    }
    char ch;
    for (ch = 'a'; ch <= 'z'; ch++) {
        fputc(ch, fp);
    }
    //ftell = 26
    rewind(fp);//ftell = 0
    fseek(fp, 0, SEEK_SET);//ftell = 0
    fseek(fp, 0, SEEK_END);//ftell = 26
    fseek(fp, 5, SEEK_SET);//ftell = 5
    fseek(fp, -5, SEEK_END);//ftell = 21

    int len = ftell(fp);
    printf("len = %d\n", len);
     */
#if 0
    FILE *fp = fopen("../fileCode/attentionb.txt", "wb");
    if (NULL == fp)
        return -1;
    fputc('a', fp);
    fputc('\n', fp);
    fputc('a', fp);
    fputc('\n', fp);
    fputc('a', fp);
    fclose(fp);
#endif
#if 0
    FILE *fp = fopen("../fileCode/attentionb.txt", "rb");
    if (NULL == fp)
        return -1;
    int i;
    for (i = 0; i < 5; i++) {
        printf("%x\t",fgetc(fp));
    }
#endif
    return 0;
}