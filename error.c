#include "error.h"

noreturn void malloc_error(const char *location) {
    perror(location);
    exit(ERR_INTERNAL_ERROR);
}