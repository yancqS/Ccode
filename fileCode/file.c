#include <stdio.h>
#include <stdlib.h>

#define SEC 10

void secFile(FILE *fpr, FILE *fpw);

void unSecFile(FILE *fpr, FILE *fpw);

int main(int argc, char *argv[]) {
#if 0
    //花费时间用于转化
    //文本文件占用磁盘空间较多,易读
    short a = 10000;//0x2710
    FILE * fps = fopen("../fileCode/ascii.txt","w");
    fprintf(fps,"%d",a);
    fclose(fps);
    //不需要花费时间转化
    //二进制文件相比于文本文件,占用空间小,磁盘文件不易读
    FILE *fps2 = fopen("../fileCode/bin.txt","wb");
    fwrite(&a,2,1,fps2);
    fclose(fps2);

    char *buf = "abcdefg";
    FILE *fp = fopen("../fileCode/ascii2.txt", "w");
    fprintf(fp, "%s", buf);
    fclose(fp);

    FILE *fp2 = fopen("../fileCode/bin2.txt","wb");
    fwrite(buf,8,1,fp2);
    fclose(fp2);
#endif
#if 0
    //文件的打开和关闭
    //fopen(const char * filename,const char * mode);
    FILE * fp = fopen("../fileCode/read.txt","r");//r 只能读现有文件,若不存在则报错
    FILE * fp = fopen("../fileCode/write.txt","w");//w 若不存在则创建,若存在则清空
    FILE * fp = fopen("../fileCode/append.txt","a");//a 若不存在则创建,若存在则在最后面追加
    /*
    mode    处理方式    当文件不存在时         当文件存在时          向文件输入           向文件输出

    "r"      读取          报错               打开文件              不能               可以
    "w"      写入        建立新文件            覆盖原有文件           可以               不能
    "a"      追加        建立新文件            在原有文件后追加        可以               不能
    "r+"    读取/写入       报错               打开文件              可以               可以
    "w+"    写入/读取     建立新文件            覆盖原有文件           可以               可以
    "a+"    读取/追加     建立新文件            在原有文件后追加        可以               可以
     */

    /*
    FILE *fp = fopen("../fileCode/fclose.txt", "w");
    if (NULL == fp) {
        printf("open error\n");
        exit(-1);
    }
    fputs("fclose can fresh flush", fp);
    fclose(fp);//可以刷缓冲
     */
#endif
#if 0
    //一次读写一个字符(文本操作)fputc fgetc
    //int fputc(int ch, FILE * stream)将ch字符写入文件，写入成功则返回写入成功的字符，如果失败，返回EOF.
    //int fgetc(FILE * steam) 正常返回读取的字符;读到文件结尾或出错时,为EOF;
    //对文件的结尾都应该通过函数返回值来判断,尽量少用feof();
    FILE *fp = fopen("../fileCode/fputc.txt", "w+");
    if (NULL == fp) {
        printf("open error\n");
        exit(-1);
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        printf("%-3c",fputc(ch, fp));
    }
    putchar(10);

    char ch;
    rewind(fp);//将文件 当前读写指针 移动到文件起始位置 (FILE结构体中有一个指向当前读写位置的指针)
    while ((ch = fgetc(fp)) && !feof(fp))   //标志位的置位总是滞后于读.
        printf("%3c", ch);
    fclose(fp);
#endif
    /*命令行参数测试
    printf("argc = %d\n", argc);
    for(int i = 0; i<argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }
     */
    /*
    //实现Linux中的cp命令
    if(argc < 3){
        printf("uage: %s src dest\n",argv[0]);
        return 0;
    }
    FILE * fp = fopen(argv[1],"r");
    if(NULL == fp){
        return -1;
    }
    FILE * fp2 = fopen(argv[2],"w");
    if(NULL == fp2){
        fclose(fp);
        return -1;
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF){
        fputc(ch,fp2);
    }
    fclose(fp);
    fclose(fp2);
     */
    //文件的加密
    FILE *fpr = fopen("../fileCode/main.txt", "r");
    if (NULL == fpr)
        return -1;
    FILE *fpw = fopen("../fileCode/mainSec.txt", "w");
    if (NULL == fpw) {
        fclose(fpr);
        return -1;
    }
    secFile(fpr, fpw);
    fclose(fpr);
    fclose(fpw);
    //文件的解密
    FILE *fr = fopen("../fileCode/mainSec.txt", "r");
    if (NULL == fr)
        return -1;
    FILE *fw = fopen("../fileCode/mainUnsec.txt", "w");
    if (NULL == fw) {
        fclose(fr);
        return -1;
    }
    unSecFile(fr, fw);
    fclose(fpr);
    fclose(fpw);

    return 0;
}

//加密
void secFile(FILE *fpr, FILE *fpw) {
    char ch;
    while ((ch = fgetc(fpr)) != EOF) {
        ch += SEC;//如果SEC定义的数值太大比较容易造成溢出
        fputc(ch, fpw);
    }
}

//解密
void unSecFile(FILE *fpr, FILE *fpw) {
    char ch;
    while ((ch = fgetc(fpr)) != EOF) {
        ch -= SEC;
        fputc(ch, fpw);
    }
}