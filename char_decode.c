#include <stdio.h>

int encode();
int decode();

int main(int argc, char** argv) {
    if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '0')) {
        printf("n/a");
        return 1;
    }
    int flag = argv[1][0] - 48;
    int res = 0;
    if (flag) {
        res = decode();
    } else {
        res = encode();
    }
    if (res) {
        printf("n/a");
    }
    return res;
}

int encode() {
    char c, space = 'e';
    while(space != '\n') {
        c = getchar();
        if (c == ' ') {
            return 1;
        }
        space = getchar();
        if (space != ' ' && space != '\n') {
            return 1;
        }
        int code = c;
        printf("%X", code);
        if (space == ' ') {
            printf(" ");
        }
    }
    return 0;
}

int decode() {
    unsigned int x;
    char space = 'e';
    while(space != '\n') {
        if (scanf("%X", &x) != 1) {
            return 1;
        }
        space = getchar();
        if (space != ' ' && space != '\n') {
            return 1;
        }
        char decode = x;
        printf("%c", decode);
        if (space == ' ') {
            printf(" ");
        }
    }
    return 0;
}