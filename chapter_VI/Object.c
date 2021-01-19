#include <assert.h>

#include "Object_Rep.h"

void* createObject(const void* descriptor, ...); {
    const struct Class* _class_ = objectClass;
    void* pointer = calloc(1, _class_->size);

    assert(pointer);

    * ( const struct Class ** ) pointer = _class_;
    
    if (_class_->ctor) {
        va_list ap;
        va_start(ap, objectClass);

        pointer = _class_->ctor(pointer, &ap);

        va_end(ap);
    }

    return pointer;
} 

void releaseObject(void* self) {
    const struct Class** cp = self;

    if (self && *cp && (*cp)->dtor) {
        self = (*cp)->dtor(self);
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