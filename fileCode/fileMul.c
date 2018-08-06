#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //不推荐使用feof
    /* 一次读写一行字符
     int fputs(char *str, FILE *fp) 把str所指向的字符串写入到fp所指向的文件中。
     正常 返回0, 出错返回EOF

     char *fgets(char *str, int length, FILE *fp)
     从fp所指向的文件中,至多读length-1个字符,送入字符数组str中。
     如果在读入length-1个字符结束之前遇到\n或EOF,读入即结束,字符串读入后在最后面加一个"\0"字符。
     fgets函数返回有3个条件:
          1).读n-1个字符前遇到\n("\n"也会被读取), 读取结束
          2).读n-1个字符遇到EOF，读取结束
          3).最大读n-1个字符
          4).在每一行后自动追加"\0"
     返回值: 正常返回str指针; 出错或遇到文件结尾 返回指针NULL.
     */
    FILE *fp = fopen("../fileCode/fputs.txt", "w+");
    if (NULL == fp)
        return -1;
    printf("Res = %d\n", fputs("abcdefg\n", fp));
    printf("Res = %d\n", fputs("abcdefg\n", fp));
    printf("Res = %d\n", fputs("abcdefg\n", fp));
    printf("Res = %d\n", fputs("abcdefg", fp));

    rewind(fp);

    char buf[1024];
    /*while (fgets(buf, 1024, fp) && !feof(fp)) {*/ //最后一行读不到因为没有"\n",feof读到EOF就返回真
    while (fgets(buf, 1024, fp)) {  //正常返回str指针; 出错或遇到文件结尾 返回指针NULL.
                                    //读完最后一行后 会再去读一次再返回NULL
        printf("strlen = %d\t", strlen(buf));
        printf("%s", buf);
    }
    fclose(fp);
    return 0;
}