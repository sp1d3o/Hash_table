#ifndef HASH_TABLE_ERROR_H
#define HASH_TABLE_ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

enum ERROR_CODES {
    ERR_OK = 0,
    ERR_MEMFAIL = 1,
    ERR_EMPTY = 2,
    ERR_OTHER = 127
};

typedef enum ERROR_CODES status_t;

noreturn void malloc_error(const char* location);

#endif //HASH_TABLE_ERROR_H
