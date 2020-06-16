#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/*

The result of this is that the seek is ignored in favor of the append flag,
resulting in a write to the end of the file.

*/

int main()
{
    int fd;
    const char *to_write = "test";
    const char *file_name = "/tmp/test";
    
    fd = open(file_name, O_WRONLY | O_APPEND);

    lseek(fd, 0, SEEK_SET);

    write(fd, to_write, strlen(to_write));

    return 0;
}
