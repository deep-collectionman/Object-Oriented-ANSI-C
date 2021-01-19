#ifndef object_rep_h
#define object_rep_h

#include <stdlib.h>
#include <stdarg.h>

#include "Object.h"

struct Class;

struct Object {
    const struct Class* _class_; /* object’s description */
};

struct Class {
    const struct Object _;
    const char* name;
    const struct Class* superclass;
    size_t size;
    void* (*ctor) (void* self, va_list* app);
    void* (*dtor) (void* self);
    int (*differ) (const void* self, const void* other);
    int (*objectInfo) (const void* self, FILE* outputFile);
};

#endif // object_rep_h