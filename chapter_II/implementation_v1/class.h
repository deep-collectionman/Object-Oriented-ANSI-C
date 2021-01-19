#ifndef class_h
#define class_h

#include <stdio.h>
#include <stdarg.h>

struct Class {
    size_t size;
    void* (*constructor) (void* self, va_list* app);
    void* (*destructor) (void* self);
    void* (*clone) (const void* self);
    int (*differ) (const void* self, const void* other);
};

#endif // class_h