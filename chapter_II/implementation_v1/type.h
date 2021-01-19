#ifndef type_h
#define type_h

#include <stdio.h>

struct type {
    size_t size; /* size of an object */
    void (*dtor) (void*); /* destructor */
};

#endif // type_h
