#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("../fileCode/AEadd.txt", "r");
    if (NULL == fp) {
        return -1;
    }
    char buf[100];
    int sum = 0;
    while (fgets(buf, 100, fp)) {
        char *p = &buf[4];
        //printf("%s\n",p);
        int i = atoi(p);
        sum += i;
    }
    printf("sum = %d\n", sum);
    return 0;
}
