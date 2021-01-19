#include <assert.h>
#include <stdlib.h>

#include "class.h"

void* newObject(const void* descriptor, ...) {
    const struct Class* _class_ = descriptor;
    void* pointer = calloc(1, _class_->size);

    assert(pointer);

    * ( const struct Class ** ) pointer = _class_;
    
    if (_class_->constructor) {
        va_list ap;
        va_start(ap, descriptor);

        pointer = _class_->constructor(pointer, &ap);

        va_end(ap);
    }

    return pointer;
} 

void deleteObject(void* self) {
    const struct Class** cp = self;

    if (self && *cp && (*cp)->destructor) {
        self = (*cp)->destructor(self);
    }

    free(self);
}

int differ(const void * self, const void * other) { 
    const struct Class * const * cp = self;

    assert(self && * cp && (*cp)->differ);

    return (*cp)->differ(self, other);
}

size_t sizeOf(const void* self) {
    const struct Class* const* cp = self;

    assert(self && *cp);
    return (*cp)->size;
}