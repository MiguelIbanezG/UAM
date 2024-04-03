#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define SHM_NAME "/shm_example"
#define MESSAGE "Test message"


int main(int argc, char *argv[]) {
    int fd;
    struct stat statbuf;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <FILE>\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    dprintf(fd, "%s", MESSAGE);
    /* Get size of the file. */

    if (fstat(fd, &statbuf) < 0)
    {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    printf("Size : %ld\n", statbuf.st_size);

    /* Truncate the file to size 5. */
    if (ftruncate(fd, (off_t)5) < 0)
    {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    close(fd);
    exit(EXIT_SUCCESS);
}
