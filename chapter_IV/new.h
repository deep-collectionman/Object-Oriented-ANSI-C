#ifndef new_h
#define new_h

#include <stdlib.h>
#include <stdarg.h>

struct Class {
    size_t size;
    void* (*ctor) (void* self, va_list* app);
    void* (*dtor) (void* self);
    void  (*draw) (const void* self);
    void  (*move) (void* self, const int dx, const int dy);
};

void draw(const void* self);

void move(void* point, const int dx, const int dy);

/// @brief object() accepts a descriptor and possibly more arguments for initialization
/// and returns a pointer to a new data item with a representation conforming to the descriptor.
/// @param objectClass The object descriptor 
void* object(const void* objectClass, ...);

/// @brief release() accepts a pointer originally produced by object() and recycles the associated resources.
/// @param object Object to release
void release(void* object);

#endif // new_h