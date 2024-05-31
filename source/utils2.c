#include "pipex.h"

void    exit_alloc(void)
{
    write(2, "Error memory allocation\n", 25);
    exit(1);
}
