#include "file_utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int float_cmp (const void *c1, const void *c2)
{
    if (c1 < c2)
    {
        return -1;
    }
    else if (c1 > c2)
    {
        return 1;
    }
    
    return 0;    
}