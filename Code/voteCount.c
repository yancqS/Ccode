#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[30];
    int voteCount;
} PERSON;

int main() {
    PERSON man[3] = {{"zhangsan", 0},
                     {"lisi",     0},
                     {"wangwu",   0}};

    char namebuf[30];
    for (int i = 0; i < 10; i++) {
        printf("pls input your person:");
        scanf("%s", namebuf);
        for (int i = 0; i < 3; i++) {
            if (strcmp(namebuf, man[i].name) == 0) {
                man[i].voteCount++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%s vote count is %d\n", man[i].name, man[i].voteCount);
    }

    if(man[0].voteCount > man[1].voteCount){
        if(man[0].voteCount > man[2].voteCount)
            printf("%s is elected\n",man[0].name);
        else
            printf("%s is elected\n",man[2].name);
    } else{
        if(man[1].voteCount > man[2].voteCount)
            printf("%s is elected\n",man[1].name);
        else
            printf("%s is elected\n",man[2].name);
    }

    system("pause");
    return 0;
}