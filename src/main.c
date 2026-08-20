#include <stdio.h>

#define BUFFER_SIZE 65536

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: meow <filename>\n");
        return 1;
    }

    FILE *SOURCEFILE = fopen(argv[1], "r");

    if (SOURCEFILE == NULL) {
        printf("failed to open file\n");
        return 2;
    }

    char buffer[BUFFER_SIZE];
    size_t n;

    while ((n = fread(buffer, 1, sizeof buffer, SOURCEFILE)) > 0) {
        fwrite(buffer, 1, n, stdout);
    }

    return 0;

}