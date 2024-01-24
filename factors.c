#include <stdio.h>
#include <stdlib.h>

void factorize(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int number = atoi(line);
        factorize(number);
    }

    fclose(file);
    return (0);
}
