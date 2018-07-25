#include "myStr.h"//自包含头文件

int myStrlen(char *src) {
    int len = 0;
    while (*src++ != '\0') {
        len++;
    }
    return len;
}

char *myStrcat(char *dest, char *src) {
    char *redest = dest;
    for (; *dest != '\0'; dest++);
    for (; *dest = *src; dest++, src++);
    return redest;
}

char *myStrcpy(char *dest, char *source) {
    char *redest = dest;
    while (*dest++ = *source++);
    return redest;
}

int myStrcmp(char * dest, char * src){
    if(!dest || !src)   //避免输入NULL空指针
        return (int) (dest - src);
    while(*dest && (*dest == *src)) //此时dest指向的字符不为'\0',并且dest指向的字符和src指向的字符相等
                                    // 则dest 和 src 指向下一个字符
    {
        dest++;
        src++;
    }
    return *dest - *src;
}

