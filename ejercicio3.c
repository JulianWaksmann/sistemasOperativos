#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int n = 3;
    int i;
    for (i = 0; i < n; i++) {
        fork();
        printf("Soy un proceso!\n");
    }
    return 0;
}
