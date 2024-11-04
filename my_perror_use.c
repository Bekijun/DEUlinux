/*
 * 5장 디버깅과 오류 처리
 * 파일 이름: my_perror_use.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// my_perror 함수 정의
void my_perror(const char *msg) {
    if (msg != NULL && *msg != '\0') {
        fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    } else {
        fprintf(stderr, "%s\n", strerror(errno));
    }
}

int main(int argc, char *argv[]) {
    FILE *f;

    if (argc < 2) {
        printf("Usage: my_perror_use nofilename\n");
        exit(1);
    }

    if ((f = fopen(argv[1], "r")) == NULL) {
        // perror() 대신 my_perror()를 사용하여 오류 메시지 출력
        my_perror("Cannot open a file");
        exit(1);
    }

    printf("Open a file \"%s\".\n", argv[1]);

    fclose(f);
    return 0;
}

