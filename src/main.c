#include <stdio.h>

#define BUFFER_SIZE 256

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

    while(fgets(buffer, sizeof(buffer), SOURCEFILE) != NULL) {
        printf("%s\n", buffer);
    }

    return 0;

}