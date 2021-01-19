#include <stdlib.h>
#include <stddef.h>
#include <memory.h>

#include "Object_Rep.h"

static void* Class_ctor(void* self, va_list* app) {
    struct Class* _self_ = self;

    _self_->name = va_arg(*app, char*);
    _self_->superclass = va_arg(*app, struct Class*);
    _self_->size = va_arg(*app, size_t);

    assert(_self_->superclass);

    const size_t offset = offsetof(struct Class, ctor);

    memcpy((char *) _self_ + offset, (char *) _self_->superclass + offset, sizeOf(_self_->superclass) - offset);

    typedef void (*voidfunc)(void);
    voidfunc selector;
    va_list ap = *app;

    while ((selector = va_arg(ap, voidfunc))) {
        voidfunc method = va_arg(ap, voidfunc);

        if (selector == (voidfunc) createObject) {
            *(voidfunc*) & _self_->ctor = method;
        } else if (selector == (voidfunc) releaseObject) {
            *(voidfunc*) & _self_->dtor = method;
        } else if (selector == (voidfunc) differ) {
            *(voidfunc*) & _self_->differ = method;
        } else if (selector == (voidfunc) objectInfo) {
            *(voidfunc*) & _self_->objectInfo = method;
        }
    }

    return _self_;
}

static void* Class_dtor(void* self) {
    struct Class* _self_ = self;

    fprintf(stderr, "%s: cannot destroy class\n", _self_->name);
    return 0;
}

const void* super(const void* self) {
    const struct Class* _self_ = self;

    assert(_self_ && _self_->superclass);
    return _self_->superclass;
}