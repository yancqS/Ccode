#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("../fileCode/smb.conf", "r");
    if (NULL == fp) {
        return -1;
    }
    FILE *fpw = fopen("../fileCode/smbfilter.txt", "w");
    if (NULL == fpw) {
        fclose(fp);
        return -1;
    }
    char buf[1024];
    while (fgets(buf, 1024, fp)) {
        if (buf[0] == '#')
            continue;
        fputs(buf, fpw);
    }
    return 0;
}
