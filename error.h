#ifndef HASH_TABLE_ERROR_H
#define HASH_TABLE_ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

enum ERROR_CODES {
    ERR_OK = 0,
    ERR_MEMORYFAIL = 1,
    ERR_EMPTY = 2,
    ERR_INTERNAL_ERROR = 3,
    ERR_OTHER = 127
};

typedef enum ERROR_CODES status_t;

noreturn void malloc_error(const char* location);

#define OK \
    status == ERR_OK \

#define NOK \
    status != ERR_OK

#define new(type, var)                  \
    type *var = malloc(sizeof(type));   \
    if(var == NULL) {                   \
        malloc_error(__func__);         \
    }

#define DEFAULT_NOT_IMPLEMENTED \
    default:                    \
        NotImplementedError;    \
        break

#define NotImplementedError \
        fprintf(stderr, "Not implemented exception inside function %s\n", __func__); \
        exit(ERR_INTERNAL_ERROR)


#endif //HASH_TABLE_ERROR_H
