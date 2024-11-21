#include <stdio.h>
#include <stdlib.h>
#include "pascal.h"

int main()
{
    int sz = read_size();
    if(sz == -1) return -1;
    int **arr = malloc(sizeof(int*) * sz);
    init_pascal(arr, sz);
    print_pascal(arr, sz);
    destroy_pascal(arr, sz);
    return 0;
}
