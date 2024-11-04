/*
 * 5장 디버깅과 오류 처리
 * 파일 이름: my_assert_use.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// my_assert 함수 정의
void my_assert(int expression) {
    if (!expression) {
        fprintf(stderr, "Assertion failed\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    FILE *f;

    // assert를 my_assert로 대체
    my_assert(argc >= 2);

    if ((f = fopen(argv[1], "r")) == NULL) {
        perror("fopen"); // perror(NULL)로도 테스트 가능
        exit(1);
    }

    printf("Open a file \"%s\".\n", argv[1]);

    fclose(f);
    return 0;
}

