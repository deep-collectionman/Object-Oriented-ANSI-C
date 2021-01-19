#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "Object_Rep.h"

static void* Object_ctor(void* self, va_list* app) {
    return self;
}

static void* Object_dtor(void* self) {
    return self;
}

static int Object_differ(const void* self, const void* other) {
    return self == other;
}

static int Object_objectInfo(const void* self, FILE* outputFile) {
    const struct Class* class = classOf(self);

    return fprintf(outputFile, "%s at %p\n", class->name, self);
}

const void* classOf(const void* self) {
    const struct Object* _self_ = self;

    assert(_self_ && _self_->_class_);
    return _self_->_class_;
}

size_t sizeOf(const void* self) {
    const struct Class* class = classOf(self);

    return class->size;
}