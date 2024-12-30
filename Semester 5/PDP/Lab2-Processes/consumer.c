#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define VECTOR_SIZE 5  // Size of the vectors
#define FIFO_FILE "/tmp/myfifo"  // Path to the FIFO

int main() {
    int fd;
    int product;
    int result = 0;

    fd = open(FIFO_FILE, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open FIFO for reading");
        exit(1);
    }

    // Read each product from the FIFO and accumulate the result
    for (int i = 0; i < VECTOR_SIZE; i++) {
        if (read(fd, &product, sizeof(product)) == -1) {
            perror("Failed to read from FIFO");
            close(fd);
            exit(1);
        }
        result += product;
        printf("Consumer: Read product of element %d, Current sum = %d\n", i, result);
    }
  
    printf("Final Scalar Product: %d\n", result);

    close(fd);
    return 0;
}
