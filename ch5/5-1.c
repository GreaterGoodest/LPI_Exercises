#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFF_SIZE 4096
#define _FILE_OFFSET_BITS 64

int main(){
    int out_fd;
    char *buff[BUFF_SIZE];
    ssize_t write_count = 0;

    memset(buff, 'A', 4096);

    out_fd = open("out_file.txt", O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    write_count = write(out_fd, buff, BUFF_SIZE);

    printf("wrote %lld bytes\n", write_count);

    close(out_fd);
     

    return 0;
}
