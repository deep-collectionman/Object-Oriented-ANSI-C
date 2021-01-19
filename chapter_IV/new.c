#include <assert.h>

#include "new.h"

void* object(const void* objectClass, ...) {
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

void release(void* self) {
    const struct Class** cp = self;

    if (self && *cp && (*cp)->dtor) {
        self = (*cp)->dtor(self);
    }

    free(self);
}

void draw(const void* self) {
    const struct Class* const* _selfClass_ = self;

    assert(self && *_selfClass_ && (*_selfClass_)->draw);
    (*_selfClass_)->draw(self);
}

void move(void* self, int dx, int dy) {
    const struct Class* const* _selfClass_ = self;

    assert(self && _selfClass_ && (*_selfClass_)->move);
    (*_selfClass_)->move(self, dx, dy);
}
