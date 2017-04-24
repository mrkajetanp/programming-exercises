#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "hello_world.h"

void hello(char *buffer, const char *name) {
    if (name == NULL)
        sprintf(buffer, "Hello, World!");
    else
        sprintf(buffer, "Hello, %s!", name);
}
