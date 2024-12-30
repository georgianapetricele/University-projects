#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define VECTOR_SIZE 5  // Size of the vectors
#define FIFO_FILE "/tmp/myfifo"  // Path to the FIFO

int main() {
    int vector1[VECTOR_SIZE] = {1, 2, 3, 4, 5};
    int vector2[VECTOR_SIZE] = {5, 4, 3, 2, 1};
    int fd;

    fd = open(FIFO_FILE, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open FIFO for writing");
        exit(1);
    }

    // Compute and write each product to the FIFO
    for (int i = 0; i < VECTOR_SIZE; i++) {
        int product = vector1[i] * vector2[i];
        printf("Producer: Writing product of element %d: %d\n", i, product);

        if (write(fd, &product, sizeof(product)) == -1) {
            perror("Failed to write to FIFO");
            close(fd);
            exit(1);
        }

        sleep(1);
    }

    close(fd);
    return 0;
}
