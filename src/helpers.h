#include <stdlib.h>
#include <cjson/cJSON.h>

char *loadFile(const char *filename);
int *getArrayFromJson(cJSON j);