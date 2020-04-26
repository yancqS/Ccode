#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("../fileCode/fileSort.txt", "r");
    if (NULL == fp)
        return -1;
    char buf[30];
    char sort[100] = {0};
    while (fgets(buf, 30, fp) != NULL) {
        strcat(sort, buf);
    }
    printf("%s", sort);
    int len = strlen(sort);
    char tmp;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (sort[j + 1] != '\n') {
                if (sort[j] > sort[j + 1]) {
                    tmp = sort[j];
                    sort[j] = sort[j + 1];
                    sort[j + 1] = tmp;
                }
            } else {
                if (sort[j] > sort[j + 2]) {
                    tmp = sort[j];
                    sort[j] = sort[j + 2];
                    sort[j + 2] = tmp;
                }
                j++;
            }
        }
    }
    printf("\n--------After Sort--------\n");
    printf("%s", sort);
    fclose(fp);
    return 0;
}