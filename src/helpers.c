#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

char *loadFile(const char *filePath)
{
    FILE *f = fopen(filePath, "rb");
    if (!f) return NULL;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    char *buffer = malloc(size + 1);
    fread(buffer, 1, size, f);
    buffer[size] = '\0';
    fclose(f);
    return buffer;
}
int *getArrayFromJson(cJSON j)
{
    return 0;
}